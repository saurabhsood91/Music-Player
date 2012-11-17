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
