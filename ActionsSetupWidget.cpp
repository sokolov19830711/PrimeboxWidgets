#include "ActionsSetupWidget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

ActionsSetupWidget::ActionsSetupWidget(unsigned char* flagsVar, const QList<int>& flagsList, QWidget* parent) : 
	QWidget(parent),
	_flags(flagsVar),
	_flagsList(flagsList)
{
	QVBoxLayout* mainLayout = new QVBoxLayout;

	QHBoxLayout* hLayout = new QHBoxLayout;
	hLayout->addStretch();
	hLayout->addLayout(mainLayout);
	hLayout->addStretch();

	QVBoxLayout* vLayout = new QVBoxLayout;
	vLayout->addStretch();
	vLayout->addLayout(hLayout);
	vLayout->addStretch();

	setLayout(vLayout);

	//---

	QHBoxLayout* actionListTitleLayout = new QHBoxLayout;
	actionListTitleLayout->addStretch();
	actionListTitleLayout->addWidget(new QLabel("ВЫПОЛНИТЬ ДЕЙСТВИЕ"));
	actionListTitleLayout->addStretch();

	mainLayout->addLayout(actionListTitleLayout);
	mainLayout->addSpacing(10);

	//---

	_notificationButton = new OnOffButton;
	_notificationButton->setChecked(*_flags & _flagsList[0]);
	connect(_notificationButton, &OnOffButton::toggled, [=]() {setFlag(_flagsList[0], _notificationButton->isChecked()); });

	_soundSignalButton = new OnOffButton;
	_soundSignalButton->setChecked(*_flags & _flagsList[1]);
	connect(_soundSignalButton, &OnOffButton::toggled, [=]() {setFlag(_flagsList[1], _soundSignalButton->isChecked()); });

	_PCShutDownButton = new OnOffButton;
	_PCShutDownButton->setChecked(*_flags & _flagsList[2]);
	connect(_PCShutDownButton, &OnOffButton::toggled, [=]() {setFlag(_flagsList[2], _PCShutDownButton->isChecked()); });

    OnOffButton* _hddButton = new OnOffButton;

	QHBoxLayout* notificationLayout = new QHBoxLayout;
	notificationLayout->addStretch();
	QLabel* notificationLabel = new QLabel("Сообщение\nадминистратору");
	notificationLabel->setAlignment(Qt::AlignRight);
	notificationLayout->addWidget(notificationLabel);
	notificationLayout->addWidget(_notificationButton);
	mainLayout->addLayout(notificationLayout);

	QHBoxLayout* soundSignalLayout = new QHBoxLayout;
	soundSignalLayout->addStretch();
	soundSignalLayout->addWidget(new QLabel("Звуковой сигнал"));
	soundSignalLayout->addWidget(_soundSignalButton);
	mainLayout->addLayout(soundSignalLayout);

	QHBoxLayout* PCShutDownLayout = new QHBoxLayout;
	PCShutDownLayout->addStretch();
	PCShutDownLayout->addWidget(new QLabel("Выключение ПК"));
	PCShutDownLayout->addWidget(_PCShutDownButton);
	mainLayout->addLayout(PCShutDownLayout);

    QHBoxLayout* hddLayout = new QHBoxLayout;
    hddLayout->addStretch();
    QLabel* hddLabel = new QLabel("Заблокировать\nHDD диск");
    hddLabel->setAlignment(Qt::AlignRight);
    hddLayout->addWidget(hddLabel);
    hddLayout->addWidget(_hddButton);
    mainLayout->addLayout(hddLayout);
}

unsigned char ActionsSetupWidget::flags() const
{
	return *_flags;
}

void ActionsSetupWidget::setFlag(int flag, bool state)
{
	if(state)
	{
		*_flags |= static_cast<unsigned char>(flag);
	}
	else
	{
		*_flags &= static_cast<unsigned char>(~flag);
	}
}
