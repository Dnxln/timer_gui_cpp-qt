#include <QTimer>
#include <QDateTime>

#include "Timer.h"
#include "ui_Timer.h"

Timer::Timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timer),
    currentFormat("dd/MM/yyyy hh:mm:ss"),
    chrono(0, 0, 0) {
        ui->setupUi(this);

        date = new QTimer(this);
        date->setObjectName("date");
        connect(date, &QTimer::timeout, this, &Timer::showDateTime);
        date->start();
        ui->listDateFormats->addItem("dd/MM/yyyy   hh:mm:ss");
        ui->listDateFormats->addItem("MM/dd/yyyy   hh:mm:ss");
        ui->listDateFormats->addItem("yyyy/MM/dd   hh:mm:ss");
        ui->listDateFormats->setCurrentRow(0);
        on_btnChange_clicked();

        timer = new QTimer(this);
        timer->setObjectName("timer");
        connect(timer, &QTimer::timeout, this, &Timer::updateChrono);
    }

Timer::~Timer() {
    delete ui;
}

void Timer::on_btnChange_clicked() {
    currentFormat = ui->listDateFormats->currentItem()->text();
    showDateTime();
}
void Timer::showDateTime(){
    QString dateTimeText = QDateTime::currentDateTime().toString(currentFormat);
    ui->labDate->setText(dateTimeText);
}

void Timer::on_btnStart_clicked() {
    timer->start(10);
}
void Timer::on_btnStop_clicked() {
    timer->stop();
}
void Timer::on_btnReset_clicked() {
    timer->stop();
    chrono = QTime(0,0,0);
    ui->labTimer->setText("00:00:00:000");
}
void Timer::updateChrono() {
    chrono = chrono.addMSecs(10);
    ui->labTimer->setText(chrono.toString("hh:mm:ss:zzz"));
}
