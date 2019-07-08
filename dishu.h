#ifndef DISHU_H
#define DISHU_H


#include <QMainWindow>
#include"myscene.h"
#include<QCloseEvent>
#include<QTimer>
#include<QMovie>


namespace Ui {
class dishu;
}

class dishu : public QMainWindow
{
    Q_OBJECT

public:
    void sendSlot();
    explicit dishu(QWidget *parent = nullptr);
    ~dishu();
    void closeEvent(QCloseEvent *event);
    int score;
    Ui::dishu *ui;


signals:
    void mySignal();



private slots:
    void updateScore();

    void on_btn_stop_clicked();

public slots:
    void slotStart();
    void slotStop();
    void slotProcessBar();
    void slotReset();

private:

    QTimer *m_timer;
     myScene *sc;
    int overTimerId;
    int winTimerId;
    QMovie overMovie;
    QMovie winMovie;


protected:
    void timerEvent(QTimerEvent *e);
};


#endif // DISHU_H
