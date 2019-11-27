#ifndef PROYECTO_GUARDAR_H
#define PROYECTO_GUARDAR_H

#include "librerias.h"
//Funcion Guardar archivo

//Funcion Guardar como pdf
//Funcion guardar archivo pdf
fstream archivo;
void Guardarpdf(vector<string> &v1, string &nombreArchivo3){

    string agregar="";
    archivo.open(nombreArchivo3.c_str(), ios::out);
    for (int i=0; i<v1.size(); i++){
        agregar+=v1[i]+"\n";
    }
    archivo << agregar;
    archivo.close();
}

#endif //PROYECTO_GUARDAR_H
