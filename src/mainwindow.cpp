#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cnc.h>
#include "windows.h"
#include "opencv2/opencv.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*
 *   Signal Mapper Menü
 */

    QSignalMapper *sm = new QSignalMapper(this);

    // connect to `clicked' on all buttons
    connect(ui->actionOperation, SIGNAL(triggered()), sm, SLOT(map()));
    connect(ui->actionBauteiledatenbank, SIGNAL(triggered()), sm, SLOT(map()));
    connect(ui->actionMaschine, SIGNAL(triggered()), sm, SLOT(map()));

    // setMapping on each button to the QStackedWidget index we'd like to switch to
    // note: this affects the value passed via QSignalMapper::mapped(int) signal
    sm->setMapping(ui->actionBauteiledatenbank, 0);
    sm->setMapping(ui->actionOperation, 1);
    sm->setMapping(ui->actionMaschine, 2);

    // finally, connect the mapper to the stacked widget
    connect(sm, SIGNAL(mapped(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

    CNC *Maschine = new CNC();

    QSignalMapper *MoveAxis = new QSignalMapper(this);
    connect(ui->btnMvXp,SIGNAL(pressed()),MoveAxis,SLOT(map()));
    connect(ui->btnMvXp,SIGNAL(released()),Maschine,SLOT(StopMoveCont()));
    connect(ui->btnMvXn,SIGNAL(pressed()),MoveAxis,SLOT(map()));
    connect(ui->btnMvXn,SIGNAL(released()),Maschine,SLOT(StopMoveCont()));

    connect(ui->btnMvYp,SIGNAL(pressed()),MoveAxis,SLOT(map()));
    connect(ui->btnMvYp,SIGNAL(released()),Maschine,SLOT(StopMoveCont()));
    connect(ui->btnMvYn,SIGNAL(pressed()),MoveAxis,SLOT(map()));
    connect(ui->btnMvYn,SIGNAL(released()),Maschine,SLOT(StopMoveCont()));

    connect(ui->btnMvZp,SIGNAL(pressed()),MoveAxis,SLOT(map()));
    connect(ui->btnMvZp,SIGNAL(released()),Maschine,SLOT(StopMoveCont()));
    connect(ui->btnMvZn,SIGNAL(pressed()),MoveAxis,SLOT(map()));
    connect(ui->btnMvZn,SIGNAL(released()),Maschine,SLOT(StopMoveCont()));

    MoveAxis->setMapping(ui->btnMvXp,-1);
    MoveAxis->setMapping(ui->btnMvXn,1);

    MoveAxis->setMapping(ui->btnMvYp,2);
    MoveAxis->setMapping(ui->btnMvYn,-2);

    MoveAxis->setMapping(ui->btnMvZp,3);
    MoveAxis->setMapping(ui->btnMvZn,-3);

    connect(MoveAxis,SIGNAL(mapped(int)),Maschine,SLOT(StartMoveCont(int)));

}


MainWindow::~MainWindow()
{
    delete ui;
}
