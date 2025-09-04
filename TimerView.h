#ifndef TIMERVIEW_H
#define TIMERVIEW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class TimerView;
}
QT_END_NAMESPACE

class TimerView : public QMainWindow
{
    Q_OBJECT

public:
    TimerView(QWidget *parent = nullptr);
    ~TimerView();

private:
    Ui::TimerView *ui;
};
#endif // TIMERVIEW_H
