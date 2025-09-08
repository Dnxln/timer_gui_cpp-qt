#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>

namespace Ui {
    class Timer;
}

class Timer : public QMainWindow {
    Q_OBJECT

    public:
        explicit Timer(QWidget *parent = nullptr);
        ~Timer();

    private slots:
        void showDateTime();
        void on_btnChange_clicked();

    private:
        Ui::Timer *ui;
        QString currentFormat;
};

#endif // TIMER_H
