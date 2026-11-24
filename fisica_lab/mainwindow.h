#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QTimer>
#include <vector>
#include "bala.h"
#include "barrera.h"
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btndisparar_clicked();
    void actualizarFisica();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QTimer *timer;
    bala proyectil;
    QGraphicsEllipseItem *graficobala;
    vector<barrera>barreras;
    vector<QGraphicsRectItem*>iconos_barrera;


    bool dispaencurso;
    int turnojugador;
   void agregarbarrera(float x, float y, float ancho, float alto, float dureza);

};
#endif // MAINWINDOW_H
