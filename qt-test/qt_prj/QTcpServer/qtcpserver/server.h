#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QtNetwork/QTcpSocket>

class MyServer : public QObject
{
    Q_OBJECT
public:
    explicit MyServer(QObject *parent = 0);

signals:

public slots:
    //声明槽函数
    void newConnection();
private:
    //QTcpServer类提供一个基于TCP的服务器
    //这个类能够接受传入的TCP连接。您可以指定端口或让QTcpServer自动选择一个端口。你可以监听一个特定的地址或计算机的所有地址。

   QTcpServer *server;
};
#endif // SERVER_H
