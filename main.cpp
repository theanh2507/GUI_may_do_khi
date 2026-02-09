#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setQuitOnLastWindowClosed(true);                              // khi dong cua so cuoi cung, chuong trinh tu thoat

    QWidget parent;                                                 // tao 1 widget parent an chua mainwindow
    parent.setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);      // FramelessWindowHint: loai bo khung vien cua so parent

    MainWindow w(&parent);                                          // tao mainwindow voi parent vua tao
    w.setWindowFlags(Qt::Window | Qt::WindowStaysOnTopHint);        // lam mainwindow luon nam tren cung
    // w.setAttribute(Qt::WA_DeleteOnClose);
    // QObject::connect(&w, &QObject::destroyed, &a, &QApplication::quit);

    w.show();

    std::string string = "MainWindow";

    // HWND Findf = ::FindWindowEx(0, 0, (const wchar_t *)"Notepad", 0);

    return a.exec();
}

// #include "mainwindow.h"

// #include <QApplication>
// #include <QGridLayout>


// int main(int argc, char *argv[])
// {
//     QApplication a(argc, argv);
//     MainWindow w;
