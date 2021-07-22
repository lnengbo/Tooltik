#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QTextBrowser>

#include "tableWidgetFiles/mytablewidget.h"
#include "tableWidgetFiles/mytopwidget.h"
#include "tableWidgetFiles/mywidget.h"
#include "tableWidgetFiles/mylistwidget.h"
#include "moduleFiles/myPushButton.h"
#include "tableWidgetFiles/mystackedwidget.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow *InitInstance();
    void initLayout();
    void initConnect();
    bool isNetWorkOnline();
public slots:
    void slot_buttonClick(int num);
    void slot_resetBTClick();
    void slot_debugText(QString str,int level);
    void slot_listWidClick(int index);
protected:
    static MainWindow *s_pMainWnd;
    void paintEvent(QPaintEvent *event);
private:
    MyTableWidget m_MyTableWidget;
    MyListWidget *m_pMyListWidget;
    MyStackedWidget *m_pMyStackedwidget;
    VolButton *m_pStartButton;
    MyPushButton *m_pResetButton;
    MyPushButton *m_pUserButton;
    MyPushButton *m_pToolButton;
    QTextBrowser *m_pTextB;
};
#endif // MAINWINDOW_H
