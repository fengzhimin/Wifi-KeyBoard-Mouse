#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->KeyBoard_CB->setChecked(true);
    ui->Num_Board_CB->setChecked(false);
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

void MainWindow::MainWindow::on_TEST_BTN_clicked()
{
    m_IP = ui->IP_LE->text();
    m_port = 8008;
    this->m_tcpSocket.connected(m_IP, m_port);
    if(this->m_tcpSocket.getConnectResult())
    {
        this->ui->INFO_LAB->setText("OK");
        ui->USE_BTN->setEnabled(true);
        QMessageBox::about(this, "info", "link success!");
    }
    else
    {
        this->ui->INFO_LAB->setText("Error");
        ui->USE_BTN->setEnabled(false);
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
