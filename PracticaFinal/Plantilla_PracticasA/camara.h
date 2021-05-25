#ifndef CAMARA_H_INCLUDED
#define CAMARA_H_INCLUDED

#include "aux.h"

class Camara{
	private:
		Tupla3f eye;
        	Tupla3f at;
        	Tupla3f up;
        	int tipo;//Perspectiva(0) o Ortogonal(1)

	public:
		Camara(Tupla3f eye, Tupla3f at, Tupla3f up, int tipo, float left, float right, float near, float far, float top, float bottom);
       		void rotarXExaminar(float angle);
        	void rotarYExaminar(float angle);
        	void rotarZExaminar(float angle);
        	void rotarXFirstPerson(float angle);
        	void rotarYFirstPerson(float angle);
        	void rotarZFirstPerson(float angle);
        	void mover(float x, float y, float z);
        	void zoom(float factor, float left, float rigth, float top, float bottom);
        	void setObserver();
        	void setProyeccion();
			float getLeft();
			float getRight();
        	float left, right, near, far, top, bottom;

};
#endif
