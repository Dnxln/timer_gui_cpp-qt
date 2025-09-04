#include <QApplication>
#include "TimerView.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    TimerView w;
    w.show();

    return a.exec();
}
