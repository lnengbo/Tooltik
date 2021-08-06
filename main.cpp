#include "mainwindow.h"
#include "singleApplication/qsingleapplication.h"
//#include "myDump.h"
#include "client/windows/handler/exception_handler.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QDebug>
#include <QDir>

void _mkDir();
bool callback(const wchar_t *dump_path, const wchar_t *id,
    void *context, EXCEPTION_POINTERS *exinfo,
    MDRawAssertionInfo *assertion,
    bool succeeded);

int main(int argc, char *argv[])
{
//    //捕获崩溃异常
//    SetUnhandledExceptionFilter(ExceptionFilter);
    //创建文件夹
    _mkDir();
    //捕获异常
    google_breakpad::ExceptionHandler eh(
        L"tmp\\", NULL, callback, NULL,
        google_breakpad::ExceptionHandler::HANDLER_ALL);
    QSingleApplication app(argc, argv);
    QSingleApplication::setApplicationName("ToolkitDemo");
    QSingleApplication::setOrganizationDomain("lnengbo@foxmail.com");
    QSingleApplication::setOrganizationName("toolkit");
    QSingleApplication::setApplicationVersion("V1.0.0");

    if(!app.isRunning())
    {
        MainWindow*pMain=MainWindow::InitInstance();
        app.w=pMain;
        pMain->resize(1366,768);
        pMain->move((QApplication::desktop()->width() - pMain->width())/2,(QApplication::desktop()->height() - pMain->height())/2);
        int res = pMain->checkLicense(false);
        if(res <= 0)
        {
            return app.exec();
        }
        pMain->show();
        return app.exec();
    }
    return 0;
}
void _mkDir()
{
    QString fullPath = "tmp";
    QDir dir;
    if(!dir.exists("tmp"))
    {
       bool ismkdir = dir.mkpath(QDir::currentPath() + "/" +fullPath);
       if(!ismkdir){
          qDebug ()<< "Create Path Fail" << endl;
       }

    }
}
bool callback(const wchar_t *dump_path, const wchar_t *id,
    void *context, EXCEPTION_POINTERS *exinfo,
    MDRawAssertionInfo *assertion,
    bool succeeded)
{
    if (succeeded)
    {
        printf("dump guid is %ws\n", id);
        qDebug() << "Create dump file success";
    }
    else
    {
        printf("dump failed\n");
        qDebug() << "Create dump file failed";
    }
    return succeeded;
}
