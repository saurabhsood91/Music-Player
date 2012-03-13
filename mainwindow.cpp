#include "mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QTableWidgetItem>
mainwindow::mainwindow(){
    currentState=0;
    hd = new helpdialog;
    m=new mediaobject;
    setupUi(this);
    setWindowTitle("Music Player");
    m=new mediaobject;
    QObject::connect(actionAbout, SIGNAL(triggered()), this, SLOT(helpShow()));
    QObject::connect(actionExit,SIGNAL(triggered()),this,SLOT(close()));
    QObject::connect(actionAdd_Files,SIGNAL(triggered()),this,SLOT(addFiles()));
    QObject::connect(buttonPause,SIGNAL(clicked()),this,SLOT(pauseFile()));
    QObject::connect(buttonPlay,SIGNAL(clicked()),this,SLOT(playCurrent()));
    QObject::connect(buttonStop,SIGNAL(clicked()),m->mobj,SLOT(stop()));
    QObject::connect(m,SIGNAL(currentSourceChanged(Phonon::MediaSource)),this,SLOT(fetchNext(Phonon::MediaSource)));
    QObject::connect(m->mobj,SIGNAL(aboutToFinish()),this,SLOT(aboutToFinish()));
    QObject::connect(m->mobj,SIGNAL(stateChanged(Phonon::State,Phonon::State)),this,SLOT(metaStateChanged(Phonon::State,Phonon::State)));
    seekSlider->setMediaObject(m->mobj);
    volumeSlider->setAudioOutput(m->audioOutput);
    show();
    // Signal and slots for help -> AboutUs

    //m->setQueue(list);
}

void mainwindow::helpShow(){
    hd->show();
}

void mainwindow::addFiles()
{
    QStringList filenames=QFileDialog::getOpenFileNames(this);
    foreach(QString string,filenames)
    {
        Phonon::MediaSource source(string);
        list.append(source);
    }
    m->mobj->setQueue(list);

    //Add code to add to the tablewidget
    QMap<QString, QString> metaData = m->mobj->metaData();
    //QString title=metaData.value("Title");
    //qDebug()<<title;
}

void mainwindow::playCurrent()
{
    if(!list.isEmpty())
    {
        m->playFiles(list.first());
        list.removeFirst();
    }
}

void mainwindow::pauseFile()
{
    if(currentState==0)
    {
        m->mobj->pause();
        currentState=1;
    }
    else
    {
        m->mobj->play();
        currentState=0;
    }
}

void mainwindow::stopFile()
{
    m->stop();
}

void mainwindow::fetchNext(const Phonon::MediaSource &newSource)
{
    qDebug()<<"changed";
    m->playFiles(newSource.url());
}

void mainwindow::aboutToFinish()
{
    int index=list.indexOf(m->mobj->currentSource())+1;
    if(list.size()>index)
    {
        m->mobj->enqueue(list.at(index));
    }
}

void mainwindow::metaStateChanged(Phonon::State newState, Phonon::State oldState)
{
    qDebug()<<"Called";
    QTableWidgetItem *item=new QTableWidgetItem(list.first().fileName());
    int ct=tableSongs->rowCount();
    tableSongs->insertRow(ct);
    tableSongs->setItem(ct,0,item);
}
