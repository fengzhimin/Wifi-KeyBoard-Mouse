#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QPainter>
#include <QFile>
#include <QDebug>
#include <QResizeEvent>

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString qss;
    QFile qssFile(":/style.qss/style.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        ui->USE_BTN->setStyleSheet(qss);
        ui->RESET_BTN->setStyleSheet(qss);
        ui->TEST_BTN->setStyleSheet(qss);
        ui->IP_LE->setStyleSheet(qss);
        ui->Num_Board_CB->setStyleSheet(qss);
        ui->KeyBoard_CB->setStyleSheet(qss);
        qssFile.close();
    }

    ui->KeyBoard_CB->setChecked(true);
    ui->Num_Board_CB->setChecked(false);

    ui->IP_LE->setPlaceholderText(tr("电脑IP地址"));  // 设置默认文字

    QString qss1="QGroupBox {\
    border: 5px solid #0000EE;\
    border-radius: 25px;\
    margin-top: 1ex; \
    font-family:仿宋;\
    font:blod 20px;\
    font-size:28px;\
    padding:2px 4px;\
    }\
    QGroupBox::title {\
    subcontrol-origin: margin;\
    subcontrol-position: top center;\
    padding: 0 3px;\
    font-size:30px;\
    }";

    ui->OPT_GB->setStyleSheet(qss1);

    ui->INFO_LAB->setStyleSheet("QLabel {background:transparent;color: #FF0000;};");
    ui->IP_LAB->setStyleSheet("QLabel {background:transparent;color: #000000;};");

    this->setAutoFillBackground(true);

    //自动寻找IP
    int serversocket;    struct sockaddr_in serveraddress,clientaddress;
    int so_broadcast=1;
    if((serversocket=socket(AF_INET,SOCK_DGRAM,0))<0){
        qDebug("socket");
        return ;
    }
    if(setsockopt(serversocket,SOL_SOCKET,SO_BROADCAST,&so_broadcast,sizeof(so_broadcast))<0){
        qDebug("setsockopt");
        return ;
    }
    serveraddress.sin_family=AF_INET;
    serveraddress.sin_port=htons(INADDR_ANY);
    serveraddress.sin_addr.s_addr=htonl(INADDR_BROADCAST);

    if(bind(serversocket,(struct sockaddr*)&serveraddress,sizeof(struct sockaddr))<0){
        qDebug("bind");
        return ;
    }

    clientaddress.sin_family=AF_INET;
    clientaddress.sin_port=htons(5050);
    clientaddress.sin_addr.s_addr=htonl(INADDR_BROADCAST);

    char buf[200];
    strcpy(buf, "wifiKeyBoard");
    if(sendto(serversocket,buf,strlen(buf),0,(struct sockaddr*)&clientaddress,sizeof(clientaddress))<0){
        qDebug("error");
        return ;
    }
    else
    {
        //发送广播地址成功
        m_pTcpServer = new QTcpServer(this);
        if (!m_pTcpServer->listen(QHostAddress::AnyIPv4, 5051))
        {
            qDebug("server listen to 5051 error, exiting...");
            return ;
        }
        else
        {
            connect(m_pTcpServer, SIGNAL(newConnection()), this, SLOT(OnNewConnection()));
        }
    }
}

//用于获取电脑IP
void MainWindow::OnNewConnection()
{
    qDebug("connect success!\n");
    QTcpSocket *clientConnection = m_pTcpServer->nextPendingConnection();
    ui->IP_LE->setText(clientConnection->peerAddress().toString());
    clientConnection->close();
    m_pTcpServer->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    QPalette pal(palette());
    pal.setBrush(QPalette::Window, QBrush(QPixmap(":/picture1.jpg").scaled(event->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    setPalette(pal);
}

void MainWindow::on_TEST_BTN_clicked()
{
    m_IP = ui->IP_LE->text();
    m_port = 8008;
    this->m_tcpSocket.connected(m_IP, m_port);
    if(this->m_tcpSocket.getConnectResult())
    {
        this->ui->INFO_LAB->setText("OK");
        QMessageBox::about(this, "info", "link success!");
    }
    else
    {
        this->ui->INFO_LAB->setText("Error");
        QMessageBox::about(this, "error", this->m_tcpSocket.getLinkError());
    }

    this->m_tcpSocket.disconnected();
}

void MainWindow::on_RESET_BTN_clicked()
{
    ui->IP_LE->clear();
}

void MainWindow::on_USE_BTN_clicked()
{
    m_IP = ui->IP_LE->text();
    m_port = 8008;
    if(ui->KeyBoard_CB->isChecked())
    {
        m_keyBoard = new KeyBoard(m_IP, 8008);
        m_keyBoard->show();
    }
    else
    {
        m_num_KeyBoard = new Num_KeyBoard(m_IP, m_port);
        m_num_KeyBoard->show();
    }
}

void MainWindow::on_KeyBoard_CB_clicked()
{
    ui->KeyBoard_CB->setChecked(true);
    ui->Num_Board_CB->setChecked(false);
}

void MainWindow::on_Num_Board_CB_clicked()
{
    ui->Num_Board_CB->setChecked(true);
    ui->KeyBoard_CB->setChecked(false);
}
