#pragma once

#include <QWidget>
#include "OnOffButton.h"

class ActionsSetupWidget : public QWidget
{
	Q_OBJECT

public:

	ActionsSetupWidget(unsigned char* flagsVar, const QList<int>& flagsList, QWidget* parent = nullptr);
	unsigned char flags() const;

private:

	void setFlag(int flag, bool state = true);

	unsigned char* _flags;
	QList<int> _flagsList;

	OnOffButton* _notificationButton;
	OnOffButton* _soundSignalButton;
	OnOffButton* _PCShutDownButton;
};