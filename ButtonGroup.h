#ifndef BUTTONGROUP_H
#define BUTTONGROUP_H

#include <QWidget>
#include <QButtonGroup>

class ButtonGroup : public QWidget
{
    Q_OBJECT

public:

    explicit ButtonGroup(QWidget *parent = nullptr);
    ButtonGroup(const QStringList& buttonsTextes, int buttonWidth, int buttonHeight, QWidget *parent = nullptr);

    int checkedId() const;
    void setChecked(int id);

signals:

    void idClicked(int id);

public slots:

private:

    QButtonGroup* group_;
    QString buttonStyle_;
};

#endif // BUTTONGROUP_H
