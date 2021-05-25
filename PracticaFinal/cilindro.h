// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: cilindro.h

//
// #############################################################################

#ifndef CILINDRO_H_INCLUDED
#define CILINDRO_H_INCLUDED

#include "aux.h"
#include "objrevolucion.h"

// *****************************************************************************
//
// clases derivadas de ObjRevolucion (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// CILINDRO 

class Cilindro : public ObjRevolucion{

   public:
   Cilindro(const int num_vert_perfil=2, const int num_instancias_perf=20, const float h=1.0, const float r=1.0) ;
	
   private:
	float altura;
	float radio;
} ;




#endif
