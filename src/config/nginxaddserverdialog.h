#ifndef NGINXADDSERVERDIALOG_H
#define NGINXADDSERVERDIALOG_H

#include <QDialog>

namespace Configuration
{
    namespace Ui {
        class NginxAddServerDialog;
    }

    class NginxAddServerDialog : public QDialog
    {
        Q_OBJECT

    public:
        explicit NginxAddServerDialog(QWidget *parent = 0);
        ~NginxAddServerDialog();

        QString address();
        QString port();
        QString weight();
        QString maxfails();
        QString timeout();
        QString phpchildren();

        enum Column {
            Address, Port, Weight, MaxFails, Timeout, PHPChildren
        };

    private:
        Configuration::Ui::NginxAddServerDialog *ui;
    };
}

#endif // NGINXADDSERVERDIALOG_H
