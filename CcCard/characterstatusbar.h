#ifndef CHARACTERSTATUSBAR_H
#define CHARACTERSTATUSBAR_H

#include <QWidget>

namespace Ui {
class CharacterStatusBar;
}

class CharacterStatusBar : public QWidget
{
    Q_OBJECT

public:
    explicit CharacterStatusBar(QWidget *parent = 0);
    ~CharacterStatusBar();
    Ui::CharacterStatusBar *ui;
private:

};

#endif // CHARACTERSTATUSBAR_H
