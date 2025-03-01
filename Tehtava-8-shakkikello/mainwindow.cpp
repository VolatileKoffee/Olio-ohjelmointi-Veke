#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->PBSwitch1,&QPushButton::clicked,this,&MainWindow::switchPlayerHandler); // player 1 turn end
    connect(ui->PBSwitch2,&QPushButton::clicked,this,&MainWindow::switchPlayerHandler); // player 2 turn end

    connect(ui->PBstart,&QPushButton::clicked,this,&MainWindow::startHandler); // game start
    connect(ui->PBstop,&QPushButton::clicked,this,&MainWindow::stopHandler); // game stop

    connect(ui->PBgame1,&QPushButton::clicked,this,&MainWindow::game1Handler); // 2 min long game
    connect(ui->PBgame2,&QPushButton::clicked,this,&MainWindow::game2Handler); // 5 min long game

    setGameInfoText("Game initialized. Choose time to start",12);

    pQTimer = new QTimer(this);
    connect(pQTimer,&QTimer::timeout,this,&MainWindow::timeHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    // Included by default in QTimer
}

void MainWindow::updateProgressBar() // updateProgressBar method updates each progress bar according to player1time-,player2Time- and gameTime-variables
{
    ui->progressBar1->setValue(player1Time);
    ui->progressBar2->setValue(player2Time);
}

void MainWindow::setGameInfoText(QString labeltext, short fontsize)
{
    QFont fontObject;
    fontObject.setPointSize(fontsize);

    ui->labelGame->setText(labeltext); // game status text
    ui->labelGame->setFont(fontObject); // game status text font size
}

void MainWindow::switchPlayerHandler()
{
    QPushButton *switchbutton = qobject_cast<QPushButton*>(sender());
    QString switchName = switchbutton->objectName();

    qDebug()<<"Player switch from " << switchName << " is recieved";

    if (switchName == "PBSwitch1") {
        qDebug()<<"Action: changed to p2"; // changing to player 2
        setGameInfoText("Player 2 turn!",10);
        currentPlayer = 1;

    } else if (switchName == "PBSwitch2") {
        qDebug()<<"Action: changed to p1"; // changing to player 1
        setGameInfoText("Player 1 turn!",10);
        currentPlayer = 0;
    }
}

void MainWindow::timeHandler()
{
    QString timeprint = QString::number(gameTime);
    qDebug()<<"Game time: " << timeprint << "s. P1 time: "<<player1Time << "s. P2 time: " << player2Time << "s.";
    setGameInfoText("Game ongoing",10);

    gameTime--; // keeps track of total game time and continues to decline with both players

    // Player checking, time decrementation, time progress bar updating:
    if (currentPlayer == 0){ // if state 0 = "player 1" is active, player1Time will be counting downwards
        player1Time--;
        updateProgressBar();
    } else if (currentPlayer == 1){ // if state 1 = "player 2" is active, player2Time will be counting downwards
        player2Time--;
        updateProgressBar();
    }

    // Game ending checking and procedures:
    if (player1Time == 0 && currentPlayer == 0) { // currentPlayer 0 is "player 1"
        setGameInfoText("Player 2 won!",14);
        pQTimer->stop();
    } else if (player2Time == 0 && currentPlayer == 1) { // currentPlayer 1 is "player 2"
        setGameInfoText("Player 1 won!",14);
        pQTimer->stop();
    }
}

void MainWindow::game1Handler() // 2min game handler
{
    qDebug()<<"2min game push received";
    qDebug()<<"Game time initialized with "<< gameTime << " seconds.";
    gameTime = 120;
    player1Time = gameTime;
    player2Time = gameTime;
    ui->progressBar1->setRange(0,player1Time); // ->setRange(min,max)
    ui->progressBar2->setRange(0,player2Time); // ->setRange(min,max)
    updateProgressBar();
    setGameInfoText("2min game selected",10);
}

void MainWindow::game2Handler() // 5min game handler
{
    qDebug()<<"5min game push received";
    qDebug()<<"Game time initialized with "<< gameTime << " seconds.";
    gameTime = 300;
    player1Time = gameTime;
    player2Time = gameTime;
    ui->progressBar1->setRange(0,player1Time); // ->setRange(min,max)
    ui->progressBar2->setRange(0,player2Time); // ->setRange(min,max)
    updateProgressBar();
    setGameInfoText("5min game selected",10);
}

void MainWindow::startHandler()
{
    qDebug()<<"Start push is received";

    pQTimer->start(1000); // Timer gets interruptions once per. 1000ms or 1s.
    setGameInfoText("Game started!",10);
}

void MainWindow::stopHandler()
{
    qDebug()<<"Stop push is received";

    player1Time = 0;
    player2Time = 0;
    gameTime = 0;
    pQTimer->stop();
    ui->progressBar1->setValue(0); // ->setValue(0) or ->reset();
    ui->progressBar2->setValue(0); // ->setValue(0) or ->reset();
    setGameInfoText("Game stopped. Start new by choosing game time:",10);
}
