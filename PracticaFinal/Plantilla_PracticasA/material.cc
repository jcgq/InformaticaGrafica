
#include "material.h"

material::material(Tupla4f _ambiente, Tupla4f _difuso, Tupla4f _especular, float _brillo){
	brillo = _brillo;
	ambiente = _ambiente;
	difuso = _difuso;
	especular = _especular;
}

void material::aplicar(){
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambiente);
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, difuso);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, especular);
	glMaterialf(GL_FRONT, GL_SHININESS, brillo);
}

Tupla4f material::getDifuso(){
		return difuso;
}
Tupla4f material::getEspecular(){
	return especular;
}
Tupla4f material::getAmbiente(){
	return ambiente;
}

float material::getBrillo(){
	return brillo;
}

void material::setDifuso(Tupla4f _difuso){
	difuso=_difuso;
}
void material::setEspecular(Tupla4f _especular){
	especular = _especular;
}
void material::setAmbiente(Tupla4f _ambiente){
	ambiente = _ambiente;
}
void material::setBrillo(float _brillo){
	brillo = _brillo;
}
