#include "dishu.h"
#include "ui_dishu.h"
#include<QMessageBox>
#include"handler.h"

extern void pauseGame();

dishu::dishu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dishu)
{
    ui->setupUi(this);
    this->sc=new myScene;
    this->ui->graphicsView->setScene(sc);
    connect(this->ui->btn_start,SIGNAL(clicked(bool)),this->sc,SLOT(startGame()));
    connect(this->ui->btn_pause,SIGNAL(clicked(bool)),this->sc,SLOT(pauseGame()));
    connect(this->ui->btn_stop,SIGNAL(clicked(bool)),this->sc,SLOT(stopGame()));
    this->score=0;
    this->ui->lcdNumber->display(this->score);
    handler *hand=handler::getInstance();
    connect(hand,SIGNAL(beatMouse()),this,SLOT(updateScore()));
    connect(this->ui->return_2,&QPushButton::clicked,this,&dishu::sendSlot);
    m_timer = new QTimer(this);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    connect(ui->btn_start,SIGNAL(clicked()),this,SLOT(slotStart()));
    connect(ui->btn_pause,SIGNAL(clicked()),this,SLOT(slotStop()));
    connect(ui->btn_stop,SIGNAL(clicked()),this,SLOT(slotReset()));
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slotProcessBar()));


}

dishu::~dishu()
{
    delete ui;
}

void dishu::closeEvent(QCloseEvent *event)
{
    int ret=QMessageBox::question(this,"确定","你忍心离开吗？","是","否");
    if(ret==1){
        event->ignore();}
}
void dishu::updateScore()
{
    this->score+=10;
    this->ui->lcdNumber->display(this->score);
}

void dishu::sendSlot()
{
    emit mySignal();

}

void dishu::on_btn_stop_clicked()
{
    score=0;
    this->ui->lcdNumber->display(this->score);
}

void dishu::slotProcessBar()
{
    static int pos=0;
    if(pos <= 101&&score>=100)
    {
         sc->stopGame();
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
    {
        sc->stopGame();
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
        pos=0;

       return;
    }
    ui->progressBar->setValue(pos++);
    }

void dishu::slotStart()
{
    m_timer->start(100);
}

void dishu::slotStop()
{
    m_timer->stop();
}

void dishu::slotReset()
{
    ui->progressBar->reset();
    ui->progressBar->setValue(0);
    }

void dishu::timerEvent(QTimerEvent *e)
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


