#ifndef MUSICSEARCHWINDOW_H
#define MUSICSEARCHWINDOW_H
#include<QDialog>
#include "ui_musicsearchwindow.h"
#include<QtWebKit/QWebView>
class musicsearchwindow:public QDialog,Ui::MusicSearch
{
Q_OBJECT
public:
musicsearchwindow();
void Connections();
private slots:
 void Submit();
 void Back();
};

#endif // MUSICSEARCHWINDOW_H
