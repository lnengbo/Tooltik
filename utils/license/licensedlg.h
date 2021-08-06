#ifndef LICENSEDLG_H
#define LICENSEDLG_H

#include <QDialog>

namespace Ui {
class LicenseDlg;
}

class LicenseDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LicenseDlg(QWidget *parent = nullptr);
    ~LicenseDlg();

private slots:

    void on_emaillb_linkActivated(const QString &link);

    void on_registerPB_clicked();

    void on_cancelPB_clicked();

private:
    Ui::LicenseDlg *ui;
};

#endif // LICENSEDLG_H
