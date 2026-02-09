#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(500, 260);
    // Tự động xóa đối tượng khi đóng cửa sổ
    setAttribute(Qt::WA_DeleteOnClose);

    // init object
    updateCom = new QTimer(this);                           // timer cap nhat com moi 1s
    taktTime = new QTimer(this);                            // timer dem nguoc mot giay mot lan
    sts_product_timer = new QTimer(this);                   // timer quet trang thai san pham moi 100ms

    qmodbus_serial = new QModbusRtuSerialClient(this);
    readDataPlcTimer = new QTimer(this);                    // timer doc data plc
    autoConnectTimer = new QTimer(this);
    updateDataTimer = new QTimer(this);                     // timer cap nhat du lieu tu notepad moi 1s


    player = new QMediaPlayer;
    audioOutput = new QAudioOutput;

    // load port va cap nhat cong com
    connect(updateCom, &QTimer::timeout, this, &MainWindow::update_com_func);
    updateCom->start(1000);                      // cap nhat cong com moi 1s

    // checkAndReconnect va load portcom modbus
    connect(autoConnectTimer, &QTimer::timeout, this, &MainWindow::checkAndReconnect);
    autoConnectTimer->start(500);
    // nhan tin hieu barcode va chay takt time
    connect(this, &MainWindow::sgn_start_countdown, this, &MainWindow::takt_time_func);

    readM3Timer = new QTimer(this);
    connect(readM3Timer, &QTimer::timeout, this, [=]()
            {
        readCoilPlcStsProduct(3,1);
    });
    connect(sts_product_timer, &QTimer::timeout, this, &MainWindow::check_sts_product);

    //slot thuc hien phat ra signal dem nguoc mot giay 1 lan
    connect(taktTime, &QTimer::timeout, this, &MainWindow::countdown_func);

    // connect doc data IO plc
    connect(readDataPlcTimer, &QTimer::timeout, this, [=]
            {
        readPlcStartProcess(5,1);
    });


    // M5 ON clicked
    connect(ui->pushButton_4, &QPushButton::clicked, this, [=]
            {
        writeDataPlc(true);
    });

    // M5 OFF clicked
    connect(ui->pushButton_3, &QPushButton::clicked, this, [=]
            {
                writeDataPlc(false);
            });

    connect(updateDataTimer, &QTimer::timeout, this, &MainWindow::getNotepadText);
    updateDataTimer->start(300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_port()
{
    QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for(const auto &port:ports)
    {
        list_current_port.append(port.portName());
    }
}

void MainWindow::update_com_func()
{
    QStringList list_new_port;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        list_new_port.append(info.portName());
    }

    QSet<QString> set_new_port = QSet<QString>(list_new_port.begin(), list_new_port.end());
    QSet<QString> set_current_port = QSet<QString>(list_current_port.begin(), list_current_port.end());

    //Cập nhật các cổng cắm thêm
    QSet<QString> added = set_new_port - set_current_port;

    //Cập nhật các cổng bị rút
    QSet<QString> removed = set_current_port - set_new_port;

    list_current_port = list_new_port;

    qDebug()<<"List Port: "<<list_current_port;

    ///////////////////////////////////////
    if(list_current_port.contains(portPlc) && plcConnected  == true)
    {
        autoConnectTimer->stop();               // chay ham checkAndReconnect
    }

    // rut 485 ra cam lai thi cap tim lai com485
    if(!list_current_port.contains(portPlc))
    {
        autoConnectTimer->start();
    }
}

void MainWindow::takt_time_func()
{
    coilValue = false;
    cycle_time = ui->spinBox->value();
    ui->lineEditTaktTime->setText(QString::number(cycle_time));
    taktTime->start(1000);              // bat dau chay ham countdown_func

    // readDataPlcTimer->start(100);
    // sts_product_timer->start(100);      // bat dau chay ham check_sts_product
}

void MainWindow::countdown_func()
{
    if(cycle_time == 0)
    {
        ui->lineEditTaktTime->setText(QString::number(cycle_time));
        taktTime->stop();
        sts_product_timer->stop();
        return;
    }
    cycle_time -= 1;
    ui->lineEditTaktTime->setText(QString::number(cycle_time));
}

