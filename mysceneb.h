#ifndef MYSCENEB_H
#define MYSCENEB_H

#include <QObject>
#include<QGraphicsScene>
#include"myitemb.h"
#include<QTimer>

class mysceneb : public QGraphicsScene
{
    Q_OBJECT
public:

    explicit mysceneb(QObject *parent = nullptr);

signals:

public slots:
    void showRabbit();
    void startGame();
    void pauseGame();
    void stopGame();

private:
    myitemb *item[16];
    QTimer *ptimer;


};
#endif // MYSCENEB_H
