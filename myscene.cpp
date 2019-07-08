#include "myscene.h"
#include"dishu.h"
#include<stdlib.h>
#include"myitem.h"


myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
int i=0;
    for(i=0;i<16;i++)
    {this->item[i]=new myitem;
    this->item[i]->setPos(i/4*this->item[i]->boundingRect().width(),i%4*this->item[i]->boundingRect().height());
    this->addItem(this->item[i]);}

    this->ptimer=new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(showMouse()));



}

void myScene::showMouse()
{
    int count=rand()%3+2;
    int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setPic(":bg/pic/1.png");
        this->item[i]->setMouse(false);
    }
    for(i=0;i<count;i++)
    {
     int index=rand()%16;
        this->item[index]->setPic(":/bg/pic/2.png");
     this->item[index]->setMouse(true);
    }
}
void myScene::startGame()
{   int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(true);
    }
    this->ptimer->start(1800);
}
void myScene::pauseGame()
{int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(false);
    }
    this->ptimer->stop();
}
void myScene::stopGame()
{
    this->ptimer->stop();
    int i=0;
    for(i=0;i<16;i++){
        this->item[i]->setStart(false);
    }

    for(i=0;i<16;i++){
        this->item[i]->setPic(":bg/pic/1.png");
        this->item[i]->setMouse(false);
    }


}



















