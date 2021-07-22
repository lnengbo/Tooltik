#include "myPushButton.h"
#include<QPainter>
#include<QDebug>
#include<QFontMetrics>
#include<QToolTip>

MyPushButton::MyPushButton(QWidget*parent):QPushButton(parent)
{
    setCursor(Qt::PointingHandCursor);//光标变成手型
    setFlat(true);//去掉按钮边框
    setStyleSheet("QPushButton{background:transparent;}");//消除原来的按钮背景
}
MyPushButton::MyPushButton(const QString& str, QWidget *parent):QPushButton(str,parent)
{
     setCursor(Qt::PointingHandCursor);
     setFlat(true);
     setStyleSheet("QPushButton{background:transparent;}");
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
VolButton::VolButton(const QString& normal,const QString& hover,const QString& pressed,QWidget*parent):QPushButton(parent)//5个连一串
{
    setCursor(Qt::PointingHandCursor);
    connect(this,&VolButton::sig_clicked,this,&VolButton::slot_PixChange);

    pixTemp[0] = QPixmap(normal);
    pixTemp[1] = QPixmap(hover);
    pixTemp[2] = QPixmap(pressed);

    m_paintPix = pixTemp[0];
    m_bPress = false;
}
void VolButton::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(5,5,size().width()-10,size().height()-10,m_paintPix);
}
void VolButton::mousePressEvent(QMouseEvent *e)
{
    int num;
    if(e->button()==Qt::LeftButton)
    {
        if(!m_bPress)
         {
            m_paintPix = pixTemp[2];
            m_bPress = true;
            num = 0;
            update();
         }else{
            m_paintPix = pixTemp[1];
            m_bPress = false;
            num = 1;
            update();
        }
        emit sig_clicked(num);

    }
}
void VolButton::mouseReleaseEvent(QMouseEvent *e)
{
//    m_paintPix = pixTemp[0];
//    update();
}

void VolButton::setButtonPixmap(int value)
{

}

void VolButton::slot_PixChange(int)
{
}

void VolButton::enterEvent(QEvent *)
{
    if(!m_bPress)
    {
        m_paintPix = pixTemp[1];
        update();
    }
}
void VolButton::leaveEvent(QEvent *)
{
    if(!m_bPress)
    {
        m_paintPix = pixTemp[0];
        update();
    }
}
