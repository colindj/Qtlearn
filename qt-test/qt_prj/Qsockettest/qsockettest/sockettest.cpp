#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) :
    QObject(parent)
{
}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    //Connect
    //connectToHost()尝试通过端口来连接地址
    socket->connectToHost("baidu.com",80);

    //waitForConnected()等待连接知道超过最大等待时间。如果连接建立函数返回true；否则返回false。
    //当返回false时可以调用error来确定无法连接的原因
    if(socket->waitForConnected(3000))
    {
        qDebug() << "Connect";
        //向地址发送信息并且等待写入
        socket->write("Hello Server\r\n\r\n");
        socket->waitForBytesWritten(1000);
        //接收地址返回信息，并且输出接收到信息
        socket->waitForReadyRead(3000);
        qDebug() <<"Reading :"<<socket->bytesAvailable();
        qDebug() <<socket->readAll();
        socket->close();
    }
    else
    {
        qDebug() << "Not Connect";
    }
}
