#include "objrevolucion.h"
#include "goomba.h"
Goomba::Goomba(){
	cabeza = new Esfera(4,20,50.0);
	cabeza->setMaterial(bronze);
	cabeza->calcular_normales();

	cuerpo = new Cilindro(4, 20, 1.5, 1.0);
	cuerpo->setMaterial(plateado);
	cuerpo->calcular_normales();

	boca = new Cilindro(4, 20, 25.0, 5.0);
	boca->setMaterial(negro);
	boca->calcular_normales();

	ojo = new Esfera(4,20,20.0);
	ojo->setMaterial(blanco);
	ojo->calcular_normales();
	
	oreja = new Esfera(4,20,20.0);
	oreja->setMaterial(negro);
	oreja->calcular_normales();

	pupila = new Esfera(4,20,5.0);
	pupila->setMaterial(negro);
	pupila->calcular_normales();

	pie = new Cilindro(4,20,1.5,1.0);
	pie->setMaterial(negro);
	pie->calcular_normales();

	ceja = new Cilindro(4, 20, 3, 1.0);
	ceja->setMaterial(negro);
	ceja->calcular_normales();

	diente = new Cono(4, 20, 3, 1.0);
	diente->setMaterial(blanco);
	diente->calcular_normales();
	
	base = new Cilindro(4,20,2,800);
	base->establecerColorS(1.0,1.0,1.0);
	base->calcular_normales();
}

void Goomba::dibujar(char modoDibujar, bool tn, bool ts){
	TN=tn;
	TS=ts;
	glPushMatrix();
		glRotatef(-andar, 0.0,1.0,0.0);
		glPushMatrix();
			glScalef(5, 5, 5);
			glTranslatef(0,-1,0);
			base->draw(modoDibujar, 'i', TN, TS);
		glPopMatrix();
			glTranslatef(250,40,0);
		glPushMatrix();
			glTranslatef(0, 70, 0);
			glScalef(1.25,1.25,1.25);
			glRotatef(45,0.0,1.0,0.0);
			glRotatef(rotarCabeza,0.0,1.0,0.0);
			glPushMatrix();//CABEZA GOOMBA
				glPushMatrix();//Cabeza Goomba
					glScalef(1.25,1.25,1.25);
					dibujarCabeza(modoDibujar);
				glPopMatrix();
				glPushMatrix();//Oreja Derecha
					glTranslatef(60, 10, 0);
					glScalef(0.8,0.8,0.8);
					dibujarOreja(modoDibujar);
				glPopMatrix();
				glPushMatrix();//Oreja Izquierda
					glTranslatef(-60, 10, 0);
					glScalef(0.8,0.8,0.8);
					dibujarOreja(modoDibujar);
				glPopMatrix();
				glPushMatrix();//Ojo Derecho
					glTranslatef(17, 10, 55);
					glScalef(0.8,0.8,0.8);
					glRotatef(rotarOjo,1.0,0.0,0.0);
					dibujarOjo(modoDibujar);
				glPopMatrix();
				glPushMatrix();//Ojo Izquierdo
					glTranslatef(-17, 10, 55);
					glScalef(0.8,0.8,0.8);
					glRotatef(rotarOjo,1.0,0.0,0.0);
					dibujarOjo(modoDibujar);
				glPopMatrix();
				glPushMatrix();//Boca Goomba
					glTranslatef(0.0,-25.0,60);
					dibujarBoca(modoDibujar);
				glPopMatrix();
				glPushMatrix();//Ceja Derecha
					glTranslatef(-14.0,30.0,65);
					glRotatef(60,0.0,0.0,1.0);
					dibujarCeja(modoDibujar);
				glPopMatrix();
				glPushMatrix();//Ceja Izquierda
					glTranslatef(14.0,30.0,65);
					glRotatef(-60,0.0,0.0,1.0);
					dibujarCeja(modoDibujar);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
		glPushMatrix();//CUERPO GOOMBA
			glPushMatrix();//Cuerpo Goomba
				glTranslatef(0,10,0);
				glScalef(3,3,3);
				dibujarCuerpo(modoDibujar);
			glPopMatrix();
			glPushMatrix();
				glPushMatrix();//Pata Goomba
					glTranslatef(30,-30,10);
					glTranslatef(0,0,-rotarPies);
					dibujarPata(modoDibujar);
				glPopMatrix();
				glPushMatrix();//Pata Goomba
					glTranslatef(-30,-30,-10);
					glTranslatef(0,0,rotarPies);
					dibujarPata(modoDibujar);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();	
}

