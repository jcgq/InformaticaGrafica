#include "aux.h"
#include "objrevolucion.h"
#include "cilindro.h"

Cilindro::Cilindro(const int num_vert_perfil, const int num_instancias_perf, const float h, const float r){
	altura=h;
	radio=r;

	std::vector<Tupla3f> p_original;
	p_original.push_back( Tupla3f(0.0, altura, 0.0) );
	
	p_original.push_back( Tupla3f(radio, altura, 0.0) );

	p_original.push_back( Tupla3f(radio, -altura, 0.0) );
	
	p_original.push_back( Tupla3f(0.0, -altura, 0.0) );
	
	
	
	/*for(int i=0; i<p_original.size(); i++)
		std::cout << "LALALA" << p_original[i] << std::endl;
	std::cout << "CREANDO CILINDRO" << std::endl;*/
	crearMalla(p_original, num_instancias_perf, false);
	//std::cout << "CREE YA LA MALLA" << std::endl;
	colorS.resize(num_instancias_perf*p_original.size());
	colorL.resize(num_instancias_perf*p_original.size());
	colorP.resize(num_instancias_perf*p_original.size());
	int R, G, B;
	R = rand()%255;
	G = rand()%255;
	B = rand()%255;
	establecerColorS(R/255.0, G/255.0, B/255.0);
	R = rand()%255;
	G = rand()%255;
	B = rand()%255;
	establecerColorL(R/255.0, G/255.0, B/255.0);
	R = rand()%255;
	G = rand()%255;
	B = rand()%255;
	establecerColorP(R/255.0, G/255.0, B/255.0);
	calcular_normales();
}
