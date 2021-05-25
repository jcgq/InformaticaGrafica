#ifndef _GOOMBA_H
#define _GOOMBA_H

#include "objrevolucion.h"
#include "esfera.h"
#include "malla.h"
#include "cilindro.h"
#include "cono.h"
using namespace std;

class Goomba{

	private:
		Cilindro * cuerpo;
		Esfera * cabeza;
		Esfera * ojo;
		Esfera * pupila;
		Cilindro * pie;
		Cilindro * ceja;
		Cilindro * boca;
		Cono * diente;
		Cilindro * base;
		Esfera * oreja;
		bool TN, TS;
		bool topeCabeza = false;
		bool topeOjo = false;
		bool topePie = false;

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
		
		
	public:
		Goomba();
		float rotarOjo = 0.0, rotarCabeza = 0.0, rotarPies = 0.0, andar=0.0;
		void dibujar(char modoDibujar, bool tn, bool ts);
		void dibujarOjo(char modoDibujar);
		void dibujarOreja(char modoDibujar);
		void dibujarCuerpo(char modoDibujar);
		void dibujarCabeza(char modoDibujar);
		void dibujarBoca(char modoDibujar);
		void dibujarPata(char modoDibujar);
		void dibujarCeja(char modoDibujar);
		void moverOjos(float incremento);
		void moverCabeza(float incremento);
		void moverPies(float incremento);
		void caminar(float incremento);
		void animarGoomba(float incremento);
};

#endif
