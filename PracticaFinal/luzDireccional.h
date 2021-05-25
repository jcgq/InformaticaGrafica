#ifndef LUZDIRECCIONAL_H_INCLUDED
#define LUZDIRECCIONAL_H_INCLUDED
#include <iostream>
#include <vector>
#include "luz.h"
class luzDireccional: public luz{


protected:
	float alpha;
	float beta;

public:
	luzDireccional(Tupla3f posicion, GLenum id, Tupla4f colorAmbiental, Tupla4f colorDifuso, Tupla4f colorEspecular);

	void variarAnguloAlpha(float incremento);
	void variarAnguloBeta(float incremento);

};
#endif
