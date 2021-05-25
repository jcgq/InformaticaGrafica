#ifndef MATERIAL_H_INCLUDED
#define MATERIAL_H_INCLUDED

#include "tuplasg.h"
#include "aux.h"

class material{


private:
	float brillo;
	Tupla4f ambiente;
	Tupla4f difuso;
	Tupla4f especular;
public:
	void aplicar();
	material(Tupla4f ambiente, Tupla4f difuso, Tupla4f especular, float brillo);
	Tupla4f getDifuso();
	Tupla4f getEspecular();
	Tupla4f getAmbiente();
	float getBrillo();

	void setDifuso(Tupla4f difuso);
	void setEspecular(Tupla4f especular);
	void setAmbiente(Tupla4f ambiental);
	void setBrillo(float brillo);

};
#endif
