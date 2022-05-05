#include "httpclient.h"
#include <QDebug>

HttpClient::HttpClient(QObject *parent) : QObject(parent)
{

}

bool HttpClient::Connect80(QString hostname)
{
    hostname = hostname.toUtf8();

    socket = new QTcpSocket(this);
    unsigned short port = 80;
    socket->connectToHost(hostname,port);

    connect(socket, &QTcpSocket::connected, this, &HttpClient::connected);
    connect(socket, &QTcpSocket::readyRead, this, &HttpClient::readyRead);

    if (!socket->waitForConnected(5000)) {
            return false;
        }
    else{
        return true;
    }
}

void HttpClient::connected()
{
    // normgerechter HTTP Request zum Server
    socket->write("GET / HTTP/1.1\r\nHost:" + hostname + "\r\n\r\n");
}

void HttpClient::readyRead()
{
    // HTTP-Antwort vom Server
    Text = socket->readAll();
    qDebug()<<Text;
    socket->disconnectFromHost();
}
