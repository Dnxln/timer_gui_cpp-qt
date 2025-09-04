#include "TimerView.h"
#include "ui_TimerView.h"

TimerView::TimerView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TimerView)
{
    ui->setupUi(this);
    connect(ui->btn, &QPushButton::clicked, this, &TimerView::on_pushButton_clicked);
}

TimerView::~TimerView()
{
    delete ui;
}

void TimerView::on_pushButton_clicked()
{
    QString userInput = ui->lineInput->text();

    QString result = m_timerLogic.joinStrings("Input inserito: ", userInput);

    ui->lineOutput->setText(result);
}
