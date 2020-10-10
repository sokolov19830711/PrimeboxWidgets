#ifndef ONOFFBUTTON_H
#define ONOFFBUTTON_H

#include <QWidget>
#include <QPushButton>

class OnOffButton : public QPushButton
{
    Q_OBJECT

public:

    explicit OnOffButton(QWidget *parent = nullptr);

    void setChecked(bool checked = true);
    void setAlert(bool state = true);

signals:
    void clicked(bool checked);

public slots:

    void changeButtonState();

private:

    QString buttonStyle_;

};

#endif // ONOFFBUTTON_H
