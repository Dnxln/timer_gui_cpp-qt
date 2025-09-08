#include <QApplication>
#include "Timer.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Timer t;
    t.show();

    return a.exec();
}
