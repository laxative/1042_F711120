#ifndef BASICRESULT_H
#define BASICRESULT_H

#include <QDialog>

namespace Ui {
class basicresult;
}

class basicresult : public QDialog
{
    Q_OBJECT

public:
    explicit basicresult(QWidget *parent = 0);
    ~basicresult();
    void scoreshow(int score);

private:
    Ui::basicresult *ui;
};

#endif // BASICRESULT_H
