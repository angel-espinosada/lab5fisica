#ifndef BALA_H
#define BALA_H

class bala
{

private:
    float x;
    float y;
    float VX;
    float VY;
    float masa;
    float radio;
public:

    bala(float x = 0.0f, float y = 0.0f, float vx = 10.0f, float vy = 10.0f, float masa=1.0f, float radio=10.0f);
    float getX();
    float getY();
    float getVX();
    float getVY();
    void setX(float x);
    void setY(float y);
    void setVX(float vx);
    void setVY(float vy);
    float getMasa();
    float getRadio();
    void setMasa(float masa);
    void setRadio(float radio);
    void actualizarPosicion(float dt, float g);

};

#endif // BALA_H
