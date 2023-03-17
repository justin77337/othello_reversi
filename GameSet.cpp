#include "GameSet.h"

using namespace std;

//class constructor
GameSet::GameSet()
{
    /*init game status at 0*/
    black=2;
    white=2;
    turn=0;
    ended= false;
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            grid[i][j]=0;       //Blank all the Grids squares
        }
    }

    /*Place initial Four circles in the center */
    grid[3][3]=1;               // Black
    grid[3][4]=-1;              // White
    grid[4][3]=-1;              // White
    grid[4][4]=1;               // Black
}

GameSet::GameSet(int color) : myColor(color)
{
}

//decostructor
GameSet::~GameSet()
{
    checkedCells.clear();     //remove all items from the list
}

bool GameSet::move(int x0, int y0, int col)
{
    Cell toCheck;
    bool cellBond=false;
    toCheck.x = x0;
    toCheck.y = y0;
    if (!(grid[x0][y0]==0))
        return false;
    for (int i=0; i<checkedCells.length(); i++)     //.length() -- count the numbers in the list
    {
        if (toCheck.x==checkedCells.at(i).x &&      //.at() -- Returns the item at index position i in the list
                toCheck.y==checkedCells.at(i).y)
        {
            cellBond= true;
            break;
        }
    }
    if (!cellBond) return false;
    int around[8];
    checkAround(x0,y0, col, around);
    bool possible=false;
    for (int i=0; i<8; i++)
    {
        if (around[i]==1)
        {
            if (checkLine(x0,y0,i,col,false))
                possible= true;
        }
    }
    if (possible)
    {
        turn++;
        grid[x0][y0]=col;
    }
    return possible;
}

bool GameSet::checkTurn()
{
    int around[8];
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (grid[i][j]==returnColor())
            {
                checkAround(i, j, returnColor(), around);
                for (int h=0; h<8; h++)
                {
                    if (around[h]==1 ) checkLine(i,j,h,returnColor(),true);
                }
            }
        }
    }
    if (checkedCells.length()==0)
        return false;
    else
        return true;
}

bool GameSet::checkTurn(int col)
{
    int around[8];
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (grid[i][j]==col)
            {
                checkAround(i, j, col, around);
                for (int h=0; h<8; h++)
                {
                    if (around[h]==1 )
                        checkLine(i,j,h,col,true);
                }
            }
        }
    }
    if (checkedCells.length()==0)
        return false;
    else
        return true;
}

void GameSet::checkAround(int x, int y, int col, int ar[])
{

    for (int i=0; i<3; i++)
    {
        if (x==0 && i==0) ar[0]=0;
        else if (x==7 && i==2) ar[2]=0;
        else if (grid[x-1+i][y-1]==-col) ar[i]=1;
        else ar[i]=0;
    }

    for (int i=0; i<2; i++)
    {
       if (y==7 && i==1) ar[i+3]=0;
       else if (grid[x+1][y+i]==-col) ar[i+3]=1;
       else ar[i+3]=0;
    }
    for (int i=0; i<2; i++)
    {
        if (x==0 && i==1) ar[i+5]=0;
        else if (grid[x-i][y+1]==-col) ar[i+5]=1;
        else ar[i+5]=0;
    }
    if (x==0) ar[7]=0;
    else if (grid[x-1][y]==-col) ar[7]=1;
    else ar[7]=0;
}

