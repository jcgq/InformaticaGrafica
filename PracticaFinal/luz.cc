#include "luz.h"
#include "tuplasg.h"


luz::luz(GLenum n, Tupla4f p, Tupla4f amb, Tupla4f dif, Tupla4f esp) {
	id = n;
	posicion = p;
	colorAmbiente = amb;
	colorDifuso = dif;
	colorEspecular = esp;
	brillo = 20;
}

void luz::activar() {
	glEnable(GL_LIGHTING);
	glEnable(id);
	setAmbiental();
	setDifusa();
	setEspecular();
	cambiarPosicion();
}


void luz::setAmbiental() {
    glLightfv(id, GL_AMBIENT, colorAmbiente);
}
void luz::setDifusa() {
    glLightfv(id, GL_DIFFUSE, colorDifuso);
}
void luz::setEspecular() {
    glLightfv(id, GL_SPECULAR, colorEspecular);
}
void luz::cambiarPosicion(){
    glLightfv(id, GL_POSITION, posicion);
}
void luz::setDireccional() {
    posicion[3] = 0.0;
}
void luz::setPuntual() {
    posicion[3] = 1.0;
}

void luz::setBrillo(int grado) {
    brillo = grado;
    glLightf(id, GL_SHININESS, brillo);
}

Tupla3f luz::getAmbiental() {return colorAmbiente;
}

Tupla3f luz::getDifusa() {return colorAmbiente;}

Tupla3f luz::getEspecular() {return colorEspecular;}

int luz::getBrillo() {return brillo;}

Tupla4f luz::getPos() {return posicion;}
