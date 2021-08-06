#include "mainwindow.h"

#include <QVBoxLayout>
#include <QGridLayout>
#include <QDebug>
#include <QDateTime>
#include <QThread>
#include <QPainter>
#include <QNetworkConfigurationManager>
#include <QMessageBox>

#pragma execution_character_set("utf-8")

MainWindow *MainWindow::s_pMainWnd=NULL;
MainWindow *MainWindow::InitInstance()
{
    if(!s_pMainWnd)
        s_pMainWnd=new MainWindow;
    return s_pMainWnd;
}

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    s_pMainWnd=this;
    this->setWindowIcon(QIcon(":/img/tool.png"));
    this->setStyleSheet("background-color:rgb(248,248,255);");
    this->setWindowTitle("Toolkit");
    initLayout();
    initConnect();
    initObject();
}

MainWindow::~MainWindow()
{
    qDebug()<<"~MainWindow()";
}
void MainWindow::initLayout()
{

    m_pStartButton = new VolButton(":/img/start.png",":/img/start(1).png",":/img/stop.png",this);
    m_pStartButton->setFixedSize(50,50);

    m_pResetButton = new MyPushButton();
    m_pResetButton->setFixedSize(50,50);
    m_pResetButton->setStyleSheet("QPushButton{border-image:url(:/img/reset.png);}"
                                  "QPushButton::hover{border-image:url(:/img/reset(2).png);}"
                                  "QPushButton::pressed{border-image:url(:/img/reset(1).png);}");

    m_pUserButton = new MyPushButton();
    m_pUserButton->setFixedSize(50,50);
    m_pUserButton->setStyleSheet("QPushButton{border-image:url(:/img/Users.png);}"
                                 "QPushButton::hover{border-image:url(:/img/Users(1).png);}"
                                 "QPushButton::pressed{border-image:url(:/img/Users(2).png);}");

    m_pToolButton = new MyPushButton();
    m_pToolButton->setFixedSize(50,50);
    m_pToolButton->setStyleSheet("QPushButton{border-image:url(:/img/toolImage(3).png);}"
                                 "QPushButton::hover{border-image:url(:/img/toolImage(1).png);}"
                                 "QPushButton::pressed{border-image:url(:/img/toolImage(2).png);}");

    QHBoxLayout *hlyout=new QHBoxLayout();

    hlyout->addWidget(m_pUserButton);
    hlyout->addWidget(m_pToolButton);
    hlyout->addWidget(m_pResetButton);
    hlyout->addWidget(m_pStartButton);

    //hlyout->addStretch();// 这里表示弹簧


    QVBoxLayout *vlyout=new QVBoxLayout();
    //vlyout->setContentsMargins(10,10,100,100);

    m_pMyListWidget = new MyListWidget();
    vlyout->addSpacing(20);
    vlyout->addLayout(hlyout,Qt::AlignRight);
    vlyout->addSpacing(20);
    //vlyout->addWidget(&m_MyTableWidget);
    vlyout->addWidget(m_pMyListWidget);


    QVBoxLayout *vlyout1=new QVBoxLayout();

    m_pMyStackedwidget = new MyStackedWidget();

    m_pTextB = new QTextBrowser();
    m_pTextB->setStyleSheet("background-color: rgb(30,30,30);");

    vlyout1->addWidget(m_pMyStackedwidget,Qt::AlignLeft);
    vlyout1->addWidget(m_pTextB);
    vlyout1->setStretchFactor(m_pMyStackedwidget,4);//设置控件、布局的拉伸系数
    vlyout1->setStretchFactor(m_pTextB,1);

    QGridLayout *glyout=new QGridLayout();
    glyout->addLayout(vlyout,0,0,1,1,Qt::AlignLeft);//表示控件名，行，列，占用行数，占用列数，对齐方式
    glyout->addLayout(vlyout1,0,1,1,1,Qt::AlignHCenter);//表示控件名，行，列，占用行数，占用列数，对齐方式
    glyout->setColumnStretch(0,1);//QGridLayout::setColumnStretch(列码, 比例值); QGridLayout::setRowStretch(行码, 比例值);
    glyout->setColumnStretch(1,3);
    glyout->setSpacing(0);
    glyout->setContentsMargins(0,0,0,0);//边框间距
    this->setLayout(glyout);


}

void MainWindow::initConnect()
{
    connect(m_pStartButton,&VolButton::sig_clicked,this,&MainWindow::slot_buttonClick);
    connect(m_pResetButton,&MyPushButton::clicked,this,&MainWindow::slot_resetBTClick);
    connect(m_pMyListWidget,&MyListWidget::sig_Click,this,&MainWindow::slot_listWidClick);
    connect(m_pUserButton,&MyPushButton::clicked,this,&MainWindow::slot_Messgbox);
}

void MainWindow::initObject()
{
    m_ptrLicenseDlg = QSharedPointer<LicenseDlg>(new LicenseDlg());
}

bool MainWindow::isNetWorkOnline()
{
    QNetworkConfigurationManager mgr;
    return mgr.isOnline();
}

int MainWindow::checkLicense(bool flag)
{
    QString softname = QApplication::applicationName();

    int status = CheckLicense(softname.toLocal8Bit().data(),m_nDiffTime);
    if (status == 2) {
        m_nDiffTime = 9999;
        return status;
    }
    if(m_ptrLicenseDlg)
    {
        if(status <= 0)
            m_ptrLicenseDlg->show();
        else if(flag)
            m_ptrLicenseDlg->show();
    }

    return status;
}

void MainWindow::slot_buttonClick(int num)
{
    if(0 == num)
    {
        slot_debugText("开始...",0);
    }
    else if(1 == num)
    {
        slot_debugText("停止...",2);
    }

}

void MainWindow::slot_resetBTClick()
{
    slot_debugText("复位...",1);
//    m_MyTableWidget.show();
//    m_pTextB->show();
}
/**
 * @brief MainWindow::slot_debugText 日志输出
 * @param str 信息
 * @param level 信息等级  0 白， 1 黄， 2 红
 */
void MainWindow::slot_debugText(QString str, int level)
{
    QString tim = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss:zzz");
    switch (level) {
    case 0:
        m_pTextB->append("<font color=\"#FFFFFF\">" +tim+"\n"+str+ "</font>");
        break;
    case 1:
        m_pTextB->append("<font color=\"#FFFF00\">" +tim+"\n"+str+ "</font>");
        break;
    case 2:
        m_pTextB->append("<font color=\"#FF0000\">" +tim+"\n"+str+ "</font>");
        break;
    default:
        break;
    }

}

void MainWindow::slot_listWidClick(int index)
{
    m_pMyStackedwidget->setCurrentIndex(index);
    if(0 == index)
      slot_debugText("USB出图",0);
    else if(1 == index)
        slot_debugText("Wifi出图",0);
    else if(2 == index)
    {
        //slot_debugText("PingNet",0);
        if(isNetWorkOnline())
            slot_debugText("网络通畅",0);
        else
            slot_debugText("网络异常",1);
    }
}

void MainWindow::slot_Messgbox()
{

    QMessageBox::about(this,"使用时间","本软件剩余使用时间"+QString::number(m_nDiffTime)+"天");
}

void MainWindow::paintEvent(QPaintEvent *event)
{
//    QPainter p(this);
//    QPixmap pix = QPixmap("skin/skin.jpg");
//    p.drawPixmap(0,0,this->width(),this->height(),pix);

}
