#ifndef MYTOPWIDGET_H
#define MYTOPWIDGET_H

#include <QObject>
#include <QWidget>

class MyTopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyTopWidget(QWidget *parent = nullptr);
    void init();

signals:

};

#endif // MYTOPWIDGET_H
