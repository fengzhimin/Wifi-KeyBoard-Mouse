#include "keyboard.h"
#include "num_keyboard.h"
#include "mainwindow.h"
#include "tcpsocket.h"
#include <QApplication>
#include <QLabel>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow main;
    main.show();
    /*
    KeyBoard w;
    w.show();
    Num_KeyBoard n_w;
    n_w.show();
*/
    return a.exec();
}
