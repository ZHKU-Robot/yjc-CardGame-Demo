#ifndef FINISHEDTURNBTN_H
#define FINISHEDTURNBTN_H

#include <QWidget>

namespace Ui {
class FinishedTurnBtn;
}

class FinishedTurnBtn : public QWidget
{
    Q_OBJECT

public:
    explicit FinishedTurnBtn(QWidget *parent = 0);
    ~FinishedTurnBtn();
    Ui::FinishedTurnBtn *ui;
private:

};

#endif // FINISHEDTURNBTN_H
