#ifndef DISHUB_H
#define DISHUB_H

#include <QMainWindow>
#include<myscenea.h>
#include<QCloseEvent>
#include<QTimer>
#include<QMovie>

namespace Ui {
class dishub;
}

class dishub : public QMainWindow
{
    Q_OBJECT

public:
    void sendSlot();
    explicit dishub(QWidget *parent = nullptr);
    ~dishub();
    void closeEvent(QCloseEvent *event);
    int score;
Ui::dishub *ui;
signals:
    void mySignal();


private slots:
    void updateScore();
    void updateScorea();

    void on_btn_stop_clicked();

public slots:
    void slotStart();
    void slotStop();
    void slotProcessBar();
    void slotReset();

private:

    QTimer *m_timer;
    myscenea *sc;
    int overTimerId;
    int winTimerId;
    QMovie overMovie;
    QMovie winMovie;

protected:
    void timerEvent(QTimerEvent *e);

};

#endif // DISHUB_H
