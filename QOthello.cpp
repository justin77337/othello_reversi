#include "QOthello.h"
#include <cmath>
#include <QPainter>
#include <QImage>
#include <QRadialGradient>

QCell::QCell(QWidget * parent) : QPushButton(parent)
{
    connect(this, SIGNAL(clicked()), this, SLOT(inClick()));
    status=0;
}

void QCell::setStatus(int Status)
{
    status=Status;
}

int QCell::Status()
{
    return status;
}

QCell::~QCell(){}

void QCell::setPos(int p)
{
    pos=p;
}

int QCell::Pos()
{
    return pos;
}

void QCell::inClick()
{
    emit clicks(pos);
}

void QCell::paintEvent(QPaintEvent *e)
{
    e->accept();
        QPainter p(this);
        p.setRenderHint(p.Antialiasing,true);
        p.setBrush(Qt::darkGreen);
        p.setPen(Qt::blue);
        p.drawRect(0,0,width(),height());
        QColor fc;
        switch(status)
        {
            case(-1):
                fc.setRgb(255,255,255);
                break;
            case(1):
                fc.setRgb(33,33,33);
                break;
            case(2):
                fc.setRgb(229,255,128);
                break;
        }
        if (status)
        {
            p.setBrush(fc);
            p.drawEllipse(2,2,width()-4,height()-4);
        }
        p.end();
}

QOthello::QOthello(QWidget * parent) : QWidget(parent)
{
    this->setFixedSize(340,340);
    for (int i = 0; i<64; i++)
    {
        QCell * t;
        t = new QCell(this);
        t->setGeometry(2+(i-(8*(i/8)))*42,2+(i/8)*42,41,41);

        t->setPos(i);
        list.push_back(t);
        connect(t, SIGNAL(clicks(int)), this, SLOT(inClick(int)));
    }
}

QOthello::~QOthello()
{
    for (int i=0; i<list.length(); i++) delete list.at(i);
    list.clear();
}

void QOthello::inClick(int p)
{
    emit clicks(p);
}

void QOthello::setStatus(int x, int y, int col)
{
    int p;
    p=y*8+x;
        list.at(p)->setStatus(col);
        list.at(p)->repaint();
}
