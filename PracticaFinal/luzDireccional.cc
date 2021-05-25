#include "luzDireccional.h"
#include "luz.h"
#include <cmath>

luzDireccional::luzDireccional(Tupla3f _posicion, GLenum id, Tupla4f colorAmbiental, Tupla4f colorDifuso, Tupla4f colorEspecular) : 
luz(id, {_posicion[0], _posicion[1], _posicion[2],  1.0}, colorAmbiental, colorDifuso, colorEspecular){
	alpha = beta = 0;
}


void luzDireccional::variarAnguloAlpha(float incremento){
	alpha = alpha+incremento;
	if(alpha>=360){
		alpha = alpha-360;
	}
	posicion=Tupla4f({cos(alpha)*cos(beta),cos(alpha)*sin(beta),sin(alpha), 0.0});
	this->cambiarPosicion();
}

void luzDireccional::variarAnguloBeta(float incremento){
	beta = beta+incremento;
	if(beta>=360){
		beta = beta-360;
	}
	posicion=Tupla4f({cos(alpha)*cos(beta),cos(alpha)*sin(beta),sin(alpha), 0.0});
	this->cambiarPosicion();
}
