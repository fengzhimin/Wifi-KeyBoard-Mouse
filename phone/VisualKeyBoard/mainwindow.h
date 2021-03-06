#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QTimer>
#include "tcpsocket.h"
#include <QTcpServer>
#include "keyboard.h"
#include "num_keyboard.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_TEST_BTN_clicked();

    void on_RESET_BTN_clicked();

    void on_USE_BTN_clicked();

    void on_KeyBoard_CB_clicked();

    void on_Num_Board_CB_clicked();

    void OnNewConnection();

private:
    Ui::MainWindow *ui;

public:
    TcpSocket m_tcpSocket;
    QString m_IP;
    short m_port;
    KeyBoard *m_keyBoard;
    Num_KeyBoard *m_num_KeyBoard;
    QTimer *m_timer;
    QTcpServer* m_pTcpServer;
};

#endif // MAINWINDOW_H
