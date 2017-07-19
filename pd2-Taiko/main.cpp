#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.move(650,250);
    w.setWindowTitle("Taiko");
    w.show();
    return a.exec();
}
