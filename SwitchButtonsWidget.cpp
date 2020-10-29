#include "SwitchButtonsWidget.h"

#include <QPushButton>

SwitchButtonsWidget::SwitchButtonsWidget(int rows, int columns, const QString& buttonStyle, const QStringList& buttonsTextes, QWidget* parent) : QWidget(parent)
{
	group_ = new QButtonGroup(this);
	layout_ = new QGridLayout;
	layout_->setSpacing(0);
	layout_->setMargin(0);
	setLayout(layout_);

	if (!buttonStyle.isEmpty())
	{
		setStyleSheet(buttonStyle);
	}

	connect(group_, &QButtonGroup::idClicked, this, &SwitchButtonsWidget::idClicked);
	connect(group_, &QButtonGroup::idToggled, this, &SwitchButtonsWidget::idToggled);

	int counter = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			QPushButton* currentButton = new QPushButton();
			buttons_.push_back(currentButton);
			currentButton->setCheckable(true);

			if (buttonsTextes.size() > counter)
			{
				currentButton->setText(buttonsTextes.at(counter));
			}

			layout_->addWidget(currentButton, i, j);
			group_->addButton(currentButton, counter);
			counter++;
		}
	}
}

int SwitchButtonsWidget::checkedId() const
{
	return group_->checkedId();
}

void SwitchButtonsWidget::setChecked(int id, bool state)
{
	QAbstractButton* button = group_->button(id);
	if (button) button->setChecked(state);
}

void SwitchButtonsWidget::setButtonsSize(int width, int height)
{
	auto buttons = group_->buttons();
	for (auto& i : buttons) (dynamic_cast<QPushButton*>(i))->setFixedSize(width, height);
}

void SwitchButtonsWidget::setSpacing(int spacing)
{
	layout_->setSpacing(spacing);
}

void SwitchButtonsWidget::setMargin(int margin)
{
	layout_->setMargin(margin);
}

void SwitchButtonsWidget::setButtonActive(int id, bool state)
{
	buttons_.at(id)->setDisabled(!state);
}

void SwitchButtonsWidget::setExclusive(bool state)
{
	group_->setExclusive(state);
}

void SwitchButtonsWidget::setButtonsVisible(bool state)
{
	Q_FOREACH(auto button, buttons_)
	{
		button->setVisible(state);
	}
}

void SwitchButtonsWidget::setActive(bool state)
{
	Q_FOREACH(auto button, buttons_)
	{
		button->setDisabled(!state);
	}
}

QList<QAbstractButton*> SwitchButtonsWidget::buttons() const
{
	return buttons_;
}

void SwitchButtonsWidget::setButtonStyleSheet(int buttonPos, const QString& styleSheet)
{
	buttons_.at(buttonPos)->setStyleSheet(styleSheet);
}
