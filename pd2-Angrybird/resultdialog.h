#ifndef RESULTDIALOG_H
#define RESULTDIALOG_H

#include <QDialog>

namespace Ui {
class resultdialog;
}

class resultdialog : public QDialog
{
    Q_OBJECT

public:
    explicit resultdialog(QWidget *parent = 0);
    ~resultdialog();
    void scoreshow(float score);
    void winlose(bool win);

private:
    Ui::resultdialog *ui;
};

#endif // RESULTDIALOG_H
