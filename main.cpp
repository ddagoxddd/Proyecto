#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;
void lectura(){
    ifstream archivo;
    string texto;
    //Abrimos el archivo en modo lectura
    archivo.open("PorqueEllaNoMeAma.txt",ios::in);
    if (archivo.fail()){
        cout<<"No se pudo abrir el texto";
        exit(1);
    }
    while(!archivo.eof()){
        getline(archivo,texto);
        cout<<texto<<endl;
    }
    //cerramos el archivo
    archivo.close();
}
int main() {
    lectura();
    int opcion=0;
    cout<<"1. Leer archivo"<<endl;
    cout<<"2. Guardar archivo"<<endl;
    cout<<"3. Justificar texto"<<endl;
    cout<<"4. Alinear texto a la izquierda"<<endl;
    cout<<"5. Alinear texto a la derecha"<<endl;
    cout<<"Eliga opcion:";
    cin>>opcion;
    switch(opcion){
        case 1:
            cout<<"Hola mundo";
            break;
        case 2:
            cout <<"";
            break;
        case 3:
            cout<<"";
            break;
    }
    return 0;
}