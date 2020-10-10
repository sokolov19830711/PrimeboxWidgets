#include "spinbox.h"

SpinBox::SpinBox(QWidget *parent) : QWidget(parent)
{
    mainLayout_ = new QVBoxLayout;
    setLayout(mainLayout_);

    buttonLayout_ = new QHBoxLayout;
    buttonLayout_->setSpacing(3);

    minusButton_ = new QPushButton("-");
    minusButton_->setFixedSize(22, 22);
    buttonLayout_->addWidget(minusButton_);

    valueLine_ = new QLineEdit;
    valueLine_->setInputMask("999");
    setValue(0);
    valueLine_->setStyleSheet("color: #ffffff; border-style:solid; border-width:1px; border-color:#7f7f7f; background-color:#595959; font-size:11pt");
    valueLine_->setAlignment(Qt::AlignCenter);
    setValueFieldWidth(36);
    buttonLayout_->addWidget(valueLine_);

    plusButton_ = new QPushButton("+");
    plusButton_->setFixedSize(22, 22);
    buttonLayout_->addWidget(plusButton_);

    mainLayout_->addLayout(buttonLayout_);

    //---

    titleLayout_ = new QHBoxLayout;
    mainLayout_->addLayout(titleLayout_);

    //---

    connect(minusButton_, SIGNAL(clicked()), this, SLOT(on_minusButton_clicked()));
    connect(plusButton_, SIGNAL(clicked()), this, SLOT(on_plusButton_clicked()));
    connect(valueLine_, SIGNAL(textEdited(const QString&)), this, SLOT(on_textEdited(const QString&)));
}

void SpinBox::setValueFieldWidth(int width)
{
    valueLine_->setFixedWidth(width);
}

int SpinBox::value() const
{
    return  currentValue_;
}

void SpinBox::setValue(int value)
{
    if (value == currentValue_) return;

    if((value <= maxValue_) && (value >= minValue_))
    {
        currentValue_ = value;
        valueLine_->setText(QString().setNum(currentValue_));
        emit valueChanged(currentValue_);
    }
}

void SpinBox::setMinValue(int value)
{
    minValue_ = value;
}

void SpinBox::setMaxValue(int value)
{
    maxValue_ = value;
}

void SpinBox::setTitle(const QString &title)
{
    if(valueTitle_)
    {
        valueTitle_->setText(title);
    }

    else
    {
        valueTitle_ = new QLabel;
        valueTitle_->setText(title);
        titleLayout_->addStretch();
        titleLayout_->addWidget(valueTitle_);
        titleLayout_->addStretch();
    }
}

void SpinBox::on_minusButton_clicked()
{
    if(currentValue_ > minValue_)
    {
        setValue(currentValue_ - 1);
    }
}

void SpinBox::on_plusButton_clicked()
{
    if(currentValue_ < maxValue_)
    {
        setValue(currentValue_ + 1);
    }
}

void SpinBox::on_textEdited(const QString &text)
{
    int inputValue = text.toInt();
    if((inputValue <= maxValue_) && (inputValue >= minValue_))
    {
        currentValue_ = inputValue;
        emit valueChanged(currentValue_);
    }
}
