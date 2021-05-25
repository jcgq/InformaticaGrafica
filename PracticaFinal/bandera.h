#ifndef _BANDERA_H
#define _BANDERA_H

#include "objrevolucion.h"
#include "esfera.h"
#include "malla.h"
#include "cilindro.h"
#include "cubo.h"
#include "cono.h"
using namespace std;

class Bandera{

	private:
		Cilindro * baseGrande;
		Cilindro * basePequenia;
		Cilindro * palo;
		Esfera * punto;
        Cubo * tela;
		bool TN, TS;
		float moverTela=0.0, subirTela=0.0; 

		material * bronze = new material({0.2125f, 0.1275f, 0.054f, 1.0f},
								{0.714f, 0.4284f, 0.18144f, 1.0f},
								 {0.393548f, 0.271906f, 0.166721f, 1.0},  
								 0.2f);
		material * plateado = new material({0.19225f, 0.19225f, 0.19225f, 1.0f},
								{0.8624f, 0.0125f, 0.8584f, 1.0f},
								 {0.4f, 0.413f, 0.4f, 1.0},  
								 2.0f);
		material * blanco = new material({0.05f, 0.05f, 0.05f, 1.0f},
								{0.50754f, 0.50754f, 0.50754f, 1.0f},
								 {0.508273f, 0.508273f, 0.508273f, 1.0},  
								 0.4f);
		material * negro = new material({0.0f, 0.0f, 0.0f, 1.0f},
								{0.01f, 0.01f, 0.01f, 1.0f},
								 {0.5f, 0.5f, 0.5f, 1.0},  
								 0.25);			 
		
		bool topeBandera = false;
	public:
		Bandera();

		void dibujar(char modoDibujar, bool TN, bool TS);

		void izarBandera(float incremento);
};

#endif