bool GameSet::checkLine(int x, int y, int dir,int col, bool searching)
{
    bool checked = false;
    int xi=x, yi=y, cvar=col, ncvar=0;
    if (searching)
    {
        ncvar=col;
        cvar=0;
    }
    Cell temp;
    QList <Cell> toColor;
    while (!checked && (xi<=7 && xi>=0) && (yi>=0 && yi<=7))
    {
        switch (dir)
        {
            case(0):
                xi--;
                yi--;
                if (xi>=0 && yi>=0 && grid[xi][yi]==cvar) checked = true;
                break;
            case(1):
                yi--;
                if (yi>=0 && grid[xi][yi]==cvar) checked = true;
                break;
            case(2):
                yi--;
                xi++;
                if (yi>=0 && xi<=7 && grid[xi][yi]==cvar) checked = true;
                break;
            case(3):
                xi++;
                if (xi<=7 && grid[xi][yi]==cvar) checked = true;
                break;
            case(4):
                yi++;
                xi++;
                if (xi<=7 && yi<=7 && grid[xi][yi]==cvar)
                    checked = true;
                break;
            case(5):
                yi++;
                if (yi<=7 && grid[xi][yi]==cvar)
                    checked = true;
                break;
            case(6):
                xi--;
                yi++;
                if (yi<=7 && xi>=0 && grid[xi][yi]==cvar)
                    checked = true;
                break;
            case(7):
                xi--;
                break;
        }
        if (grid[xi][yi]==ncvar)
            break;
        temp.x=xi;
        temp.y=yi;
        toColor.push_back(temp);
        if ((xi>=0 && xi<=7) && (yi<=7 && yi>=0) && grid[xi][yi]==cvar)
            checked = true;
    }
    if (!checked)
        return false;
    if (!searching)
    {
        for (int i=0; i<(toColor.length()-1);i++)
        {
            grid[toColor.at(i).x][toColor.at(i).y]=col;
        }
    }
    else
    {
        temp= toColor.at(toColor.length()-1);
        checkedCells.push_back(temp);
    }
    return true;
}

int GameSet::blackPoint()
{
    return black;
}

int GameSet::whitePoint()
{
    return white;
}

bool GameSet::status()
{
    return !ended;
}

int GameSet::winner()
{
    int win;
    if (!status())
    {
        if (white<black)
            win = 1;
        if (white>black)
            win = -1;
        if (white==black)
            win = 0;
    }
//    else
 //       return 101;
    return win;
}

int GameSet::returnColor()
{
    if (turn%2==0)
        return 1;
    else
        return -1;
}

void GameSet::update()
{
    white=0;
    black=0;
    int empty=0;
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            if (grid[i][j]==1) black++;
            if (grid[i][j]==-1) white++;
            if (grid[i][j]==0) empty++;
        }
    }
    if (empty == 0 || black == 0 || white == 0)
        ended = true;
    checkedCells.clear();
}

int GameSet::at(int x, int y)
{
    return grid[x][y];
}

void GameSet::passTurn()
{
    turn++;
}

void GameSet::stall(bool isStall)
{
    ended=isStall;
}

void GameSet::increaseTurn()
{
        turn++;
}

void GameSet::Grid(int mat[][8])
{
    for (int i=0; i<8;i++)
        for (int j=0; j<8; j++) mat[i][j]=grid[i][j];
}

void GameSet::gameReset()
{
    white=2;
    black=2;
    turn = 0;
    ended= false;
    for (int i=0; i<8; i++)
    {
        for (int j=0; j<8; j++)
        {
            grid[i][j]=0;
        }
    }
    grid[3][3]=1;
    grid[3][4]=-1;
    grid[4][3]=-1;
    grid[4][4]=1;    
}

void GameSet::setPoint(int x, int y, int col)
{
    grid[x][y]=col;
}


Cell GameSet::chooseMove(int iteration)
{
    checkedCells.clear();
    Cell temp;
    temp.x=-10;
    temp.y=-10;
    this->checkTurn(myColor);
    if (checkedCells.length())
    {
        temp= checkedCells[0];
        for (int i=1; i<checkedCells.length(); i++)
        {
            if (temp.beauty<=checkedCells[i].beauty) temp= checkedCells[i];
        }
    }

    move(temp.x, temp.y,myColor);

    return temp;
}

void GameSet::updateGrid(int ngrid[][8])
{
    for (int i=0;i<8; i++)
    {
        for (int j=0; j<8; j++) grid[i][j]=ngrid[i][j];
    }
}
