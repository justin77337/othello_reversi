#ifndef OTHELLOUI_H
#define OTHELLOUI_H

#include <QtGui/QMainWindow>
#include <QTimer>
#include "QOthello.h"
#include "GameSet.h"
#include "newgamewindow.h"

namespace Ui
{
    class OthelloUi;
}

class OthelloUi : public QMainWindow
{
    Q_OBJECT

    public:
        OthelloUi(QWidget *parent = 0);
        ~OthelloUi();

    private:
        info gameInfo;
        bool started;
        Ui::OthelloUi *m_ui;
        GameSet * game;
        GameSet * IA1;
        GameSet * IA2;
        QOthello * grid_pos;      //SET THE TABLE
        QLabel * statusLabel;
        int stallCounter;
        void updateStatus();
        void showWinner();
        QTimer * ia1Timer;
        QTimer * ia2Timer;

    public slots:
        void startGame();

    private slots:
        void ia2Play();
        void startNewGame(info newGameInfo);
        void reciver(int p);
        void newGame();
};



#endif // OTHELLOUI_H