void Goomba::dibujarOjo(char modoDibujar){
	glPushMatrix();//Cuerpo del Ojo
		glRotatef(60, 1.0, 0.0, 0.0);
		glPushMatrix();
			ojo->draw(modoDibujar, 'i', TN, TS);
		glPopMatrix();
		glPushMatrix();//Pupila
			glTranslatef(0,0,20);
			pupila->draw(modoDibujar, 'i', TN, TS);
		glPopMatrix();
	glPopMatrix();
}

void Goomba::dibujarCabeza(char modoDibujar){
	glPushMatrix();//Cabeza Goomba (Cabeza)
		cabeza->draw(modoDibujar, 'i', TN, TS);
	glPopMatrix();
}

void Goomba::dibujarBoca(char modoDibujar){
	glPushMatrix();//Boca Goomba
		glPushMatrix();//Boca Goomba
			glRotatef(90, 0.0,0.0,1.0);
			boca->draw(modoDibujar, 'i', TN, TS);
		glPopMatrix();
		glPushMatrix();//Diente Derecho
			glTranslatef(-20,3,5);
			glScalef(3,3,3);
			diente->draw(modoDibujar, 'i', TN, TS);
		glPopMatrix();
		glPushMatrix();//Diente Izquierdo
			glTranslatef(20,3,5);
			glScalef(3,3,3);
			diente->draw(modoDibujar, 'i', TN, TS);
		glPopMatrix();	
	glPopMatrix();
}

void Goomba::dibujarPata(char modoDibujar){
	glPushMatrix();//Pata Goomba
		glRotatef(90,1.0,0.0,0.0);
		glScalef(16,16,16);
		pie->draw(modoDibujar, 'i', TN, TS);
	glPopMatrix();
}

void Goomba::dibujarCuerpo(char modoDibujar){
	glPushMatrix();//Cuerpo Goomba
		glScalef(10,10,10);
		cuerpo->draw(modoDibujar, 'i', TN, TS);
	glPopMatrix();
}

void Goomba::dibujarCeja(char modoDibujar){
	glPushMatrix();//Ceja Goomba
		glScalef(4,4,4);
		ceja->draw(modoDibujar, 'i', TN, TS);
	glPopMatrix();
}

void Goomba::moverOjos(float incremento){

	if(rotarOjo<=-80){
		topeOjo=true;
	}
	else{
		if(rotarOjo>=0){
			topeOjo=false;
		}
	}
	if(topeOjo==false){
		rotarOjo-=incremento;
	}
	if(topeOjo==true){
		rotarOjo+=incremento;
	}
}

void Goomba::moverCabeza(float incremento){
	if(rotarCabeza<=-90){
		topeCabeza=true;
	}
	else{
		if(rotarCabeza>=0){
			topeCabeza=false;
		}
	}
	if(topeCabeza==false){
		rotarCabeza-=incremento;
	}
	if(topeCabeza==true){
		rotarCabeza+=incremento;
	}
}

void Goomba::moverPies(float incremento){
	if(rotarPies<=-10){
		topePie=true;
	}
	else{
		if(rotarPies>=20){
			topePie=false;
		}
	}
	if(topePie==false){
		rotarPies-=incremento;
	}
	if(topePie==true){
		rotarPies+=incremento;
	}	
}

void Goomba::caminar(float incremento){
	andar+=incremento;
}

void Goomba::dibujarOreja(char modoDibujar){
	glPushMatrix();//Oreja
		oreja->draw(modoDibujar, 'i', true, true);
	glPopMatrix();
}

void Goomba::animarGoomba(float incremento){
	this->moverOjos(incremento);
	this->moverCabeza(incremento);
	this->moverPies(incremento);
	this->caminar(incremento);
}














