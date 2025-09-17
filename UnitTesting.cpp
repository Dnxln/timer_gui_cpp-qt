#include "UnitTesting.h"
#include <QTest>
#include <QSignalSpy>
#include <QTimer>
#include <QListWidget>
#include <QLabel>
#include <QDebug>
#include <QApplication>

#include "Timer.h"

void UnitTesting::testStartFunctionality() {
    int argc = 0;
    char **argv = nullptr;
    QApplication app(argc, argv);
    Timer timer(nullptr);
    QTest::qWait(200);
    QTimer* testTimer = timer.findChild<QTimer*>("timer");
    QVERIFY(testTimer != nullptr);

    QVERIFY(!testTimer->isActive());
    QMetaObject::invokeMethod(&timer, "on_btnStart_clicked");
    QTest::qWait(200);
    QVERIFY(testTimer->isActive());
}

void UnitTesting::testStopFunctionality() {
    int argc = 0;
    char **argv = nullptr;
    QApplication app(argc, argv);
    Timer timer(nullptr);
    QTest::qWait(200);
    QTimer* testTimer = timer.findChild<QTimer*>("timer");
    QVERIFY(testTimer != nullptr);

    QMetaObject::invokeMethod(&timer, "on_btnStart_clicked");
    QTest::qWait(200);
    QVERIFY(testTimer->isActive());
    QMetaObject::invokeMethod(&timer, "on_btnStop_clicked");
    QTest::qWait(200);
    QVERIFY(!testTimer->isActive());
}

void UnitTesting::testResetFunctionality() {
    int argc = 0;
    char **argv = nullptr;
    QApplication app(argc, argv);
    Timer timer(nullptr);
    QTest::qWait(200);
    QLabel* labTimer = timer.findChild<QLabel*>("labTimer");
    QVERIFY(labTimer != nullptr);

    QMetaObject::invokeMethod(&timer, "on_btnStart_clicked");
    QTest::qWait(200);
    QMetaObject::invokeMethod(&timer, "on_btnReset_clicked");
    QTest::qWait(200);
    QVERIFY(labTimer->text().contains("00:00:00:000"));
}

void UnitTesting::testDateFormatChanges() {
    int argc = 0;
    char **argv = nullptr;
    QApplication app(argc, argv);
    Timer date(nullptr);
    QTest::qWait(200);
    QListWidget* listDateFormats = date.findChild<QListWidget*>("listDateFormats");
    QLabel* labDate = date.findChild<QLabel*>("labDate");
    QVERIFY(listDateFormats != nullptr);
    QVERIFY(labDate != nullptr);

    QString format = labDate->text().left(10);
    listDateFormats->setCurrentRow(1);
    QMetaObject::invokeMethod(&date, "on_btnChange_clicked");
    QTest::qWait(200);
    QString format_ = labDate->text().left(10);
    listDateFormats->setCurrentRow(2);
    QMetaObject::invokeMethod(&date, "on_btnChange_clicked");
    QTest::qWait(200);
    QString format__ = labDate->text().left(10);
    QVERIFY(format != format_ && format != format__ && format_ != format__);
}

QTEST_APPLESS_MAIN(UnitTesting)
