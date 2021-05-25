#include "aux.h"
#include "malla.h"
#include "cuadro.h"

Cuadro::Cuadro(float lado){
	v.resize(4);
	f.resize(2);	
	colorS.resize(4);
	colorL.resize(4);
	colorP.resize(4);

	v[0]= Tupla3f(-lado, -lado, 0);
   	v[1]= Tupla3f(lado, -lado, 0);
   	v[2]= Tupla3f(lado, lado, 0);
   	v[3]= Tupla3f(-lado, lado, 0);
   

   	f[0]= Tupla3i(0,2,3);
   	f[1]= Tupla3i(0,1,2);
	
	establecerColorS(0.0, 0.0, 100.0);
	establecerColorL(100.0, 0.0, 0.0);
	establecerColorP(0.0, 100.0, 0.0);

    calcular_normales();
}


void Cuadro::setTextura(textura *_textura){
    textu =_textura;
    ct.resize(v.size());
    ct[0] = {1,1};
    ct[1] = {1,0};
    ct[2] = {0,0};
    ct[3] = {0,1};
}