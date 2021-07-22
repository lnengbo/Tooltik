#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QMenu>

class MyTableWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit MyTableWidget(QWidget *parent = nullptr);
    void init();
signals:

private:
    QLabel *m_pLabel;
    QMenu  *m_pMenu;
private slots:
    void slot_ShowTextEditMenu(QPoint);



};

#endif // TABLEWIDGET_H
