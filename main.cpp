#include "TimerView.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TimerView tv;
    tv.show();
    return a.exec();
}
