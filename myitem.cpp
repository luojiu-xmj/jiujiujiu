#include "myitem.h"
#include"handler.h"
#include<QPixmap>
#include<QDebug>
#include<QCursor>
myitem::myitem()
{
this->setPixmap(QPixmap(":/bg/pic/1.png"));
    this->start=false;
    this->mouse=false;
    this->setCursor(QCursor(QPixmap(":/mouse/pic/5.png")));
}

void myitem::setPic(QString path)
{

    this->setPixmap(QPixmap(path));
}
void myitem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/pic/5.png")));
    if(this->isStart()){
        handler *hand=handler::getInstance();
    if(this->isMouse()){
        hand->addScore();
        this->setPixmap(QPixmap(":/mouse/pic/4.png"));
        this->mouse=false;
    }
    }
}

void myitem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
this->setCursor(QCursor(QPixmap(":/mouse/pic/3.png")));
}


void myitem::setMouse(bool mouse)
{
    this->mouse=mouse;
}
bool myitem::isMouse()
{
    return this->mouse;
}

void myitem::setStart(bool start)

{
    this->start=start;
}

bool myitem::isStart()
{
    return this->start;
}





