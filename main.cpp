#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
void lectura();
int main(){
    int opcion=0;
    cout<<"1. Leer archivo txt"<<endl;
    cout<<"2. Guardar archivo"<<endl;
    cout<<"3. Justificar texto"<<endl;
    cout<<"4. Alinear texto a la izquierda"<<endl;
    cout<<"5. Alinear texto a la derecha"<<endl;
    cout<<"Elige alguna opcion:";
    cin>>opcion;
    switch(opcion){
        case 1:
            lectura();
            break;
        case 2:
            cout<<"Hola";
            break;
    }
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