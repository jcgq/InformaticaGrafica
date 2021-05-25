#ifndef OBJREVOLUCION_H_INCLUDED
#define OBJREVOLUCION_H_INCLUDED

#include "aux.h"
#include "malla.h"
#include "cmath"
#include "ply_reader.h"

// *****************************************************************************
//
// clases derivadas de Malla3D (definen constructores específicos)
//
// *****************************************************************************

// *****************************************************************************
// Cubo con centro en el origen y lado unidad por defecto
// (tiene 9 vertices y 6 caras)

class ObjRevolucion : public Malla3D
{
   public:
	bool Tapa_Norte;
     	bool Tapa_Sur;

	ObjRevolucion();
	ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true) ;
	ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup=true, bool tapa_inf=true) ;
   
	void draw(char modo, char vis, bool tn, bool ts) ; //redefinicion
	void draw_ModoAjedrez( bool tn, bool ts); //redefinicion
	void draw_ModoInmediato( bool tn, bool ts); //redefinicion
private:
    	int numero_instancias;
	void crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias);
protected:
	void crearMalla(const std::vector<Tupla3f> &perfil_original, const int num_instancias_perf, const bool conTapas);
} ;




#endif
