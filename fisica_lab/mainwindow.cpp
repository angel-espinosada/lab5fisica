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
    rebotes = 0;
    timer->start(20);
}

void MainWindow::actualizarFisica()
{
    float dt=0.05f;
    float g=9.8f;
    proyectil.actualizarPosicion(dt,g);

    float x=proyectil.getX();
    float y=proyectil.getY();
    float vx= proyectil.getVX();
    float vy=proyectil.getVY();
    float r= proyectil.getRadio();
    //rebotes
    if(x-r<=0.0f){
        proyectil.setX(r);
        proyectil.setVX(-vx);
        rebotes ++;

    }else if(x+r>=740.0f){
        proyectil.setX(740.0f-r);
        proyectil.setVX(-vx);
        rebotes ++;

    }

    if(y-r<=0.0f){
        proyectil.setY(r);
        proyectil.setVY(-vy);
        rebotes ++;

    }else if(y+r>=380.0f){
        proyectil.setY(380.0f-r);
        proyectil.setVY(-vy);
        rebotes ++;

    }
    graficobala->setPos(proyectil.getX()-r,proyectil.getY()-r);


    for(int i=0;i<barreras.size(); i++){
        if(barreras[i].estaderribada()){
            continue;
        }
        if(graficobala->collidesWithItem(iconos_barrera[i])){
            float v=sqrt(vx*vx+vy*vy);
            float danio=0.3f*proyectil.getMasa()*v;
            barreras[i].recibirataque(danio);
            textobarrera[i]->setPlainText(QString::number((int)barreras[i].getDureza()));

            if(barreras[i].estaderribada()){
                iconos_barrera[i]->hide();
                textobarrera[i]->hide();

            }
            proyectil.setX(x-vx*dt);
            proyectil.setY(y-vy*dt);
            float dibujoX=proyectil.getX()-r;
            float dibujoY=proyectil.getY()-r;
            graficobala->setPos(dibujoX, dibujoY);


            proyectil.setVX(-vx*0.5f);
            proyectil.setVY(-vy*0.5f);
            rebotes++;
            if(rebotes>=3){
                terminaturno();
            }
            break;
        }

    }
}

void MainWindow::terminaturno()
{
    timer->stop();
    dispaencurso=false;


    if(turnojugador==1){

        turnojugador=2;
        ui->lblTurno->setText("Turno Jugador 2");

    }else{
        turnojugador=1;
        ui->lblTurno->setText("Turno: Jugador 1");
    }
}

void MainWindow::agregarbarrera(float x, float y, float ancho, float alto, float dureza)
{


    barrera b(x,y, ancho,alto, dureza);
    barreras.push_back(b);
    QColor color=(dureza>=200.0f)?QColor(255,224,178):QColor(220, 220, 220);
    QGraphicsRectItem *rect=escena->addRect(x,y,ancho,alto, QPen(Qt::black),QBrush(color));
    iconos_barrera.push_back(rect);
    QGraphicsTextItem *texto=escena->addText(QString::number((int)dureza));
    texto->setPos(x+ancho/2-15,y+alto/2-10);
    textobarrera.push_back(texto);
}

