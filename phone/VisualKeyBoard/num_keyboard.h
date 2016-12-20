#ifndef NUM_KEYBOARD_H
#define NUM_KEYBOARD_H

#include <QWidget>
#include "tcpsocket.h"
#include <QTimer>

namespace Ui {
class Num_KeyBoard;
}

class Num_KeyBoard : public QWidget
{
    Q_OBJECT

public:
    QString m_IP;
    short m_port;
    TcpSocket m_tcpSocket;
    QTimer *m_timer;
    QString m_str;
    int m_point;

protected:
     void closeEvent(QCloseEvent *event);

public:
    explicit Num_KeyBoard(QString _ip, short _port, QWidget *parent = 0);
    ~Num_KeyBoard();
    void keyNum();
    void paintEvent(QPaintEvent *event);

private slots:
    void timerUpDate();

    void keyReleased();

    void on_SLANT_BTN_pressed();

    void on_STAR_BTN_pressed();

    void on_SUB_BTN_pressed();

    void on_NUM7_BTN_pressed();

    void on_NUM8_BTN_pressed();

    void on_NUM9_BTN_pressed();

    void on_ADD_BTN_pressed();

    void on_NUM4_BTN_pressed();

    void on_NUM5_BTN_pressed();

    void on_NUM6_BTN_pressed();

    void on_NUM1_BTN_pressed();

    void on_NUM2_BTN_pressed();

    void on_NUM3_BTN_pressed();

    void on_ENTER_BTN_pressed();

    void on_NUM0_BTN_pressed();

    void on_DOUBLE0_BTN_pressed();

    void on_POINT_BTN_pressed();

    void on_NUMLOCK_BTN_clicked();

private:
    Ui::Num_KeyBoard *ui;
};

#endif // NUM_KEYBOARD_H
