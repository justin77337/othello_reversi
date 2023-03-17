#include <QtGui/QApplication>
#include "GameSet.h"
#include "othelloui.h"
#include "newgamewindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OthelloUi w;

    w.startGame();
    return a.exec();
}
