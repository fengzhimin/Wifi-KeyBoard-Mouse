#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>
#include "tcpsocket.h"
#include <QRect>
#include <QString>
#include <QTimer>
#include <QSize>

namespace Ui {
class KeyBoard;
}

class KeyBoard : public QWidget
{
    Q_OBJECT

public:
    QString m_IP;
    short m_port;
    TcpSocket m_tcpSocket_mouse, m_tcpSocket_keyBoard;
    QTimer *m_timer;
    QString m_str;
    int m_point;
    QPoint m_point_prev;
    bool m_case_point;
    bool m_shift_left_point;
    bool m_shift_right_point;
    bool m_ctrl_left_point;
    bool m_ctrl_right_point;
    bool m_win_left_point;
    bool m_win_right_point;
    bool m_alt_left_point;
    bool m_alt_right_point;

public:
    explicit KeyBoard(QString _ip, short _port, QWidget *parent = 0);
    ~KeyBoard();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseDoubleClickEvent(QMouseEvent *event);
    void keyNum();
    void judgeSpecialKey();

private slots:
    void timerUpDate();

    void keyReleased();

    void on_LEFT_BTN_pressed();
    void on_LEFT_BTN_released();
    void on_RIGHT_BTN_pressed();
    void on_RIGHT_BTN_released();

    void on_ESC_BTN_clicked();
    void on_F1_BTN_pressed();
    void on_F2_BTN_pressed();
    void on_F3_BTN_pressed();
    void on_F4_BTN_pressed();
    void on_F5_BTN_pressed();
    void on_F6_BTN_pressed();
    void on_F7_BTN_pressed();
    void on_F8_BTN_pressed();
    void on_F9_BTN_pressed();
    void on_F10_BTN_pressed();
    void on_F11_BTN_pressed();
    void on_F12_BTN_pressed();

    void on_TILDE_BTN_pressed();
    void on_NUM1_BTN_pressed();
    void on_NUM2_BTN_pressed();
    void on_NUM3_BTN_pressed();
    void on_NUM4_BTN_pressed();
    void on_NUM5_BTN_pressed();
    void on_NUM6_BTN_pressed();
    void on_NUM7_BTN_pressed();
    void on_NUM8_BTN_pressed();
    void on_NUM9_BTN_pressed();
    void on_NUM0_BTN_pressed();
    void on_SUB_BTN_pressed();
    void on_ADD_BTN_pressed();
    void on_BACK_BTN_pressed();

    void on_TAB_BTN_pressed();
    void on_Q_BTN_pressed();
    void on_W_BTN_pressed();
    void on_E_BTN_pressed();
    void on_R_BTN_pressed();
    void on_T_BTN_pressed();
    void on_Y_BTN_pressed();
    void on_U_BTN_pressed();
    void on_I_BTN_pressed();
    void on_O_BTN_pressed();
    void on_P_BTN_pressed();
    void on_BRACE_LEFT_BTN_pressed();
    void on_BRACE_RIGHT_BTN_pressed();

    void on_A_BTN_pressed();
    void on_S_BTN_pressed();
    void on_D_BTN_pressed();
    void on_F_BTN_pressed();
    void on_G_BTN_pressed();
    void on_H_BTN_pressed();
    void on_J_BTN_pressed();
    void on_K_BTN_pressed();
    void on_L_BTN_pressed();
    void on_COLON_BTN_pressed();
    void on_QUOTE_BTN_pressed();
    void on_BACK_SLANT_BTN_pressed();
    void on_ENTER_BTN_pressed();

    //void on_SHIFT_LEFT_BTN_pressed();
    void on_Z_BTN_pressed();
    void on_X_BTN_pressed();
    void on_C_BTN_pressed();
    void on_V_BTN_pressed();
    void on_B_BTN_pressed();
    void on_N_BTN_pressed();
    void on_M_BTN_pressed();
    void on_ANGLE_LEFT_BTN_pressed();
    void on_ANGLE_RIGHT_BTN_pressed();
    void on_QUES_BTN_pressed();
    //void on_SHIFT_RIGHT_BTN_pressed();

    void on_SPACE_BTN_pressed();
/*
    void on_SHIFT_LEFT_BTN_released();

    void on_CTRL_LEFT_BTN_pressed();

    void on_CTRL_LEFT_BTN_released();

    void on_WIN_LEFT_BTN_pressed();

    void on_WIN_LEFT_BTN_released();

    void on_ALT_LEFT_BTN_pressed();

    void on_ALT_LEFT_BTN_released();

    void on_ALT_RIGHT_BTN_pressed();

    void on_ALT_RIGHT_BTN_released();

    void on_WIN_RIGHT_BTN_pressed();

    void on_WIN_RIGHT_BTN_released();

    void on_CTRL_RIGHT_BTN_pressed();

    void on_CTRL_RIGHT_BTN_released();
*/

    void on_CASE_BTN_clicked();

    //void on_SHIFT_RIGHT_BTN_released();

    void on_SHIFT_LEFT_BTN_clicked();

    void on_CTRL_LEFT_BTN_clicked();

    void on_WIN_LEFT_BTN_clicked();

    void on_ALT_LEFT_BTN_clicked();

    void on_ALT_RIGHT_BTN_clicked();

    void on_WIN_RIGHT_BTN_clicked();

    void on_CTRL_RIGHT_BTN_clicked();

    void on_SHIFT_RIGHT_BTN_clicked();

protected:
     void closeEvent(QCloseEvent *event);

private:
    Ui::KeyBoard *ui;
};

#endif // KEYBOARD_H
