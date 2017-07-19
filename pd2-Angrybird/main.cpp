#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.move(250,65);
    w.setWindowTitle("AngryBird");
    w.show();

    return a.exec();
}
