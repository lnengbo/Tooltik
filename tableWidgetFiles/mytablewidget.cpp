#include "mytablewidget.h"
#include "mytopwidget.h"

#include <QHeaderView>
#include <QScrollBar>
#include <qgridlayout.h>
#include <QMessageBox>
#include <QLabel>
#include <QAction>
#include <QComboBox>

MyTableWidget::MyTableWidget(QWidget *parent) : QTableWidget(parent),m_pMenu(nullptr)
{
  init();
}

void MyTableWidget::init()
{
    setMouseTracking(true);
    setFrameShadow(QFrame::Plain);//设置平的样式
    setFrameShape(QFrame::NoFrame);//设置无边样式
    setFocusPolicy(Qt::NoFocus);//无焦点
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//水平滚动条scrollbar禁用
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//垂直滚动条禁用
    setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Expanding);
    setShowGrid(false);//组件中的线隐藏
    this->horizontalHeader()->setVisible(false);//等宽禁用
    this->verticalHeader()->setVisible(false);//等高禁用
    setEditTriggers(QTableWidget::NoEditTriggers);//禁止编辑
    setSelectionBehavior (QAbstractItemView::SelectRows); //整行选中的方式
    setSelectionMode (QAbstractItemView::ExtendedSelection);//拓展选 效果和ContiguousSelection一样，同时支持按键支持其他功能，ctrl,shift
    setContextMenuPolicy(Qt::CustomContextMenu);//widget添加右键目录
    connect(this,&MyTableWidget::customContextMenuRequested,this,&MyTableWidget::slot_ShowTextEditMenu);
    setAcceptDrops(true);//拖放

    insertColumn(0);
    insertColumn(1);
    insertColumn(2);
    horizontalHeader()->resizeSection(0,120);
    horizontalHeader()->resizeSection(1,170);
    horizontalHeader()->resizeSection(2,120);
    verticalHeader()->setDefaultSectionSize(32);//设置默认item高度的32

    setMinimumWidth(310);
    setMaximumWidth(580);
    setMinimumHeight(100);
    setStyleSheet("QTableWidget{color:rgb(48,48,48);}"
                  "QTableWidget::item:selected{background:rgb(180,180,180,100);}"
                  "QTableWidget::item{selection-color:rgb(38,38,38);}");

//    QStringList header;
//    header<<"Month"<<"Description";
//    setHorizontalHeaderLabels(header);
//    setItem(0,0,new QTableWidgetItem("Jan"));
//    setItem(1,0,new QTableWidgetItem("Feb"));
//    setItem(2,0,new QTableWidgetItem("Mar"));
    QComboBox *comBox = new QComboBox();
    comBox->addItem("Y");
    comBox->addItem("N");
    setCellWidget(0,2,comBox);

    //this->setItem(0,0,QTableWidgetItem("hello"));
   //QLabel *label1 = new QLabel(this);
//    QLabel *label2 = new QLabel(this);
//    QLabel *label3 = new QLabel(this);
    //label1->setText("1111111");
//    label2->setText("2222222");
//    label3->setText("3333333");
}

void MyTableWidget::slot_ShowTextEditMenu(QPoint)
{
    if(m_pMenu)//保证同时只存在一个menu，及时释放内存
     {
        delete m_pMenu;
        m_pMenu = NULL;
     }
    m_pMenu = new QMenu(this);
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
