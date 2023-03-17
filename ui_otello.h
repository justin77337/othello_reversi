/********************************************************************************
** Form generated from reading ui file 'otello.ui'
**
** Created: Mon Oct 5 14:41:20 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OTELLO_H
#define UI_OTELLO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Otello
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Otello)
    {
        if (Otello->objectName().isEmpty())
            Otello->setObjectName(QString::fromUtf8("Otello"));
        Otello->resize(602, 402);
        centralWidget = new QWidget(Otello);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(0, 10, 102, 21));
        Otello->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Otello);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 602, 22));
        Otello->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Otello);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Otello->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Otello);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Otello->setStatusBar(statusBar);

        retranslateUi(Otello);

        QMetaObject::connectSlotsByName(Otello);
    } // setupUi

    void retranslateUi(QMainWindow *Otello)
    {
        Otello->setWindowTitle(QApplication::translate("Otello", "Otello", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Otello", "esci", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Otello);
    } // retranslateUi

};

namespace Ui {
    class Otello: public Ui_Otello {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTELLO_H
