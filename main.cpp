#include "mainwindow.h"
#include "singleApplication/qsingleapplication.h"
#include "myDump.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>



int main(int argc, char *argv[])
{
    SetUnhandledExceptionFilter(ExceptionFilter);
    QSingleApplication app(argc, argv);
    if(!app.isRunning())
    {
        MainWindow*pMain=MainWindow::InitInstance();
        app.w=pMain;
        pMain->resize(1366,768);
        pMain->move((QApplication::desktop()->width() - pMain->width())/2,(QApplication::desktop()->height() - pMain->height())/2);
        pMain->show();
        return app.exec();
    }
    return 0;
}
