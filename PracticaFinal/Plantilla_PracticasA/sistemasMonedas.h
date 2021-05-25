#ifndef SISTEMAMONEDAS_H_INCLUDED
#define SISTEMAMONEDAS_H_INCLUDED

#include "aux.h"
#include "cubo.h"
#include "malla.h"
#include "esfera.h"


class sistemaMonedas{

public:
    Esfera * esf2 = nullptr;
    Esfera * esf3 = nullptr;
    Esfera * esf1 = nullptr;
    float salto = 0.0;
    bool TN, TS;
    sistemaMonedas();
    void dibujar(char modoPintar, bool tn, bool ts);
    void saltar(float incremento);

    

    material * oro = new material({0.135f, 0.2225f, 0.1575f, 1.0f},
								{0.54f, 0.89f, 0.63f, 1.0f},
								 {0.316228f, 0.316228f, 0.316228f, 1.0f},  
								 0.1f);	 
};




#endif