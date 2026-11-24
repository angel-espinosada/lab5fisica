#ifndef BARRERA_H
#define BARRERA_H

class barrera
{

private:
    float x;
    float y;
    float ancho;
    float alto;
    float dureza;
public:
    barrera(float x=0.0f, float y=0.0f, float ancho= 50.0f, float alto=50.0f, float dureza= 100.0f);

   float getX();
    float getY();
    float getAncho();
   float  getAlto();
   float  getDureza();
    void recibirataque(float danio);
    bool estaderribada();

};

#endif // BARRERA_H
