#ifndef LUZ_H_INCLUDED
#define LUZ_H_INCLUDED

#include "tuplasg.h"
#include "aux.h"

class luz{


protected:
	GLenum id;
	Tupla4f posicion;
	Tupla3f colorAmbiente;
	Tupla3f colorDifuso;
	Tupla3f colorEspecular;
	int brillo;
public:
        luz(GLenum n, Tupla4f p, Tupla4f amb, Tupla4f dif, Tupla4f esp);
        void activar();

        void setAmbiental();
        void setDifusa();
        void setEspecular();
        void cambiarPosicion();
        void setDireccional();
        void setPuntual();
        void setBrillo(int grado);

        Tupla3f getAmbiental();
        Tupla3f getDifusa();
        Tupla3f getEspecular();
        int getBrillo();
        Tupla4f getPos();
};

#endif
