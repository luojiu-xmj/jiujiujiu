#include "myitema.h"
#include"handler.h"
#include<QPixmap>
#include<QDebug>
#include<QCursor>
myitema::myitema()
{
this->setPixmap(QPixmap(":/bg/pic/1.png"));
    this->start=false;
    this->mouse=false;
    this->rabbit=false;
    this->setCursor(QCursor(QPixmap(":/mouse/pic/5.png")));
}

void myitema::setPic(QString path)
{

    this->setPixmap(QPixmap(path));
}
void myitema::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/mouse/pic/5.png")));

    if(this->isStart())
    {
        handler *hand=handler::getInstance();
        handler *handa=handler::getInstancea();
        if(this->isMouse()){
            hand->addScore();
            this->setPixmap(QPixmap(":/mouse/pic/4.png"));
            this->mouse=false;
        }
            if(this->isRabbit()){
                    handa->jianScore();
                    this->setPixmap(QPixmap(":/rb/pic/6.png"));
                    this->rabbit=false;
                }


    }
}

void myitema::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
this->setCursor(QCursor(QPixmap(":/mouse/pic/3.png")));
}


void myitema::setMouse(bool mouse)
{
    this->mouse=mouse;
}

void myitema::setRabbit(bool rabbit)
{
    this->rabbit=rabbit;
}

bool myitema::isMouse()
{
    return this->mouse;
}

bool myitema::isRabbit()
{
    return this->rabbit;
}

void myitema::setStart(bool start)

{
    this->start=start;
}

bool myitema::isStart()
{
    return this->start;
}
