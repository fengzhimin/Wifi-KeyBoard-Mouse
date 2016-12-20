#include "keyboard.h"
#include "ui_keyboard.h"
#include <QMouseEvent>
#include <QMessageBox>
#include <QBitmap>
#include <QPainter>

KeyBoard::KeyBoard(QString _ip, short _port, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyBoard)
{ 
    ui->setupUi(this);

    this->setAutoFillBackground(true);    //Widget增加背景图片时，这句一定要。
    QPixmap pixmap(":/picture4.png");
    QPixmap fitpixmap=pixmap.scaled(1200, 1200).scaled(this->width(),this->height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(fitpixmap));
    this->setPalette(palette);

    this->m_IP = _ip;
    this->m_port = _port;
    bool _connectMouse_ret = m_tcpSocket_mouse.connected(m_IP, 8009);
    bool _connectKeyBoard_ret = m_tcpSocket_keyBoard.connected(m_IP, m_port);
    if(!_connectMouse_ret || !_connectKeyBoard_ret)
    {
        QMessageBox::about(this, "error", "connect PC failure!");
        QTimer::singleShot(0, qApp, SLOT(quit()));
    }
    m_timer = new QTimer(this);
    m_point = 0;
    m_case_point = false;
    m_shift_left_point = false;
    m_shift_right_point = false;
    m_ctrl_left_point = false;
    m_ctrl_right_point = false;
    m_win_left_point = false;
    m_win_right_point = false;
    m_alt_left_point = false;
    m_alt_right_point = false;

    connect(ui->F1_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F2_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F3_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F4_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F5_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F6_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F7_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F8_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F9_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F10_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F11_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F12_BTN, SIGNAL(released()), this, SLOT(keyReleased()));

    connect(ui->TILDE_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM1_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM2_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM3_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM4_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM5_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM6_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM7_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM8_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM9_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->NUM0_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->SUB_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->ADD_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->BACK_BTN, SIGNAL(released()), this, SLOT(keyReleased()));

    connect(ui->TAB_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->Q_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->W_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->E_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->R_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->T_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->Y_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->U_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->I_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->O_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->P_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->BRACE_LEFT_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->BRACE_RIGHT_BTN, SIGNAL(released()), this, SLOT(keyReleased()));

    connect(ui->A_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->S_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->D_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->F_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->G_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->H_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->J_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->K_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->L_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->COLON_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->QUOTE_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->BACK_SLANT_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->ENTER_BTN, SIGNAL(released()), this, SLOT(keyReleased()));

    connect(ui->Z_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->X_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->C_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->V_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->B_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->N_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->M_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->ANGLE_LEFT_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->ANGLE_RIGHT_BTN, SIGNAL(released()), this, SLOT(keyReleased()));
    connect(ui->QUES_BTN, SIGNAL(released()), this, SLOT(keyReleased()));

    connect(ui->SPACE_BTN, SIGNAL(released()), this, SLOT(keyReleased()));

    connect(m_timer, SIGNAL(timeout()), this, SLOT(timerUpDate()));
}

KeyBoard::~KeyBoard()
{
    delete ui;
}

void KeyBoard::closeEvent(QCloseEvent *event)
{
    m_tcpSocket_keyBoard.disconnected();
    m_tcpSocket_mouse.disconnected();
}

void KeyBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(":/picture4.png"));
}

void KeyBoard::timerUpDate()
{
    if(m_point != 15)
    {
        m_point++;
    }
    else
        m_tcpSocket_keyBoard.writeData(m_str);
}

void KeyBoard::keyReleased()
{
    m_point = 0;
    m_str = "";
    if(m_shift_left_point)
        m_tcpSocket_keyBoard.writeData("42 ");
    if(m_shift_right_point)
       m_tcpSocket_keyBoard.writeData("54 ");
    if(m_ctrl_left_point)
        m_tcpSocket_keyBoard.writeData("29 ");
    if(m_ctrl_right_point)
        m_tcpSocket_keyBoard.writeData("97 ");
    if(m_win_left_point)
        m_tcpSocket_keyBoard.writeData("55 ");
    if(m_win_right_point)
        m_tcpSocket_keyBoard.writeData("55 ");
    if(m_alt_left_point)
        m_tcpSocket_keyBoard.writeData("56 ");
    if(m_alt_right_point)
        m_tcpSocket_keyBoard.writeData("100 ");
    m_shift_left_point = false;
    m_shift_right_point = false;
    m_ctrl_left_point = false;
    m_ctrl_right_point = false;
    m_win_left_point = false;
    m_win_right_point = false;
    m_alt_left_point = false;
    m_alt_right_point = false;
    m_timer->stop();
}

