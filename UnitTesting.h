#ifndef UNITTESTING_H
#define UNITTESTING_H

#include <QObject>
#include <QtTest/QTest>

class Timer;

class UnitTesting : public QObject
{
    Q_OBJECT

private slots:
    void testStartFunctionality();
    void testStopFunctionality();
    void testResetFunctionality();
    void testDateFormatChanges();
};

#endif // UNITTESTING_H
