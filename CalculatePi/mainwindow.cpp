#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString str=ui->lineEdit->text();
    if(str=="") return;
    bool ok;
    int numberThread=str.toInt(&ok,10);
    if(!ok)  QMessageBox::critical(this, "ERROR", "вводить можно только числа!" );
    else if(numberThread<=0) QMessageBox::critical(this, "ERROR", "вводить можно только положительные числа!" );
/*    else if(numberThread >15) {
        QMessageBox::critical(this, "ERROR", "слишком много потоков. Ваша запись отклонена" );
        numberThread=0;
    }*/
    else{
        //переход на новое окно
        hide();
        SecondWindow window(numberThread);
       // window.setNumberThread(numberThread);
        window.setModal(true);
        window.exec();
        ui->lineEdit->setText("");
        show();


    }
}

