#ifndef LABELTIMER_H
#define LABELTIMER_H

#include <QLabel>
#include <QWidget>
#include <QTimer>
#include <QTime>

class LabelTimer : public QLabel
{
    Q_OBJECT
public:
    explicit LabelTimer(QWidget *parent = nullptr);
    ~LabelTimer();
protected:
    virtual void enterEvent(QEvent *ev);//наведение на элемент
    virtual void leaveEvent(QEvent *ev);//отведение от элемента
    virtual void mousePressEvent(QMouseEvent *event);//удерживание мыши
    virtual void mouseReleaseEvent(QMouseEvent *event);//отпускание мыши
    virtual void mouseDoubleClickEvent(QMouseEvent *event);//двойной клик на элемент
private:
    int ms,s;
    bool flag,hover;
    QTimer *time;
    QString getStringTime();//возврат строки вида sec sec: ms ms
private slots:
    void updateTime();//перерисовывает виджет

};

#endif // LABELTIMER_H
