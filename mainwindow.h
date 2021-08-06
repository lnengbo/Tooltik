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
#include "utils/license/nrlicense.h"
#include "utils/license/licensedlg.h"
#include "singleApplication/qsingleapplication.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static MainWindow *InitInstance();
    int checkLicense(bool flag);
public slots:
    void slot_buttonClick(int num);
    void slot_resetBTClick();
    void slot_debugText(QString str,int level);
    void slot_listWidClick(int index);
    void slot_Messgbox();
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
    QSharedPointer<LicenseDlg> m_ptrLicenseDlg;

    void initLayout();
    void initConnect();
    void initObject();
    bool isNetWorkOnline();

    int m_nDiffTime;//剩余天数
};
#endif // MAINWINDOW_H
