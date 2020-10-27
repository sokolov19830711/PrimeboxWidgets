#include "sensorinicator.h"

SensorInicator::SensorInicator(QWidget *parent) : QLabel (parent)
{
    setStyleSheet(normalStyle_);
}

void SensorInicator::setActive(bool state)
{
    isActive_ = state;
    refresh();
}

void SensorInicator::setValue(int value)
{
    value_ = value;
    isActive_ = true;
    setText(QString().setNum(value_));
    refresh();
}

void SensorInicator::setMaxNormal(int value)
{
    maxNormal_ = value;
    refresh();
}

void SensorInicator::setMinNormal(int value)
{
    minNormal_ = value;
    refresh();
}

void SensorInicator::refresh()
{
    if (!isActive_)
    {
        setStyleSheet(alertStyle_);
        setText("OFF");
        return;
    }

    if((value_ > minNormal_) && (value_ < maxNormal_))
    {
        setStyleSheet(normalStyle_);
    }

    else
    {
        setStyleSheet(alertStyle_);
    }
}
