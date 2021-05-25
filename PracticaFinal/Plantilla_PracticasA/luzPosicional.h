#ifndef LUZPOSICIONAL_H_INCLUDED
#define LUZPOSICIONAL_H_INCLUDED

#include <iostream>
#include <vector>
#include "luz.h"
class luzPosicional: public luz{

public:
	luzPosicional(Tupla3f posicion, GLenum id, Tupla4f colorAmbiental, Tupla4f colorDifuso, Tupla4f colorEspecular);
	void animarLuz(float incremento);
	void changeAmbiental(float x, float y);
};
#endif
