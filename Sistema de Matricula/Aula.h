#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>

using namespace std;

class Aula {
private:
	char cod_aula[10];
	char b_cod_aula[10];
	char descripcion[50];
	char capacidad[4];
public:
	Aula() {
		int i;
		for (i = 0; i < 50; i++) {
			descripcion[i] = ' ';
		}
		for (i = 0; i < 4; i++) {
			
			capacidad[i] = ' ';
		}
		for (i = 0; i < 10; i++) {
			cod_aula[i] = ' ';
			b_cod_aula[i] = ' ';
			
		}
	}
	~Aula() {
		cout << "\n<<Liberando espacio de memoria>>\n";
	}

	ofstream temp;
	ifstream leer;

	void agregarAula(char _cod_aula[4], char _descrip[50],char _capacidad[4]) {

		FILE* archivo;
		archivo = fopen("Grupo.txt", "a");

		if (archivo == NULL) {
			printf("No se puede abrir el archivo !!!");
			exit(1);
		}
		fprintf(archivo, "%s ", cod_aula);

		for (int i = 0; i < 50; i++) {
			if (_descrip[i] == ' ') {
				_descrip[i] = '_';
			}
		}
		fprintf(archivo, "%s ", _descrip);
		fprintf(archivo, "%s\n", _capacidad);
		fclose(archivo);

	}

	void BuscarAula() {
		leer.open("Aula.txt");
		leer >> cod_aula;
		cin.ignore();
		cout << "Ingrese Codigo de aula: ";
		cin.getline(b_cod_aula, 10);
		int tam = strlen(b_cod_aula);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de aula 3 digitos max: "; cin.getline(b_cod_aula, 10);
			tam = strlen(b_cod_aula);
		}
		bool encontrado = false;
		while (!leer.eof()) {
			leer >> descripcion >> capacidad;

			if (cod_aula[0] == b_cod_aula[0] && cod_aula[1] == b_cod_aula[1] && cod_aula[2] == b_cod_aula[2]) {
				encontrado = true;
				cout << "\ncodido de aula:" << cod_aula << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;
				cout << "\nCapacidad: " << capacidad << endl;
				cout << endl;
			}
			if(encontrado == false) {
				cout << "\naula no encontrado\n";
			}

			leer >> cod_aula;
		}
		leer.close();
		system("pause");
	}

	void eliminarAula() {
		temp.open("temp.txt");
		leer.open("Aula");
		leer >> cod_aula;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese codigo de aula a eliminar: ";
		cin.getline(b_cod_aula, 10);
		int tam = strlen(b_cod_aula);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de aula 3 digitos max: "; cin.getline(b_cod_aula, 10);
			tam = strlen(b_cod_aula);
		}
		while (!leer.eof()) {
			leer >> descripcion >> capacidad;

			if (cod_aula[0] == b_cod_aula[0] && cod_aula[1] == b_cod_aula[1] && cod_aula[2] == b_cod_aula[2]) {
				encontrado = true;
				cout << "\ncodido de aula:" << cod_aula << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;
				cout << "\nCapacidad: " << capacidad << endl;
				cout << "\n\n-----Aula Eliminado----" << endl;
				cout << endl;
			}
			else {
				temp << cod_aula << " " << descripcion <<" "<< capacidad << endl;
			}

			leer >> cod_aula;

			if (encontrado == false) {
				cout << "\nAula no encontrado";
			}
		}
		leer.close();
		temp.close();
		remove("Aula.txt");
		rename("Temp.txt", "Aula.txt");
		system("pause");
	}

	void modificarAula() {
		int op;
		temp.open("temp.txt");
		leer.open("Aula");
		leer >> cod_aula;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese codigo de aula a eliminar: ";
		cin.getline(b_cod_aula, 10);
		int tam = strlen(b_cod_aula);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de aula 3 digitos max: "; cin.getline(b_cod_aula, 10);
			tam = strlen(b_cod_aula);
		}
		while (!leer.eof()) {
			leer >> descripcion >> capacidad;

			if (cod_aula[0] == b_cod_aula[0] && cod_aula[1] == b_cod_aula[1] && cod_aula[2] == b_cod_aula[2]) {
				encontrado = true;
				cout << "\ncodido de aula:" << cod_aula << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;
				cout << "\nCapacidad: " << capacidad << endl;
				cout << endl;

				cout << "\n\t1)codigo de aula\n\t2)descripcion\n\t3)Capacidad";
				cout << "\nElija la opcion a modificar: "; cin >> op;
				if (op == 1) {
					char Ncod_aula[4];
					cin.ignore();
					cout << "\nDigite nuevo codigo de aula: ";
					cin.getline(Ncod_aula, 4);
					temp << Ncod_aula << " " << descripcion <<" "<< capacidad << endl;
					cout << endl;
				}



				if (op == 2) {
					char Ndescripcion[50];
					cin.ignore();
					cout << "\nDigite nueva descripcion: ";
					cin.getline(Ndescripcion, 50);
					for (int i = 0; i < 50; i++) {
						if (Ndescripcion[i] == ' ') {
							Ndescripcion[i] = '_';
						}
					}
					temp << cod_aula << " " << Ndescripcion <<" "<<capacidad<< endl;
					cout << endl;
				}
				if (op == 3) {
					char Ncapacidad[4];
					cin.ignore();
					cout << "\nDigite la nueva capacidad: ";
					cin.getline(Ncapacidad, 4);
					temp << cod_aula << " " << descripcion << " "<< Ncapacidad << endl;
					cout << endl;
				}
			}
			else {
				temp << cod_aula << " " << descripcion << " " << capacidad <<endl;
			}


			leer >> cod_aula;

			if (encontrado == false) {
				cout << "\nAula no encontrado";
			}
		}
		leer.close();
		temp.close();
		remove("Aula.txt");
		rename("Temp.txt", "Aula.txt");
		system("pause");
	}

	struct Nodo {
		char cod_aula[4];
		char descripcion[50];
		char capacidad[4];
		Nodo* siguiente;
	};

	void insertarAula(Nodo*& lista, char _codaula[4], char _descripcion[50],char _capacidad[4]) {
		Nodo* nuevo_nodo = new Nodo();
		int i;
		for (i = 0; i < 50; i++) {
			nuevo_nodo->descripcion[i] = _descripcion[i];

		}
		for (i = 0; i < 4; i++) {
			nuevo_nodo->cod_aula[i] = _codaula[i];
			nuevo_nodo->capacidad[i] = _capacidad[i];
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
			cout << "\nCodigo de aula: " << actual->cod_aula << endl;
			cout << "\nDescripcion: " << actual->descripcion << endl;
			cout << "\nCapacidad: " << actual->capacidad << endl;
			actual = actual->siguiente;
		}
		system("pause");
	}

	void mostrarlistAula() {
		Nodo* lista = NULL;
		leer.open("Aula.txt");
		leer >> cod_aula;
		while (!leer.eof()) {
			leer >> descripcion>>capacidad;
			insertarAula(lista, cod_aula, descripcion, capacidad);
			leer >> cod_aula;
			
		}

		leer.close();
		system("pause");
		complementarAntesDemostrar(lista);
	}

};