#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "basic.h"
#include <QMainWindow>
#include <QKeyEvent>
#include <QtMultimedia/QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void keyPressEvent(QKeyEvent *k);
    void changeSelect();
    void MoveS();
    void SelectS();
    void select();

signals:
    void playMoveSound();
    void playselectSound();

private:
    Ui::MainWindow *ui;
    QMediaPlayer *movesound;
    QMediaPlayer *selectsound;
    basic *basicwindow;
    int selectIndex;
};

#endif // MAINWINDOW_H
