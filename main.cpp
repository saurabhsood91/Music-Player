#include <QtGui/QApplication>
#include <QMovie>
#include <QSplashScreen>
#include <QTimer>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mainwindow *w=new mainwindow;

    /*
    animationLabel-> setWindowFlags(Qt::FramelessWindowHint);
    QMovie *movie = new QMovie("icon.gif");
    animationLabel->setMovie(movie);
    movie->start();
    */
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/images/splash-bird.gif"));
    splash->show();
    long i=0;
    while(i++<9000000000000);
    QTimer::singleShot(10000*6,splash, SLOT(close()) );
    splash->finish(w);
    delete splash;
    w->show();

    return a.exec();
}
