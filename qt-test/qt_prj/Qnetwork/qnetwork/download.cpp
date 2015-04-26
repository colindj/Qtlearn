#include "download.h"
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QFile>
#include <QTextStream>

DownLoad::DownLoad(QObject *parent) :
    QObject(parent)
{
}

void DownLoad::do_download()
{
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //连接信号和槽
    //finished()这个信号当一个待定的的网络回复完成时这个信号被发射。回复参数是一个包含刚刚完成的回复的指针。
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));
    //QNetworkRequest类保存QNetworkAccessManager类的请求信息
    //QUrl类提供了一个处理URL的方便的接口
   //get()函数发出一个请求获得目标对象的内容，获得内容保存在一个 QNetworkReply对象中
   manager->get(QNetworkRequest(QUrl("http://www.baidu.com")));

}

void DownLoad::replyFinished(QNetworkReply *reply)
{
    //error()返回QNetworkAccessManager请求过程中发生的错误信息
    //判断网络请求过程中是否发生错误
    if(reply->error() == QNetworkReply::NoError)
    {
        qDebug() << "Connected.";
        QString text = reply->readAll();
        qDebug() << "Size: "<<text.size();//显示网页信息大小
        QFile file("H:/project/Qt_Prj/Qnetwork/download.txt");  //保存网页信息的文件路径
        //将网页信息进行存储
        if(file.open(QIODevice::WriteOnly))
        {
            QTextStream out(&file);
            out << text;
            out.flush();
            qDebug()<<"DownLoad Web Succes";
            file.close();
        }
        else
        {
            qDebug() <<"Failed to open file";
        }

    }
    else
    {
        qDebug() << "ERROR!";
        qDebug() << reply->errorString();   //显示网络请求过程中出错信息
    }
    reply->deleteLater();//按照程序进程删除该对象，防止内存泄露
}
