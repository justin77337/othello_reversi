#include "newgamewindow.h"

newGameWindow::newGameWindow(QWidget * parent ):QDialog(parent)
{
    this->setWindowTitle("Reversi Game");
    this->setModal(true);
    this->setFixedSize(250,140);

    QPushButton *okBt = new QPushButton("Play",this);
    okBt->setGeometry(175,110,60,25);
    okBt->show();

    connect(okBt,SIGNAL(clicked()),this,SLOT(okClicked()));
    QPushButton *cancelBt = new QPushButton("Exit",this);
    cancelBt->setGeometry(15,110,60,25);
    cancelBt->show();

    connect(cancelBt,SIGNAL(clicked()), this, SLOT(cancelClicked()));
    QLabel * ply1Label = new QLabel("<b><font color=RED size=25>Welcome to",this);
    ply1Label->setGeometry(45,5,180,30);
    ply1Label->show();

    QLabel * ply1Labe2 = new QLabel("<B><font color=BLUE size=25>*Reversi*",this);
    ply1Labe2->setGeometry(60,20,180,65);
    ply1Labe2->show();

    QLabel * ply1Labe3 = new QLabel("<B><font color=RED size=25>Game",this);
    ply1Labe3->setGeometry(85,20,100,125);
    ply1Labe3->show();

    widgetList.push_back(cancelBt);
    widgetList.push_back(okBt);
    ok=false;
}

newGameWindow::~newGameWindow()
{
    for (int i=0;i<widgetList.length(); i++)
        delete widgetList[i];
    widgetList.clear();
}

void newGameWindow::closeEvent(QCloseEvent *e)
{
    if(!ok)
    {
        this->cancelClicked();
    }
    e->accept();
}

void newGameWindow::okClicked()
{
     newGameData.bot1=false;
     newGameData.bot2=true;
     newGameData.level2=0;

    emit newGame(newGameData);
    ok=true;
    this->close();
}

void newGameWindow::cancelClicked()
{
    emit returnToGame();
    ok=true;
    this->close();
}
