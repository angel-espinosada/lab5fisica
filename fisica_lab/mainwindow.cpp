#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBrush>
#include <QPen>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    escena = new QGraphicsScene(this);
    escena->setSceneRect(0,0,740,380);
    ui->graphicsView->setScene(escena);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    agregarbarrera(50,280,35,100,200.0f);
    agregarbarrera(155,280,35, 100, 200.0f);
    agregarbarrera(50,245,140, 35, 100.0f);
    escena->addEllipse(108,330, 24, 24, QPen(Qt::black), QBrush(Qt::blue));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btndisparar_clicked()
{

}

void MainWindow::actualizarFisica()
{

}

void MainWindow::agregarbarrera(float x, float y, float ancho, float alto, float dureza)
{
    barrera b(x,y, ancho,alto, dureza);
    barreras.push_back(b);
    QColor color=(dureza>=200.0f)?QColor(255,224,178):QColor(220, 220, 220);
    QGraphicsRectItem *rect=escena->addRect(x,y,ancho,alto, QPen(Qt::black),QBrush(color));
    iconos_barrera.push_back(rect);
}

