#ifndef TIMERVIEW_H
#define TIMERVIEW_H

#include <QMainWindow>
#include "TimerLogic.h"

namespace Ui {
class TimerView;
}

class TimerView : public QMainWindow {
    Q_OBJECT

public:
    explicit TimerView(QWidget *parent = nullptr);
    ~TimerView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TimerView *ui;
    TimerLogic m_timerLogic;
};

#endif // TIMERVIEW_H
