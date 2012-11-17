#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "helpui.h"
#include <QMainWindow>
#include "mediafile.h"
#include<phonon/MediaSource>
#include<QSystemTrayIcon>
class mainwindow: public QMainWindow, Ui::MainWindow{
    Q_OBJECT
private:
    QString currentFileName;
    int currentState;
public: mainwindow();
    helpdialog *hd;
    mediaobject *m;
    QList<Phonon::MediaSource> list;
     ~mainwindow();
    //bool event(QEvent *evt);
public slots:
    void helpShow();
    void addFiles();
    void playCurrent();
    void fetchNext(const Phonon::MediaSource &newSource);
    void pauseFile();
    void stopFile();
    void aboutToFinish();
    void metaStateChanged(Phonon::State newState,Phonon::State oldState);
    void onlineMusic();
private:
    Ui::MainWindow *ui;

    // Tray Icon Functions
    void createTrayActions();
    void createTrayIcon();
    void setTrayIcon();

    void closeEvent(QCloseEvent *);
    void changeEvent(QEvent *);

    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *showHideTray;
    QAction *closeTray;

private slots:
    void trayIconClicked(QSystemTrayIcon::ActivationReason);
    void showHideWindow();

};

#endif // MAINWINDOW_H
