#ifndef PROYECTO_MODTEXTO_H
#define PROYECTO_MODTEXTO_H
#include "librerias.h"

//Funcion ajuste de linea
void Ajustelinea(string &texto, vector<string> &v1){
    string linea, elemento, elemento1, elemento2, elemento3;
    int cont=0, random=0, validacion=0;
    int margen=50, longitud=80;

    while (validacion==0){
        cont=0;
        //linea="";
        random=36+rand()%(margen+1-36);
        for (int i=0; i<texto.length(); i++){
            cont++;
            if (cont==random){ //Si el contador marca que nos encontramos en el espacio 60 del texto...
                elemento=texto[i];
                if (elemento==" "){ //Aquí se verifica si el espacio 60 es un espacio en blanco.
                    linea+=elemento;
                    texto.erase(0, i+1);
                }
                else if (elemento!=" "){ //En otras palabras, si el espacio 60 se trata de un caracter...
                    elemento1=texto[i-1];
                    elemento2=texto[i+1];
                    if (elemento1==" " && elemento2==" "){
                        linea+=elemento2;
                        texto.erase(0, i+2);
                    }
                    else if (elemento1==" " && elemento2!=" ")
                        texto.erase(0, i);
                    else if (elemento1!=" " && elemento2==" "){
                        linea+=elemento;
                        linea+=elemento2;
                        texto.erase(0, i+2);
                    }
                    else if (elemento1!=" " && elemento2!=" "){
                        for (int j=i; j<i+20; j++){
                            elemento3=texto[j];
                            linea+=elemento3;
                            if (elemento3==" "){
                                texto.erase(0, j+1);
                                break;
                            }
                        }
                    }

                } //Fin del else if
                v1.push_back(linea);
                cout << linea << endl;
                linea="";
                break;

            } //Fin de la condición primaria
            else {
                linea+=texto[i];
                if (linea==texto){
                    v1.push_back(linea);
                    cout << linea << endl;
                    validacion=1;
                    break;
                }
            }
        } // Fin de la iteración for
        if (validacion==1)
            break;
    } // Fin de la iteración while

} //Fin de la funcion Ajuste de linea

//Funcion lectura del archivo
void lectura(ifstream &archivo, int &val, string &nombreArchivo){
    string validacion;
    cout << "Digite el nombre o la ubicacion del archivo o fichero:\n";
    getline(cin, nombreArchivo);
    archivo.open(nombreArchivo.c_str(), ios::in); //Abrimos el archivo en modo lectura

    if (archivo.fail()) {
        cout << "Lo siento. No se pudo abrir el archivo";
        exit(1);
    }
    else {
        cout << "Archivo abierto con exito.\n" << endl;
        val=1;
        //Cerramos el archivo
    }

}



#endif //PROYECTO_MODTEXTO_H

