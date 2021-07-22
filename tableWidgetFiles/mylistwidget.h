#ifndef MYLISTWIDGET_H
#define MYLISTWIDGET_H

#include <QObject>
#include <QListWidget>

class MyListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit MyListWidget(QWidget *parent = nullptr);
    ~MyListWidget();
    void init();
protected:
signals:
    void sig_Click(int);

private slots:
    void slot_ShowTextEditMenu(QPoint);
    void slot_ItemClick(QListWidgetItem *item);
private:

    QMenu  *m_pMenu;




};

#endif // MYLISTWIDGET_H
