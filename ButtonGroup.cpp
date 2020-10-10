#include "buttongroup.h"

#include <QPushButton>
#include <QHBoxLayout>

ButtonGroup::ButtonGroup(QWidget *parent) : QWidget(parent)
{

}

ButtonGroup::ButtonGroup(const QStringList& buttonsTextes, int buttonWidth, int buttonHeight, QWidget *parent) : QWidget(parent)
{
    buttonStyle_ =  "QPushButton:checked{color: #ffffff; border-style:solid; border-width:0px; border-color:#00CE6E; background-color:#00b050;}"
                            "QPushButton{color: #ffffff; border-style:solid; border-width:0px; border-color:#7f7f7f; background-color:#595959;}";

    setStyleSheet(buttonStyle_);

    group_ = new QButtonGroup(this);
    QHBoxLayout* mainLayout = new QHBoxLayout;
    setLayout(mainLayout);

    int counter = 0;
    Q_FOREACH(const QString& text, buttonsTextes)
    {
        QPushButton* currentButton = new QPushButton(text);
        currentButton->setCheckable(true);
        currentButton->setFixedSize(buttonWidth, buttonHeight);
        mainLayout->addWidget(currentButton);
        group_->addButton(currentButton, 1 << counter);
        counter++;
    }

    connect(group_, &QButtonGroup::idClicked, this, &ButtonGroup::idClicked);
}

int ButtonGroup::checkedId() const
{
    return group_->checkedId();
}

void ButtonGroup::setChecked(int id)
{
    QAbstractButton* button = group_->button(id);
    if(button) button->setChecked(true);
}
