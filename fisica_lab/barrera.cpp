#include "barrera.h"



barrera::barrera(float x, float y, float ancho, float alto, float dureza)
{
    this->x=x;
    this->y=y;
    this->ancho=ancho;
    this->alto=alto;
    this->dureza=dureza;
}

float barrera::getX()
{
    return x;
}

float barrera::getY()
{
    return y;
}

float barrera::getAncho()
{
    return ancho;
}

float barrera::getAlto()
{
    return alto;
}

float barrera::getDureza()
{
    return dureza;
}

void barrera::recibirataque(float danio)
{
    dureza=dureza-danio;
    if(dureza<0.0f){
        dureza=0.0f;
    }
}

bool barrera::estaderribada()
{
    return dureza<=0.0f;
}
