#include "ModTexto.h"
#include "Buscar.h"
#include "Alineacion.h"
#include "Guardar.h"
#include "Justificar.h"

int main() {
    srand(time(NULL));
    ifstream archivo;
    int i, j;
    int opcion = 0;
    int val = 0;
    string texto;
    string validacion;
    string nombreArchivo;
    vector<string> lineas;
    vector<vector<string>>palabras;
    lectura(archivo, val, nombreArchivo);
    while (!archivo.eof())
        getline(archivo, texto);

    Ajustelinea(texto, lineas); //Aquí, 'lineas' (que es un vector) sera quien contenga las lineas del texto.
    cout << "\nTexto ajustado con exito.\n" << endl;
    archivo.close(); //Cerramos el archivo

    if (val == 1) {
        cout << "Estas son las opciones: " << endl;
        cout << "1. Centrar texto" << endl;
        cout << "2. Alinear texto a la izquierda" << endl;
        cout << "3. Alinear texto a la derecha" << endl;
        cout << "5. Buscar palabra" << endl;
        cout << "6. Reemplazar palabra" << endl;
        cout << "7. Contar la cantidad de veces que aparece una palabra." << endl;
        cout << "8.Justificar texto." << endl;

        do{
            cout << "Elige alguna opcion: ";
            cin >> opcion;
            if (opcion == 1) { //Centrar texto
                CTexto(lineas);
            }
            else if (opcion == 2) { //Alinear a la izquiera
                AIzquierda(lineas);
            }
            else if (opcion == 3) { //Alinear a la derecha
                ADerecha(lineas);
            }
            else if(opcion == 8){


                palabras[i]=lineas;
                palabras[j]={"holahola","akaokso","lamdladmld","ldmlamdlad","mlamldmañdma","dmladm","msms"};
                JustTexto();
            }
            else if(opcion==9){
                string nombreArchivo3;
                cout << "Ingresa el nombre del nuevo archivo: ";
                cin>>nombreArchivo3;
                Guardarpdf(lineas, nombreArchivo3);
            }
            else if (opcion==5 || opcion==6 || opcion==7){ //Buscar o reemplazar palabra
                string buscar;
                string reemplazar="";
                int contador=0;
                cout << "Ingresa la palabra a buscar: ";
                cin >> buscar;
                if (opcion==5 || opcion==7){
                    for (int i=0; i<lineas.size(); i++)
                        Separarpalabra(lineas[i], buscar, reemplazar, opcion, contador);
                    if (opcion==5){
                        if (contador<1)
                            cout << "La palabra no se encontró en el texto." << endl;
                        else
                            cout << "La palabra '" << buscar << "' existe en el texto." << endl;
                    }
                    else if (opcion==7){
                        if (contador==1)
                            cout << "La palabra '" << buscar << "' aparece solo una vez en el texto." << endl;
                        else if (contador>1)
                            cout << "La palabra aparece " << contador << " veces en el texto." << endl;
                        else
                            cout << "La palabra '" << buscar << "' no aparece en el texto." << endl;
                    }

                }
                else if (opcion==6){
                    cout << "Reemplazar por: ";
                    cin >> reemplazar;
                    cout << "\n";
                    for (int i=0; i<lineas.size(); i++){
                        Separarpalabra(lineas[i], buscar, reemplazar, opcion, contador);
                    }
                    if (contador==0)
                        cout << "\nAccion no concretada. La palabra '" << buscar << "' no aparece en el texto." << endl;
                    else{
                        Imprimirtexto(lineas);
                        cout << "\nPalabra '" << buscar << "' reemplazada exitosamente " << contador << " veces." << endl;
                    }

                }

            }
            cout << "\n¿Desea realizar una operacion mas? ";
            cin >> validacion;
            if (validacion == "Si")
                opcion = 0;
            else
                opcion = 4;
        }while (opcion != 4);

        //cout << "¿Desea guardar los cambios?" << endl;
        //cin >> validacion;
        return 0;
    }
}
///Users/davidgabo/Desktop/EllaNoMeAma.txt