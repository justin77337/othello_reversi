#ifndef NEWGAMEWINDOW_H
#define NEWGAMEWINDOW_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <QCloseEvent>


struct info
{
    bool possibility;
    bool bot1,bot2;
    int level2;
};

class newGameWindow : public QDialog
{
    Q_OBJECT

    public:
        newGameWindow(QWidget * parent = 0);
        ~newGameWindow();

    private:
        info newGameData;
        QList <QWidget*> widgetList;
        bool ok;

    protected:
        void closeEvent(QCloseEvent *e);

    private slots:
        void okClicked();
        void cancelClicked();

    signals:
        void newGame(info data);
        void returnToGame();
};

#endif // NEWGAMEWINDOW_H
