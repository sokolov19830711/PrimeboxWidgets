#pragma once

#include <QGridLayout>
#include <QWidget>
#include <QButtonGroup>

class SwitchButtonsWidget: public QWidget
{
	Q_OBJECT

public:

	SwitchButtonsWidget(int rows, int columns, const QString& buttonStyle = QString(), const QStringList& buttonsTextes = {}, QWidget* parent = nullptr);

	int checkedId() const;
	void setChecked(int id, bool state = true);
	void setButtonsSize(int width, int height);
	void setSpacing(int spacing);
	void setMargin(int margin);
	void setActive(bool state = true);
	void setButtonActive(int id, bool state = true);
	void setButtonsVisible(bool state = true);
	void setExclusive(bool state = true);

	QList<QAbstractButton*> buttons() const;
	void setButtonStyleSheet(int buttonPos, const QString& styleSheet);

signals:

	void idClicked(int id);
	void idToggled(int id, bool checked);

private:

	QGridLayout* layout_;
	QButtonGroup* group_;
	QString buttonStyle_;

	QList<QAbstractButton*> buttons_;
};
