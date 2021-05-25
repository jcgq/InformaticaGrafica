#include "camara.h"

Camara::Camara(Tupla3f _eye, Tupla3f _at, Tupla3f _up, int _tipo, float _left, float _right, float _near, float _far, float _top, float _bottom){
    this->eye=_eye;
    this->at=_at;
    this->up=_up;
    this->tipo=_tipo;
    this->right=_right;
    this->left=_left;
    this->top=_top;
    this->bottom=_bottom;
    this->near=_near;
    this->far=_far;
}

void Camara::setObserver(){
    gluLookAt(eye(X), eye(Y), eye(Z), at(X), at(Y), at(Z), up(X), up(Y), up(Z));
}

void Camara::setProyeccion(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(tipo==0){
        glFrustum(left, right, bottom, top, near, far);
    }  
    else
        glOrtho(left, right, bottom, top, near, far);
    
}

void Camara::zoom(float factor, float _left, float _rigth, float _top, float _bottom){
    this->left=_left*factor;
    this->right=_rigth*factor;
    this->top=_top*factor;
    this->bottom=_bottom*factor;
    this->setProyeccion();
}


void Camara::rotarXFirstPerson(float angle){
    at(X)=at(X)+angle;
    //eye(Y)=eye(Y)+angle;
}
void Camara::rotarYFirstPerson(float angle){
    at(Z)=at(Z)+angle;
    //eye(X)=eye(X)+angle;
}
void Camara::rotarZFirstPerson(float angle){
    at(Z)=at(Z)+angle;
    //eye(Z)=eye(Z)+angle;
}



//Rotar Examinar

void Camara::rotarXExaminar(float angle){
    eye(Y)=(eye(Y)*cos(angle))+(sin(angle)*eye(Z));
    eye(Z)=(eye(Y)*(-sin(angle)))+(cos(angle)*eye(Z));
    up(Y)=(up(Y)*cos(angle))+(up(angle)*up(Z));
    up(Z)=(up(Y)*(-sin(angle)))+(cos(angle)*up(Z));
    if(eye(Y)>=360)
        eye(Y)=0;
     if(eye(Z)>=360)
        eye(Z)=0;
}

void Camara::rotarYExaminar(float angle){
    eye(X)=(eye(X)*cos(angle))-(sin(angle)*eye(Z));
    eye(Z)=(eye(X)*sin(angle))+(cos(angle)*eye(Z));
    up(X)=(up(X)*cos(angle))-(sin(angle)*up(Z));
    up(Z)=(up(X)*sin(angle))+(cos(angle)*up(Z));
    if(eye(X)>=360)
        eye(Y)=0;
     if(eye(Z)>=360)
        eye(Z)=0;
}

void Camara::rotarZExaminar(float angle){
    eye(Y)=(eye(X)*cos(angle))+(sin(angle)*eye(Y));
    eye(Z)=(eye(X)*(-sin(angle)))+(cos(angle)*eye(Y));
    up(Y)=(up(X)*cos(angle))+(sin(angle)*up(Y));
    up(Z)=(up(X)*(-sin(angle)))+(cos(angle)*up(Y));
    if(eye(Y)>=360)
        eye(Y)=0;
     if(eye(X)>=360)
        eye(X)=0;
}



float Camara::getLeft(){
    return this->left;
}

float Camara::getRight(){
    return this->right;
}