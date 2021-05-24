#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(int number2, QWidget *parent):
    QDialog(parent), number(number2),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    calculateValue = new CalculateValue();

    timeChangeLabel=new QTimer(this);
    connect(timeChangeLabel, SIGNAL(timeout()), this, SLOT(showPiEndInter()));

    for(int i=0;i<number;++i){
        QTimer *time=new QTimer(this);
        connect(time, SIGNAL(timeout()), calculateValue, SLOT(calculate()));
        timeCalculate.push_back(time);
    }

}

SecondWindow::~SecondWindow()
{
    for(int i=0;i<number;++i){
        delete timeCalculate[i];
    }
    delete calculateValue;
    delete ui;
    delete timeChangeLabel;

}


void SecondWindow::on_buttonBack_clicked()
{
    //возвращение к первому окну
    if(calculateValue->getFlag()){//нужно проверить, что процесс остановлен
        QMessageBox::critical(this, "ERROR", "перед выходом остановите вычисления." );
        return;
    }
    QMessageBox::StandardButton reply=QMessageBox::information(this,"Вы уверены?","Вы уверены, что хотите вернуться к предыдущему окну?", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes)
    {
        close();
    }
}



void SecondWindow::on_buttonStart_clicked()
{
//запустить процесс вычисления
   //
    if(calculateValue->getFlag()) return;//вычисление уже запущено, поэтоу выходим


    calculateValue->changeFlag();//иначе запускаем
    for(int i=0; i<number;++i)
        timeCalculate[i]->start();
    timeChangeLabel->start(500);
}


void SecondWindow::on_buttonStop_clicked()
{
    //остановить процесс вычисления

    if(!calculateValue->getFlag()) return;//вычисление уже остановлено, поэтому выходим
    calculateValue->changeFlag();//иначе меняем флаг и останавливаем процесс
    for(int i=0; i<number;++i)
        timeCalculate[i]->stop();
    timeChangeLabel->stop();


}


void SecondWindow::on_buttonReset_clicked()
{
    //сбросить все параметры вычисления до нуля

    if(calculateValue->getFlag()){//нужно проверить, что процесс остановлен
        QMessageBox::critical(this, "ERROR", "сначала нужно оставновить вычисления, а потом обнулять." );
        return;
    }
    calculateValue->reset();
    ui->linePi->setText(" Число пи: 0");
    ui->lineInter->setText(" Интерация: " +QString::number(calculateValue->getInter()));
}

void SecondWindow::showPiEndInter()
{
    //обновления виджетов
    ui->linePi->setText(" Число пи: "+QString::number(calculateValue->getPi()));
    ui->lineInter->setText(" Интерация: " +QString::number(calculateValue->getInter()));
}



