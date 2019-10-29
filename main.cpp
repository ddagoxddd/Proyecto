#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
void lectura();
int main(){
    int opcion=0;
    lectura();
    cout<<"1. Justificar texto"<<endl;
    cout<<"2. Alinear texto a la izquierda"<<endl;
    cout<<"3. Alinear texto a la derecha"<<endl;

    cout<<"Elige alguna opcion:";
    cin>>opcion;
    return 0;
}

void lectura(){
    ifstream archivo;
    string nombreArchivo,texto;
    cout<<"Digite el nombre o la ubicacion del archivo o fichero: ";
    getline(cin,nombreArchivo);
    archivo.open(nombreArchivo.c_str(),ios::in); //Abrimos el archivo en modo lectura

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){ //mientras no sea final del archivo
        getline(archivo,texto);
        cout<<texto<<endl;
    }

    archivo.close(); //Cerramos el archivo
}