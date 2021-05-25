#include "textura.h"

textura::textura(std::string archivo){

    jpg::Imagen * pimg = NULL;
    pimg = new jpg::Imagen(archivo);

    height=pimg->tamY();
    width=pimg->tamX();
    
    //Se empaquetan los datos
    for(int i = 0; i<width;i++){
        for(int j = 0; j<height;j++){
            data.push_back(*(pimg->leerPixel(i, j)));
            data.push_back(*(pimg->leerPixel(i, j)+1));
            data.push_back(*(pimg->leerPixel(i, j)+2));
        }
    }
}


void textura::activar(){
    glEnable(GL_TEXTURE_2D);
    if(textura_id==0){
        glGenTextures(1, &textura_id);
        glBindTexture(GL_TEXTURE_2D, textura_id);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data.data());
    }
    glBindTexture(GL_TEXTURE_2D, textura_id);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

    glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL, GL_SEPARATE_SPECULAR_COLOR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}