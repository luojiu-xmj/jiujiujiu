#ifndef DISHUA_H
#define DISHUA_H

#include <QMainWindow>
#include<myscenea.h>
#include<QCloseEvent>
#include<QTimer>
#include<QMovie>

namespace Ui {
class dishua;
}

class dishua : public QMainWindow
{
    Q_OBJECT

public:
    void sendSlot();
    explicit dishua(QWidget *parent = nullptr);
    ~dishua();
    void closeEvent(QCloseEvent *event);
    int score;
    Ui::dishua *ui;
signals:
    void mySignal();

public slots:
    void slotStart();
    void slotStop();
    void slotProcessBar();
    void slotReset();

private slots:
    void updateScore();
    void updateScorea();

    void on_btn_stop_clicked();

private:

    myscenea *sc;
    QTimer *m_timer;
    int overTimerId;
    int winTimerId;
    QMovie overMovie;
    QMovie winMovie;

protected:
    void timerEvent(QTimerEvent *e);
};

#endif // DISHUA_H
