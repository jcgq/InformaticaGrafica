#include "aux.h"
#include "objrevolucion.h"
#include "math.h"
#include "iostream"
#include "cstdlib"


// *****************************************************************************
//
// Clase ObjRevolucion (práctica 2)
//
// *****************************************************************************


// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un PLY)

ObjRevolucion::ObjRevolucion() {}

ObjRevolucion::ObjRevolucion(const std::string & archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
	Tapa_Norte=tapa_sup;
  	Tapa_Sur=tapa_inf;
	std::vector<Tupla3f> perfil_original;
	ply::read_vertices(archivo, perfil_original);
   	crearMalla(perfil_original, num_instancias);
	colorS.resize(num_instancias*perfil_original.size());
	colorL.resize(num_instancias*perfil_original.size());
	colorP.resize(num_instancias*perfil_original.size());
	int R, G, B;
	int basura = 0 +rand();
	R = rand()%255;
	G = rand()%255;
	B = rand()%255;
	establecerColorS(R/255.0, G/255.0, B/255.0);
	R = rand()%255;
	G = rand()%255;
	B = rand()%255;
	establecerColorL(R/255.0, G/255.0, B/255.0);
	R = rand()%255;
	G = rand()%255;
	B = rand()%255;
	establecerColorP(R/255.0, G/255.0, B/255.0);
	calcular_normales();
}

// *****************************************************************************
// objeto de revolución obtenido a partir de un perfil (en un vector de puntos)

 
ObjRevolucion::ObjRevolucion(std::vector<Tupla3f> archivo, int num_instancias, bool tapa_sup, bool tapa_inf) {
	Tapa_Norte=tapa_sup;
  	Tapa_Sur=tapa_inf;
    crearMalla(archivo, num_instancias);
	calcular_normales();
}

void ObjRevolucion::crearMalla(std::vector<Tupla3f> perfil_original, int num_instancias) {
 
   crearMalla(perfil_original, num_instancias, false);
	calcular_normales();
}