void MainWindow::check_sts_product()
{
    if(cycle_time > 0 && coilValue == true)
    {
        ui->label_product->setText("OK");
        ui->label_product->setStyleSheet("color: yellow;"
                                             "font-size: 100px;"
                                             "font-weight: bold;"
                                             "background-color: rgb(0,255,0);"
                                             "min-width:240px;"
                                             "max-height:130px;");
        coilValue = false;
        cycle_time = 0;
        countOK +=1;
        playAudio("OK");
        ui->label_count_ok->setText(QString::number(countOK));
        sts_product_timer->stop();
        readM3Timer->stop();
    }

    else if((cycle_time <= 0))
    {
        ui->label_product->setText("NG");
        ui->label_product->setStyleSheet("color: yellow;"
                                         "font-size: 100px;"
                                         "font-weight: bold;"
                                         "background-color: rgb(255,0,0);"
                                         "min-width:240px;"
                                         "max-height:130px;");
        coilValue = false;
        cycle_time = 0;
        countNG +=1;
        playAudio("NG");
        ui->label_count_ng->setText(QString::number(countNG));
        sts_product_timer->stop();
        readM3Timer->stop();
    }
}

void MainWindow::initModbusSerial(const QString &port)
{
    qmodbus_serial->setConnectionParameter(
        QModbusDevice::SerialPortNameParameter, port);
    qmodbus_serial->setConnectionParameter(
        QModbusDevice::SerialParityParameter, QSerialPort::NoParity);
    qmodbus_serial->setConnectionParameter(
        QModbusDevice::SerialBaudRateParameter, QSerialPort::Baud9600);
    qmodbus_serial->setConnectionParameter(
        QModbusDevice::SerialDataBitsParameter, QSerialPort::Data8);
    qmodbus_serial->setConnectionParameter(
        QModbusDevice::SerialStopBitsParameter, QSerialPort::OneStop);

    qmodbus_serial->setTimeout(500);
    qmodbus_serial->setNumberOfRetries(2);
}

void MainWindow::writeDataPlc(bool value)
{
    if (!qmodbus_serial)                                // kiem tra con tro qmodbus_serial rong ko (qmodbus_serial != nullptr)
        return;

    if (qmodbus_serial->state() != QModbusDevice::ConnectedState)
        return;

    QModbusDataUnit data(QModbusDataUnit::Coils, 5, 1);
    data.setValue(0, value);                            // dat thanh ghi o vi tri 0 (coil m3) voi gia tri value

    if (QModbusReply *reply = qmodbus_serial->sendWriteRequest(data, 1))    // slave id: 1
    {
        connect(reply, &QModbusReply::finished, this, [=]()
                {
                    if (reply->error() == QModbusDevice::NoError)
                    {
                        qDebug() << "Write coil OK";
                    }
                    else
                    {
                        qDebug() << "Write coil ERROR:" << reply->errorString();
                    }
                    reply->deleteLater();
                });
    }
    else
    {
        qDebug() << "Send write request failed";
    }
}

void MainWindow::readCoilPlcStsProduct(int address, quint16 size)            // doc
{
    // check trang thai xem da ket noi chua
    if (qmodbus_serial->state() != QModbusDevice::ConnectedState)
        return;

    QModbusDataUnit data(QModbusDataUnit::Coils, address, size);

    if (QModbusReply *reply = qmodbus_serial->sendReadRequest(data, 1))
    {
        connect(reply, &QModbusReply::finished,this,[=]()
                {
            if(reply == nullptr)
            {
                qDebug()<<"No response";
                return;
            }

            else if(reply->error() == QModbusDevice::NoError)
            {
                const QModbusDataUnit data = reply->result();
                coilValue = data.value(0);
                qDebug()<<"Coil value"<<coilValue;
            }
            reply->deleteLater();                                   // xoa object o vong lap tiep theo tranh crash
        });
    }
}

