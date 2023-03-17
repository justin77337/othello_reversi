#ifndef QOTHELLO_H
#define QOTHELLO_H

#include <QWidget>
#include <QColor>
#include <QList>
#include <QPushButton>
#include <QPaintEvent>


class QCell : public QPushButton
{
    Q_OBJECT

    public:
        QCell(QWidget * parent = 0);
        ~QCell();
        void setPos(int p);
        int Pos();
        void setStatus(int Status);
        int Status();

    private:
        int status;
        int pos;

    protected:
        void paintEvent(QPaintEvent *e);

    private slots:
        void inClick();

    signals:
        void clicks(int p);
};


class QOthello : public QWidget
{
    Q_OBJECT

    public:
        QOthello(QWidget * parent=0);
        ~QOthello();
        void setStatus(int x, int y, int col);

    private:
        QList <QCell*> list;

    private slots:
        void inClick(int p);

    signals:
        void clicks(int p);
};

#endif // QOTHELLO_H
