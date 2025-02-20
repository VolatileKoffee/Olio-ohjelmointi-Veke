#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->PB0,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 0
    connect(ui->PB1,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 1
    connect(ui->PB2,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 2
    connect(ui->PB3,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 3
    connect(ui->PB4,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 4
    connect(ui->PB5,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 5
    connect(ui->PB6,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 6
    connect(ui->PB7,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 7
    connect(ui->PB8,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 8
    connect(ui->PB9,&QPushButton::clicked,this,&MainWindow::numberClickHandler); // button 9

    connect(ui->PBenter,&QPushButton::clicked,this,&MainWindow::enterClickHandler); // button enter
    connect(ui->PBclear,&QPushButton::clicked,this,&MainWindow::clearClickHandler); // button clear

    connect(ui->PBplus,&QPushButton::clicked,this,&MainWindow::operatorClickHandler); // button plus
    connect(ui->PBminus,&QPushButton::clicked,this,&MainWindow::operatorClickHandler); // button minus
    connect(ui->PBmulti,&QPushButton::clicked,this,&MainWindow::operatorClickHandler); // button multiplication
    connect(ui->PBdiv,&QPushButton::clicked,this,&MainWindow::operatorClickHandler); // button division

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickHandler()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    QString numberName = button->objectName();

    qDebug()<<"Number " << numberName.at(2) << " is received";

    if(calcState == 0){
        ui->num1->setText(ui->num1->text()+numberName.at(2)); // calcState = 0 (default) --> receiving 1st number
        number1 = (ui->num1->text());   // number1 sum udpdate
    } else {
        ui->num2->setText(ui->num2->text()+numberName.at(2)); // calcState = 2 --> receiving 2nd number
        number2 = (ui->num2->text());   // number2 sum update
    }
    //qDebug()<<"Number 1 = '" << number1 << "'";
    //qDebug()<<"Number 2 = '" << number2 << "'";
}

void MainWindow::enterClickHandler()
{
    qDebug()<<"Enter push is received";

    float n1 = number1.toFloat();
    float n2 = number2.toFloat();
    qDebug()<<"Number 1 is " << n1 << " and Number 2 is " << n2 << Qt::endl;

    switch(calcOperator){
    case 0:
        calcResult = n1+n2;
        break;
    case 1:
        calcResult = n1-n2;
        break;
    case 2:
        calcResult = n1*n2;
        break;
    case 3:
        calcResult = n1/n2;
        break;
    }
    ui->result->setText(QString::number(calcResult));
}

void MainWindow::clearClickHandler() // clearing num1, num2 and result QLineEdit-windows
{
    qDebug()<<"Clear push is received";

    calcResult = 0.0;
    number1.clear();
    number2.clear();
    ui->num1->clear();
    ui->oper->clear();
    ui->num2->clear();
    ui->result->clear();

    calcState = 0;
}

void MainWindow::operatorClickHandler() // handles calculation operators +, -, * and /
{
    QAbstractButton *button = qobject_cast<QPushButton*>(sender());
    QString operatorSymbol = button->text();

    qDebug()<<"Operator " << operatorSymbol.at(0) << " is received";
    ui->oper->setText(ui->oper->text()+operatorSymbol.at(0));

    if (operatorSymbol == "+"){
        calcOperator = 0;
    } else if (operatorSymbol == "-"){
        calcOperator = 1;
    } else if (operatorSymbol == "*"){
        calcOperator = 2;
    } else if (operatorSymbol == "/"){
        calcOperator = 3;
    }

    calcState = 2;
}
