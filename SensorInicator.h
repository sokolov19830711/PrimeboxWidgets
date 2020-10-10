#ifndef SENSORINICATOR_H
#define SENSORINICATOR_H

#include <QLabel>

class SensorInicator : public QLabel
{
	Q_OBJECT

public:

    explicit SensorInicator(QWidget *parent = nullptr);

    void setActive(bool state = true);

public slots:

    void setValue(int value);
    void setMaxNormal(int value);
    void setMinNormal(int value);


private:

    int value_ = 0;
    int maxNormal_ = 0x7FFF;
    int minNormal_ = - 0x7FFF;

    QString normalStyle_ = "font-size:14pt; color:#ffffff";
    QString alertStyle_ = "font-size:14pt; color:#c05046";

    bool isActive_ = true;

    void refresh();
};

#endif // SENSORINICATOR_H
