#include "objply.h"
#include "ply_reader.h"
 

// *****************************************************************************
//
// Clase ObjPLY (práctica 2)
//
// *****************************************************************************

ObjPLY::ObjPLY( const std::string & nombre_archivo )
{
   // leer la lista de caras y vértices
   ply::read( nombre_archivo, this->v, this->f );
	colorS.resize(this->v.size()*this->f.size());
	colorL.resize(this->v.size()*this->f.size());
	colorP.resize(this->v.size()*this->f.size());
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


