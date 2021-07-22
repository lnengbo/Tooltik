#include "mylistwidget.h"
#include <QLabel>
#include <QMenu>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "moduleFiles/myPushButton.h"

MyListWidget::MyListWidget(QWidget *parent) : QListWidget(parent)
    ,m_pMenu(nullptr)
{
  setContextMenuPolicy(Qt::CustomContextMenu);//右键菜单
  init();

}

MyListWidget::~MyListWidget()
{
    delete m_pMenu;
    m_pMenu = nullptr;
    qDebug()<<"~MyListWidget()";
}

void MyListWidget::init()
{
    setMouseTracking(true);
    setFrameShadow(QFrame::Plain);//设置平的样式
    setFrameShape(QFrame::NoFrame);//设置无边样式
    setFocusPolicy(Qt::NoFocus);//无焦点
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条scrollbar禁用
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//垂直滚动条禁用
    setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Expanding);
    //setShowGrid(false);//组件中的线隐藏
    setGeometry(55,55,310,140);
    setGridSize(QSize(335, 50));//设置行间距

    QWidget *w = new QWidget;
    QHBoxLayout *layout=new QHBoxLayout;
    QPushButton *pushButton=new QPushButton("12334444");
    layout->addWidget(pushButton);
    w->setLayout(layout);

    QListWidgetItem *UsbItem = new QListWidgetItem(QIcon(":/img/usb.png"),"USB出图", this);
    //setItemWidget(UsbItem,w);
    new QListWidgetItem(QIcon(":/img/wifi.png"),"Wifi出图", this);
    new QListWidgetItem(QIcon(":/img/Ping.png"),"PingNet", this);

    setMinimumWidth(310);
    setMaximumWidth(580);
    setMinimumHeight(100);
    connect(this,&MyListWidget::customContextMenuRequested,this,&MyListWidget::slot_ShowTextEditMenu);
    connect(this,&MyListWidget::itemClicked,this,&MyListWidget::slot_ItemClick);

}



void MyListWidget::slot_ShowTextEditMenu(QPoint)
{
    if(m_pMenu)//保证同时只存在一个menu，及时释放内存
     {
        delete m_pMenu;
        m_pMenu = NULL;
     }
    m_pMenu = new QMenu();
    QAction*act_flush=new QAction("刷新");
    QAction*act_add=new QAction("添加");

    m_pMenu->addAction(act_flush);
    m_pMenu->addAction(new QAction("刷新1"));
    m_pMenu->addAction(new QAction("刷新2"));
    m_pMenu->addAction(new QAction("刷新3"));
    m_pMenu->addSeparator();//添加工具栏分隔线
    m_pMenu->addAction(act_add);
    m_pMenu->addAction(new QAction("添加1"));
    m_pMenu->addAction(new QAction("添加2"));
    m_pMenu->addAction(new QAction("添加3"));
    m_pMenu->addSeparator();



    m_pMenu->exec(QCursor::pos());//在当前鼠标位置显示

}

void MyListWidget::slot_ItemClick(QListWidgetItem *item)
{
    if("USB出图" == item->text())
        emit sig_Click(0);
    else if("Wifi出图" == item->text())
        emit sig_Click(1);
    else if("PingNet" == item->text())
        emit sig_Click(2);

}

