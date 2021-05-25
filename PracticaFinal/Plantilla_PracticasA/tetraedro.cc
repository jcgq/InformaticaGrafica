#include "aux.h"
#include "malla.h"
#include "tetraedro.h"

Tetraedro::Tetraedro()
{

   // inicializar la tabla de vértices
	v.resize(4);
    	f.resize(4);
	colorS.resize(4);
	colorL.resize(4);
	colorP.resize(4);

   
    
   // inicializar la tabla de caras o triángulos:
   // (es importante en cada cara ordenar los vértices en sentido contrario
   //  de las agujas del reloj, cuando esa cara se observa desde el exterior del cubo)
	
    v[0] = Tupla3f(-70,-70,-70);
    v[1] = Tupla3f(0,-70,70);
    v[2] = Tupla3f(70,-70,-70);
    v[3] = Tupla3f(0,70,0);
	
    	f[0] = Tupla3i{0,1,3};
    	f[1] = Tupla3i{1,2,3};
    	f[2] = Tupla3i{2,0,3};
	f[3] = Tupla3i{0,2,1};


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


void Tetraedro::setTextura(textura *_textura){
    textu =_textura;
    ct.resize(v.size());
    ct[0] = {1,1};
    ct[1] = {1,0};
    ct[2] = {0,0};
    ct[3] = {0,1};
}
