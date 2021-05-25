#include "sistemasMonedas.h"
#include "cubo.h"
#include "esfera.h"


sistemaMonedas::sistemaMonedas(){
    esf1 = new Esfera(4,20,20);
    esf1->setMaterial(oro);
    esf2 = new Esfera(4,20,20);
    esf2->setMaterial(oro);
    esf3 = new Esfera(4,20,20);
    esf3->setMaterial(oro);
}




void sistemaMonedas::dibujar(char modoPintar, bool tn, bool ts){
    TN=tn;
    TS=ts;
        glPushMatrix();//Sistemas de Cubos
			glPushMatrix();
				glTranslatef(0, 310, -200);
                glTranslatef(0, salto, 0);
				esf1->draw(modoPintar, 'i', TN, TS);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-98, 320, -200);
                glTranslatef(0, salto, 0);
				esf2->draw(modoPintar, 'i', TN, TS);
			glPopMatrix();
			glPushMatrix();
				glTranslatef(98, 300, -200);
                glTranslatef(0, salto, 0);
				esf3->draw(modoPintar,'i', TN, TS);
			glPopMatrix();
		glPopMatrix();
}

void sistemaMonedas::saltar(float incremento){
    salto+=incremento;
    if(salto>=80)
        salto=0;
}