//      This program is free software; you can redistribute it and/or modify
//      it under the terms of the GNU General Public License as published by
//      the Free Software Foundation; either version 2 of the License, or
//      (at your option) any later version.
//      
//      This program is distributed in the hope that it will be useful,
//      but WITHOUT ANY WARRANTY; without even the implied warranty of
//      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//      GNU General Public License for more details.
//      
//      You should have received a copy of the GNU General Public License
//      along with this program; if not, write to the Free Software
//      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
//      MA 02110-1301, USA.
//      


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
