#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QList>
#include <QMouseEvent>
#include <QTimer>
#include <QSlider>
#include <QString>
#include <QMap>

//#include<myMediaList.h>
class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    MyPushButton(QWidget*parent=0);
    MyPushButton(const QString& str,QWidget*parent=0);
};
///////////////////////////////////////////////////////////////////
class VolButton:public QPushButton
{
    Q_OBJECT
public:
    VolButton(const QString& normal,const QString& hover,const QString& pressed,QWidget*parent=0);
    void setParentSlider(QSlider* slider){m_partnerslider=slider;}
protected:
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e)override;//override 虚函数重载
    void mouseReleaseEvent(QMouseEvent *e)override;
private:
    bool m_isenter;
    bool m_bPress;
    int m_savevol;
    int m_isvolempty;
    int m_index;
    QPixmap pixTemp[3];
    QPixmap m_paintPix;
    QVector<QPixmap> m_listnormal;
    QVector<QPixmap> m_listhover;
    QVector<QPixmap> m_listpressed;

    QSlider *m_partnerslider;
public slots:
    void setButtonPixmap(int);//getFromSlider
private slots:
    void slot_PixChange(int);
signals:
    void setMute(int);
    void sig_clicked(int);
};

#endif // MYPUSHBUTTON_H