void KeyBoard::keyNum()
{
    m_tcpSocket_keyBoard.writeData(m_str);
    m_timer->start(50);
}

void KeyBoard::judgeSpecialKey()
{
    if(m_shift_left_point)
        m_str += "f";
    if(m_shift_right_point)
        m_str += "g";
    if(m_ctrl_left_point)
        m_str += "h";
    if(m_ctrl_right_point)
        m_tcpSocket_keyBoard.writeData("97 ");
    if(m_win_left_point)
        m_str += "j";
    if(m_win_right_point)
        m_str += "k";
    if(m_alt_left_point)
        m_str += "l";
    if(m_alt_right_point)
        m_str += "m";
}

void KeyBoard::mouseMoveEvent(QMouseEvent *event)
{
    QRect _rect = this->ui->MOUSE_FRAME->frameGeometry();
    QPoint _point = event->pos();
    _rect = QRect(_rect.x()+2, _rect.y()+2, _rect.width() - 2, _rect.height() - 2);
    if(_rect.contains(_point))
    {
        QString location = QString("%1,%2 ").arg(_point.x()-m_point_prev.x()).arg(_point.y()-m_point_prev.y());
        m_tcpSocket_mouse.writeData(location);
    }
    m_point_prev = _point;
}

void KeyBoard::mousePressEvent(QMouseEvent *event)
{
    m_point_prev = event->pos();
}

void KeyBoard::mouseReleaseEvent(QMouseEvent *event)
{

}

void KeyBoard::mouseDoubleClickEvent(QMouseEvent *event)
{
    QString _str = "ab";
    m_tcpSocket_mouse.writeData(_str);
}

void KeyBoard::on_LEFT_BTN_pressed()
{
    QString _str = "a";
    m_tcpSocket_mouse.writeData(_str);
}

void KeyBoard::on_LEFT_BTN_released()
{
    QString _str = "b";
    m_tcpSocket_mouse.writeData(_str);
}

void KeyBoard::on_RIGHT_BTN_pressed()
{
    QString _str = "c";
    m_tcpSocket_mouse.writeData(_str);
}

void KeyBoard::on_RIGHT_BTN_released()
{
    QString _str = "d";
    m_tcpSocket_mouse.writeData(_str);
}

void KeyBoard::on_ESC_BTN_clicked()
{
    m_str = "1 ";
    m_tcpSocket_keyBoard.writeData(m_str);
}

void KeyBoard::on_F1_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "59 ";
    keyNum();
}

void KeyBoard::on_F2_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "60 ";
    keyNum();
}

void KeyBoard::on_F3_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "61 ";
    keyNum();
}

void KeyBoard::on_F4_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "62 ";
    keyNum();
}

void KeyBoard::on_F5_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "63 ";
    keyNum();
}

void KeyBoard::on_F6_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "64 ";
    keyNum();
}

void KeyBoard::on_F7_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "65 ";
    keyNum();
}

void KeyBoard::on_F8_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "66 ";
    keyNum();
}

void KeyBoard::on_F9_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "67 ";
    keyNum();
}

void KeyBoard::on_F10_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "68 ";
    keyNum();
}

void KeyBoard::on_F11_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "87 ";
    keyNum();
}

void KeyBoard::on_F12_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "88 ";
    keyNum();
}

void KeyBoard::on_TILDE_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "41 ";
    keyNum();
}

void KeyBoard::on_NUM1_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "2 ";
    keyNum();
}

void KeyBoard::on_NUM2_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "3 ";
    keyNum();
}
void KeyBoard::on_NUM3_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "4 ";
    keyNum();
}
void KeyBoard::on_NUM4_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "5 ";
    keyNum();
}
void KeyBoard::on_NUM5_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "6 ";
    keyNum();
}

