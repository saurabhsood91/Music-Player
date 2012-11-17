#include "mainwindow.h"
#include<QFileDialog>
#include<QDebug>
#include<QTableWidgetItem>
#include <taglib/tag.h>
#include <taglib/fileref.h>
#include <taglib/id3v2tag.h>
#include <taglib/tstring.h>
#include <taglib/audioproperties.h>
#include <string>
#include <QEvent>
#include <cstdio>
#include <QKeyEvent>
#include "musicsearchwindow.h"

mainwindow::mainwindow(){
    currentState=0;
    hd = new helpdialog;
    m=new mediaobject;
    setupUi(this);
    setWindowTitle("Blue Music Box");
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
    QObject::connect(actionOnline,SIGNAL(triggered()),this,SLOT(onlineMusic()));
    seekSlider->setMediaObject(m->mobj);
    volumeSlider->setAudioOutput(m->audioOutput);
    show();
    int w=this->width();
    int h=this->height();
    this->setFixedSize(w,h);
    // Signal and slots for help -> AboutUs

    //m->setQueue(list);
    createTrayActions();
    createTrayIcon();
    setTrayIcon();
    trayIcon->show();
}

void mainwindow::onlineMusic()
{
    musicsearchwindow *ob=new musicsearchwindow;

    ob->show();

}

void mainwindow::changeEvent(QEvent *event)
{
    QMainWindow::changeEvent(event);
    if(event->type() == QEvent::WindowStateChange) {
        if(isMinimized())
            this->hide();
    }
}

void mainwindow::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        showHideWindow();
        event->ignore();
    }
}

void mainwindow::showHideWindow()
{
    if(this->isVisible())
    {
        this->hide();
        showHideTray->setIcon(QIcon(":/images/splash-bird.gif"));
        showHideTray->setText("Show Main Window");
    }
    else
    {
        this->show();
        showHideTray->setIcon(QIcon(":/images/splash-bird.gif"));
        showHideTray->setText("Hide Main Window");
    }
}

void mainwindow::trayIconClicked(QSystemTrayIcon::ActivationReason reason)
{
    if(reason == QSystemTrayIcon::DoubleClick)
        showHideWindow();
}

void mainwindow::setTrayIcon()
{
    trayIcon->setIcon(QIcon(":/images/splash-bird.gif"));
}
void mainwindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(showHideTray);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(closeTray);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);

    connect(
            trayIcon,
          SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this,
            SLOT(trayIconClicked(QSystemTrayIcon::ActivationReason))
           );
}
void mainwindow::createTrayActions()
{
    showHideTray = new QAction(tr("&Hide Main Window"), this);
    connect(showHideTray, SIGNAL(triggered()), this, SLOT(showHideWindow()));
    showHideTray->setIcon(QIcon(":/images/splash-bird.gif"));
    closeTray = new QAction(tr("&Exit"), this);
    connect(closeTray, SIGNAL(triggered()), qApp, SLOT(quit()));
    closeTray->setIcon(QIcon(":/images/splash-bird.gif"));
}
mainwindow::~mainwindow()
{
    delete ui;
    delete trayIcon;
    delete trayIconMenu;
    delete showHideTray;
    delete closeTray;
}
/*
bool mainwindow::event(QEvent *evt) {
      if ( evt->type() == QEvent::KeyPress ) {
          QKeyEvent *ke = (QKeyEvent *)evt;
          if ( ke->key() == Qt::Key_Escape ) {
              return FALSE;
          }
          if  (ke->type()==Qt::Key_Close)
          {
              this->hide();
              return FALSE;
          }
      }
      return QWidget::event(evt);
  } //mainwindow::event(QEvent *evt) close
*/
void mainwindow::helpShow(){
    hd->show();
}

void mainwindow::addFiles()
{
    TagLib::Tag *tag;
    QStringList filenames=QFileDialog::getOpenFileNames(this);
    foreach(QString string,filenames)
    {
        Phonon::MediaSource source(string);
        list.append(source);

        TagLib::FileRef f(string.toStdString().c_str());
        tag = f.tag();

        char year[15];
        qDebug() << tag->year();
        sprintf(year, "%u", tag->year());
        std::string yr = year;

        std::cout << "Artist name is " << tag->artist().toCString() << std::endl;
        QTableWidgetItem *item=new QTableWidgetItem(QString::fromLocal8Bit(tag->title().toCString()));
        QTableWidgetItem *item1=new QTableWidgetItem(QString::fromLocal8Bit(tag->artist().toCString()));
        QTableWidgetItem *item2=new QTableWidgetItem(QString::fromStdString(tag->album().toCString()));
        QTableWidgetItem *item3=new QTableWidgetItem(QString::fromStdString(yr));
        int ct=tableSongs->rowCount();
        tableSongs->setColumnCount(4);
        tableSongs->insertRow(ct);
        tableSongs->setItem(ct,0,item);
        tableSongs->setItem(ct, 1, item1);
        tableSongs->setItem(ct, 2, item2 );
        tableSongs->setItem(ct, 3, item3);
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
    m->playFiles(newSource.url());

    TagLib::FileRef f(newSource.url().toString().toStdString().c_str());
    TagLib::Tag *tag = f.tag();
    std::cout << "Artist name is " << tag->artist().toCString() << std::endl;
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

    if(!list.empty()){

    }
}
