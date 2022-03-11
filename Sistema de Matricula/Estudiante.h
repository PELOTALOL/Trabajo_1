#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>

#pragma warning(disable:4996)

using namespace std;

class Estudiante {
private:
    char nombre[50];
    char apellido1[50];
    char cedula[20];
    char apellido2[50];
    char cod_est[4];
    char telefono[9];
    char direccion[50];
    char Bcedula[20];
    char Newname[50];
    char cod_grupo[4];
    int num;
public:
    Estudiante() {
        int i;
        for (i = 0; i < 50; i++) {
            nombre[i] = ' ';
            apellido1[i] = ' ';
            apellido2[i] = ' ';
            direccion[i] = ' ';
            Newname[i] = ' ';

        }
        for (i = 0; i < 4; i++) {
            cod_est[i] = ' ';
            cod_grupo[i] = ' ';
           
        }
        for (i = 0; i < 20; i++) {
            cedula[i] = ' ';
            Bcedula[i] = ' ';
        }
        for (i = 0; i < 9; i++) {
            telefono[i]=' ';
        }
        num = 0;
    }
    ~Estudiante() {
        cout << "\n<<Eliminado espacio de memoria>>\n";
    }
  
    int getnum() {
        return num;
    }  
    ofstream temp;
    ifstream leer;
    void agregarEstudiante(char _nombre[50], char _apellido1[50], char _cedula[9],char _apellido2[50], char _cod_est[9], char _cod_grupo[3], char _telefono[8],char _direccion[50]) {
       
        FILE* archivo;
        archivo = fopen("Estudiante.txt", "a");
    
        if (archivo == NULL) {
            printf("No se puede abrir el archivo !!!");
            exit(1);
        }
            fprintf(archivo, "%s ", _cod_est);
            fprintf(archivo, "%s ", _cod_grupo);
            fprintf(archivo, "%s ", _cedula);
            fprintf(archivo, "%s ", _apellido1);
            fprintf(archivo, "%s ", _apellido2);
            fprintf(archivo, "%s ", _nombre);
            fprintf(archivo, "%s ", _telefono);
            for (int i = 0; i < 50; i++) {
                if (_direccion[i] == ' ') {
                    _direccion[i] = '_';
                }
            }
            fprintf(archivo, "%s\n", _direccion);
          

            fclose(archivo);

        }
    void eliminarEstudiante() {
        temp.open("temp.txt");
        leer.open("Estudiante.txt");
        leer >> cod_est;
        cin.ignore();
        bool encontrado = false;
        cout << "Ingrese cedula de estudiante a eliminar: ";
        cin.getline(Bcedula, 20);
        int tam = strlen(Bcedula);
        while (tam > 10) {
            cout << "La cedula no se puede guardar";
            cout << "\nDigite nuevamente la cedula con 9 digitos max: "; cin.getline(Bcedula, 20);
            tam = strlen(Bcedula);
        }
        while (!leer.eof()) {
            leer >> cod_grupo >> cedula >> apellido1 >> apellido2 >> nombre >> telefono >> direccion;
           
            if (cedula[0]==Bcedula[0]&& cedula[1] == Bcedula[1] && cedula[2] == Bcedula[2] && cedula[3] == Bcedula[3] && cedula[4] == Bcedula[4] && cedula[5] == Bcedula[5] && cedula[6] == Bcedula[6]&&cedula[7] == Bcedula[7] && cedula[8] == Bcedula[8] && cedula[9] == Bcedula[9]) {
                encontrado = true;
                cout << "\ncodido estudiante:" << cod_est << endl;
                cout << "\ncodigo de grupo:" << cod_grupo << endl;
                cout << "\ncedula: " << cedula << endl;
                cout << "\nApellido 1: " << apellido1 << endl;
                cout << "\nApellido 2: " << apellido2 << endl;
                cout << "\nNombre: " << nombre << endl;
                cout << "\ntelefono: " << telefono << endl;
                for (int i = 0; i < 50; i++) {
                    if (direccion[i] == ' ') {
                        direccion[i] = '_';
                    }
                }
               
                 num = atoi(cod_grupo);
             
                cout << "\nDireccion: " << direccion<<endl;
                cout << "\nEStudiante Eliminado";
                cout << endl;
            }
            else {
                temp << cod_est << " " << cod_grupo << " " << cedula << " " << apellido1 << " " << apellido2 << " " << nombre << " " << telefono << " " << direccion << endl;
            }
                
               
            leer >> cod_est;

            if (encontrado == false) {
                cout << "\nEstudiante no encontrado";
            }
        }
        leer.close();
        temp.close();
        remove("Estudiante.txt");
        rename("Temp.txt","Estudiante.txt");
        system("pause");
    }
    void BuscarEstudiante() {
        leer.open("Estudiante.txt");
        leer >> cod_est;
        cin.ignore();
        bool encontrado=false;
        cout << "Ingrese cedula: ";
        cin.getline(Bcedula, 20);
        int tam = strlen(Bcedula);
        while (tam > 10) {
            cout << "La cedula no se puede guardar";
            cout << "\nDigite nuevamente la cedula con 9 digitos max: "; cin.getline(Bcedula, 20);
            tam = strlen(Bcedula);
        }
        while (!leer.eof()) {
            leer >> cod_grupo>>cedula >> apellido1>> apellido2>> nombre >> telefono>>direccion;
           
            if (cedula[0] == Bcedula[0] && cedula[1] == Bcedula[1] && cedula[2] == Bcedula[2] && cedula[3] == Bcedula[3] && cedula[4] == Bcedula[4] && cedula[5] == Bcedula[5] && cedula[6] == Bcedula[6] && cedula[7] == Bcedula[7] && cedula[8] == Bcedula[8] && cedula[9] == Bcedula[9]) {
                encontrado = true;
                    cout << "\ncodido estudiante:" << cod_est << endl;
                    cout << "\ncodigo de grupo:" << cod_grupo << endl;
                    cout << "\ncedula: " << cedula << endl;
                    cout << "\nApellido 1: " << apellido1 << endl;
                    cout << "\nApellido 2: " << apellido2 << endl;
                    cout << "\nNombre: " << nombre << endl;
                    cout << "\ntelefono: " << telefono << endl;
                    for (int i = 0; i < 50; i++) {
                        if (direccion[i] == '_') {
                            direccion[i] = ' ';
                        }
                    }
                    cout << "\nDireccion: " << direccion<<"\n";

                    cout << endl;
            }
            if(encontrado==false)  {
                cout << "\nEstudiante no encontrado";
            }
            
            leer >> cod_est;
        }
        leer.close();
        system("pause");
    }
    void mostrarEstudiante() {
        leer.open("Estudiante.txt");
        leer >> cod_est;
        while (!leer.eof()) {
            leer >> cod_grupo >> cedula >> apellido1 >> apellido2 >> nombre >> telefono >> direccion;
            cout << "\ncodido estudiante:" << cod_est << endl;
            cout << "\ncodigo de grupo:" << cod_grupo << endl;
            cout << "\ncedula: " << cedula << endl;
            cout << "\nApellido 1: " << apellido1 << endl;
            cout << "\nApellido 2: " << apellido2 << endl;
            cout << "\nNombre: " << nombre << endl;
            cout << "\ntelefono: " << telefono << endl;
            for (int i = 0; i < 50; i++) {
                if (direccion[i] == '_') {
                    direccion[i] = ' ';
                }
            }
            cout << "\nDireccion: " << direccion;

            cout << "\n-----------------------------------------\n";
            leer >> cod_est;
        }
        leer.close();
        system("pause");
    }
    void modificarEstudiante() {
        int op;
        temp.open("temp.txt");
        leer.open("Estudiante.txt");
        leer >> cod_est;
        cin.ignore();
        bool encontrado = false;
        cout << "Ingrese cedula de estudiante: ";
        cin.getline(Bcedula, 20);
        int tam = strlen(Bcedula);
        while (tam > 10) {
            cout << "La cedula no se puede guardar";
            cout << "\nDigite nuevamente la cedula con 9 digitos max: "; cin.getline(Bcedula, 20);
            tam = strlen(Bcedula);
        }
        while (!leer.eof()) {
            leer >> cod_grupo >> cedula >> apellido1 >> apellido2 >> nombre >> telefono >> direccion;

            if (cedula[0] == Bcedula[0] && cedula[1] == Bcedula[1] && cedula[2] == Bcedula[2] && cedula[3] == Bcedula[3] && cedula[4] == Bcedula[4] && cedula[5] == Bcedula[5] && cedula[6] == Bcedula[6] && cedula[7] == Bcedula[7] && cedula[8] == Bcedula[8] && cedula[9] == Bcedula[9]) {
                encontrado = true;
                cout << "\ncodido de estudiante:" << cod_est << endl;
                cout << "\ncodigo de grupo:" << cod_grupo << endl;
                cout << "\ncedula: " << cedula << endl;
                cout << "\nApellido 1: " << apellido1 << endl;
                cout << "\nApellido 2: " << apellido2 << endl;
                cout << "\nNombre: " << nombre << endl;
                cout << "\ntelefono: " << telefono << endl;
                cout << "\nDireccion: " << direccion << endl;
                cout << "\n\t1)Cod_est\n\t2)Cod_grupo\n\t3)Apellido 1\n\t4)Apellido 2\n\t5)Nombre\n\t6)Telefono\n\t7)Direccion\n";
                cout << "Elija la opcion a modificar: "; cin >> op;
                if (op == 1) {
                    char NcodEst[4];
                    cin.ignore();
                    cout << "\nDigite nuevo Codigo de estudiante: ";
                    cin.getline(NcodEst, 4);
                    temp << NcodEst << " " << cod_grupo << " " << cedula << " " << apellido1 << " " << apellido2 << " " << nombre << " " << telefono << " " << direccion << endl;
                    cout << endl;
                }
                if (op == 2) {
                    char NcodGrup[4];
                    cin.ignore();
                    cout << "\nDigite nuevo de Codigo grupo: ";
                    cin.getline(NcodGrup, 4);
                    temp << cod_est << " " << NcodGrup << " " << cedula << " " << apellido1 << " " << apellido2 << " " << nombre << " " << telefono << " " << direccion << endl;
                    cout << endl;
                }
                if (op == 3) {
                    char Napellido1[50];
                    cin.ignore();
                    cout << "\nDigite nuevo Apellido 1: ";
                    cin.getline(Napellido1, 50);
                    temp << cod_est << " " << cod_grupo << " " << cedula << " " << Napellido1 << " " << apellido2 << " " << nombre << " " << telefono << " " << direccion << endl;
                    cout << endl;
                }
                if (op == 4) {
                    char Napellido2[50];
                    cin.ignore();
                    cout << "\nDigite nuevo Apellido 2: ";
                    cin.getline(Napellido2, 50);
                    temp << cod_est << " " << cod_grupo << " " << cedula << " " << apellido1 << " " << Napellido2 << " " << nombre << " " << telefono << " " << direccion << endl;
                    cout << endl;
                }
                if (op == 5) {
                    cin.ignore();
                    cout << "\nDigite nuevo nombre: ";
                    cin.getline(Newname, 50);
                    temp << cod_est << " " << cod_grupo << " " << cedula << " " << apellido1 << " " << apellido2 << " " << Newname << " " << telefono << " " << direccion << endl;
                    cout << endl;
                }
                if (op == 6) {
                    char Ntelefono[9];
                    cin.ignore();
                    cout << "\nDigite nuevo Telefono: ";
                    cin.getline(Ntelefono, 9);
                    temp << cod_est << " " << cod_grupo << " " << cedula << " " << apellido1 << " " << apellido2 << " " << nombre << " " << Ntelefono << " " << direccion << endl;
                    cout << endl;
                }
                if (op == 7) {
                    char Ndireccion[50];
                    cin.ignore();
                    cout << "\nDigite nueva direccion: ";
                    cin.getline(Ndireccion, 50);
                    for (int i = 0; i < 50; i++) {
                        if (Ndireccion[i] == ' ') {
                            Ndireccion[i] = '_';
                        }
                    }
                    temp << cod_est << " " << cod_grupo << " " << cedula << " " << apellido1 << " " << apellido2 << " " << nombre << " " << telefono << " " << Ndireccion << endl;
                    cout << endl;
                }
               
            }
            else {
                temp << cod_est << " " << cod_grupo << " " << cedula << " " << apellido1 << " " << apellido2 << " " << nombre << " " << telefono << " " << direccion << endl;
            }


            leer >> cod_est;

            if (encontrado == false) {
                cout << "\nEstudiante no encontrado";
            }
        }
        leer.close();
        temp.close();
        remove("Estudiante.txt");
        rename("Temp.txt","Estudiante.txt");
        system("pause");
    }
    struct Nodo {
        char nombre[50];
        char apellido1[50];
        char cedula[10];
        char apellido2[50];
        char cod_est[4];
        char cod_grupo[4];
        char telefono[9];
        char direccion[50];
        Nodo* siguiente;
    };
    void insertarEstudiante(Nodo*& lista, char _nombre[50], char _apellido1[50], char _cedula[9], char _apellido2[50], char _cod_est[3], char _cod_grupo[3], char _telefono[8], char _direccion[50]) {
        Nodo* nuevo_nodo = new Nodo();
        int i;
        for (i = 0; i < 50; i++) {
            nuevo_nodo->nombre[i] = _nombre[i];
            nuevo_nodo->apellido1[i] = _apellido1[i];
            nuevo_nodo->apellido2[i] = _apellido2[i];
            nuevo_nodo->direccion[i] = _direccion[i];
        }
        for (i = 0; i < 4; i++) {
            nuevo_nodo->cod_est[i] = _cod_est[i];
            nuevo_nodo->cod_grupo[i] = _cod_grupo[i];
        }
        for (i = 0; i < 9; i++) {
            nuevo_nodo->telefono[i] = _telefono[i];
        }
        for (i = 0; i < 10; i++) {
            nuevo_nodo->cedula[i] = _cedula[i];
        }
        Nodo* aux1 = lista;

        if (lista == aux1) {
            lista = nuevo_nodo;
        }
        nuevo_nodo->siguiente = aux1;
    }
    void complementarAntesDemostrar(Nodo* lista) {
        Nodo* actual = new Nodo();
        actual = lista;
        while (actual != NULL) {
            cout << "\n----------------------------------------------" << endl;
            cout << "\nCodigo est: " << actual->cod_est << endl;
            cout << "\nCodigo grupo: " << actual->cod_grupo << endl;
            cout << "\nCedula: " << actual->cedula << endl;
            cout << "\nApellido 1: " << actual->apellido1 << endl;
            cout << "\nApellido 2: " << actual->apellido2 << endl;
            cout << "\nNombre: " << actual->nombre << endl;
            cout << "\nTelfono: " << actual->telefono << endl;
            cout << "\nDireccion: " << actual->direccion << endl;
            actual = actual->siguiente;
        }
        system("pause");
    }
    void mostrarlistEstudiante() {
        Nodo* lista = NULL;
        leer.open("Estudiante.txt");
        leer >> cod_est;
        while (!leer.eof()) {
            leer >> cod_grupo >> cedula >> apellido1 >> apellido2 >> nombre >> telefono >> direccion;
            insertarEstudiante(lista, nombre, apellido1, cedula, apellido2, cod_est, cod_grupo, telefono, direccion);
            leer >> cod_est;
        }
        
        leer.close();
        system("pause");
        complementarAntesDemostrar(lista);
    }
    
};
