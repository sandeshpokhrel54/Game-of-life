#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include"grid.h"
#include<iostream>
#include<QThread>





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



};
#endif // MAINWINDOW_H
