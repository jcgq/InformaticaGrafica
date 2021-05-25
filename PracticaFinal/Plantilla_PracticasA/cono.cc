#include "aux.h"
#include "objrevolucion.h"
#include "cono.h"

Cono::Cono(const int num_vert_perfil, const int num_instancias_perf, const float h, const float r){
	altura=h;
	radio=r;

	std::vector<Tupla3f> p_original;
	
	p_original.push_back( Tupla3f(0.0, 0.0, 0.0) );
	p_original.push_back( Tupla3f(radio, 0.0, 0.0) );
	p_original.push_back( Tupla3f(0.0, altura, 0.0) );

	crearMalla(p_original, num_instancias_perf, false);
	colorS.resize(num_instancias_perf*p_original.size());
	colorL.resize(num_instancias_perf*p_original.size());
	colorP.resize(num_instancias_perf*p_original.size());
	establecerColorS(1.0, 1.0, 1.0);
	establecerColorL(100.0, 0.0, 0.0);
	establecerColorP(0.0, 100.0, 0.0);
	calcular_normales();
}
