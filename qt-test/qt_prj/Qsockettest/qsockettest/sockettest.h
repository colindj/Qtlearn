#ifndef SOCKETTEST_H
#define SOCKETTEST_H

#include <QObject>
#include <QTcpSocket>
#include <QDebug>

class SocketTest : public QObject
{
    Q_OBJECT
public:
    explicit SocketTest(QObject *parent = 0);
    void Connect(); //申明连接函数
signals:

public slots:

private:
    //QTcpSocket类可以提供一个TCP Socket。QTcpSocket类是 QAbstractSocket的子类，并且可以允许你建立TCP连接和发送数据流。
    QTcpSocket *socket;
};

#endif // SOCKETTEST_H