void KeyBoard::on_NUM6_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "7 ";
    keyNum();
}
void KeyBoard::on_NUM7_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "8 ";
    keyNum();
}
void KeyBoard::on_NUM8_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "9 ";
    keyNum();
}
void KeyBoard::on_NUM9_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "10 ";
    keyNum();
}
void KeyBoard::on_NUM0_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "11 ";
    keyNum();
}

void KeyBoard::on_SUB_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "12 ";
    keyNum();
}

void KeyBoard::on_ADD_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "13 ";
    keyNum();
}

void KeyBoard::on_BACK_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "14 ";
        keyNum();
}

void KeyBoard::on_TAB_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "15 ";
    keyNum();
}

void KeyBoard::on_Q_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "16 ";
    keyNum();
}
void KeyBoard::on_W_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "17 ";
    keyNum();
}
void KeyBoard::on_E_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "18 ";
    keyNum();
}
void KeyBoard::on_R_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "19 ";
    keyNum();
}
void KeyBoard::on_T_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "20 ";
    keyNum();
}
void KeyBoard::on_Y_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "21 ";
    keyNum();
}
void KeyBoard::on_U_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "22 ";
    keyNum();
}
void KeyBoard::on_I_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "23 ";
    keyNum();
}
void KeyBoard::on_O_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "24 ";
    keyNum();
}

void KeyBoard::on_P_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "25 ";
    keyNum();
}

void KeyBoard::on_BRACE_LEFT_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "26 ";
    keyNum();
}

void KeyBoard::on_BRACE_RIGHT_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "27 ";
    keyNum();
}

void KeyBoard::on_A_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "30 ";
    keyNum();
}
void KeyBoard::on_S_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "31 ";
    keyNum();
}
void KeyBoard::on_D_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "32 ";
    keyNum();
}
void KeyBoard::on_F_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "33 ";
    keyNum();
}
void KeyBoard::on_G_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "34 ";
    keyNum();
}
void KeyBoard::on_H_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "35 ";
    keyNum();
}
void KeyBoard::on_J_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "36 ";
    keyNum();
}
void KeyBoard::on_K_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "37 ";
    keyNum();
}
void KeyBoard::on_L_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "38 ";
    keyNum();
}

void KeyBoard::on_COLON_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "39 ";
    keyNum();
}

void KeyBoard::on_QUOTE_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "40 ";
    keyNum();
}

void KeyBoard::on_BACK_SLANT_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "43 ";
    keyNum();
}

void KeyBoard::on_ENTER_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "28 ";
    keyNum();
}

/*
void KeyBoard::on_SHIFT_LEFT_BTN_pressed()
{
    m_shift_left_point = true;
    m_tcpSocket_keyBoard.writeData("42 ");
}
*/

void KeyBoard::on_Z_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "44 ";
    keyNum();
}
void KeyBoard::on_X_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "45 ";
    keyNum();
}
void KeyBoard::on_C_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "46 ";
    keyNum();
}
void KeyBoard::on_V_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "47 ";
    keyNum();
}
void KeyBoard::on_B_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "48 ";
    keyNum();
}
void KeyBoard::on_N_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "49 ";
    keyNum();
}
void KeyBoard::on_M_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "50 ";
    keyNum();
}

void KeyBoard::on_ANGLE_LEFT_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "51 ";
    keyNum();
}

void KeyBoard::on_ANGLE_RIGHT_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "52 ";
    keyNum();
}

void KeyBoard::on_QUES_BTN_pressed()
{
    judgeSpecialKey();
    m_str += "53 ";
    keyNum();
}

/*
void KeyBoard::on_SHIFT_RIGHT_BTN_pressed()
{
    m_shift_right_point = true;
    m_tcpSocket_keyBoard.writeData("54 ");
}
*/

void KeyBoard::on_SPACE_BTN_pressed()
{
    judgeSpecialKey();
    m_str = +"57 ";
    keyNum();
}

/*
void KeyBoard::on_SHIFT_LEFT_BTN_released()
{
    m_shift_left_point = false;
    m_tcpSocket_keyBoard.writeData("42 ");
}
*/

