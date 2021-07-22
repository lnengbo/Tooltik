#include "mystackedwidget.h"
#include <QLabel>

MyStackedWidget::MyStackedWidget(QWidget *parent) : QStackedWidget(parent)
{
    init();
}

void MyStackedWidget::init()
{
    QLabel *m_pLabel = new QLabel;
    QLabel *m_pLabel_1 = new QLabel;
    m_pMyWidget = new MyWidget;
    m_pLabel->setText("USB出图");
    m_pLabel_1->setText("Wifi出图");
    m_pLabel->setStyleSheet("QLabel{background-color:rgb(220,220,220);}");
    addWidget(m_pLabel); //添加一个文本进入窗体
    addWidget(m_pLabel_1);
    insertWidget(3,m_pMyWidget);
}
