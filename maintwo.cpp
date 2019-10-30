#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

void lectura(int opcion);
void ADerecha(string &texto);
void AIzquierda(string &texto);

int main(){
    int opcion=0;
    string validacion;
    lectura(opcion);
    //cout << "¿Desea guardar los cambios?" << endl;
    //cin >> validacion;
    return 0;
}

void lectura(int opcion) {
    ifstream archivo;
    string nombreArchivo, texto;
    cout << "Digite el nombre o la ubicacion del archivo o fichero: ";
    getline(cin, nombreArchivo);
    archivo.open(nombreArchivo.c_str(), ios::in); //Abrimos el archivo en modo lectura

    if (archivo.fail()) {
        cout << "Lo siento. No se pudo abrir el archivo";
        exit(1);
    } else {
        cout << "Archivo abierto con exito.\n" << endl;
        cout << "Estas son las opciones: " << endl;
        cout << "1. Justificar texto" << endl;
        cout << "2. Alinear texto a la izquierda" << endl;
        cout << "3. Alinear texto a la derecha" << endl;

        cout << "Elige alguna opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {

            }
            case 2: {
                while(!archivo.eof()){
                    getline(archivo,texto);
                    AIzquierda(texto);
                }

            }
            case 3: {
                while (!archivo.eof()) { //mientras no sea final del archivo
                    getline(archivo, texto);
                    ADerecha(texto);
                }
            }
        }

        archivo.close(); //Cerramos el archivo
    }
}

void ADerecha(string &texto){
    string agregar="";
    int espacios=0;
    espacios=80-texto.length();
    for (int i=0; i<espacios; i++){
        agregar+=" ";
    }
    texto=agregar+texto;
    cout << texto << endl;
    
}

void AIzquierda(string &texto){
    string gaaa="";
    int spaces=0;
    spaces=80-texto.length();
    for (int i=0; i<spaces; i++){
        gaaa+=" ";
    }
    texto=gaaa+texto;
    cout << texto << endl;

}

///Users/davidgabo/Desktop/EllaNoMeAma.txt