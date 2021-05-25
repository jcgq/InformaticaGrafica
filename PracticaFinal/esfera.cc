#include "esfera.h"
#include <vector>
#include "aux.h"
#include "objrevolucion.h"

Esfera::Esfera(const int num_vert_perfil, const int num_instancias_perf, const float r){
    radio=r;
    float angulo,x,y;

    std::vector<Tupla3f> p_original;
using namespace std;

    Tupla3f vertice;
    //primer punto
    p_original.push_back(Tupla3f(0,-radio,0));

    //puntos intermedios
    for(int i=1; i<num_instancias_perf; i++){
        angulo=i*(180/num_instancias_perf);
        angulo+=270;
        vertice(X)=radio*cos(angulo*M_PI/180);
        vertice(Y)=radio*sin(angulo*M_PI/180);
        vertice(Z)=0.0;
        p_original.push_back(vertice);
    }

    //ultimo punto
    p_original.push_back(Tupla3f(0,radio,0));

    crearMalla(p_original, num_instancias_perf, false);

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
