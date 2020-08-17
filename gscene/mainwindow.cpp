#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //creating a graphics view scene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    resolution = 40;  //hardcoded resolution
    gridLength = 30;  //hardcoded gridLength

    genCount = 1;     //generation counter
    setupGrid();  //create the original grid



}

void MainWindow::setupGrid()
{
    for(int i=0; i<gridLength; i++ )
    {
        for(int j=0; j<gridLength; j++)
        {
            grid[i][j] = new Grid;
            nextGen[i][j] = new Grid;
            grid[i][j]->positionX = i;
            grid[i][j]->positionY = j;
            grid[i][j]->squareDim = resolution;
            scene->addItem(grid[i][j]);

            //a container for next gen
            nextGen[i][j]->positionX = i;
            nextGen[i][j]->positionY = j;
            nextGen[i][j]->squareDim = resolution;
//            nextGen[i][j] = grid[i][j];


        }
    }

}

void MainWindow::on_Start_clicked()
{

    gameLogic();
    gridUpdate();
    ui->genCount->setText("Generation:"+ QString::number(genCount));
    genCount++;
}

void MainWindow::on_Reset_clicked()
{
    genCount = 1;
    ui->genCount->setText("Generation:" + QString::number(genCount));
    for(int i=0; i<gridLength; i++)
    {
       for(int j=0; j<gridLength; j++)
       {
            grid[i][j]->life = false;
            grid[i][j]->update();
       }
    }

}


void MainWindow::gridUpdate()
{
    for(int i=0; i<gridLength; i++)
    {
        for(int j=0; j<gridLength; j++)
        {
            grid[i][j]->life = nextGen[i][j]->life;
            grid[i][j]->update();
//                nextGen[i][j]->life = false;

        }
    }

}


void MainWindow::gameLogic()
{
    int liveNeighbours=0;

    for(int i=0; i<gridLength; i++)
    {

        for(int j=0; j<gridLength; j++)
        {
            liveNeighbours = 0;
            //top-left neighbour
            if((j-1>=0) && (i-1>=0) && grid[i-1][j-1]->life)
                liveNeighbours++;

            //above neighbour
            if((i-1>=0) && grid[i-1][j]->life)
                liveNeighbours++;

            //top-right neighbour
            if((i-1>=0) && (j+1<gridLength) && grid[i-1][j+1]->life)
                liveNeighbours++;

            //left-side neighbour
            if((j-1>=0) && grid[i][j-1]->life)
                liveNeighbours++;

            //right-side neighbour
            if((j+1<gridLength) && grid[i][j+1]->life)
                liveNeighbours++;

            //bottom-left neighbour
            if((i+1<gridLength) && (j-1>=0) && grid[i+1][j-1]->life)
                liveNeighbours++;

            //below neighbour
            if((i+1<gridLength) && grid[i+1][j]->life)
                liveNeighbours++;

            //bottom-right neighbour
            if((i+1<gridLength) && (j+1<gridLength) && grid[i+1][j+1]->life)
                liveNeighbours++;

            if(liveNeighbours < 2 || liveNeighbours > 3)
            {
                 //grid[i][j]->life = false;
                 nextGen[i][j]->life = false;
            }

            if(liveNeighbours == 2 || liveNeighbours == 3)
            {
                nextGen[i][j]->life = grid[i][j]->life;
            }

            if(liveNeighbours == 3)
            {
                //grid[i][j]->life = true;
                nextGen[i][j]->life = true;
            }

    }
 }

}


//void MainWindow::on_autoPlay_clicked()
//{
//    ui->autoPlay->setObjectName("Stop");
//    for(int i=0; genCount<100; i++)
//    {

//        gameLogic();
//        gridUpdate();
//        ui->genCount->setText("Generation:"+ QString::number(genCount));
//        genCount++;
//        QThread::sleep(2000);

//    }
//}
//void MainWindow::gridResize()
//{
//    for(int i=0; i<gridLength; i++)
//    {
//        for(int j=0; j<gridLength; j++)
//        {
//            grid[i][j]->squareDim = resolution;
//            nextGen[i][j]->squareDim = resolution;
//            grid[i][j]->update();
//            nextGen[i][j]->update();
//        }
//    }
//
//}


//void MainWindow::on_Resolution_actionTriggered(int action)
//{
//    resolution = action;
//    gridResize();

//}


MainWindow::~MainWindow()
{
    delete ui;
}