void MainWindow::checkAndReconnect()
{
    // bool foundPlc = false;
    countRetry++;
    for (const QString &port : list_current_port)
    {
        qDebug() << "Try PLC on" << port;

        qmodbus_serial->disconnectDevice();                 // dong ket noi
        initModbusSerial(port);
        qmodbus_serial->connectDevice();

        QModbusDataUnit test(QModbusDataUnit::Coils, 5, 1);

        // sendReadRequest tra ve 1 object reply neu ko co loi, tra ve nullptr neu ko doc duoc
        QModbusReply *reply = qmodbus_serial->sendReadRequest(test, 1);
        if (!reply)         // reply == nullptr
            continue;

        connect(reply, &QModbusReply::finished, this, [=]()
                {
                    if (reply->error() == QModbusDevice::NoError)
                    {
                        countRetry = 0;
                        plcConnected = true;
                        foundPlc = true;
                        portPlc = port;

                        ui->labelNameCom->setText(port);
                        ui->labelStsCom->setText("CONNECTED");
                        qDebug() << "PLC FOUND ON" << port;

                        if (!readDataPlcTimer->isActive())      // neu chua bat dau doc data
                            readDataPlcTimer->start(500);
                    }
                    else
                    {
                        qDebug() << "PLC not on" << port << reply->errorString();
                    }
                    reply->deleteLater();
                });
        break;  //warning quet bo qua com
    }

    qDebug() << "PLC FOUND ON:" << portPlc;

    if(countRetry > 3)
    {
        foundPlc = false;
        plcConnected = false;
        if (!foundPlc)
        {
            ui->labelStsCom->setText("DISCONNECT");

            if (readDataPlcTimer->isActive())
                readDataPlcTimer->stop();
        }
    }
}
void MainWindow::readPlcStartProcess(int address, quint16 size)
{
    if(qmodbus_serial->state() == QModbusDevice::UnconnectedState)
        return;

    // doc IO
    // QModbusDataUnit data(QModbusDataUnit::DiscreteInputs, 2, 1);         // doc dau vao X2
    // QModbusReply *reply = qmodbus_serial->sendReadRequest(data, 1);

    // doc coil M
    QModbusDataUnit data(QModbusDataUnit::Coils, address, size);
    QModbusReply *reply = qmodbus_serial->sendReadRequest(data, 1);
    if(reply == nullptr)
    {
        qDebug()<<"no respon IO";
        return;
    }

    connect(reply, &QModbusReply::finished, this, [=]
            {
        if(reply->error() == QModbusDevice::NoError)
            {
            QModbusDataUnit dataPlcIO;
            dataPlcIO = reply->result();
            bool current = dataPlcIO.value(0);

            if (current && !last_response_from_plc)              // neu m5 on chi phat signal 1 lan, ko phat lien tuc
            {
                emit sgn_start_countdown();                      // bat dau dem nguoc
                readM3Timer->start(500);
                sts_product_timer->start(500);
            }
            last_response_from_plc = current;
        }
    });
}

void MainWindow::playAudio(const QString &text)
{
    player->setAudioOutput(audioOutput);
    if(text == "OK")
    {
        player->setSource(QUrl::fromLocalFile("E:/antue/giao dien may test do khi/Am thanh/audio-OK.mp3"));
    }

    else
    {
        player->setSource(QUrl::fromLocalFile("E:/antue/giao dien may test do khi/Am thanh/audio-NG.mp3"));
    }
    audioOutput->setVolume(1.0);
    player->play();
}

HWND MainWindow::FindChildWindow(HWND hwndParent, LPCWSTR className)
{
    HWND hwndchild = ::FindWindowEx(hwndParent, NULL, className, NULL);
    if(hwndchild)
        return hwndchild;

    else
    {
        hwndchild = ::FindWindowEx(hwndParent, NULL, NULL, NULL);
        while(hwndchild)
        {
            HWND hwndfound = FindChildWindow(hwndchild, className);
            if(hwndfound)
                return hwndfound;
            hwndchild = ::FindWindowExW(hwndParent, hwndchild, NULL, NULL);

        }
        // if(hwndchild == className)
        // {
        //     hwndchild = className;
        //     return hwndchild;
        // }
        return NULL;
    }
}

void MainWindow:: getNotepadText() {
    HWND hwndNotepad = ::FindWindowW(L"Notepad", NULL);         // HWND: tim handle

    // if (hwndNotepad) {
    //     HWND hContainer = ::FindWindowExW(hwndNotepad, NULL, L"NotepadTextBox", NULL);
    //     if (hContainer) {
    //         if (hContainer) {
    //             hContainer = ::FindWindowExW(hContainer, NULL, L"RichEditD2DPT", NULL);
    //         }
    //     }

    HWND hContainer = FindChildWindow(hwndNotepad, L"RichEditD2DPT");

        qDebug()<<"hContainer: "<<hContainer;

        if (hContainer) {

            int len = ::SendMessage(hContainer, WM_GETTEXTLENGTH, 0, 0);                    // gui yeu cau lay do dai van ban
            if (len > 0) {
                wchar_t *buffer = new wchar_t[len + 1];
                ::SendMessage(hContainer, WM_GETTEXT, (WPARAM)len + 1, (LPARAM)buffer);     // copy du lieu sang buffer dung WM_GETTEXT

                QString finalStr = QString::fromWCharArray(buffer);
                ui->data_serial->setText(finalStr);
                delete[] buffer;
            }
        }
    }


void MainWindow::keyPressEvent(QKeyEvent *event) {
    qint64 elapsed = keyTimer.restart();

    if (elapsed > 50) {
        buffer.clear();
    }

    buffer += event->text();

    if (event->key() == Qt::Key_Return) {
        if (buffer.length() < 15 && elapsed < 50) {
            qDebug() << "Đây là Barcode:" << buffer;
        } else {
            qDebug() << "Đây là người gõ phím!";
        }
        buffer.clear();
    }
}


