#ifndef BALA_H
#define BALA_H

class bala
{

private:
    float x;
    float y;
    float VX;
    float VY;
public:

    bala(float x = 0.0f, float y = 0.0f, float vx = 10.0f, float vy = 10.0f);
    float getX();
    float getY();
    float getVX();
    float getVY();
    void setX(float x);
    void setY(float y);
    void setVX(float vx);
    void setVY(float vy);
    bala();
};

#endif // BALA_H
