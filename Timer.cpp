#include "Timer.h"
#include "ui_Timer.h"

#include <QTimer>
#include <QDateTime>

Timer::Timer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Timer),
    currentFormat("dd/MM/yyyy hh:mm:ss") {
        ui->setupUi(this);

        QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(showDateTime()));
        timer->start();
        ui->listDateFormats->addItem("dd/MM/yyyy   hh:mm:ss");
        ui->listDateFormats->addItem("MM/dd/yyyy   hh:mm:ss");
        ui->listDateFormats->addItem("yyyy/MM/dd   hh:mm:ss");
        ui->listDateFormats->setCurrentRow(0);
        on_btnChange_clicked();
    }

Timer::~Timer() {
    delete ui;
}

void Timer::showDateTime(){
    QString dateTimeText = QDateTime::currentDateTime().toString(currentFormat);
    ui->labDate->setText(dateTimeText);
}

void Timer::on_btnChange_clicked() {
    currentFormat = ui->listDateFormats->currentItem()->text();
    showDateTime();
}

