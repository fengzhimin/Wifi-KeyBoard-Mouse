#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

class TcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit TcpSocket(QObject *parent = 0);
    ~TcpSocket();
    bool connected(QString _ipaddress, quint16 _port);
    void disconnected();
    bool getConnectResult();
    QString getLinkError();
    int writeData(QString _str);
    int readData(char *data, int size);

signals:

public slots:
    void connectedSlots();

    void disconnectedSlots();

    void socketErroSlots();

public:
    QTcpSocket * socket;

private:
    bool m_connectResult;
    QString m_connectErrorInfo;
};

#endif // TCPSOCKET_H
