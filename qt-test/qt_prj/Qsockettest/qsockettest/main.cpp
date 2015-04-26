#include <QCoreApplication>
#include "sockettest.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SocketTest socket;  //新建一个新的对象
    socket.Connect();   //进行连接

    return a.exec();
}
