// #############################################################################
//
// Informática Gráfica (Grado Informática)
//
// Archivo: Malla3D.h
// -- declaraciones de clase Malla3D (mallas indexadas) y derivados
//
// #############################################################################

#ifndef MALLA3D_H_INCLUDED
#define MALLA3D_H_INCLUDED

#include "aux.h"
#include "material.h"
#include "textura.h"
#include "jpg_imagen.hpp"


// *****************************************************************************
//
// clase para objetos 3D (mallas indexadas)
//
// *****************************************************************************

class Malla3D{

   public:
	GLuint CrearVBO( GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram );
   // dibuja el objeto en modo inmediato
   void draw_ModoInmediato();

   // dibuja el objeto en modo diferido (usando VBOs)
   void draw_ModoDiferido();
	void calcular_normales() ; // calcula tabla de normales de vértices (práctica 3)
   //dibuja en modo ajedrez
	void draw_ajedrez();
	void dibujar_normales();
   // está función llama a 'draw_ModoInmediato' (modo inmediato)
   // o bien a 'draw_ModoDiferido' (modo diferido, VBOs)
   void draw(unsigned char a) ;
	bool puedoAcceder=false;
	unsigned char modoAoD='i';

	void establecerColorS(float cr, float cg, float cb);
	void establecerColorActivo(unsigned char modo);
	void establecerColorP(float cr, float cg, float cb);
	void establecerColorL(float cr, float cg, float cb);
	void setMaterial(material *mat);
	void setTextura(textura *tex);
        material *m = nullptr;
	std::vector<Tupla3f> nv ; //Vector de normales de los vertices
	std::vector<Tupla2f> ct;

   protected:

   
	textura * textu = nullptr;
   	std::vector<Tupla3f> v ;   // tabla de coordenadas de vértices (una tupla por vértice, con tres floats)
   	std::vector<Tupla3i> f ; // una terna de 3 enteros por cada cara o triángulo

	

	GLuint id_vbo_v=0;
	GLuint id_vbo_f=0;
	unsigned char vengoDe='i';
	
	std::vector<Tupla3i> caraPar;
	std::vector<Tupla3i> caraImpar;
	Tupla3f * activacionColor = nullptr;
	std::vector<Tupla3f> colorS;
	std::vector<Tupla3f> colorP;
	std::vector<Tupla3f> colorL;
	

   // completar: tabla de colores, tabla de normales de vértices

	private:
} ;


#endif
