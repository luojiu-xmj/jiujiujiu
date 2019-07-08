#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include"dishu.h"
#include"dishua.h"
#include"dishub.h"


#include<QDialog>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void changewin();
    void dealsub();
    void changewina();
    void dealsuba();
    void changewinb();
    void dealsubb();

private slots:

    void on_easy_clicked();
    void on_difficult_clicked();
    void on_devil_clicked();

private:
    Ui::MainWindow *ui;
    dishu d;
    dishua di;
    dishub dis;




};

#endif // MAINWINDOW_H
