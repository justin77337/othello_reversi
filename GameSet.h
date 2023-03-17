#ifndef GAMESET_H
#define GAMESET_H

#include <QList>

struct Cell
{
        int x,y;
        double beauty;
};

class GameSet
{
    public:
        GameSet();
        GameSet(int color = -1);
        ~GameSet();
        bool move(int x0,int y0, int col);
        void passTurn();
        int blackPoint();
        int whitePoint();
        bool status();
        void update();
        int winner();
        int returnColor();
        int at(int x,int y);
        bool checkTurn();
        bool checkTurn(int col);
        void stall(bool isStall);
        void increaseTurn();
        void setPoint(int x, int y, int col);
        void Grid(int mat[][8]);
        void gameReset();
        void updateGrid(int ngrid[][8]);
        Cell chooseMove(int iteration = 0);

    protected:
        int grid[8][8];
        int black, white, turn;
        bool ended;
        QList <Cell> checkedCells;
        void checkAround(int x, int y, int col, int ar[]);
        bool checkLine(int x,int y, int dir, int col, bool searching = true);
        int myColor;
};

#endif // GAMESET_H
