#include <QCoreApplication>
#include "download.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    DownLoad download;  //新建一个DownLaod
    download.do_download(); //执行下载网页的操作

    return a.exec();
}
