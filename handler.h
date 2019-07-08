#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>



class handler : public QObject
{
    Q_OBJECT
public:
    static handler *getInstance();
    static handler *getInstancea();

    void addScore();
    void jianScore();
private:
    explicit handler(QObject *parent = nullptr);

signals:
    void beatMouse();
    void beatRabbit();


public slots:

private:
    static handler *hand;
    static handler *handa;



};

#endif // HANDLER_H
