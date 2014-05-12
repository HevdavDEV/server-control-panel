/*
    WPN-XM Server Control Panel

    WPN-XM SCP is a GUI tool for managing server daemons under Windows.
    It's a fork of Easy WEMP written by Yann Le Moigne and (c) 2010.
    WPN-XM SCP is written by Jens-Andre Koch and (c) 2011 - onwards.

    This file is part of WPN-XM Server Stack for Windows.

    WPN-XM SCP is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    WPN-XM SCP is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with WPN-XM SCP. If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

// local includes
#include "tray.h"
#include <QCloseEvent>
class QCloseEvent;

// global includes
#include <QMainWindow>
#include <QAction>
#include <QLayoutItem>
#include <QGridLayout>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT  // Enables signals and slots

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setVisible(bool visible);

    QString getPHPVersion();
    QString getNginxVersion();
    QString getMariaVersion();
    QString getMongoVersion();
    QString getMemcachedVersion();

    QString parseVersionNumber(QString stringWithVersion);

public slots:

    // General Action Slots of the MainWindow
    void startAllDaemons();
    void stopAllDaemons();

    void goToWebsite();
    void goToGoogleGroup();
    void goToReportIssue();
    void goToDonate();

    void openToolPHPInfo();
    void openToolPHPMyAdmin();
    void openToolWebgrind();
    void openToolAdminer();

    void openProjectFolderInBrowser();
    void openProjectFolderInExplorer();

    void openWebinterface();
    void openConfigurationDialog();
    void openHelpDialog();
    void openAboutDialog();

    void openConfigurationDialogNginx();
    void openConfigurationDialogPHP();
    void openConfigurationDialogMariaDb();
    void openConfigurationDialogMongoDb();

    void openLog();

    void setLabelStatusActive(QString label, bool enabled);
    void enableToolsPushButtons(bool enabled);

    void quitApplication();

private:
    Ui::MainWindow *ui;

    Tray *tray;

    Settings *settings;
    Servers *servers;

    QAction *minimizeAction;
    QAction *restoreAction;
    QAction *quitAction;

    void checkAlreadyActiveDaemons();
    void createActions();
    void createTrayIcon();
    void startMonitoringDaemonProcesses();

    void setDefaultSettings();
    void autostartDaemons();

    void deleteChildWidgets(QLayoutItem *item);
    void removeRow(QGridLayout *layout, int row, bool deleteWidgets);
    void remove(QGridLayout *layout, int row, int column, bool deleteWidgets);
    void showOnlyInstalledDaemons();


    // Returns full path to project folder (appPath + www).
    QString getProjectFolder() const;
    void showPushButtonsOnlyForInstalledTools();

private slots:

     // when tray icon is activated
     void iconActivated(QSystemTrayIcon::ActivationReason reason);
     void execEditor(QUrl logfile);

protected:
    void closeEvent(QCloseEvent *event);
    void changeEvent(QEvent *event);

};

#endif // MAINWINDOW_H
