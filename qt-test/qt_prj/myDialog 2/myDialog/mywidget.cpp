#include "mywidget.h"
#include "mydialog.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
    //先关闭主界面，其实他是隐藏起来了，并没有真正退出。然后新建MyDialog对象
    close();
    MyDialog dlg;
    //如果按下了“进入主创口”的按钮，则在次显示主界面
    //否则，因为现在已经没有显示的界面了，所以程序将推出
    if(dlg.exec() == QDialog::Accepted) show();
}


void MyWidget::on_pushButton_2_clicked()
{

}
