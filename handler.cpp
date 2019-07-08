#include "handler.h"

handler::handler(QObject *parent) : QObject(parent)
{


}

handler *handler::hand=new handler;
handler *handler::handa=new handler;


handler *handler::getInstance()
{
    return hand;
}
handler *handler::getInstancea()
{
    return handa;
}


void handler::addScore()
{
    emit beatMouse();
}
void handler::jianScore()
{
    emit beatRabbit();
}
