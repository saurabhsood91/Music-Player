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

#include"mainwindow.h"
#include<QtWebKit/QWebView>
#include"musicsearchwindow.h"
musicsearchwindow::musicsearchwindow()
{
    setupUi(this);
    Connections();
    this->setWindowTitle("MusicSearch");
    this->setFixedSize(this->width(),this->height());
}
void musicsearchwindow::Connections()
{
    connect(backPushButton,SIGNAL(clicked()),this,SLOT(Back()));
    connect(searchPushButton,SIGNAL(clicked()),this,SLOT(Submit()));
}

void musicsearchwindow::Back()
{
    this->close();
}

void musicsearchwindow::Submit()
{

QString mp3=musicSearchTextBox->text();
QString mp3Name;
for(int i=0;i<mp3.length();i++)
{
if(mp3.at(i)==' ')
mp3Name.append("-");
else
mp3Name.append(mp3.at(i));
}
QString url="http://en.dilandau.eu/download_music/";
mp3Name.append("-1");
url.append(mp3Name);
url.append(".html#0");


   webView->setStyleSheet("background-color:rgb(150,147,88); padding: 7px ; color:rgb(255,255,255)");
   webView->load(QUrl(url));
   webView->showMaximized();

}
