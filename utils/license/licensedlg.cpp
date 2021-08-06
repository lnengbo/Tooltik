#include "licensedlg.h"
#include "ui_licensedlg.h"
#include "nrlicense.h"
#include <QDebug>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>
LicenseDlg::LicenseDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LicenseDlg)
{
    ui->setupUi(this);
    setObjectName(QLatin1String("qlite_dialog"));
    setWindowTitle("Register");
    //QMetaObject::connectSlotsByName(this);
    NR_CHAR hostid[NR_HOSTID_BUFSIZE] = {0};
    NR_INT nret = CreateHostIDNew(hostid,0);
    if(nret == NR_OK)
    {
        ui->hostidLe->setText(QString::fromLocal8Bit(hostid));
    }else {
        ui->hostidLe->setText(tr("Please check configuration!"));
    }
}

LicenseDlg::~LicenseDlg()
{
    delete ui;
}







void LicenseDlg::on_emaillb_linkActivated(const QString &link)
{
    Q_UNUSED(link);
    QString softname = QApplication::applicationName();
    QString hostid = ui->hostidLe->text();
    QDesktopServices::openUrl(QUrl(tr("mailto:lnengbo@foxmail.com?subject=%1 &body=soft name: %2; host id: %3")
                                   .arg(softname).arg(softname).arg(hostid)));
}



void LicenseDlg::on_registerPB_clicked()
{
        QString softname = QApplication::applicationName();
        QString shostid = ui->hostidLe->text();
        QString slicense = ui->serialnumberLe->text();
        int difftime = 0;
        qDebug() << "softname" << softname ;
    #if (QT_VERSION < QT_VERSION_CHECK(5,0,0))

       if (RegisterLicense(softname.toAscii().data(), shostid.data(), slicense.toAscii().data()) == NR_OK)
    #else
       if (RegisterLicense(softname.toLocal8Bit().data(), shostid.toLocal8Bit().data(),
                           slicense.toLocal8Bit().data()) == NR_OK)
    #endif
       {
    #if (QT_VERSION < QT_VERSION_CHECK(5,0,0))
           int nret = CheckLicense(softname.toAscii().data());
    #else
           int nret = CheckLicense(softname.toLocal8Bit().data(),difftime);
    #endif

           if (nret > 0) {
               //close();
               if(nret != 2)
                    QMessageBox::information(this,tr("Tips"),QString::number(difftime) + " days");
               else
                    QMessageBox::information(this,tr("Tips"),tr("Permanent"));
           } else {
               QMessageBox::information(this, tr("Tips"), tr("Serial number registration failure!"));
           }
       }
}

void LicenseDlg::on_cancelPB_clicked()
{
    reject();
}
