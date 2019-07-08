#ifndef MYSCENEA_H
#define MYSCENEA_H

#include <QObject>
#include<QGraphicsScene>
#include"myitema.h"
#include<QTimer>

class myscenea : public QGraphicsScene
{
    Q_OBJECT
public:

    explicit myscenea(QObject *parent = nullptr);

signals:

public slots:
    void showRabbit();
    void startGame();
    void pauseGame();
    void stopGame();

private:
    myitema *item[16];
    QTimer *ptimer;


};
#endif // MYSCENEA_H
