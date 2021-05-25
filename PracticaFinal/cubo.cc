#include "aux.h"
#include "malla.h"
#include "cubo.h"

Cubo::Cubo(float lado){
	v.resize(8);
	f.resize(12);	
	colorS.resize(8);
	colorL.resize(8);
	colorP.resize(8);

	v[0]= Tupla3f(-lado, -lado, lado);
   	v[1]= Tupla3f(lado, -lado, lado);
   	v[2]= Tupla3f(lado, lado, lado);
   	v[3]= Tupla3f(-lado, lado, lado);
   	v[4]= Tupla3f(-lado, -lado, -lado);
   	v[5]= Tupla3f(lado, -lado, -lado);
   	v[6]= Tupla3f(lado, lado, -lado);
   	v[7]= Tupla3f(-lado, lado, -lado);
   

   	f[0]= Tupla3i(0,2,3);
   	f[1]= Tupla3i(0,1,2);
   	f[2]= Tupla3i(1,6,2);
   	f[3]= Tupla3i(1,5,6);
   	f[4]= Tupla3i(5,7,6);
   	f[5]= Tupla3i(5,4,7);
   	f[6]= Tupla3i(4,3,7);
   	f[7]= Tupla3i(4,0,3);
   	f[8]= Tupla3i(3,6,7);
   	f[9]= Tupla3i(3,2,6);
   	f[10]= Tupla3i(4,5,0);
   	f[11]= Tupla3i(5,1,0);
	
	establecerColorS(0.0, 0.0, 100.0);
	establecerColorL(100.0, 0.0, 0.0);
	establecerColorP(0.0, 100.0, 0.0);
	calcular_normales();
}