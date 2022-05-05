#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QObject>
#include <QCoreApplication>
#include <QAbstractSocket>
#include <QTcpSocket>

class HttpClient : public QObject
{
    Q_OBJECT
public:
    explicit HttpClient(QObject *parent = nullptr);

    bool Connect80(QString hostname);

    QTcpSocket* socket;
    QByteArray hostname;

    void connected();
    void readyRead();

    QString Text;

signals:

public slots:

};

#endif // HTTPCLIENT_H
