#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QDebug>

class DownLoad : public QObject
{
    Q_OBJECT
public:
    explicit DownLoad(QObject *parent = 0);
    //声明下载函数
    void do_download();
signals:

public slots:
    //槽函数声明
    void replyFinished(QNetworkReply* reply);
private:
    //QNetworkAccessManager类允许应用发送互联网请求并且接收其回复信息
    QNetworkAccessManager *manager;
};

#endif // DOWNLOAD_H