void ObjRevolucion::crearMalla(const std::vector<Tupla3f> & perfil_original,const int num_instancias_perf, const bool conTapas){

numero_instancias=num_instancias_perf;
//Aquí creamos el vector de vértices y de caras de malla

std::vector<Tupla3f> perfil_modificado;

for(int j=0; j<=perfil_original.size()-1; j++){
   perfil_modificado.push_back(perfil_original[j]);
}
//Buscamos si hay tapas

Tupla3f polo_n, polo_s;
bool tapaSur=false, tapaNorte=false;
using namespace std;

if(perfil_modificado[0](X)==0){
   polo_s=perfil_modificado[0];
   perfil_modificado.erase(perfil_modificado.begin());
   tapaSur=true;
}
else{
   Tupla3f polo_aniadido;
   polo_aniadido(X)=0.0;
   polo_aniadido(Y)=perfil_modificado[0](Y);
   polo_aniadido(Z)=0.0;
   polo_s=polo_aniadido;
   tapaSur=true;
}


if(perfil_modificado[perfil_modificado.size()-1](X)==0){
   polo_n=perfil_modificado[perfil_modificado.size()-1];
   perfil_modificado.erase(perfil_modificado.end());
   tapaNorte=true;
}
else{
   Tupla3f polo_aniadido2;
   polo_aniadido2(X)=0.0;
   polo_aniadido2(Y)=perfil_modificado[perfil_modificado.size()-1](Y);
   polo_aniadido2(Z)=0.0;
   polo_n=polo_aniadido2;
   tapaNorte=true;
}

Tupla3f aux;
if(polo_s(Y)>polo_n(Y)){
   aux=polo_s;
   polo_s=polo_n;
   polo_n=aux;
}

//cout << "POLO NORTE: " << polo_n << " POLO SUR: " << polo_s << endl;

for(int i=0; i<perfil_modificado.size(); i++){
   for(int j=0; j<perfil_modificado.size()-1; j++){
      if(perfil_modificado[j](Y) > perfil_modificado[j+1](Y)){
         aux=perfil_modificado[j];
         perfil_modificado[j]=perfil_modificado[j+1];
         perfil_modificado[j+1]=aux;
      }
   }
}



char rotar='y';
Tupla3f vertice;

for(int i=0; i<=num_instancias_perf-1 ; i++){
   for(int j=0; j<=perfil_modificado.size()-1; j++){
      if(rotar=='y'){
            vertice(X)=perfil_modificado[j](X)*cos(2*M_PI*i/num_instancias_perf)+perfil_modificado[j](Z)*sin(2*M_PI*i/num_instancias_perf); 
            vertice(Y)=perfil_modificado[j](Y);
            vertice(Z)=-(perfil_modificado[j](X)*sin(2*M_PI*i/num_instancias_perf)-perfil_modificado[j](Z)*cos(2*M_PI*i/num_instancias_perf)); 
      }
      if(rotar=='x'){
            vertice(X)=perfil_modificado[j](X);
            vertice(Y)=perfil_modificado[j](Y)*cos(2*M_PI*i/num_instancias_perf)-perfil_modificado[j](Z)*sin(2*M_PI*i/num_instancias_perf); 
            vertice(Z)=perfil_modificado[j](Y)*sin(2*M_PI*i/num_instancias_perf)+perfil_modificado[j](Z)*cos(2*M_PI*i/num_instancias_perf); 
      }
      if(rotar=='z'){
            vertice(Z)=perfil_modificado[j](Z);
            vertice(X)=perfil_modificado[j](Z)*sin(2*M_PI*i/num_instancias_perf)-perfil_modificado[j](X)*sin(2*M_PI*i/num_instancias_perf); 
            vertice(Y)=perfil_modificado[j](Z)*sin(2*M_PI*i/num_instancias_perf)+perfil_modificado[j](X)*cos(2*M_PI*i/num_instancias_perf); 
      }
      v.push_back(vertice);  //Añadimos vértice al final del vector de los vértices en malla
   }
}




int a, b;
//Vector de caras

for(int i=0; i<num_instancias_perf; i++){
   for(int j=0; j<=perfil_modificado.size()-2 && perfil_modificado.size()!=1; j++){
      a=perfil_modificado.size()*i+j;
      b=perfil_modificado.size()*((i+1)%num_instancias_perf)+j;
      
      f.push_back(Tupla3i(a,b,b+1));
      f.push_back(Tupla3i(a,b+1,a+1));
      
   }
}
//Deberiamos buscar polo norte y polo sur
 int posPoloSur,posPoloNorte;
if(tapaSur){
   v.push_back(polo_s);
   posPoloSur=v.size()-1;
   for(int i=0; i<perfil_modificado.size()*num_instancias_perf; i+=perfil_modificado.size()){
      f.push_back(Tupla3i(posPoloSur,(i+perfil_modificado.size())%(perfil_modificado.size()*num_instancias_perf),i%(perfil_modificado.size()*num_instancias_perf)));
   
   }
}

if(tapaNorte){
   v.push_back(polo_n);
  posPoloNorte=v.size()-1;
  for(int i=perfil_modificado.size()-1; i<perfil_modificado.size()*num_instancias_perf; i+=perfil_modificado.size()){
      f.push_back(Tupla3i(posPoloNorte,i%(perfil_modificado.size()*num_instancias_perf),(i+perfil_modificado.size())%(perfil_modificado.size()*num_instancias_perf)));
   }
}
 
}

void ObjRevolucion::draw(char modo, char vis, bool tn, bool ts){
   if(modo=='a')
		draw_ModoAjedrez(tn, ts);
	else{
		establecerColorActivo(modo);
		draw_ModoInmediato(tn,ts);
	}

}

