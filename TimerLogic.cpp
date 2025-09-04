#include "TimerLogic.h"

QString TimerLogic::joinStrings(const QString& basePhrase, const QString& userInput) const
{
    return basePhrase + " " + userInput;
}
