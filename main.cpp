#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
using namespace std;

void lectura(int opcion);
void ADerecha(string &texto);
void CTexto(string &texto);

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
        cout << "4. Centrar el texto" << endl;

        cout << "Elige alguna opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
            }
            case 2: {
            }
            case 3: {
                while (!archivo.eof()) { //mientras no sea final del archivo
                    getline(archivo, texto);
                    ADerecha(texto);
                }
            }
            case 4: {
                while(!archivo.eof()){ //mientras no sea final del archivo
                    getline(archivo,texto);
                    CTexto(texto);
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
    int op;
    cout <<"1. Guardar \n2. Salir";
    cin >> op;
    if(op==1){
        ofstream archivo;
        archivo.open("C://Users/Irvin Coronado/Proyecto/Registro.txt",ios::out);
        archivo<<texto;
        archivo.close();
    }
}
void CTexto(string &texto) {
    int espacios;
    espacios = (80 - texto.length()) / 2;
    for (int i = 1; i <= espacios; i++) {
        cout << " ";
    }
    cout << texto << endl;
    int op;
    cout <<"1. Guardar \n2. Salir";
    cin >> op;
    if(op==1){
        ofstream archivo;
        archivo.open("C://Users/Irvin Coronado/Proyecto/Registro.txt",ios::out);
        archivo<<texto;
        archivo.close();
    }
}