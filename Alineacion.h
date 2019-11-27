#ifndef PROYECTO_ALINEACION_H
#define PROYECTO_ALINEACION_H
#include "librerias.h"

void Quitarespacios(string &l) {
    string compr;
    int cont = 0;
    compr = l[0];
    if (compr == " ") {
        for (int i = 0; i <= l.length(); i++) {
            compr = l[i];
            if (compr == " ")
                cont++;
            else
                break;
        }
        l.erase(0, cont);
    }
}

//Funcion Alinear a la izquierda
void AIzquierda(vector<string> &v1) {
    string texto;
    string compr;
    int cont=0;
    for (int i=0; i<v1.size(); i++){
        cont=0;
        texto=v1[i];
        compr = texto[0];
        if (compr == " ") {
            for (int i = 0; i <= texto.length(); i++) {
                compr = texto[i];
                if (compr == " ")
                    cont++;
                else
                    break;
            }
            texto.erase(0, cont);
        }
        v1[i]=texto;
        cout << texto << endl;
    }
}

//Funcion Alinear a la derecha
void ADerecha(vector<string> &v1){
    string texto, agregar="";
    int espacios=0, i, j;
    for (i=0; i<v1.size(); i++){
        Quitarespacios(v1[i]);
        agregar="";
        texto=v1[i];
        espacios=80-texto.length();
        for (j=0; j<espacios; j++){
            agregar+=" ";
        }
        texto=agregar+texto;
        v1[i]=texto;
        cout << texto << endl;
    }
}

//Funcion Centrar texto
void CTexto(vector<string> &v1) {
    string texto, agregar;
    int espacios, i, j;
    for (i=0; i<v1.size(); i++){
        Quitarespacios(v1[i]);
        texto=v1[i];
        espacios = (80 - texto.length()) / 2;
        agregar="";
        for (j = 1; j <= espacios; j++) {
            agregar+=" ";
        }
        texto=agregar+texto;
        v1[i]=texto;
        cout << texto << endl;
    }




}

//Funcion Justificar texto


#endif //PROYECTO_ALINEACION_H
