#include "objrevolucion.h"
#include "bandera.h"

Bandera::Bandera(){
    baseGrande = new Cilindro(4, 20, 30, 100);
    baseGrande->calcular_normales();
    baseGrande->setMaterial(plateado);

	basePequenia = new Cilindro(4, 20, 20, 60);
    basePequenia->calcular_normales();
    basePequenia->setMaterial(bronze);

	palo = new Cilindro(4, 20, 300, 10);
    palo->calcular_normales();
    palo->setMaterial(blanco);

	punto = new Esfera(4,20,30.0);
    punto->calcular_normales();
    punto->setMaterial(plateado);

    tela = new Cubo(3);
    tela->calcular_normales();
    tela->setMaterial(negro);
}

void Bandera::dibujar(char modoPintar, bool tn, bool ts){
    TN=tn;
    TS=ts;
    glPushMatrix();
        glPushMatrix();
            glTranslatef(0,30,0);
            baseGrande->draw(modoPintar, '2', TN, TS);
            glPushMatrix();
                glTranslatef(0,40,0);
                basePequenia->draw(modoPintar, '2', TN, TS);
            glPopMatrix();
            glRotatef(moverTela, 0.0, 1.0, 0.0);
            glPushMatrix();
                glTranslatef(0,300,0);
                palo->draw(modoPintar, '2', TN, TS);
                glPushMatrix();
                glTranslatef(0,300,0);
                    punto->draw(modoPintar, '2', TN, TS);
                glPopMatrix();
                glTranslatef(70,220,0);
                glTranslatef(0.0, subirTela, 0.0);
                glScalef(20,15,1);
                    tela->draw(modoPintar);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}



void Bandera::izarBandera(float incremento){
   
    moverTela+=(incremento*2.0);
    if(moverTela>=30)
        moverTela=-30;


    if(subirTela<=-350){
		topeBandera=true;
	}
	else{
		if(subirTela>=0){
			topeBandera=false;
		}
	}
	if(topeBandera==false){
		subirTela-=incremento;
	}
	if(topeBandera==true){
		subirTela+=incremento;
	}
}