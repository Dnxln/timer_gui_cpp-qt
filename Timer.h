#ifndef TIMER_H
#define TIMER_H

#include <QMainWindow>
#include <QTime>

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

        void on_btnStart_clicked();
        void on_btnStop_clicked();
        void on_btnReset_clicked();
        void updateChrono();

    private:
        Ui::Timer *ui;
        QString currentFormat;
        QTimer *timer;
        QTime chrono;
        QTimer *date;
};

#endif // TIMER_H
