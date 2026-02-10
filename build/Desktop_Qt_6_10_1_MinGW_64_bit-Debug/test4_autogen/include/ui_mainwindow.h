/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_container;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_sp;
    QLineEdit *data_serial;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_takttime;
    QSpinBox *spinBox;
    QLineEdit *lineEditTaktTime;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_count_ok;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_ok;
    QLabel *label_count_ok;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_ng;
    QLabel *label_count_ng;
    QWidget *widget_product;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_product;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QLabel *labelCOM;
    QLabel *labelNameCom;
    QSpacerItem *horizontalSpacer_4;
    QLabel *labelStsCom;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_5;
    QWidget *widget_expand_funtion;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(767, 330);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        widget_container = new QWidget(centralwidget);
        widget_container->setObjectName("widget_container");
        widget_container->setStyleSheet(QString::fromUtf8("QWidget#widget_container {\n"
"	background-color:rgb(200, 200, 200);\n"
"	max-width: 300px;\n"
"	min-height: 80px;\n"
"}\n"
""));
        verticalLayout_2 = new QVBoxLayout(widget_container);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_sp = new QLabel(widget_container);
        label_sp->setObjectName("label_sp");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_sp->sizePolicy().hasHeightForWidth());
        label_sp->setSizePolicy(sizePolicy1);
        label_sp->setMinimumSize(QSize(100, 0));
        label_sp->setMaximumSize(QSize(50, 30));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        label_sp->setFont(font);
        label_sp->setStyleSheet(QString::fromUtf8("QLabel#label_sp\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	max-width:50px;\n"
"	max-height:30px;\n"
"}"));
        label_sp->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_4->addWidget(label_sp);

        data_serial = new QLineEdit(widget_container);
        data_serial->setObjectName("data_serial");
        QFont font1;
        font1.setPointSize(13);
        data_serial->setFont(font1);
        data_serial->setAutoFillBackground(false);
        data_serial->setStyleSheet(QString::fromUtf8("QLineEdit#data_serial\n"
"{\n"
"	min-width: 120px;\n"
"	max-height: 30px;\n"
"}"));
        data_serial->setReadOnly(true);

        horizontalLayout_4->addWidget(data_serial);

        horizontalLayout_4->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_takttime = new QLabel(widget_container);
        label_takttime->setObjectName("label_takttime");
        label_takttime->setFont(font);
        label_takttime->setStyleSheet(QString::fromUtf8("QLabel#label_takttime\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	max-width:80px;\n"
"	max-height:20px;\n"
"}"));
        label_takttime->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_takttime);

        spinBox = new QSpinBox(widget_container);
        spinBox->setObjectName("spinBox");
        spinBox->setStyleSheet(QString::fromUtf8("QSpinBox#spinBox\n"
"{\n"
"	max-width:50px;\n"
"	max-height:20px;\n"
"}"));
        spinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        spinBox->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        spinBox->setMaximum(59);

        horizontalLayout_2->addWidget(spinBox);

        lineEditTaktTime = new QLineEdit(widget_container);
        lineEditTaktTime->setObjectName("lineEditTaktTime");
        sizePolicy1.setHeightForWidth(lineEditTaktTime->sizePolicy().hasHeightForWidth());
        lineEditTaktTime->setSizePolicy(sizePolicy1);
        lineEditTaktTime->setStyleSheet(QString::fromUtf8("QLineEdit#lineEditTaktTime\n"
"{\n"
"	min-width: 50px;\n"
"	max-height:20px;\n"
"	border-radius: 2px; \n"
"}"));
        lineEditTaktTime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lineEditTaktTime->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditTaktTime);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_6->addWidget(widget_container);

        widget_count_ok = new QWidget(centralwidget);
        widget_count_ok->setObjectName("widget_count_ok");
        widget_count_ok->setStyleSheet(QString::fromUtf8("QWidget#widget_count_ok {\n"
"	background-color: rgb(255, 170, 0);\n"
"	max-width: 300px;\n"
"	min-height: 70px;\n"
"}\n"
""));
        gridLayout = new QGridLayout(widget_count_ok);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(5, 5, 5, 5);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_ok = new QLabel(widget_count_ok);
        label_ok->setObjectName("label_ok");
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(true);
        label_ok->setFont(font2);
        label_ok->setStyleSheet(QString::fromUtf8("QLabel#label_ok\n"
"{\n"
"}"));
        label_ok->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_ok);

        label_count_ok = new QLabel(widget_count_ok);
        label_count_ok->setObjectName("label_count_ok");
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        label_count_ok->setFont(font3);
        label_count_ok->setStyleSheet(QString::fromUtf8("QLabel#label_count_ok\n"
"{\n"
"	background-color: rgb(204, 204, 204);\n"
"	max-width:50px;\n"
"	max-height:70px;\n"
"}"));
        label_count_ok->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_count_ok);


        gridLayout->addLayout(horizontalLayout_3, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_ng = new QLabel(widget_count_ok);
        label_ng->setObjectName("label_ng");
        label_ng->setFont(font2);
        label_ng->setStyleSheet(QString::fromUtf8("QLabel#label_ng\n"
"{\n"
"\n"
"}"));
        label_ng->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_ng);

        label_count_ng = new QLabel(widget_count_ok);
        label_count_ng->setObjectName("label_count_ng");
        label_count_ng->setFont(font3);
        label_count_ng->setStyleSheet(QString::fromUtf8("QLabel#label_count_ng\n"
"{\n"
"	background-color: rgb(204, 204, 204);\n"
"	max-width:50px;\n"
"	max-height:70px;\n"
"}"));
        label_count_ng->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_5->addWidget(label_count_ng);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);


        verticalLayout_6->addWidget(widget_count_ok);


        horizontalLayout_8->addLayout(verticalLayout_6);

        widget_product = new QWidget(centralwidget);
        widget_product->setObjectName("widget_product");
        widget_product->setStyleSheet(QString::fromUtf8("QWidget#widget_product{\n"
"	background-color: rgb(200, 200, 200);\n"
"	max-width:250px;\n"
"	max-height:150px;\n"
"}"));
        verticalLayout_4 = new QVBoxLayout(widget_product);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(5, 5, 5, 5);
        label_product = new QLabel(widget_product);
        label_product->setObjectName("label_product");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_product->sizePolicy().hasHeightForWidth());
        label_product->setSizePolicy(sizePolicy2);
        label_product->setMaximumSize(QSize(16777215, 250));
        QFont font4;
        font4.setPointSize(30);
        font4.setBold(true);
        label_product->setFont(font4);
        label_product->setStyleSheet(QString::fromUtf8("QLabel#label_product\n"
"{\n"
"	background-color: rgb(0, 170, 127);\n"
"	min-width: 230px;\n"
"	max-height:250px;\n"
"	color: rgb(0, 0, 0);\n"
"}"));
        label_product->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_product);


        horizontalLayout_8->addWidget(widget_product);


        gridLayout_2->addLayout(horizontalLayout_8, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout->addWidget(pushButton_3);

        labelCOM = new QLabel(centralwidget);
        labelCOM->setObjectName("labelCOM");
        labelCOM->setFont(font);
        labelCOM->setStyleSheet(QString::fromUtf8("QLabel#labelCOM\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	max-height: 20px;\n"
"	min-width:50px;\n"
"	border-radius: 2px; \n"
"}"));
        labelCOM->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelCOM);

        labelNameCom = new QLabel(centralwidget);
        labelNameCom->setObjectName("labelNameCom");
        labelNameCom->setFont(font);
        labelNameCom->setStyleSheet(QString::fromUtf8("QLabel#labelNameCom\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	max-height: 20px;\n"
"	min-width:100px;\n"
"	border-radius: 2px; \n"
"}"));
        labelNameCom->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelNameCom);

        horizontalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        labelStsCom = new QLabel(centralwidget);
        labelStsCom->setObjectName("labelStsCom");
        labelStsCom->setFont(font);
        labelStsCom->setStyleSheet(QString::fromUtf8("QLabel#labelStsCom\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	max-height: 20px;\n"
"	min-width:100px;\n"
"	border-radius: 2px; \n"
"}"));
        labelStsCom->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(labelStsCom);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer_5 = new QSpacerItem(80, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);

        widget_expand_funtion = new QWidget(centralwidget);
        widget_expand_funtion->setObjectName("widget_expand_funtion");
        widget_expand_funtion->setStyleSheet(QString::fromUtf8("QWidget#widget_expand_funtion\n"
"{\n"
"	background-color: rgb(76, 154, 255);\n"
"	max-height:50px;\n"
"}"));
        horizontalLayout_7 = new QHBoxLayout(widget_expand_funtion);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        pushButton = new QPushButton(widget_expand_funtion);
        pushButton->setObjectName("pushButton");
        QFont font5;
        font5.setBold(true);
        pushButton->setFont(font5);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton#pushButton\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	max-height: 20px;\n"
