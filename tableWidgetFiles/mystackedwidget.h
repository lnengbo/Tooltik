#ifndef MYSTACKEDWIDGET_H
#define MYSTACKEDWIDGET_H

#include <QObject>
#include <QStackedWidget>
#include "tableWidgetFiles/mywidget.h"

class MyStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    explicit MyStackedWidget(QWidget *parent = nullptr);
    void init();

signals:
private:
    MyWidget *m_pMyWidget;

};

#endif // MYSTACKEDWIDGET_H
