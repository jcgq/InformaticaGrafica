#include "aux.h"// includes de OpenGL/glut/glew, windows, y librería std de C++
#include "escena.h"
#include "malla.h" // objetos: Cubo y otros....
#include "luz.h"

#include "camara.h"
#include "material.h"


using namespace std;

//**************************************************************************
// constructor de la escena (no puede usar ordenes de OpenGL)
//**************************************************************************




Escena::Escena(){
    Front_plane       = 50.0;
    Back_plane        = 2000.0;
    Observer_distance = 4*Front_plane;
    Observer_angle_x  = 0.0 ;
    Observer_angle_y  = 0.0 ;

    ejes.changeAxisSize( 5000 );

    // crear los objetos de la escena....
		tetraedro = new Tetraedro();
    	cubo = new Cubo(50);
		goomba=new Goomba();
		bandera=new Bandera();
		monedas=new sistemaMonedas();
	
	//Luces
luzPos1=new luzPosicional({250, 0, 0}, GL_LIGHT0, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
//luzPos2=new luzPosicional({-250, 0, 0}, GL_LIGHT1, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
luzPos2=new luzPosicional({-250, 0, 0}, GL_LIGHT1, {1,1,1,1}, {1,1,1,1}, {1,1,1,1});
luzPos3=new luzPosicional({0, 250, 0}, GL_LIGHT2, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
luzPos4=new luzPosicional({0, -250, 0}, GL_LIGHT3, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
luzPos5=new luzPosicional({0, 0, 250}, GL_LIGHT4, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
luzPosAnimada=new luzPosicional({0, 0, -250}, GL_LIGHT5, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
luzDir7=new luzDireccional({0, 50, 259}, GL_LIGHT6, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
luzDir8=new luzDireccional({259, 50, 0}, GL_LIGHT7, {0.24725, 0.1995, 0.0745, 0.6}, {0.75164, 0.60648, 0.22648, 0.0}, {0.628281, 0.555802, 0.366065, 0.0});
	
	//Camaras
	/*
	Camara * cam0 = new Camara({200.0, 100.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
	Camara * cam1 = new Camara({0.0, 100.0, 200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
	Camara * cam2 = new Camara({-200.0, 100.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 1, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
	Camara * cam3 = new Camara({0.0, 100.0, -200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 1, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
	*/

	cam0 = new Camara({0.0, 100.0, 200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 1.0, 450.0, 1.0,-1.0);
	cam1 = new Camara({100.0, 100.0, 200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
	cam2 = new Camara({0.0, 100.0, -200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);
	cam3 = new Camara({-100.0, 100.0, 200.0}, {0.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, 0, -1.0, 1.0, 0.5, 450.0, 1.0,-1.0);

	cam.push_back(*cam0);
	cam.push_back((*cam1));
	cam.push_back((*cam2));
	cam.push_back((*cam3));

	//Texture	
	cuadro1 = new Cuadro(1);
	text1 = new textura("bowser.jpg");
	text2 = new textura("piedraPiramide.jpg");
	cuadro1->setTextura(text1);
	tetraedro->setTextura(text2);
}

//**************************************************************************
// inicialización de la escena (se ejecuta cuando ya se ha creado la ventana, por
// tanto sí puede ejecutar ordenes de OpenGL)
// Principalmemnte, inicializa OpenGL y la transf. de vista y proyección
//**************************************************************************

void Escena::inicializar( int UI_window_width, int UI_window_height ){
	glClearColor( 1.0, 1.0, 1.0, 1.0 );// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable( GL_DEPTH_TEST );	// se habilita el z-bufer

	Width  = UI_window_width/10;
	Height = UI_window_height/10;

	change_projection();
	glViewport( 0, 0, UI_window_width, UI_window_height );
}
// **************************************************************************
//
// función de dibujo de la escena: limpia ventana, fija cámara, dibuja ejes, y dibuja los objetos
//
// **************************************************************************

void Escena::aniadirFiguras(unsigned char modoPintar){
		glPushMatrix();
			goomba->dibujar(modoPintar, TAPASUPERIOR, TAPAINFERIOR);
		glPopMatrix();
		glPushMatrix();
			bandera->dibujar(modoPintar, TAPASUPERIOR, TAPAINFERIOR);
		glPopMatrix();

		glPushMatrix();//Cubos
			glPushMatrix();
				glScalef(0.8,0.8,0.8);
				glTranslatef(0, 380, -250);
				cubo->draw(modoPintar);
			glPopMatrix();
			glPushMatrix();
				glScalef(0.8,0.8,0.8);
				glTranslatef(-100, 380, -250);
				cubo->draw(modoPintar);
			glPopMatrix();
			glPushMatrix();
				glScalef(0.8,0.8,0.8);
				glTranslatef(100, 380, -250);
				cubo->draw(modoPintar);
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//Sistema Monedas
			monedas->dibujar(modoPintar, TAPASUPERIOR, TAPAINFERIOR);
		glPopMatrix();

		glPushMatrix();//Cuadro Bowser
		glRotatef(90, 0, 1, 0);
			glTranslatef(0,200,-600);
			glScalef(200, 200, 200);
			cuadro1->draw(modoPintar);
		glPopMatrix();
		glPushMatrix();//Piramide Castillo
			glTranslatef(700, 360, 0);
			glScalef(5, 5, 5);
			tetraedro->draw(modoPintar);
		glPopMatrix();
		if(contador == 0){
			cout << endl;
	   		cout << "Puedes pulsar la V para activar el modo visualización "  << endl;
	   		cout << "Pulsa la R para activar la animacion automatica" << endl;
			cout << "Pulsa la M para activar la animacion manual" << endl;
			cout << "Pulsa la C para activar el modo Cámara" << endl;
			cout << "Pulse Q para salir del programa" << endl;
			contador=26;
   		}
		
	}

void Escena::dibujar(){
	glEnable(GL_NORMALIZE);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	
	change_observer();
	glLineWidth(3);
    	ejes.draw();
	glEnable(GL_CULL_FACE);
	if(iluminacion){
		if(interruptorLuz[0]){
				glEnable(GL_LIGHT0);
				luzPos1->activar();
		}
		else{
			glDisable(GL_LIGHT0);
		}
		if(interruptorLuz[1]){
				glEnable(GL_LIGHT1);
				luzPos2->activar();
		}
		else{
			glDisable(GL_LIGHT1);
		}
		if(interruptorLuz[2]){
				glEnable(GL_LIGHT2);
				luzPos3->activar();
		}
		else{
			glDisable(GL_LIGHT2);
		}
		if(interruptorLuz[3]){
				glEnable(GL_LIGHT3);
				luzPos4->activar();
		}
		else{
			glDisable(GL_LIGHT3);
		}
		if(interruptorLuz[4]){
				glEnable(GL_LIGHT4);
				luzPos5->activar();
		}
		else{
			glDisable(GL_LIGHT4);
		}
		if(interruptorLuz[5]){
				glEnable(GL_LIGHT5);
				luzPosAnimada->activar();
		}
		else{
			glDisable(GL_LIGHT5);
		}
		if(interruptorLuz[6]){
				glEnable(GL_LIGHT6);
				luzDir7->activar();
		}
		else{
			glDisable(GL_LIGHT6);
		}
		if(interruptorLuz[7]){
				glEnable(GL_LIGHT7);
				luzDir8->activar();
		}
		else{
			glDisable(GL_LIGHT7);
		}
	}
    // Dibujar los diferentes elementos de la escena
	if(modoPintar[4]==true){
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		glShadeModel(GL_SMOOTH);
		aniadirFiguras('i');
	}
	else{
		if(modoPintar[3]==true){
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
			aniadirFiguras('a');
		}else{
			if(modoPintar[0]==true){
				glPolygonMode(GL_FRONT_AND_BACK,GL_POINT);
				aniadirFiguras('p');
			}
			if(modoPintar[1]==true){
				glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
				aniadirFiguras('l');
			}
			if(modoPintar[2]==true){
				glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
				aniadirFiguras('s');
			}
		}
	}	

}

//**************************************************************************
//
// función que se invoca cuando se pulsa una tecla
// Devuelve true si se ha pulsado la tecla para terminar el programa (Q),
// devuelve false en otro caso.
//
//**************************************************************************

bool Escena::teclaPulsada( unsigned char tecla, int x, int y ){
   cout << "Tecla pulsada: '" << tecla << "'" << endl;
   
   bool salir=false;
   switch( toupper(tecla) ){
      case 'K' :
        if(modoMenu!=NADA)
			modoMenu=NADA;
			cout << "Saliendo del modo" << endl;
        break ;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		case 'Q':
			cout << "Saliendo del programa " << endl;
            salir=true ;
		break;  

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	case 'V' :
         // ESTAMOS EN MODO SELECCION DE MODO DE VISUALIZACION
        modoMenu=SELVISUALIZACION;
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
        break ;

	case 'P':
		if(modoMenu == SELVISUALIZACION && !iluminacion){
			cout << "Punto" << endl;
			glPointSize(5);
			modoPintar[0]=!modoPintar[0];
			modoPintar[4]=false;
			iluminacion=false;
			glDisable(GL_LIGHTING);
			cout << "Puedes pulsar la P para desactivar en modo punto "  << endl;
			cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
			cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
			cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
			cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
			cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
			cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
		}
		if(iluminacion && modoMenu == SELVISUALIZACION){
			animarLuzAnimada=!animarLuzAnimada;
			cout << "Puedes pulsar la P para parar la animacion de la luz puntual"  << endl;
	   		cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
			cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
			cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
			cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
			cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
			cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
		}
	break ;
	case 'L':
		if(modoMenu == SELVISUALIZACION){
			cout << "Linea" << endl;
			modoPintar[1]=!modoPintar[1];
			modoPintar[4]=false;
			iluminacion=false;
			glDisable(GL_LIGHTING);
			cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
			cout << "Puedes pulsar la L para desactivar en modo linea" << endl;
			cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
			cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
			cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
			cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
			cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
		}
	break ;
	case 'S':
		if(modoMenu == SELVISUALIZACION){
			cout << "Solido" << endl;
			modoPintar[2]=!modoPintar[2];
			modoPintar[4]=false;
			iluminacion=false;
			glDisable(GL_LIGHTING);
			cout << "Puedes pulsar la S para visualizar en modo punto "  << endl;
			cout << "Puedes pulsar la L para desactivar en modo linea" << endl;
			cout << "Puedes pulsar la P para visualizar en modo solido" << endl;
			cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
			cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
			cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
			cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
		}
	break ;
	case 'A':
		if(modoMenu == SELVISUALIZACION){
			cout << "ModoAjedrez" << endl;
			modoPintar[3]=!modoPintar[3];
			modoPintar[4]=false;
			iluminacion=false;
			glDisable(GL_LIGHTING);
			cout << "Puedes pulsar la A para visualizar en modo punto "  << endl;
			cout << "Puedes pulsar la L para desactivar en modo linea" << endl;
			cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
			cout << "Puedes pulsar la P para visualizar en modo ajedrez" << endl;
			cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
			cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
			cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
		}
	break ;
	case 'I':
		if(modoMenu == SELVISUALIZACION){
			cout << "Iluminacion" << endl;
			iluminacion=!iluminacion;
			modoPintar[0]=false;
			modoPintar[1]=false;
			modoPintar[2]=false;
			modoPintar[3]=false;
			modoPintar[4]=true;
			if(iluminacion)
				glEnable(GL_LIGHTING);	
			else	
				glDisable(GL_LIGHTING);
			cout << "Puedes pulsar la P para animar la luz puntual (Tecla 5)"  << endl;
			cout << "Pulse la V para activar el modo Visualización"<< endl;
			cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
			cout << "Pulse Q para salir del programa" << endl;
			cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
			cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
			cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
			cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
			cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
			cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
			cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
			cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
		}		
	break ;
	case 'R':
		aniAuto=!aniAuto;
		aniManu=false;
		cout << "Activando animacion AUTOMATICA" << endl;
		cout << "Ahora pulsa + para aumentar el movimiento o - para disminuir" << endl;
		this->animacion();
		cout << "Pulse la V para activar el modo Visualización"<< endl;
		cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
	break;

	case 'M':
		aniManu=!aniManu;
		aniAuto=false;
		cout << "Activando animacion MANUAL Pulsa 1 (Ojos) 2 (Cabeza) 3 (Pies) para mover esa parte." << endl;
		cout << "Pulse la V para activar el modo Visualización"<< endl;
		cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;

		cout << "Pulse / para aumentar la velocidad" << endl;
		cout << "Pulse * para disminuir la velocidad" << endl;
		cout << "Pulse + para mover la parte" << endl;
		cout << "Pulse - para mover la parte" << endl;
		cout << endl << endl;
	break;

	case '<':
		if(interruptorLuz[6]){
			if(alpha){
				if(variarAnguloAlpha<=0.0){
					variarAnguloAlpha=0;
				}
				variarAnguloAlpha+=0.3;
				this->variarLuces(variarAnguloAlpha);
			}
			if(beta){
				if(variarAnguloBeta<=0.0){
					variarAnguloBeta=0;
				}
				variarAnguloBeta+=0.3;
				this->variarLuces(variarAnguloBeta);
			}
		}
		if(interruptorLuz[7]){
			if(alpha){
				if(variarAnguloAlpha<=0.0){
					variarAnguloAlpha=0;
				}
				variarAnguloAlpha+=0.3;
				this->variarLuces(variarAnguloAlpha);
			}
			if(beta){
				if(variarAnguloBeta<=0.0){
					variarAnguloBeta=0;
				}
				variarAnguloBeta+=0.3;
				this->variarLuces(variarAnguloBeta);
			}
		}
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse > para aumentar alpha o beta" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
	break;
	case '>':
		if(interruptorLuz[6]){
			if(alpha){
				if(variarAnguloAlpha>=0.0){
					variarAnguloAlpha=0;
				}
				variarAnguloAlpha-=0.3;
				this->variarLuces(variarAnguloAlpha);
			}
			if(beta){
				if(variarAnguloBeta>=0.0){
					variarAnguloBeta=0;
				}
				variarAnguloBeta-=0.3;
				this->variarLuces(variarAnguloBeta);
			}
		}
		if(interruptorLuz[7]){
			if(alpha){
				if(variarAnguloAlpha>=0.0){
					variarAnguloAlpha=0;
				}
				variarAnguloAlpha-=0.3;
				this->variarLuces(variarAnguloAlpha);
			}
			if(beta){
				if(variarAnguloBeta>=0.0){
					variarAnguloBeta=0;
				}
				variarAnguloBeta-=0.3;
				this->variarLuces(variarAnguloBeta);
			}
		}
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse > para disminuir alpha o beta" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
	break;


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//CONTROL DE LA ANIMACION
	
	case '+':
	if(aniAuto){
		variarAnimacionGoomba+=0.5;
		saltoC1+=0.1;
		moverBandera+=0.2;
		variacionLuces+=0.5;
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse + para aumentar la velocidad" << endl;
		cout << "Pulse - para seguir disminuyendo la velocidad" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
   }
   if(aniManu){
	    if(velocidad<0)
	   		velocidad=velocidad*(-1);
		if(parteGombaMover[0]==true){
			this->animarOjos();
		}
		if(parteGombaMover[1]==true){
			this->animarCabeza();
		}
		if(parteGombaMover[2]==true){
			this->animarPies();
		}
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse + o - para mover las partes" << endl;
		cout << "Pulse / para aumentar la velocidad" << endl;
		cout << "Pulse * para disminuir la velocidad" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << endl << endl;
   }
	break ;
	
	case '-':
	if(aniAuto){
		if(variarAnimacionGoomba>=0.5){
			variarAnimacionGoomba-=0.5;
		}	
		if(saltoC1>=0.1){
			saltoC1-=0.1;
		}
		if(moverBandera>=0.2){
			moverBandera-=0.2;
		}
		if(variacionLuces>=0.9){
			variacionLuces-=0.9;
		}
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse + para aumentar la velocidad" << endl;
		cout << "Pulse - para seguir disminuyendo la velocidad" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	}
	if(aniManu){
		if(velocidad>0)
	   		velocidad=velocidad*(-1);
		if(parteGombaMover[0]==true){
			this->animarOjos();
		}
		if(parteGombaMover[1]==true){
			this->animarCabeza();
		}
		if(parteGombaMover[2]==true){
			this->animarPies();
		}
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse + o - para mover las partes" << endl;
		cout << "Pulse / para aumentar la velocidad" << endl;
		cout << "Pulse * para disminuir la velocidad" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	}
		
	break ;
		
		
	break ;

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//QUITAR O ENCENDER LAS LUCES
	case '0':
		if(iluminacion){
			if(!activoCamara){
				interruptorLuz[0]=!interruptorLuz[0];
			}
			else{
				cout << "Desactive el modo Camara para poder activar/desactivar la luz 0" << endl;
			}	
		}
		else
			cout << "No se ha activado la iluminacion"<<endl;

		if(activoCamara){
			camaraActiva[0]=!camaraActiva[0];
			camaraActiva[1]=false;
			camaraActiva[2]=false;
			camaraActiva[3]=false;
			numCamaraActiva=0;
		}	
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break ;
	case '1':
		if(aniManu){
			cout << "Ahora pulsa + para aumentar el movimiento o - para disminuir" << endl;
			parteGombaMover[0]=!parteGombaMover[0];
			parteGombaMover[1]=false;
			parteGombaMover[2]=false;
		}

		if(iluminacion){
			if(!aniManu ){
				if(!activoCamara){
					interruptorLuz[1]=!interruptorLuz[1];
				}
				else{
					cout << "Desactive el modo Camara para poder activar/desactivar la luz 1" << endl;
				}	
			}
			else
				cout << "Desactive el modo Manual para poder activar/desactivar la luz 1"<<endl;
		}
		else
			cout << "No se ha activado la iluminacion"<<endl;	
		if(activoCamara){
			camaraActiva[1]=!camaraActiva[1];
			camaraActiva[0]=false;
			camaraActiva[2]=false;
			camaraActiva[3]=false;
			numCamaraActiva=1;
		}
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break ;
	case '2':
		if(aniManu){
			cout << "Ahora pulsa + para aumentar el movimiento o - para disminuir" << endl;
			parteGombaMover[1]=!parteGombaMover[1];
			parteGombaMover[0]=false;
			parteGombaMover[2]=false;
		}

		if(iluminacion){
			if(!aniManu ){
				if(!activoCamara){
					interruptorLuz[2]=!interruptorLuz[2];
				}
				else{
					cout << "Desactive el modo Camara para poder activar/desactivar la luz 2" << endl;
				}	
			}
			else
				cout << "Desactive el modo Manual para poder activar/desactivar la luz 2"<<endl;
		}
		else
			cout << "No se ha activado la iluminacion"<<endl;	

		if(activoCamara){
			camaraActiva[2]=!camaraActiva[2];
			camaraActiva[0]=false;
			camaraActiva[1]=false;
			camaraActiva[3]=false;
			numCamaraActiva=2;
		}	
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;	
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break ;
	case '3':
		if(aniManu){
			cout << "Ahora pulsa + para aumentar el movimiento o - para disminuir" << endl;
			parteGombaMover[2]=!parteGombaMover[2];
			parteGombaMover[1]=false;
			parteGombaMover[0]=false;
		}
		if(activoCamara){
			camaraActiva[3]=!camaraActiva[3];
			camaraActiva[1]=false;
			camaraActiva[0]=false;
			camaraActiva[2]=false;
			numCamaraActiva=3;
			cam[numCamaraActiva].setProyeccion();
		}
		if(iluminacion){
			if(!aniManu ){
				if(!activoCamara){
					interruptorLuz[2]=!interruptorLuz[2];
				}
				else{
					cout << "Desactive el modo Camara para poder activar/desactivar la luz 3" << endl;
				}	
			}
			else
				cout << "Desactive el modo Manual para poder activar/desactivar la luz 3"<<endl;
		}
		else
			cout << "No se ha activado la iluminacion"<<endl;	

		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break;		
	case '4':
		if(iluminacion){
			if(!aniManu ){
				if(!activoCamara){
					interruptorLuz[3]=!interruptorLuz[3];
				}
				else{
					cout << "Desactive el modo Camara para poder activar/desactivar la luz 4" << endl;
				}	
			}
			else
				cout << "Desactive el modo Manual para poder activar/desactivar la luz 4"<<endl;
		}
		else
			cout << "No se ha activado la iluminacion"<<endl;	

		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;	
	break ;
	case '5':
		if(iluminacion){
			if(!aniManu ){
				if(!activoCamara){
					interruptorLuz[4]=!interruptorLuz[4];
				}
				else{
					cout << "Desactive el modo Camara para poder activar/desactivar la luz 5" << endl;
				}	
			}
			else
				cout << "Desactive el modo Manual para poder activar/desactivar la luz 5"<<endl;
		}
		else
			cout << "No se ha activado la iluminacion"<<endl;	

		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;	
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break ;
	case '6':
		if(iluminacion){
			if(!aniManu ){
				if(!activoCamara){
					interruptorLuz[5]=!interruptorLuz[5];
				}
				else{
					cout << "Desactive el modo Camara para poder activar/desactivar la luz 6" << endl;
				}	
			}
			else
				cout << "Desactive el modo Manual para poder activar/desactivar la luz 6"<<endl;
		}
		else
			cout << "No se ha activado la iluminacion"<<endl;	

		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse 7 para activar/desactivar la luz 7" << endl;
		cout << "Pulse H para mover Alpha. Es una luz direccional" << endl;
		cout << "Pulse J para mover Beta. Es una luz direccional" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break ;
	case '7':
		if(iluminacion){
			if(!aniManu ){
				if(!activoCamara){
					interruptorLuz[6]=!interruptorLuz[6];
				}
				else{
					cout << "Desactive el modo Camara para poder activar/desactivar la luz 7" << endl;
				}	
			}
			else
				cout << "Desactive el modo Manual para poder activar/desactivar la luz 7"<<endl;
		}
		else
			cout << "No se ha activado la iluminacion"<<endl;	

		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para desactivar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 0 para activar/desactivar la luz 0" << endl;
		cout << "Pulse 2 para activar/desactivar la luz 2" << endl;
		cout << "Pulse 1 para activar/desactivar la luz 1" << endl;
		cout << "Pulse 4 para activar/desactivar la luz 4" << endl;
		cout << "Pulse 5 para activar/desactivar la luz 5" << endl;
		cout << "Pulse 6 para activar/desactivar la luz 6" << endl;
		cout << "Pulse 3 para activar/desactivar la luz 3" << endl;
		cout << "Pulse H para mover Alpha. Es una luz direccional" << endl;
		cout << "Pulse J para mover Beta. Es una luz direccional" << endl;
	break ;

	case '8':
		TAPASUPERIOR=!TAPASUPERIOR;
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break;
	case '9':
		TAPAINFERIOR=!TAPAINFERIOR;
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break;

	case 'C':
		activoCamara=!activoCamara;
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
	break;

	case 'H':
		alpha=!alpha;
		beta=false;
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << "Pulse < o > para variar los angulos de las luces Direccionales" << endl;
	break;

	case 'J':
		beta=!beta;
		alpha=false;
		cout << "Puedes pulsar la P para visualizar en modo punto "  << endl;
	   	cout << "Puedes pulsar la L para visualizar en modo linea" << endl;
		cout << "Puedes pulsar la S para visualizar en modo solido" << endl;
		cout << "Puedes pulsar la A para visualizar en modo ajedrez" << endl;
		cout << "Puedes pulsar la I para activar la Iluminacion" << endl;
		cout << "Puedes pulsar la K para salir del modo Visualización" << endl;
		cout << "Pulse Q para salir del programa" << endl;
		cout << "Pulse 8 para poner/quitar las Tapas SUPERIORES " << endl;
		cout << "Pulse 9 para poner/quitar las Tapas INFERIORES " << endl;
		cout << "Pulse < o > para variar los angulos de las luces Direccionales" << endl;
	break;

	case '/':
		velocidad+=0.5;
	break;

	case '*':
		if(velocidad>0.5)
			velocidad-=0.5;
	break;

            
   }
   return salir;
}
//**************************************************************************



void Escena::teclaEspecial( int Tecla1, int x, int y ){
   switch ( Tecla1 ){
	   	case GLUT_KEY_LEFT:
		 	if(activoCamara){
				cam[numCamaraActiva].rotarYFirstPerson(-3.0);
				
		 	}
		 	else{
				Observer_angle_y-- ;
		 	}
        break;
	   case GLUT_KEY_RIGHT:
        if(activoCamara){
				cam[numCamaraActiva].rotarYFirstPerson(3.0);
		 	}
		 	else{
				Observer_angle_y++ ;
		 	}
        break;
	   case GLUT_KEY_UP:
         if(activoCamara){
				cam[numCamaraActiva].rotarXFirstPerson(3.0);
		 	}
		 	else{
				Observer_angle_x-- ;
		 	}
         break;
	   case GLUT_KEY_DOWN:
         if(activoCamara){
				cam[numCamaraActiva].rotarXFirstPerson(-3.0);
		 	}
		 	else{
				Observer_angle_x++ ;
		 	}
         break;
	   case GLUT_KEY_PAGE_UP:
		 if(activoCamara){
			cam[numCamaraActiva].zoom(2.0, cam[numCamaraActiva].left, cam[numCamaraActiva].right, cam[numCamaraActiva].top, cam[numCamaraActiva].bottom);
		 }
		 else{ 
         	Observer_distance *=1.2 ;
		 }
		 
         break;
	   case GLUT_KEY_PAGE_DOWN:
		if(activoCamara){
			cam[numCamaraActiva].zoom(0.5, cam[numCamaraActiva].left, cam[numCamaraActiva].right, cam[numCamaraActiva].top, cam[numCamaraActiva].bottom);
		 }
		 else{ 
         	Observer_distance /= 1.2 ;
		 }
        break;
	}

	//std::cout << Observer_distance << std::endl;
}

//**************************************************************************
// Funcion para definir la transformación de proyeccion
//
// ratio_xy : relacción de aspecto del viewport ( == ancho(X) / alto(Y) )
//
//***************************************************************************

void Escena::change_projection(){
   glMatrixMode( GL_PROJECTION );
   glLoadIdentity();

   if(!activoCamara){
	   	glFrustum(-Width, Width, -Height, Height, Front_plane, Back_plane);
   }
   else{
   		cam[numCamaraActiva].setProyeccion();  
   }
}
//**************************************************************************
// Funcion que se invoca cuando cambia el tamaño de la ventana
//***************************************************************************

void Escena::redimensionar( int newWidth, int newHeight ){
   change_projection();
   Width  = newWidth/10;
   Height = newHeight/10;
   glViewport( 0, 0, newWidth, newHeight );
}

//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************

void Escena::change_observer(){
   // posicion del observador
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   if(!activoCamara){
	   	glTranslatef(0,0,-Observer_distance);
   		glRotatef(Observer_angle_x, 1, 0, 0);
   		glRotatef(Observer_angle_y, 0, 1, 0);  
   }
   else{
   		cam[numCamaraActiva].setObserver();
   }
}



//Funcion que anima al Modelo Jerárquico
void Escena::animacion(){
		if(this->aniAuto==true){
			goomba->animarGoomba(variarAnimacionGoomba);
			monedas->saltar(saltoC1);
			bandera->izarBandera(moverBandera);
		}
}

void Escena::animacionDeLasLuces(){
	if(animarLuzAnimada && interruptorLuz[5]==true){
		luzPosAnimada->animarLuz(variacionLuces);
	}
}

//Funciones para animar individualmente al Modelo Jerárquico
void Escena::animarPies(){
	goomba->moverPies(cambiarGrados * velocidad);
}
void Escena::animarCabeza(){
	goomba->moverCabeza(cambiarGrados * velocidad);
}
void Escena::animarOjos(){
	goomba->moverOjos(cambiarGrados * velocidad);
}

//Funcion para controlar la variación Alpha y Beta
void Escena::variarLuces(float incremento){
	if(this->interruptorLuz[6]){
		if(alpha){
			luzDir7->variarAnguloAlpha(incremento);
		}
		if(beta){
			luzDir7->variarAnguloBeta(incremento);
		}
	}
	if(this->interruptorLuz[7]){
		if(alpha){
			luzDir8->variarAnguloAlpha(incremento);
		}
		if(beta){
			luzDir8->variarAnguloBeta(incremento);
		}
	}


}

	void Escena::ratonMovido(int x, int y){
		if(moverse){
			this->mover(x-xant, y-yant);
			xant=x;
			yant=y;
		}
	}

	void Escena::mover(int x, int y){
		cam[numCamaraActiva].rotarXFirstPerson(x);
		cam[numCamaraActiva].rotarYFirstPerson(y);
	}