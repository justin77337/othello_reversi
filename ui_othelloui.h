/********************************************************************************
** Form generated from reading UI file 'othelloui.ui'
**
** Created: Sun Dec 11 12:02:57 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHELLOUI_H
#define UI_OTHELLOUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OthelloUi
{
public:
    QAction *actionNew_Game;
    QWidget *centralwidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OthelloUi)
    {
        if (OthelloUi->objectName().isEmpty())
            OthelloUi->setObjectName(QString::fromUtf8("OthelloUi"));
        OthelloUi->resize(656, 444);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Othello-risorse/resurces/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        OthelloUi->setWindowIcon(icon);
        actionNew_Game = new QAction(OthelloUi);
        actionNew_Game->setObjectName(QString::fromUtf8("actionNew_Game"));
        centralwidget = new QWidget(OthelloUi);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        OthelloUi->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(OthelloUi);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 656, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        OthelloUi->setMenuBar(menuBar);
        statusBar = new QStatusBar(OthelloUi);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        OthelloUi->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew_Game);

        retranslateUi(OthelloUi);

        QMetaObject::connectSlotsByName(OthelloUi);
    } // setupUi

    void retranslateUi(QMainWindow *OthelloUi)
    {
        OthelloUi->setWindowTitle(QApplication::translate("OthelloUi", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionNew_Game->setText(QApplication::translate("OthelloUi", "New Game", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("OthelloUi", "Game", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OthelloUi: public Ui_OthelloUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHELLOUI_H