"}"));

        horizontalLayout_6->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(widget_expand_funtion);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setFont(font5);
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_2\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"	max-height: 20px;\n"
"}"));

        horizontalLayout_6->addWidget(pushButton_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_3);

        horizontalLayout_6->setStretch(2, 1);

        horizontalLayout_7->addLayout(horizontalLayout_6);


        gridLayout_2->addWidget(widget_expand_funtion, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 767, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_sp->setText(QCoreApplication::translate("MainWindow", "M\303\243 s\341\272\243n ph\341\272\251m", nullptr));
        label_takttime->setText(QCoreApplication::translate("MainWindow", "TAKT TIME", nullptr));
        label_ok->setText(QCoreApplication::translate("MainWindow", "S\341\273\220 L\306\257\341\273\242NG S\341\272\242N PH\341\272\250M OK", nullptr));
        label_count_ok->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_ng->setText(QCoreApplication::translate("MainWindow", "S\341\273\220 L\306\257\341\273\242NG S\341\272\242N PH\341\272\250M NG", nullptr));
        label_count_ng->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_product->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "M5 ON", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "M5 OFF", nullptr));
        labelCOM->setText(QCoreApplication::translate("MainWindow", "COM", nullptr));
        labelNameCom->setText(QCoreApplication::translate("MainWindow", "NameCom", nullptr));
        labelStsCom->setText(QCoreApplication::translate("MainWindow", "DISCONNECT", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "TRUY V\341\272\244N", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "RESET", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
