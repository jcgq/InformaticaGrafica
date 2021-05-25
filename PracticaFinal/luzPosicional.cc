#include "luzPosicional.h"
#include "luz.h"


luzPosicional::luzPosicional(Tupla3f _posicion, GLenum id, Tupla4f colorAmbiental, Tupla4f colorDifuso, Tupla4f colorEspecular): 
luz(id, {_posicion[0], _posicion[1], _posicion[2],  1.0}, colorAmbiental, colorDifuso, colorEspecular) {

}


void luzPosicional::animarLuz(float incremento){
    this->changeAmbiental(incremento, -incremento);
}


void luzPosicional::changeAmbiental(float x, float y){
    colorAmbiente[0]+= x;
    std::cout << "Color Ambiente vale " << colorAmbiente[0] << std::endl;
    //posicion[1]=
    if(colorAmbiente[0]>=6.0){
        colorAmbiente[0]=0.0;
    }
    colorAmbiente[2] += y;
    if(colorAmbiente[2]>=6.0){
        colorAmbiente[2]=0.0;
    }
}