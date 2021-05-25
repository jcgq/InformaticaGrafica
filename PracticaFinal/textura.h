#ifndef _TEXTURA_H_INCLUDED
#define _TEXTURA_H_INCLUDED

#include "aux.h"
#include "string.h"
#include "jpg_imagen.hpp"


class textura{

    private:
        GLuint textura_id=0;
        std::vector<unsigned char> data;
        unsigned width;
        unsigned height;
    public:
        textura(std::string archivo);
        void activar();

};




#endif