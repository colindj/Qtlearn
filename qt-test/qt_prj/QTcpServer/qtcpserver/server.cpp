#include "server.h"

MyServer::MyServer(QObject *parent) :
    QObject(parent)
{
    server  = new QTcpServer(this);
    //每当一个新的连接建立时，newConnection()信号就会被发射出来；这里的newConnection()是指SIGNAL(newConnection())中的
    //虽然这里信号和槽同名，但请不要混淆
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnection()));
    //listen()告诉服务器监听按地址或端口传入的连接。如果端口是0，则端口被自动选择；如果地址是QHostAddress::Any，则服务器会监听所有网络接口。
    //listen()操作成功返回true;否则返回false
    if(!server->listen(QHostAddress::Any , 1234))
    {
        qDebug() <<"Server could not start!";
    }
    else
    {
        qDebug() <<"Server started!";
    }
}

void MyServer::newConnection()
{
    //nextPendingConnection()将下一个挂起的连接以QTcpSocket对象的形式返回
    QTcpSocket *socket =server->nextPendingConnection();
    //写入数据
    socket->write("Hello Client\r\n");
    socket->flush();//刷新缓存
    //等待写入数据
    socket->waitForBytesWritten(3000);
    socket->close();
}
