#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QPainter>
#include <QFile>
#include <QResizeEvent>

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
