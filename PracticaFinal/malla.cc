#include "aux.h"
#include "malla.h"
#include <stdlib.h>
#include <iostream>
#include "textura.h"

using namespace std;

// *****************************************************************************
//
// Clase Malla3D
//
// *****************************************************************************

// Visualización en modo inmediato con 'glDrawElements'

void Malla3D::draw_ModoInmediato(){
//	std::cout << "MODO INMEDIATO " << std::endl;
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, v.data());

	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, nv.data());

	if(textu!=nullptr){
		textu->activar();
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, ct.data());
	}
	if(glIsEnabled(GL_LIGHTING)){
		if(m!=nullptr){
			m->aplicar();
		}
	}
	else{
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, &this->activacionColor[0]);
		//glDisable(GL_TEXTURE_2D);
	}
	glDrawElements(GL_TRIANGLES, f.size()*3,GL_UNSIGNED_INT, f.data());

	glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);
	glDisable(GL_TEXTURE_2D);
}
// -----------------------------------------------------------------------------
// Visualización en modo diferido con 'glDrawElements' (usando VBOs)

GLuint Malla3D::CrearVBO( GLuint tipo_vbo, GLuint tamanio_bytes, GLvoid * puntero_ram ){
	GLuint id_vbo ; // resultado: identificador de VBO
	glGenBuffers( 1, & id_vbo ); // crear nuevo VBO, obtener identificador (nunca 0)
	glBindBuffer( tipo_vbo, id_vbo ); // activar el VBO usando su identificador

	// esta instrucción hace la transferencia de datos desde RAM hacia GPU
	glBufferData( tipo_vbo, tamanio_bytes, puntero_ram, GL_STATIC_DRAW );
	glBindBuffer( tipo_vbo, 0 ); // desactivación del VBO (activar 0)
	return id_vbo ;	// devolver el identificador resultado
}

void Malla3D::draw_ModoDiferido(){
   	// (la primera vez, se deben crear los VBOs y guardar sus identificadores en el objeto)
   	// completar (práctica 1)
	glEnableClientState(GL_NORMAL_ARRAY);
	glNormalPointer(GL_FLOAT, 0, nv.data());
	if(id_vbo_v==0)
		id_vbo_v = CrearVBO(GL_ARRAY_BUFFER, 3*v.size()*sizeof(float),v.data());
	if(id_vbo_f==0)
		id_vbo_f = CrearVBO(GL_ELEMENT_ARRAY_BUFFER, 3*f.size()*sizeof(unsigned int), f.data());
	if(textu!=nullptr){
		textu->activar();
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glTexCoordPointer(2, GL_FLOAT, 0, ct.data());
	}
	if(glIsEnabled(GL_LIGHTING)){
		if(m!=nullptr){
			m->aplicar();
		}
	}
	else{
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, &this->activacionColor[0]);
		//glDisable(GL_TEXTURE_2D);
	}
	glBindBuffer( GL_ARRAY_BUFFER, id_vbo_v ); // activar VBO de vértices
	glVertexPointer( 3, GL_FLOAT, 0, 0 ); // especifica formato y offset (=0)
	glBindBuffer( GL_ARRAY_BUFFER, 0 ); // desactivar VBO de vértices.
	glEnableClientState( GL_VERTEX_ARRAY ); // habilitar tabla de vértices

	// visualizar triángulos con glDrawElements (puntero a tabla == 0)
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, id_vbo_f );// activar VBO de triángulos
	glDrawElements( GL_TRIANGLES, 3*f.size(), GL_UNSIGNED_INT, 0 ) ;
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, 0 ); // desactivar VBO de triángulos

	// desactivar uso de array de vértices
	glDisableClientState( GL_VERTEX_ARRAY );
}
// -----------------------------------------------------------------------------
// Función de visualización de la malla,
// puede llamar a  draw_ModoInmediato o bien a draw_ModoDiferido

void Malla3D::draw(unsigned char a){
	char h='i';
	glEnableClientState(GL_COLOR_ARRAY);
	if(a=='a'){
		this->draw_ajedrez();
	}
	else{
		if(a=='p')
			activacionColor=&colorP[0];
		if(a=='l')
			activacionColor=&colorL[0];
		if(a=='s')
			activacionColor=&colorS[0];	
	}

	if(h=='d'){
		draw_ModoDiferido();	
	}
	if(h=='i'){		
		draw_ModoInmediato();
	}

}


void Malla3D::draw_ajedrez(){

	for(int i=0; i<f.size(); i++){
		if(i%2==0)
			caraPar.push_back(f[i]);
		
		else
			caraImpar.push_back(f[i]);
	}
	establecerColorP(0.1,0.1,0.1);
	glVertexPointer(3, GL_FLOAT, 0, v.data());
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glShadeModel(GL_FLAT);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(3, GL_FLOAT, 0, v.data());
	glColorPointer(3, GL_FLOAT, 0, colorP.data());
	glDrawElements( GL_TRIANGLES, 3*caraPar.size(), GL_UNSIGNED_INT, caraPar.data() ) ;
	glColorPointer(3, GL_FLOAT, 0, colorL.data());
	glDrawElements( GL_TRIANGLES, 3*caraImpar.size(), GL_UNSIGNED_INT, caraImpar.data() ) ;

}


	void Malla3D::establecerColorS(float cr, float cg, float cb){
		for(int i=0; i<colorS.size(); i++)
			colorS[i]=Tupla3f(cr, cg, cb);
	}

	void Malla3D::establecerColorP(float cr, float cg, float cb){
		for(int i=0; i<colorP.size(); i++)
			colorP[i]=Tupla3f(cr, cg, cb);
	}

	void Malla3D::establecerColorL(float cr, float cg, float cb){
		for(int i=0; i<colorL.size(); i++)
			colorL[i]=Tupla3f(cr, cg, cb);
	}

	void Malla3D::establecerColorActivo(unsigned char modo){
		activacionColor=&colorP[0];
		if(modo=='p')
			activacionColor=&colorP[0];
		if(modo=='l'){
			activacionColor=&colorL[0];
		}
		if(modo=='s'){
			activacionColor=&colorS[0];
		}
	}

void Malla3D::calcular_normales(){
	Tupla3f p, q, r, a, b, w;
	std::vector<Tupla3f> nc;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
//Calculamos las normales de las caras
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
	for(int i=0; i<f.size(); i++){
		p=v[f[i](X)];
		q=v[f[i](Y)];
		r=v[f[i](Z)];
		
		a=q-p;
		b=r-p;
		
		w=a.cross(b); //Calculamos el producto vectorial
		a=w.normalized();
		nc.push_back(a); //Aniadimos el vector unitario al vector de normales y normalizamos
	}
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
//Calculamos las normales de cada vértice
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
	nv.resize(v.size());
	for(int i=0; i<f.size();i++){
		nv[f[i](X)]=nv[f[i](X)]+nc[i];
		nv[f[i](Y)]=nv[f[i](Y)]+nc[i];
		nv[f[i](Z)]=nv[f[i](Z)]+nc[i];
	}	
 	for(int i=0; i<nv.size(); i++){
		 nv[i]=nv[i].normalized();
	 }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	
//Normalizamos el vector de normales de los puntos
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++	

}

void Malla3D::setMaterial(material *mat){
	m=mat;
}

void Malla3D::setTextura(textura *tex){
	textu = tex;
}









