#include "mywidget.h"
#include <QLabel>
#include <QPainter>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QLabel *lable = new QLabel(this);
    lable->setText("label0000");
    setAutoFillBackground(true);
}

void MyWidget::paintEvent(QPaintEvent *)
{
    QPixmap pix = QPixmap("1.jpg");
    QPainter p(this);
    p.drawPixmap(0,0,rect().width(),rect().height(),pix);
}
