#include "logindig.h"
#include "ui_logindig.h"

Logindig::Logindig(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logindig)
{
    ui->setupUi(this);
}

Logindig::~Logindig()
{
    delete ui;
}
