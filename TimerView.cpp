#include "TimerView.h"
#include "./ui_TimerView.h"

TimerView::TimerView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TimerView)
{
    ui->setupUi(this);
}

TimerView::~TimerView()
{
    delete ui;
}
