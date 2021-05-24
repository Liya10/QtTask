#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QThread>
#include <QTime>
#include <QTimer>
#include "calculatevalue.h"
namespace Ui {
class SecondWindow;
}


class SecondWindow : public QDialog
{
    Q_OBJECT

public:
     SecondWindow(int numberThread, QWidget *parent = nullptr);
    ~SecondWindow();
private slots:
    void on_buttonStart_clicked();
    void on_buttonBack_clicked();
    void on_buttonStop_clicked();
    void on_buttonReset_clicked();
    void showPiEndInter();

private:
    CalculateValue *calculateValue;
    Ui::SecondWindow *ui;

    QVector<QTimer *> timeCalculate;
    QTimer *timeChangeLabel;
    int number;
    void reset();
};

#endif // SECONDWINDOW_H
