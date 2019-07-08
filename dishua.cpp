#include "dishua.h"
#include "ui_dishua.h"
#include<QMessageBox>
#include"handler.h"

dishua::dishua(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dishua)
{
    ui->setupUi(this);
    this->sc=new myscenea;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this->sc,SLOT(stopGame()));
    this->score=0;
    this->ui->lcdNumber->display(this->score);
    handler *hand=handler::getInstance();
    handler *handa=handler::getInstancea();

    connect(hand,SIGNAL(beatMouse()),this,SLOT(updateScore()));
    connect(handa,SIGNAL(beatRabbit()),this,SLOT(updateScorea()));
    connect(this->ui->return_2,&QPushButton::clicked,this,&dishua::sendSlot);
    m_timer = new QTimer(this);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    connect(ui->btn_start,SIGNAL(clicked()),this,SLOT(slotStart()));
    connect(ui->btn_pause,SIGNAL(clicked()),this,SLOT(slotStop()));
    connect(ui->btn_stop,SIGNAL(clicked()),this,SLOT(slotReset()));
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotProcessBar()));

}

dishua::~dishua()
{
    delete ui;
}
void dishua::closeEvent(QCloseEvent *event)
{
    int ret=QMessageBox::question(this,"确定","你忍心离开吗？","是","否");
    if(ret==1){
        event->ignore();}
}
void dishua::updateScore()
{
    this->score+=10;
    this->ui->lcdNumber->display(this->score);
}
void dishua::updateScorea()
{
    this->score-=30;
    this->ui->lcdNumber->display(this->score);
}

void dishua::sendSlot()
{
    emit mySignal();

}


void dishua::on_btn_stop_clicked()
{
    score=0;
    this->ui->lcdNumber->display(this->score);
}

void dishua::slotProcessBar()
{
    static int pos=0;
    if(pos <= 101&&score>=100)
    { sc->stopGame();
        score=0;
        this->ui->lcdNumber->display(this->score);
        slotReset();
            m_timer->stop();
        int r=QMessageBox::information(this,"成功","恭喜闯关成功😘",QObject::tr(("确认")));
        if(r==QObject::tr(("确认")).toInt())
        {
           winMovie.start();
            ui->stackedWidget->setCurrentWidget(ui->pagelose);
            winTimerId=startTimer(1500);}pos=0;
        return;
        }
    else if(pos==101)
    { sc->stopGame();
        score=0;
        this->ui->lcdNumber->display(this->score);
        slotReset();
        m_timer->stop();
        int r=QMessageBox::information(this,"失败","很遗憾闯关失败😭",QObject::tr(("确认")));
        if(r==QObject::tr(("确认")).toInt())
        {
            overMovie.start();
            ui->stackedWidget->setCurrentWidget(ui->pagewin);
            overTimerId=startTimer(1500);
        }
        pos=0;return;
    }
    ui->progressBar->setValue(pos++);
    }

void dishua::slotStart()
{
    m_timer->start(100);
}

void dishua::slotStop()
{
    m_timer->stop();
}

void dishua::slotReset()
{
    ui->progressBar->reset();
    ui->progressBar->setValue(0);
    }

void dishua::timerEvent(QTimerEvent *e)
{
    if(e->timerId()==overTimerId)
    {
        overMovie.stop();
        killTimer(overTimerId);
        ui->stackedWidget->setCurrentWidget(ui->page_3);
    }
    if(e->timerId()==winTimerId)
    {
        winMovie.stop();
        killTimer(winTimerId);
        ui->stackedWidget->setCurrentWidget(ui->page_3);
}
}