void ObjRevolucion::draw_ModoInmediato( bool tn, bool ts){
   std::vector<Tupla3f> v_mod;
   std::vector<Tupla3i> f_mod;

   for(int i=0; i<v.size(); i++)
      v_mod.push_back(v[i]);

   for(int i=0; i<f.size(); i++)
      f_mod.push_back(f[i]);

   if(!tn && !ts){
      v_mod.erase(v_mod.end());
      v_mod.erase(v_mod.end());

      for(int i=0; i<numero_instancias*2; i++){
         f_mod.pop_back();
      }
   }
   else{
      if(!tn){
         v_mod.erase(v_mod.end());
         
         for(int i=0; i<numero_instancias; i++){
            f_mod.pop_back();
         }
      }
      if(!ts){
         Tupla3f aux;
         std::vector<Tupla3i> v_aux;

         aux=v_mod[v_mod.size()-1];
         v_mod.erase(v_mod.end());
         v_mod.erase(v_mod.end());
         v_mod.push_back(aux);

         for(int i=0; i<numero_instancias; i++){
            v_aux.push_back(f_mod[f_mod.size()-1]);
            f_mod.pop_back();
         }
         for(int i=0; i<numero_instancias; i++){
            f_mod.pop_back();
         }
          for(int i=numero_instancias-1; i>=0; i--){
            f_mod.push_back(v_aux[i]);
         }
      }
   }
   glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, v_mod.data());
   glEnableClientState(GL_NORMAL_ARRAY);
   glNormalPointer(GL_FLOAT, 0, nv.data());
	if(glIsEnabled(GL_LIGHTING)){
		if(m!=nullptr){
         m->aplicar();
      }
	}
	else{
		glEnableClientState(GL_COLOR_ARRAY);
		glColorPointer(3, GL_FLOAT, 0, &this->activacionColor[0]);
	}
	

	
	glDrawElements(GL_TRIANGLES, f_mod.size()*3,GL_UNSIGNED_INT, f_mod.data());

	glDisableClientState(GL_NORMAL_ARRAY);
        glDisableClientState(GL_VERTEX_ARRAY);	


}

void ObjRevolucion::draw_ModoAjedrez( bool tn, bool ts){
   std::vector<Tupla3f> v_mod;
   std::vector<Tupla3i> f_mod;

   for(int i=0; i<v.size(); i++)
      v_mod.push_back(v[i]);

   for(int i=0; i<f.size(); i++)
      f_mod.push_back(f[i]);

   if(!tn && !ts){
      v_mod.erase(v_mod.end());
      v_mod.erase(v_mod.end());

      for(int i=0; i<numero_instancias*2; i++){
         f_mod.pop_back();
      }
   }
   else{
      if(!tn){
         v_mod.erase(v_mod.end());
         
         for(int i=0; i<numero_instancias; i++){
            f_mod.pop_back();
         }
      }
      if(!ts){
         Tupla3f aux;
         std::vector<Tupla3i> v_aux;

         aux=v_mod[v_mod.size()-1];
         v_mod.erase(v_mod.end());
         v_mod.erase(v_mod.end());
         v_mod.push_back(aux);

         for(int i=0; i<numero_instancias; i++){
            v_aux.push_back(f_mod[f_mod.size()-1]);
            f_mod.pop_back();
         }
         for(int i=0; i<numero_instancias; i++){
            f_mod.pop_back();
         }
          for(int i=numero_instancias-1; i>=0; i--){
            f_mod.push_back(v_aux[i]);
         }
      }
   }

  //Rellenamos vectores de caras pares e impares
  for(int i=0; i<f_mod.size(); i++){
		if(i%2==0)
			caraPar.push_back(f_mod[i]);
		else
			caraImpar.push_back(f_mod[i]);
  }

  glEnableClientState( GL_VERTEX_ARRAY );
 
  glVertexPointer( 3, GL_FLOAT, 0, v_mod.data());
  glEnableClientState( GL_COLOR_ARRAY );
  glColorPointer(3, GL_FLOAT, 0, colorP.data());
  
  glDrawElements( GL_TRIANGLES, 3*caraPar.size(), GL_UNSIGNED_INT, caraPar.data());
  

  glEnableClientState( GL_VERTEX_ARRAY );

  glVertexPointer( 3, GL_FLOAT, 0, v_mod.data());
  glEnableClientState( GL_COLOR_ARRAY );
  glColorPointer(3, GL_FLOAT, 0, colorL.data());
  glDrawElements( GL_TRIANGLES, 3*caraImpar.size(), GL_UNSIGNED_INT, caraImpar.data());
}


