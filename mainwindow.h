#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
#include <QMessageBox>
#include <qmodbusrtuserialclient>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QFile>
#include <QMediaPlayer>
#include <QElapsedTimer>
#include <QKeyEvent>

#include <windows.h>
#include <uiautomation.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sgn_start_countdown();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;

    // khoi tao va ket noi com
    QTimer *updateCom;
    QStringList list_current_port;

    void load_port();
    void update_com_func();
    void connect_port(const QString &portName);

    // nhan tin hieu tu barcode va chay takt time
    int cycle_time = 0;
    QTimer *taktTime;

    void takt_time_func();          // nhan tin hieu va dem nguoc
    void countdown_func();

    int countNG = 0;
    int countOK = 0;
    QTimer *sts_product_timer;
    void check_sts_product();

    // khoi tao va doc du lieu tu plc
    QModbusRtuSerialClient *qmodbus_serial;
    QTimer *readDataPlcTimer;
    QTimer *autoConnectTimer;
    QVector<quint16> dataPlc;
    QTimer *readM3Timer;
    QString portPlc;

    bool coilValue;
    bool plcConnected = false;
    bool last_response_from_plc = false;
    bool foundPlc;
    int countRetry = 0;

    void initModbusSerial(const QString &port);
    void checkAndReconnect();           // tim va tu dong ket noi com voi plc
    void writeDataPlc(bool value);
    void readPlcStartProcess(int address, quint16 size);
    void readCoilPlcStsProduct(int address, quint16 size);

    // phat am thanh ra loa
    QMediaPlayer *player;
    QAudioOutput *audioOutput;
    void playAudio(const QString &text);

    // check ki tu xem tu ban phim hay barcode
    QElapsedTimer keyTimer;
    QString buffer;

    // doc ki tu va show text qua window api
    QTimer *updateDataTimer;
    HWND FindChildWindow(HWND hwndParent, LPCWSTR className);      // tra ve handle can tim
    void getNotepadText();
};
#endif // MAINWINDOW_H