/*
void KeyBoard::on_CTRL_LEFT_BTN_pressed()
{
    m_ctrl_left_point = true;
    m_tcpSocket_keyBoard.writeData("29 ");
}

void KeyBoard::on_CTRL_LEFT_BTN_released()
{
    m_ctrl_left_point = false;
    m_tcpSocket_keyBoard.writeData("29 ");
}
*/

/*
void KeyBoard::on_WIN_LEFT_BTN_pressed()
{
    m_win_left_point = true;
    m_tcpSocket_keyBoard.writeData("55 ");
}

void KeyBoard::on_WIN_LEFT_BTN_released()
{
    m_win_left_point = false;
    m_tcpSocket_keyBoard.writeData("55 ");
}
*/

/*
void KeyBoard::on_ALT_LEFT_BTN_pressed()
{
    m_alt_left_point = true;
    m_tcpSocket_keyBoard.writeData("56 ");
}

void KeyBoard::on_ALT_LEFT_BTN_released()
{
    m_alt_left_point = false;
    m_tcpSocket_keyBoard.writeData("56 ");
}

void KeyBoard::on_ALT_RIGHT_BTN_pressed()
{
    m_alt_left_point = true;
    m_tcpSocket_keyBoard.writeData("100 ");
}

void KeyBoard::on_ALT_RIGHT_BTN_released()
{
    m_alt_left_point = false;
    m_tcpSocket_keyBoard.writeData("100 ");
}
*/

/*
void KeyBoard::on_WIN_RIGHT_BTN_pressed()
{
    m_win_left_point = true;
    m_tcpSocket_keyBoard.writeData("55 ");
}

void KeyBoard::on_WIN_RIGHT_BTN_released()
{
    m_win_left_point = false;
    m_tcpSocket_keyBoard.writeData("55 ");
}
*/

/*
void KeyBoard::on_CTRL_RIGHT_BTN_pressed()
{
    m_ctrl_left_point = true;
    m_tcpSocket_keyBoard.writeData("97 ");
}
*/

/*
void KeyBoard::on_CTRL_RIGHT_BTN_released()
{
    m_ctrl_left_point = false;
    m_tcpSocket_keyBoard.writeData("97 ");
}
*/

void KeyBoard::on_CASE_BTN_clicked()
{
    if(m_case_point)
        m_case_point = false;
    else
        m_case_point = true;

    m_tcpSocket_keyBoard.writeData("58 ");
}

/*
void KeyBoard::on_SHIFT_RIGHT_BTN_released()
{
    m_shift_left_point = false;
    m_tcpSocket_keyBoard.writeData("54 ");
}
*/

void KeyBoard::on_SHIFT_LEFT_BTN_clicked()
{
    m_shift_left_point = true;
    m_tcpSocket_keyBoard.writeData("42 ");
}

void KeyBoard::on_CTRL_LEFT_BTN_clicked()
{
    m_ctrl_left_point = true;
    m_tcpSocket_keyBoard.writeData("29 ");
}

void KeyBoard::on_WIN_LEFT_BTN_clicked()
{
    m_win_left_point = true;
    m_tcpSocket_keyBoard.writeData("55 ");
}

void KeyBoard::on_ALT_LEFT_BTN_clicked()
{
    m_alt_left_point = true;
    m_tcpSocket_keyBoard.writeData("56 ");
}

void KeyBoard::on_ALT_RIGHT_BTN_clicked()
{
    m_alt_right_point = true;
    m_tcpSocket_keyBoard.writeData("100 ");
}

void KeyBoard::on_WIN_RIGHT_BTN_clicked()
{
    m_win_right_point = true;
    m_tcpSocket_keyBoard.writeData("55 ");
}

void KeyBoard::on_CTRL_RIGHT_BTN_clicked()
{
    m_ctrl_right_point = true;
    m_tcpSocket_keyBoard.writeData("97 ");
}

void KeyBoard::on_SHIFT_RIGHT_BTN_clicked()
{
    m_shift_right_point = true;
    m_tcpSocket_keyBoard.writeData("54 ");
}
