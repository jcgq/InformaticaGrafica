#ifndef _ESCENA_H
#define _ESCENA_H

#include "ejes.h"
#include "malla.h"
#include "cubo.h"
#include "tetraedro.h"
#include "cilindro.h"
#include "cono.h"
#include "esfera.h"
#include "luz.h"
#include "luzPosicional.h"
#include "luzDireccional.h"
#include "objply.h"
#include "material.h"
#include "goomba.h"
#include "bandera.h"
#include "sistemasMonedas.h"
#include "camara.h"
#include "cuadro.h"

typedef enum {NADA, SELOBJETO,SELVISUALIZACION,SELDIBUJADO} menu;
class Escena{

   private:
   

 // ** PARÁMETROS DE LA CÁMARA (PROVISIONAL)
       
       // variables que definen la posicion de la camara en coordenadas polares
   GLfloat Observer_distance;
   GLfloat Observer_angle_x;
   GLfloat Observer_angle_y;

   // variables que controlan la ventana y la transformacion de perspectiva
   GLfloat Width, Height, Front_plane, Back_plane;

    // Transformación de cámara
	void change_projection();
	void change_observer();
    


   void clear_window();
	std::vector<bool> modoPintar={false, false, true, false, false, false};//Punto Linea Solido Ajedrez
   menu modoMenu=NADA;
   // Objetos de la escena
   Ejes ejes;
   Cubo * cubo = nullptr ; // es importante inicializarlo a 'nullptr'
   Tetraedro * tetraedro= nullptr ; // es importante inicializarlo a 'nullptr'
	Cilindro * cilindro = nullptr;
	Cono * cono = nullptr;
	Esfera * esfera = nullptr;
	bool pintar=false;
	float tamanioCubo = 0.0;
	bool opcionActivada=false;

	//Parte del Goomba
	bool aniAuto = false, aniManu = false;
	std::vector<bool> parteGombaMover={false, false, false};
	Goomba * goomba = nullptr;
	float variarAnimacionGoomba = 0.1;
	float cambiarGrados = 1.0;
	float moverBandera = 0.1;
	//Parte de la Bandera
	Bandera * bandera = nullptr;
	float saltoC1=0.1;
	//Sistema de Cubos
	sistemaMonedas * monedas = nullptr;
	float velocidad=0.5;




	bool TAPASUPERIOR=true, TAPAINFERIOR=true;
	

	//LUCES	
	std::vector<bool> interruptorLuz={true, true, true, true, true, true, true, true};
	bool iluminacion = false;
	luzPosicional * luzPos1 = nullptr;
	luzPosicional * luzPos2 = nullptr;
	luzPosicional * luzPos3 = nullptr;
	luzPosicional * luzPos4 = nullptr;
	luzPosicional * luzPos5 = nullptr;
	luzPosicional * luzPosAnimada = nullptr;
	luzDireccional * luzDir7 = nullptr;
	luzDireccional * luzDir8 = nullptr;
	float variarAnguloAlpha = 0.0, variarAnguloBeta = 0.0;
	bool alpha=false, beta=false;
	float variacionLuces = 0.5;
	bool animarLuzAnimada=false;

	//Materiales

	material * m1 = new material({0.05, 0.0, 0.0, 0.0},
								 {0.4, 0.5, 0.4, 0.0}, 
								 {0.04, 0.7, 0.04, 0.0}, 
								 0.78125);

	//Camaras
	int numCamaraActiva=0;
	const static int numCamaras = 4;
	std::vector<bool> camaraActiva={false, false, false, false};
	std::vector<Camara> cam;
	bool activoCamara=false;
	
	Camara * cam0 = nullptr;
	Camara * cam1 = nullptr;
	Camara * cam2 = nullptr;
	Camara * cam3 = nullptr;
	


	//Textura
	textura * text1 = nullptr;
	textura * text2 = nullptr;
	Cuadro * cuadro1 = nullptr;

	int contador = 0;
	
   
   public:

    Escena();
	int xant = 0, yant = 0;
	int raton=0;
	void inicializar( int UI_window_width, int UI_window_height );
	void redimensionar( int newWidth, int newHeight ) ;
	void aniadirFiguras(unsigned char modoPintar);
	// Dibujar
	void dibujar() ;
	void animacion();
	void animarPies();
	void animarCabeza();
	void animarOjos();
	void variarLuces(float incremento);
	void animacionDeLasLuces();
	// Interacción con la escena
	bool teclaPulsada( unsigned char Tecla1, int x, int y ) ;
	void teclaEspecial( int Tecla1, int x, int y );
	void mover(int x, int y);
	void ratonMovido(int x, int y);

	bool moverse=false;
	
};
#endif
