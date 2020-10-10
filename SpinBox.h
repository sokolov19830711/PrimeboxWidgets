#ifndef SPINBOX_H
#define SPINBOX_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class SpinBox : public QWidget
{
    Q_OBJECT
public:
    explicit SpinBox(QWidget *parent = nullptr);

    void setValueFieldWidth(int width);
    int value() const;

signals:

    void valueChanged(int value);

public slots:

    void setValue(int value);
    void setMinValue(int value);
    void setMaxValue(int value);
    void setTitle(const QString& title = "");

    void on_minusButton_clicked();
    void on_plusButton_clicked();

    void on_textEdited(const QString& text);

private:

    QVBoxLayout* mainLayout_;
    QHBoxLayout* buttonLayout_;
    QHBoxLayout* titleLayout_;

    QPushButton* minusButton_;
    QPushButton* plusButton_;
    QLineEdit* valueLine_;
    QLabel* valueTitle_ = nullptr;

    int currentValue_ = -1;
    int minValue_ = 0;
    int maxValue_ = 100;
};

#endif // SPINBOX_H
