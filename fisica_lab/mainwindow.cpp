#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBrush>
#include <QPen>
#include<cmath>

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
    //Lado izquierdo
    agregarbarrera(50,280,35,100,200.0f);
    agregarbarrera(155,280,35, 100, 200.0f);
    agregarbarrera(50,245,140, 35, 100.0f);
    escena->addEllipse(108,330, 24, 24, QPen(Qt::black), QBrush(Qt::blue));
    //Lado derecho

    agregarbarrera(550, 280, 35, 100, 200.0f);
    agregarbarrera(655, 280, 35, 100, 200.0f);
    agregarbarrera(550, 245, 140, 35, 100.0f);
    escena->addEllipse(608,330, 24, 24, QPen(Qt::black), QBrush(Qt::red));
//cañon
    escena->addRect(10,180, 30,15, QPen(Qt::black), QBrush(Qt::darkGray));
    escena->addRect(700,180, 30,15, QPen(Qt::black), QBrush(Qt::darkGray));

    turnojugador=1;
    dispaencurso=false;
    graficobala=nullptr;
    timer= new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::actualizarFisica);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btndisparar_clicked()
{
    if (dispaencurso){
        return;
    }

    float angulo= ui->sbAngulo->value();
    float velocidad=ui->sbVelocidad->value();

    float rad = angulo*3.14159265f / 180.0f;
    float x0, y0, vx,vy;
    if(turnojugador==1){
        x0=45.0f;
        y0=180.0f;
        vx=velocidad*cos(rad);
        vy=-velocidad*sin(rad);
    }
    else{
        x0=685.0f;
        y0=180.0f;
        vx=-velocidad*cos(rad);
        vy=-velocidad*sin(rad);

    }

    proyectil=bala(x0, y0, vx, vy, 5.0f, 8.0f);

    if(graficobala!=nullptr){
        escena->removeItem(graficobala);
        delete graficobala;

    }
    float r=proyectil.getRadio();
    graficobala=escena->addEllipse(0,0,r*2,r*2, QPen(Qt::black), QBrush(Qt::darkRed));
    graficobala->setPos(x0-r, y0-r);

    dispaencurso=true;
    timer->start(20);
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

