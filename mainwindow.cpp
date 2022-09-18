#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // initialize variables
    this->number = 0;
    this->op=false;
    this->add=false;
    this->sub=false;
    this->term1=0;
    this->term2=0;
    ui->setupUi(this);
    ui->lcdNumber->setHexMode();
    // connects clicked buttons with relevant SLOTs
    connect(ui->numberButtons,SIGNAL(buttonClicked(int)),this,SLOT(shiftnum(int)));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(clear()));
    connect(ui->operatorButtons,SIGNAL(buttonClicked(int)),this,SLOT(operation(int)));
    connect(ui->equal,SIGNAL(clicked()),this,SLOT(result()));
}
// displays the stored number
void MainWindow::mydisplay(){
    ui->lcdNumber->display(this->number);
}
// updates the number
void MainWindow::shiftnum(const int &num){
    this->number *= 16;
    if ((QString::compare((ui->numberButtons->button(num)->text()), "1", Qt::CaseInsensitive))==0){
        this->number += 1;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "2", Qt::CaseInsensitive))==0){
        this->number += 2;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "3", Qt::CaseInsensitive))==0){
        this->number += 3;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "4", Qt::CaseInsensitive))==0){
        this->number += 4;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "5", Qt::CaseInsensitive))==0){
        this->number += 5;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "6", Qt::CaseInsensitive))==0){
        this->number += 6;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "7", Qt::CaseInsensitive))==0){
        this->number += 7;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "8", Qt::CaseInsensitive))==0){
        this->number += 8;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "9", Qt::CaseInsensitive))==0){
        this->number += 9;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "A", Qt::CaseInsensitive))==0){
        this->number += 10;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "B", Qt::CaseInsensitive))==0){
        this->number += 11;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "C", Qt::CaseInsensitive))==0){
        this->number += 12;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "D", Qt::CaseInsensitive))==0){
        this->number += 13;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "E", Qt::CaseInsensitive))==0){
        this->number += 14;
    }
    else if ((QString::compare((ui->numberButtons->button(num)->text()), "F", Qt::CaseInsensitive))==0){
        this->number += 15;
    }
    mydisplay();
}
// resets the calculator
void MainWindow::clear(){
    this->number=0;
    this->op=false;
    this->add=false;
    this->sub=false;
    this->term1=0;
    this->term2=0;
    mydisplay();
}
// does arithmetic operations and displays the result
void MainWindow::result(){
    if(op){
        this->term2 = this->number;
        if(add){
            this->number = term1+term2;
        }
        else if(sub){
            this->number = term1-term2;
        }
        this->term1 = this->number;
    }
    this->op=false;
    this->add=false;
    this->sub=false;
    mydisplay();
}
// updates the first term with the input and resets the number
void MainWindow::operation(const int &type){
    if(op){
        result();
    }
    this->op = true;
    if((QString::compare((ui->operatorButtons->button(type)->text()), "+", Qt::CaseInsensitive))==0){
        this->term1 = this->number;
        this->add=true;
        this->number=0;
    }
    else if((QString::compare((ui->operatorButtons->button(type)->text()), "-", Qt::CaseInsensitive))==0){
        this->term1 = this->number;
        this->sub=true;
        this->number=0;
    }
}
MainWindow::~MainWindow()
{
    delete ui;
}

