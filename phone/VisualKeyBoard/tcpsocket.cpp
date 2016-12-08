#include "tcpsocket.h"
#include<QDataStream>
#include <QThread>

TcpSocket::TcpSocket(QObject *parent) : QObject(parent)
{
    this->m_connectResult = false;
    //set Tcp socket
    this->socket = new QTcpSocket(this);
    connect(this->socket,SIGNAL(connected()),this,SLOT(connectedSlots()));
    connect(this->socket,SIGNAL(disconnected()),this,SLOT(disconnectedSlots()));
    connect(this->socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(socketErroSlots()));
}

TcpSocket::~TcpSocket()
{
    this->socket->close();
}

bool TcpSocket::connected(QString _ipaddress, quint16 _port)
{
    this->socket->connectToHost(_ipaddress, _port, QTcpSocket::ReadWrite);
    m_connectResult = this->socket->waitForConnected();

    return m_connectResult;
}

void TcpSocket::disconnected()
{
    this->socket->close();
}

QString TcpSocket::getLinkError()
{
    return this->m_connectErrorInfo;
}

bool TcpSocket::getConnectResult()
{
    return this->m_connectResult;
}

void TcpSocket::connectedSlots()
{
    //QMessageBox::about(this,"提示","连接成功");
    this->m_connectResult = true;
}

void TcpSocket::disconnectedSlots()
{
    //QMessageBox::about(this, "提示","断开成功");
}

void TcpSocket::socketErroSlots()
{
    this->m_connectErrorInfo = this->socket->errorString();
    //QMessageBox::about(this, "提示", socketErrInfo);
    this->m_connectResult = false;
}

int TcpSocket::readData(char *data, int size)
{
    bool ret = this->socket->waitForReadyRead();
    if(ret)
        return this->socket->read(data, size);
    return 0;
}

int TcpSocket::writeData(QString _str)
{
    int ret = this->socket->write(_str.toStdString().c_str(), strlen(_str.toStdString().c_str()));
    return ret;
}
