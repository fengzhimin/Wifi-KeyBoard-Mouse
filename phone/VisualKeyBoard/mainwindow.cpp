#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setAutoFillBackground(true);    //Widget增加背景图片时，这句一定要。
    QPixmap pixmap(":/picture1.png");
    QPixmap fitpixmap=pixmap.scaled(1200, 1200).scaled(this->width(),this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(fitpixmap));
    this->setPalette(palette);

    ui->KeyBoard_CB->setChecked(true);
    ui->Num_Board_CB->setChecked(false);

    ui->IP_LE->setPlaceholderText(tr("电脑IP地址"));  // 设置默认文字

    QString qss1="QGroupBox {\
    border: 2px solid #0000EE;\
    border-radius: 5px;\
    margin-top: 1ex; \
    font-family:仿宋;\
    font:blod 14px;\
    font-size:20px;\
    }\
    QGroupBox::title {\
    subcontrol-origin: margin;\
    subcontrol-position: top center;\
    padding: 0 3px;\
    font-size:20px;\
    }";

    ui->OPT_GB->setStyleSheet(qss1);

    ui->INFO_LAB->setStyleSheet("QLabel {color: #FF0000;};");

    //ui->USE_BTN->setEnabled(false);
    //set lineEdit form for IP address
    /*
    QRegExp rx("((2[0-4]//d|25[0-5]|[01]?//d//d?)//.){3}(2[0-4]//d|25[0-5]|[01]?//d//d?)");
    QRegExpValidator v(rx, this);
    ui->IP_LE->setValidator(&v);
    ui->IP_LE->setInputMask("000.000.000.000;0");
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/picture1.png"));
}

void MainWindow::MainWindow::on_TEST_BTN_clicked()
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
