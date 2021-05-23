#include "labeltimer.h"

LabelTimer::LabelTimer(QWidget *parent):QLabel(parent)
{
    ms=0; s=0; flag=false;hover=false; time=new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(updateTime()));

}

LabelTimer::~LabelTimer()
{
    delete time;
}
void LabelTimer::enterEvent(QEvent *ev)
{
    if (!hover){
        hover = true;
        this->setStyleSheet("background-color:rgb(155, 187, 89);"
                             "color:white;"
                             "border-style: outset;"
                              "border-width: 2px;"
                              "border-color:red;");
    }
    QLabel::enterEvent(ev);
}

void LabelTimer::leaveEvent(QEvent *ev)
{
    if (hover){
        hover = false;
        this->setStyleSheet("background-color:rgb(155, 187, 89);"
                             "color:white;"
                             "border-style: outset;"
                              "border-width: 2px;"
                              " border-color:rgb(113, 137, 63);");
    }
    QLabel::leaveEvent(ev);
}

void LabelTimer::mousePressEvent(QMouseEvent *ev)
{
    if(!flag){
        time->start(10);
        flag=true;
    }
    QLabel::mousePressEvent(ev);
}

void LabelTimer::mouseReleaseEvent(QMouseEvent *ev)
{
    time->stop();
    flag=false;
    QLabel::mouseReleaseEvent(ev);
}

void LabelTimer::mouseDoubleClickEvent(QMouseEvent *ev)
{//после двойного щелчка таймер сбрасывается почти до нуля
    //дописывает пару микросекунд, то есть могут быть 00:05, или 00:08, или 00:13
    //я это оставил
    ms=0; s=0;
    this->setText(getStringTime());
    QLabel::mouseDoubleClickEvent(ev);

}

QString LabelTimer::getStringTime()
{
    if(ms>=100){
        ms=0;
        s++;
    }
    if(s>=60){
        s=0;
    }
    QString str="";
    if(s<10){
        str="0";
    }
    str+=QString::number(s)+":";
    if(ms<10){
        str+="0";
    }
    str+=QString::number(ms);
    return str;
}

void LabelTimer::updateTime()
{
    ms++;
    this->setText(getStringTime());
}


