#ifndef LOGINDIG_H
#define LOGINDIG_H

#include <QDialog>

namespace Ui {
class Logindig;
}

class Logindig : public QDialog
{
    Q_OBJECT

public:
    explicit Logindig(QWidget *parent = 0);
    ~Logindig();

private:
    Ui::Logindig *ui;
};

#endif // LOGINDIG_H
