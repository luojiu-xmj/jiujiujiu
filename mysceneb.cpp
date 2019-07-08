#include "mysceneb.h"
#include"myitemb.h"
#include<stdlib.h>
#include"dishu.h"
mysceneb::mysceneb(QObject *parent) : QGraphicsScene(parent)
{
int i=0;
    for(i=0;i<16;i++)
    {this->item[i]=new myitemb;
    this->item[i]->setPos(i/4*this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
    this->addItem(this->item[i]);}

this->ptimer=new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showRabbit()));

}

void mysceneb::showRabbit()
{
    int count=rand()%3+8;

    int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setPic(":bg/pic/1.png");
        this->item[i]->setMouse(false);
    }

    for(i=0;i<count;i++)
    {
        int mor=rand()%2+1;
        int index=rand()%16;

  if(mor==1)
        {
         this->item[index]->setPic(":/bg/pic/2.png");
         this->item[index]->setMouse(true);
         this->item[index]->setRabbit(false);
        }
         if(mor==2)
         {
         this->item[index]->setPic(":/rb/pic/7.png");
         this->item[index]->setRabbit(true);
         this->item[index]->setMouse(false);
         }

    }
}

void mysceneb::startGame()
{   int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(true);
    }
    this->ptimer->start(0);
}
void mysceneb::pauseGame()
{int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();
}
void mysceneb::stopGame()
{int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();
    for(i=0;i<16;i++){
        this->item[i]->setPic(":bg/pic/1.png");
        this->item[i]->setMouse(false);
    }

}





