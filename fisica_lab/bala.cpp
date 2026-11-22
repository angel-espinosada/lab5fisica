#include "bala.h"

bala::bala(float x, float y, float vx, float vy)
{
    this->x=x;
    this->y=y;
    this->VX=vx;
    this->VY=vy;
}

bala::bala() {}
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
