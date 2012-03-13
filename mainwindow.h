#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "helpui.h"
#include <QMainWindow>
#include "mediafile.h"
#include<phonon/MediaSource>
class mainwindow: public QMainWindow, Ui::MainWindow{
    Q_OBJECT
private:
    QString currentFileName;
    int currentState;
public: mainwindow();
    helpdialog *hd;
    mediaobject *m;
    QList<Phonon::MediaSource> list;
public slots:
    void helpShow();
    void addFiles();
    void playCurrent();
    void fetchNext(const Phonon::MediaSource &newSource);
    void pauseFile();
    void stopFile();
    void aboutToFinish();
    void metaStateChanged(Phonon::State newState,Phonon::State oldState);
};

#endif // MAINWINDOW_H
