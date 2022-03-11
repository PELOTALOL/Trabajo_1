#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>

using namespace std;
class Profesor {
private:
	char codigoProfesor[4];
	char cedula[20];
	char nombre[50];
	char apellido1[50];
	char apellido2[50];
	char telefono[9];
	char direccion[50];
	char Bcedula[20];
public:
	Profesor() {
		int i;
		for (i = 0; i < 50; i++) {
			nombre[i] = ' ';
			apellido1[i] = ' ';
			apellido2[i] = ' ';
			direccion[i] = ' ';
		}
		for (i = 0; i < 20; i++) {
			cedula[i] = ' ';
			Bcedula[i] = ' ';
		}
		for (i = 0; i < 9; i++) {
			telefono[i] = ' ';
		}
		for (i = 0; i < 4; i++) {
			codigoProfesor[i] = ' ';
		}
	}
	~Profesor() {
		cout << "\n<<Liberando espacio de memoria>>\n";
	}
	ofstream temp;
	ifstream leer;
	void agregarProfesor(char _nombre[50], char _apellido1[50], char _cedula[9], char _apellido2[50], char _cod_prof[3], char _telefono[8], char _direccion[50]) {

		FILE* archivo;
		archivo = fopen("Profesor.txt", "a");

		if (archivo == NULL) {
			printf("No se puede abrir el archivo !!!");
			exit(1);
		}
		fprintf(archivo, "%s ", _cod_prof);
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
	void BuscarProfesor() {
		leer.open("Profesor.txt");
		leer >> codigoProfesor;
		cin.ignore();
		cout << "Ingrese cedula: ";
		cin.getline(Bcedula, 20);
		int tam = strlen(Bcedula);
		while (tam > 10) {
			cout << "La cedula no se puede guardar";
			cout << "\nDigite nuevamente la cedula con 9 digitos max: "; cin.getline(Bcedula, 20);
			tam = strlen(Bcedula);
		}
		bool encontrado = false;
		while (!leer.eof()) {
			leer >> cedula >> nombre>> apellido1 >> apellido2  >> telefono >> direccion;

			if (cedula[0] == Bcedula[0] && cedula[1] == Bcedula[1] && cedula[2] == Bcedula[2] && cedula[3] == Bcedula[3] && cedula[4] == Bcedula[4] && cedula[5] == Bcedula[5] && cedula[6] == Bcedula[6] && cedula[7] == Bcedula[7] && cedula[8] == Bcedula[8] && cedula[9] == Bcedula[9]) {
				 encontrado = true;
				cout << "\ncodido de profesor:" << codigoProfesor << endl;
				cout << "\ncedula: " << cedula << endl;
				cout << "\nNombre: " << nombre << endl;
				cout << "\nApellido 1: " << apellido1 << endl;
				cout << "\nApellido 2: " << apellido2 << endl;
				cout << "\ntelefono: " << telefono << endl;
				for (int i = 0; i < 50; i++) {
					if (direccion[i] == '_') {
						direccion[i] = ' ';
					}
				}
				cout << "\nDireccion: " << direccion << "\n";

				cout << endl;
			}
			if( encontrado == false) {
				cout << "\n\tProfesor no encontrado\n";
			}

			leer >> codigoProfesor;
		}
		leer.close();
		system("pause");
	}
	void eliminarProfesor() {
		temp.open("temp.txt");
		leer.open("Profesor.txt");
		leer >> codigoProfesor;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese cedula de profesor a eliminar: ";
		cin.getline(Bcedula, 20);
		int tam = strlen(Bcedula);
		while (tam > 10) {
			cout << "La cedula no se puede guardar";
			cout << "\nDigite nuevamente la cedula con 9 digitos max: "; cin.getline(Bcedula, 20);
			tam = strlen(Bcedula);
		}
		while (!leer.eof()) {
			leer  >> cedula >>nombre >> apellido1 >> apellido2 >> telefono >> direccion;

			if (cedula[0] == Bcedula[0] && cedula[1] == Bcedula[1] && cedula[2] == Bcedula[2] && cedula[3] == Bcedula[3] && cedula[4] == Bcedula[4] && cedula[5] == Bcedula[5] && cedula[6] == Bcedula[6] && cedula[7] == Bcedula[7] && cedula[8] == Bcedula[8] && cedula[9] == Bcedula[9]) {
				encontrado = true;
				cout << "\ncodido estudiante:" << codigoProfesor << endl;
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
				cout << "\nDireccion: " << direccion << endl;
				cout << "\nEStudiante Eliminado";
				cout << endl;
			}
			else {
				temp << codigoProfesor << " "  << cedula << " " << nombre << " " << apellido1 << " " << apellido2  << " " << telefono << " " << direccion << endl;
			}

			leer >> codigoProfesor;

			if (encontrado == false) {
				cout << "\n\tProfesor no encontrado\n";
			}
		}
		leer.close();
		temp.close();
		remove("Profesor.txt");
		rename("Temp.txt", "Profesor.txt");
		system("pause");
	}
	void modificarProfesor() {
		int op;
		temp.open("temp.txt");
		leer.open("Profesor.txt");
		leer >> codigoProfesor;
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
			leer >> cedula >> nombre >> apellido1 >> apellido2  >> telefono >> direccion;

			if (cedula[0] == Bcedula[0] && cedula[1] == Bcedula[1] && cedula[2] == Bcedula[2] && cedula[3] == Bcedula[3] && cedula[4] == Bcedula[4] && cedula[5] == Bcedula[5] && cedula[6] == Bcedula[6] && cedula[7] == Bcedula[7] && cedula[8] == Bcedula[8] && cedula[9] == Bcedula[9]) {
				encontrado = true;
				cout << "\ncodido estudiante:" << codigoProfesor << endl;
				cout << "\ncedula: " << cedula << endl;
				cout << "\nApellido 1: " << apellido1 << endl;
				cout << "\nApellido 2: " << apellido2 << endl;
				cout << "\nNombre: " << nombre << endl;
				cout << "\ntelefono: " << telefono << endl;
				cout << "\nDireccion: " << direccion << endl;
				cout << "\n\t1)codigo de profesor\n\t2)Apellido 1\n\t3)Apellido2\n\t4)nombre\n\t5)telefono\n\t6)Direccion";
				cout << "Elija la opcion a modificar: "; cin >> op;
				if (op == 1) {
					char Ncodprof[4];
					cin.ignore();
					cout << "\nDigite nuevo codigo de profesor: ";
					cin.getline(Ncodprof, 4);
					temp << Ncodprof << " " << cedula <<" "<< nombre << " " << apellido1 << " " << apellido2  << " " << telefono << " " << direccion << endl;
					cout << endl;
				}
				
				if (op == 2) {
					char Napellido1[50];
					cin.ignore();
					cout << "\nDigite nuevo Apellido 1: ";
					cin.getline(Napellido1, 50);
					temp << codigoProfesor  << " " << cedula << " " << nombre << " " << Napellido1 << " " << apellido2 << " " << telefono << " " << direccion << endl;
					cout << endl;
				}
				if (op == 3) {
					char Napellido2[50];
					cin.ignore();
					cout << "\nDigite nuevo Apellido 2: ";
					cin.getline(Napellido2, 50);
					temp << codigoProfesor << " " << cedula << " " << nombre << " " << apellido1 << " " << Napellido2  << " " << telefono << " " << direccion << endl;
					cout << endl;
				}
				if (op == 4) {
					char Newname[50];
					cin.ignore();
					cout << "\nDigite nuevo nombre: ";
					cin.getline(Newname, 50);
					temp << codigoProfesor  << " " << cedula << " " << Newname << " " << apellido1 << " " << apellido2  << " " << telefono << " " << direccion << endl;
					cout << endl;
				}
				if (op == 5) {
					char Ntelefono[9];
					cin.ignore();
					cout << "\nDigite nuevo Telefono: ";
					cin.getline(Ntelefono, 9);
					temp << codigoProfesor  << " " << cedula << " " << nombre << " " << apellido1 << " " << apellido2  << " " << Ntelefono << " " << direccion << endl;
					cout << endl;
				}
				if (op == 6) {
					char Ndireccion[50];
					cin.ignore();
					cout << "\nDigite nueva Direccion: ";
					cin.getline(Ndireccion, 50);
					for (int i = 0; i < 50; i++) {
						if (Ndireccion[i] == ' ') {
							Ndireccion[i] = '_';
						}
					}
					temp <<codigoProfesor  << " " << cedula << " " << nombre << " " << apellido1 << " " << apellido2  << " " << telefono << " " << Ndireccion << endl;
					cout << endl;
				}

			}
			else {
				temp << codigoProfesor << " " << cedula << " " << nombre<< " " << apellido1 << " " << apellido2 << " " << telefono << " " << direccion << endl;
			}


			leer >> codigoProfesor;

			if (encontrado == false) {
				cout << "\n\tProfesor no encontrado\n";
			}
		}
		leer.close();
		temp.close();
		remove("Profesor.txt");
		rename("Temp.txt", "Profesor.txt");
		system("pause");
	}
	struct Nodo {
		char nombre[50];
		char apellido1[50];
		char cedula[10];
		char apellido2[50];
		char cod_prof[4];
		char telefono[9];
		char direccion[50];
		Nodo* siguiente;
	};
	void insertarProfesor(Nodo*& lista, char _nombre[50], char _apellido1[50], char _cedula[9], char _apellido2[50], char _cod_prof[3], char _telefono[8], char _direccion[50]) {
		Nodo* nuevo_nodo = new Nodo();
		int i;
		for (i = 0; i < 50; i++) {
			nuevo_nodo->nombre[i] = _nombre[i];
			nuevo_nodo->apellido1[i] = _apellido1[i];
			nuevo_nodo->apellido2[i] = _apellido2[i];
			nuevo_nodo->direccion[i] = _direccion[i];
		}
		for (i = 0; i < 4; i++) {
			nuevo_nodo->cod_prof[i] = _cod_prof[i];
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
			cout << "\nCodigo est: " << actual->cod_prof << endl;
			cout << "\nCedula: " << actual->cedula << endl;
			cout << "\nNombre: " << actual->nombre << endl;
			cout << "\nApellido 1: " << actual->apellido1 << endl;
			cout << "\nApellido 2: " << actual->apellido2 << endl;
			cout << "\nTelfono: " << actual->telefono << endl;
			cout << "\nDireccion: " << actual->direccion << endl;
			actual = actual->siguiente;
		}
		system("pause");
	}
	void mostrarlistProfesor() {
		Nodo* lista = NULL;
		leer.open("Profesor.txt");
		leer >> codigoProfesor;
		while (!leer.eof()) {
			leer  >> cedula >> nombre >>apellido1 >> apellido2  >> telefono >> direccion;
			insertarProfesor(lista, nombre, apellido1, cedula, apellido2, codigoProfesor, telefono, direccion);
			leer >> codigoProfesor;
			
		}

		leer.close();
		system("pause");
		complementarAntesDemostrar(lista);
	}
};

