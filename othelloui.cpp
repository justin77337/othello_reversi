#include "othelloui.h"
#include "ui_othelloui.h"

#include <QMessageBox>

OthelloUi::OthelloUi(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::OthelloUi)
{
    started=false;
    game = new GameSet(0);
    IA1= new GameSet(1);
    IA2 = new GameSet(-1);
    game->checkTurn();
    m_ui->setupUi(this);
    this->setFixedSize(340,396);
    this->setWindowTitle("Reversi");
    stallCounter=0;
    grid_pos = new QOthello(this);
    grid_pos->setGeometry(0,30,340,340);
    statusLabel= new QLabel(m_ui->statusBar);
    m_ui->statusBar->addWidget(statusLabel);
    ia2Timer = new QTimer();
    connect(grid_pos , SIGNAL(clicks(int)), this, SLOT(reciver(int)));
    connect(m_ui->actionNew_Game, SIGNAL(triggered()), this, SLOT(startGame()));
    connect(ia2Timer, SIGNAL(timeout()),this, SLOT(ia2Play()));
}


OthelloUi::~OthelloUi()
{
    delete m_ui;
    delete statusLabel;
    delete game;
    delete IA1;
    delete IA2;
}

void OthelloUi::startGame()
{
    newGameWindow * ngw = new newGameWindow();
    ngw->show();
    connect(ngw, SIGNAL(newGame(info)), this, SLOT(startNewGame(info)));
    if (!started)
        connect(ngw,SIGNAL(returnToGame()), this,SLOT(close()));
    else
        connect(ngw,SIGNAL(returnToGame()), ngw, SLOT(close()));
}

void OthelloUi::reciver(int p)
{
    int x,y;
    x=p-(8*(p/8));
    y=p/8;
    if (!((gameInfo.bot1 && game->returnColor()==1) ||
          (gameInfo.bot2 && game->returnColor()==-1)))
    {
        if (!game->checkTurn())
        {
            game->passTurn();
            stallCounter++;
            this->updateStatus();
        }
        else
            stallCounter=0;
        if (stallCounter>1)
        {
            game->stall(true);
        }

        if (!game->status())
            showWinner();
        if (game->returnColor()==1 && game->status() && !gameInfo.bot1)
        {
            game->move(x,y,game->returnColor());
            this->updateStatus();
        }
        if (game->returnColor()==-1 && game->status() && !gameInfo.bot2)
        {
            game->move(x,y,game->returnColor());
            this->updateStatus();
        }
        if (!game->checkTurn())
        {
            game->passTurn();
            stallCounter++;
            this->updateStatus();
        }
        else
            stallCounter=0;
        if (stallCounter>1)
        {
            game->stall(true);
        }
        if (!game->status())
             showWinner();
    }
}

void OthelloUi::updateStatus()
{
    game->update();
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8;j++)
            grid_pos->setStatus(i,j,game->at(i,j));
    }
    game->checkTurn();
    if (game->status() && gameInfo.possibility)
    {
        QList <Cell> list;
        for (int i=0; i< list.length(); i++)
            grid_pos->setStatus(list[i].x, list[i].y, 2);
    }
}

void OthelloUi::newGame()
{
    game->gameReset();
    stallCounter =0;
    if (gameInfo.bot2)
        ia2Timer->start(2500);
    else
        ia2Timer->stop();
    delete IA1;
    delete IA2;
    IA1 = new GameSet(1);
    IA2 = new GameSet(-1);
    this->updateStatus();
}

void OthelloUi::showWinner()
{
    if (!game->status())
    {
        ia2Timer->stop();
        int winner= game->winner();
        QString win="<b><font color=red size=10>";
        switch (winner)
        {
            case(0)   : win=win+"Par!"; break;
            case(1)   : win=win+"You won the game!"; break;
            case(-1)  : win=win+"You lost the game!"; break;
            default   : win=win+"Error!!"; break;
        }
        QMessageBox msgBox;
        msgBox.setText(win);
        msgBox.setModal(true);
        msgBox.setInformativeText("<I><font color=BLUE>Do you want to start a new game?");
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::No);
        int ret = msgBox.exec();
        switch(ret)
        {
            case (QMessageBox::No) : this->close();  // add this one to close the Grid
                                     break;
            case (QMessageBox::Ok) : this->startGame();
                                     break;
        }

    }
}

void OthelloUi::startNewGame(info newGameInfo)
{
    gameInfo=newGameInfo;
    if (!started)
    {
        show();
        started=true;
    }

    this->newGame();
}
void OthelloUi::ia2Play()
{
    if (gameInfo.bot2 && game->returnColor()==-1)
    {
        //Check if this turn is possible
            if (!game->checkTurn())
            {
               game->passTurn();
               stallCounter++;
               this->updateStatus();
            }
            else
                stallCounter=0;
            if (stallCounter>1)
            {
                game->stall(true);
            }
            if (!game->status())
                showWinner();
            //IA MOVE
            int tmpGrid[8][8];
            game->Grid(tmpGrid);
            IA2->updateGrid(tmpGrid);
            Cell move = IA2->chooseMove(gameInfo.level2);
            game->move(move.x,move.y,-1);
            this->updateStatus();
            //Check if next turn is possible
            if (!game->checkTurn())
            {
                game->passTurn();
                stallCounter++;
                this->updateStatus();
            }
            else
                stallCounter=0;
            if (stallCounter>1)
            {
                game->stall(true);
            }
            if (!game->status())
                 showWinner();

    }
}
