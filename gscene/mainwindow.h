#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include"grid.h"
#include<iostream>
#include<QTimer>





QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Start_clicked();

    void on_Reset_clicked();

    void on_autoPlay_clicked();

    void on_gridVal_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    void setupGrid();
    void gridUpdate();
    void gameLogic();
//    void gridResize();
    Grid *grid[30][30], *nextGen[30][30];
    int gridLength,resolution;
    int genCount=0;
    QTimer *timer;
    bool play;
    void deallocate();
    const int maxresol = 55;



};
#endif // MAINWINDOW_H
