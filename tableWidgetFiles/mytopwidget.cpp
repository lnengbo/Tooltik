#include "mytopwidget.h"
#include "myPushButton.h"

#include <QHBoxLayout>
#include <QString>

MyTopWidget::MyTopWidget(QWidget *parent) : QWidget(parent)
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    init();
}

void MyTopWidget::init()
{
//    setMinimumWidth(310);
//    setMaximumWidth(380);
//    setMinimumHeight(100);
//    volButton *btn=new volButton(QString(":/img/start.png"),QString(":/img/start(1).png"),QString(":/img/stop.png"),this);
//    QHBoxLayout *hlyout=new QHBoxLayout;
//    hlyout->addWidget(btn);
}
