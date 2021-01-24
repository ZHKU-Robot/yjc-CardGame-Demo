#ifndef MPBAR_H
#define MPBAR_H

#include <QWidget>

namespace Ui {
class MpBar;
}

class MpBar : public QWidget
{
    Q_OBJECT

public:
    explicit MpBar(QWidget *parent = 0);
    ~MpBar();
    Ui::MpBar *ui;
private:

};

#endif // MPBAR_H
