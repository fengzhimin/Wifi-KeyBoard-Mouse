#include "num_keyboard.h"
#include "ui_num_keyboard.h"
#include <unistd.h>
#include <QMessageBox>
#include <QPainter>
#include <QFile>

Num_KeyBoard::Num_KeyBoard(QString _ip, short _port, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Num_KeyBoard)
{
    ui->setupUi(this);

    this->setAutoFillBackground(true);    //Widget增加背景图片时，这句一定要。
    QPixmap pixmap(":/picture4.png");
    QPixmap fitpixmap=pixmap.scaled(1200, 1200).scaled(this->width(),this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(fitpixmap));
    this->setPalette(palette);

    QString qss;
    QFile qssFile(":/style.qss/style.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qss = QLatin1String(qssFile.readAll());
        this->setStyleSheet(qss);
        qssFile.close();
    }

    this->m_IP = _ip;
    this->m_port = _port;
    bool _connect_ret = m_tcpSocket.connected(m_IP, m_port);
    if(!_connect_ret)
    {
        QMessageBox::about(this, "error", "connect PC failure!");
        QTimer::singleShot(0, qApp, SLOT(quit()));
    }
    m_timer = new QTimer(this);
    m_point = 0;
    connect(m_timer, SIGNAL(timeout()), this, SLOT(timerUpDate()));
    connect(ui->SLANT_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->STAR_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->SUB_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->ADD_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM0_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->DOUBLE0_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM1_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM2_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM3_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM4_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM5_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM6_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM7_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM8_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM9_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->ENTER_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->POINT_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
}

Num_KeyBoard::~Num_KeyBoard()
{
    m_tcpSocket.disconnected();
    delete ui;
}

void Num_KeyBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/picture4.png"));
}

void Num_KeyBoard::closeEvent(QCloseEvent *event)
{
    m_tcpSocket.disconnected();
}

void Num_KeyBoard::timerUpDate()
{
    if(m_point != 15)
    {
        m_point++;
    }
    else
        m_tcpSocket.writeData(m_str);
}

void Num_KeyBoard::keyReleased()
{
    m_point = 0;
    m_timer->stop();
}

void Num_KeyBoard::keyNum()
{
    m_tcpSocket.writeData(m_str);
    m_timer->start(50);
}

void Num_KeyBoard::on_SLANT_BTN_pressed()
{
    m_str = "98 ";
    keyNum();
}

void Num_KeyBoard::on_STAR_BTN_pressed()
{
    m_str = "55 ";
    keyNum();
}

void Num_KeyBoard::on_SUB_BTN_pressed()
{
    m_str = "74 ";
    keyNum();
}

void Num_KeyBoard::on_NUM7_BTN_pressed()
{
    m_str = "71 ";
    keyNum();
}

void Num_KeyBoard::on_NUM8_BTN_pressed()
{
    m_str = "72 ";
    keyNum();
}

void Num_KeyBoard::on_NUM9_BTN_pressed()
{
    m_str = "73 ";
    keyNum();
}

void Num_KeyBoard::on_ADD_BTN_pressed()
{
    m_str = "78 ";
    keyNum();
}

void Num_KeyBoard::on_NUM4_BTN_pressed()
{
    m_str = "75 ";
    keyNum();
}

void Num_KeyBoard::on_NUM5_BTN_pressed()
{
    m_str = "76 ";
    keyNum();
}

void Num_KeyBoard::on_NUM6_BTN_pressed()
{
    m_str = "77 ";
    keyNum();
}

void Num_KeyBoard::on_NUM1_BTN_pressed()
{
    m_str = "79 ";
    keyNum();
}

void Num_KeyBoard::on_NUM2_BTN_pressed()
{
    m_str = "80 ";
    keyNum();
}

void Num_KeyBoard::on_NUM3_BTN_pressed()
{
    m_str = "81 ";
    keyNum();
}

void Num_KeyBoard::on_ENTER_BTN_pressed()
{
    m_str = "96 ";
    keyNum();
}

void Num_KeyBoard::on_NUM0_BTN_pressed()
{
    m_str = "82 ";
    keyNum();
}

void Num_KeyBoard::on_DOUBLE0_BTN_pressed()
{
    m_str = "82 82 ";
    keyNum();
}

void Num_KeyBoard::on_POINT_BTN_pressed()
{
    m_str = "83 ";
    keyNum();
}

void Num_KeyBoard::on_NUMLOCK_BTN_clicked()
{
    m_str = "69 ";
    keyNum();
}
