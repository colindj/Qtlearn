#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QErrorMessage>

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
    QColorDialog dialog(Qt::red, this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
    qDebug()<<"color:"<<color;
}

void MyWidget::on_pushButton_4_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("文件对话框"), "/home/dj/", tr("图片文件(*png *jpg)"));
    qDebug()<<"filename:"<<filename;
}

void MyWidget::on_pushButton_2_clicked()
{
    //ok用于标记是否单击乐ok按钮。然后获得选择的字体
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    //如果单击OK按钮，那么让“字体对话框”按钮使用薪资体
    //如果单击Cancel按钮，那么输出信息
    if(ok) ui->pushButton_2->setFont(font);
    else qDebug()<<tr("没有选择字体！");
}


void MyWidget::on_pushButton_5_clicked()
{
    bool ok;
    //获取字符串
    QString string = QInputDialog::getText(this,tr("输入字符串对话框"),tr("请输入用户名"),QLineEdit::Normal,tr("admin"),&ok);
    if (ok) qDebug()<<"string:"<<string;

    //获取整数
    int value1 = QInputDialog::getInt(this,tr("输入整数对话框"),tr("请输入-1000到1000之间的数值"),100,-1000,1000,10,&ok);
    if (ok) qDebug()<<"value1:"<<value1;

    //获取浮点数
    double value2 = QInputDialog::getDouble(this,tr("输入浮点数对话框"),tr("请输入-1000到1000之间的数值"),0.00,-1000,1000,2,&ok);
    if (ok) qDebug()<<"value2:"<<value2;

    QStringList items;
    items<<tr("条目1")<<tr("条目2");
    //获取条目
    QString item = QInputDialog::getItem(this, tr("输入条目对话框"),tr("请选择一个条目"),items,0,true,&ok);
    if(ok) qDebug()<<"item:"<<item;
}

void MyWidget::on_pushButton_3_clicked()
{
    //问题对话框
    int ret1 = QMessageBox::question(this, tr("问题对画框"), tr("你了解QT吗？"), QMessageBox::Yes, QMessageBox::No);
    if (ret1 == QMessageBox::Yes) qDebug()<<tr("问题！");
    //关于对话框
    QMessageBox::about(this, tr("关于对话框"), tr("这是一个QT程序！"));
}

void MyWidget::on_pushButton_6_clicked()
{
    QProgressDialog dialog(tr("文件复制进度"), tr("取消"), 0, 5000, this);
    dialog.setWindowTitle(tr("进度对话框")); //设置窗口标题
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i=0; i<50000; i++)
    {
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled()) break;
    }
    dialog.setValue(50000);
    qDebug()<<tr("复制结束！");
}

void MyWidget::on_pushButton_7_clicked()
{
    QErrorMessage *dialog = new QErrorMessage(this);
    dialog->setWindowTitle(tr("错误信息对话框"));
    dialog->showMessage(tr("这里是出错信息！"));
}
