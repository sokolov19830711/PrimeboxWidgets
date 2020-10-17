#include "onoffbutton.h"

OnOffButton::OnOffButton(QWidget *parent) : QPushButton(parent)
{
    buttonStyle_ =  "QPushButton:checked{color: #ffffff; border-style:solid; border-width:0px; border-color:#00CE6E; background-color:#00b050; font-size:11pt}"
                            "QPushButton{color: #ffffff; border-style:solid; border-width:0px; border-color:#7f7f7f; background-color:#595959; font-size:11pt}";

    setCheckable(true);
    setChecked(false);
    setStyleSheet(buttonStyle_);
    setFixedSize(38, 38);
    setText("OFF");

    connect(this, &QPushButton::clicked, this, &OnOffButton::changeButtonState);
    connect(this, &QPushButton::clicked, this, &OnOffButton::clicked);
}

void OnOffButton::setChecked(bool checked)
{
    QPushButton::setChecked(checked);
    changeButtonState();
}

void OnOffButton::setAlert(bool state)
{
    if(state) setStyleSheet("color: #ffffff; border-style:solid; border-width:1px; border-color:#7f7f7f; background-color:#c05046; font-size:11pt");
    else setStyleSheet(buttonStyle_);
}

void OnOffButton::changeButtonState()
{
    if(isChecked()) setText("ON");
    else setText("OFF");
}
