// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Cono.h

//
// #############################################################################

#ifndef CONO_H_INCLUDED
#define CONO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

// *****************************************************************************
//
// clases derivadas de ObjRevolucion (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// CONO 

class Cono : public ObjRevolucion{

   public:
   Cono(const int num_vert_perfil, const int num_instancias_perf, const float h, const float r) ;
	private:
	float altura;
	float radio;
} ;




#endif
