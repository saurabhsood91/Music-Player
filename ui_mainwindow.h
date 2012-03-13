/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Mar 12 15:26:47 2012
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Files;
    QAction *actionExit;
    QAction *actionAbout;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    Phonon::SeekSlider *seekSlider;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonPlay;
    QPushButton *buttonPause;
    QPushButton *buttonStop;
    Phonon::VolumeSlider *volumeSlider;
    QTableWidget *tableSongs;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(651, 297);
        MainWindow->setMaximumSize(QSize(651, 297));
        actionAdd_Files = new QAction(MainWindow);
        actionAdd_Files->setObjectName(QString::fromUtf8("actionAdd_Files"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 0, 629, 234));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        seekSlider = new Phonon::SeekSlider(layoutWidget);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));

        gridLayout->addWidget(seekSlider, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonPlay = new QPushButton(layoutWidget);
        buttonPlay->setObjectName(QString::fromUtf8("buttonPlay"));
        buttonPlay->setMaximumSize(QSize(85, 31));

        horizontalLayout->addWidget(buttonPlay);

        buttonPause = new QPushButton(layoutWidget);
        buttonPause->setObjectName(QString::fromUtf8("buttonPause"));
        buttonPause->setMaximumSize(QSize(85, 31));

        horizontalLayout->addWidget(buttonPause);

        buttonStop = new QPushButton(layoutWidget);
        buttonStop->setObjectName(QString::fromUtf8("buttonStop"));
        buttonStop->setMaximumSize(QSize(85, 31));

        horizontalLayout->addWidget(buttonStop);

        volumeSlider = new Phonon::VolumeSlider(layoutWidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setMaximumSize(QSize(352, 16777215));

        horizontalLayout->addWidget(volumeSlider);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        tableSongs = new QTableWidget(layoutWidget);
        if (tableSongs->columnCount() < 1)
            tableSongs->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableSongs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableSongs->setObjectName(QString::fromUtf8("tableSongs"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableSongs->sizePolicy().hasHeightForWidth());
        tableSongs->setSizePolicy(sizePolicy);
        tableSongs->setMaximumSize(QSize(627, 162));

        gridLayout->addWidget(tableSongs, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 651, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionAdd_Files);
        menuFile->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionAdd_Files->setText(QApplication::translate("MainWindow", "Add Files", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        buttonPlay->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        buttonPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        buttonStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableSongs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Filename", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
