#include "bala.h"

bala::bala(float x, float y, float vx, float vy, float masa, float radio)
{
    this->x=x;
    this->y=y;
    this->VX=vx;
    this->VY=vy;
    this ->masa=masa;
    this->radio=radio;

}

float bala ::getX() {
    return x;
}

float bala::getY() {
    return y;
}

float bala::getVX() {
    return VX;
}

float bala::getVY() {
    return VY;
}

void bala::setX(float x) {
    this->x = x;
}

void bala::setY(float y) {
    this->y = y;
}

void bala::setVX(float vx) {
    this->VX = vx;
}

void bala::setVY(float vy) {
    this->VY = vy;
}

float bala::getMasa()
{
    return masa;
}

float bala::getRadio()
{
    return radio;
}

void bala::setMasa(float masa)
{
    this->masa=masa;

}

void bala::setRadio(float radio)
{
    this->radio=radio;
}

void bala::actualizarPosicion(float dt, float g)
{
    x=x+VX*dt;
    y=y+VY*dt+0.5f*g*dt*dt;
    VY=VY+g*dt;
}
