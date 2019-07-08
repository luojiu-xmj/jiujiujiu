#ifndef MYITEMB_H
#define MYITEMB_H
#include<QGraphicsPixmapItem>
#include<QString>
#include<QGraphicsSceneMouseEvent>


class myitemb : public QGraphicsPixmapItem
{
public:
    myitemb();
    void setPic(QString path);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void setMouse(bool mouse);
    void setRabbit(bool rabbit);
    bool isMouse();
    bool isRabbit();
    void setStart(bool start);
    bool isStart();

private:
    bool mouse;
    bool rabbit;
    bool start;

};

#endif // MYITEMB_H
