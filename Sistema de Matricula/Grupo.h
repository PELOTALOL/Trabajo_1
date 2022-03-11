#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>

using namespace std; 

class Grupo {
private:
	char cod_grupo[10];
	char descripcion[50];
	char b_cod_grupo[10];
public:
	Grupo() {
		int i;
		for (i = 0; i < 50; i++) {
			descripcion[i] = ' ';
		}
		for (i = 0; i < 10; i++) {
			cod_grupo[i] = ' ';
			b_cod_grupo[i] = ' ';
		}
	}
	char getcod_grupo() {
		for (int i = 0; i < 3; i++) {
			return cod_grupo[i];
		}
	}

	~Grupo() {
		cout << "\n<<Liberando espacio de memoria>>\n";
	}

	ofstream temp;
	ifstream leer;

	void agregarGrupo(char _cod_grupo[4], char _descrip[50]) {

		FILE* archivo;
		archivo = fopen("Grupo.txt", "a");

		if (archivo == NULL) {
			printf("No se puede abrir el archivo !!!");
			exit(1);
		}
		fprintf(archivo, "%s ", _cod_grupo);

		for (int i = 0; i < 50; i++) {
			if (_descrip[i] == ' ') {
				_descrip[i] = '_';
			}
		}
		fprintf(archivo, "%s\n", _descrip);
		
		fclose(archivo);

	}

	void BuscarGrupo() {
		leer.open("Grupo.txt");
		leer >> cod_grupo;
		cin.ignore();
		cout << "Ingrese Codigo del grupo: ";
		cin.getline(b_cod_grupo, 10);
		int tam = strlen(b_cod_grupo);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de grupo 3 digitos max: "; cin.getline(b_cod_grupo, 10);
			tam = strlen(b_cod_grupo);
		}
		bool encontrado = false;
		while (!leer.eof()) {
			leer >> descripcion;

			if (cod_grupo[0] == b_cod_grupo[0] && cod_grupo[1] == b_cod_grupo[1] && cod_grupo[2] == b_cod_grupo[2]) {
				 encontrado = true;
				cout << "\ncodido de Grupo:" << cod_grupo << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;
				cout << endl;
			}
			if(encontrado == false) {
				cout << "\nGrupo no encontrado\n";
			}

			leer >> cod_grupo;
		}
		leer.close();
		system("pause");
	}

	void eliminarGrupo() {
		temp.open("temp.txt");
		leer.open("Grupo.txt");
		leer >> cod_grupo;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese codigo de grupo a eliminar: ";
		cin.getline(b_cod_grupo, 10);
		int tam = strlen(b_cod_grupo);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de grupo 3 digitos max: "; cin.getline(b_cod_grupo, 10);
			tam = strlen(b_cod_grupo);
		}
		while (!leer.eof()) {
			leer >> descripcion;

			if (cod_grupo[0] == b_cod_grupo[0] && cod_grupo[1] == b_cod_grupo[1] && cod_grupo[2] == b_cod_grupo[2]) {
				encontrado = true;
				cout << "\ncodido de grupo:" << cod_grupo << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;
				
				cout << endl;

				cout << "\n\n-----Grupo Eliminado----" << endl;
				cout << endl;
			}
			else {
				temp << cod_grupo << " " << descripcion << endl;
			}

			leer >> cod_grupo;

			if (encontrado == false) {
				cout << "\nGrupo no encontrado";
			}
		}
		leer.close();
		temp.close();
		remove("Grupo.txt");
		rename("Temp.txt", "Grupo.txt");
		system("pause");
	}

	void modificarGrupo() {
		int op;
		temp.open("temp.txt");
		leer.open("Grupo.txt");
		leer >> cod_grupo;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese codigo de grupo: ";
		cin.getline(b_cod_grupo, 10);
		int tam = strlen(b_cod_grupo);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de grupo 3 digitos max: "; cin.getline(b_cod_grupo, 10);
			tam = strlen(b_cod_grupo);
		}
		while (!leer.eof()) {
			leer >> descripcion ;

			if (cod_grupo[0] == b_cod_grupo[0] && cod_grupo[1] == b_cod_grupo[1] && cod_grupo[2] == b_cod_grupo[2]) {
				encontrado = true;
				cout << "\ncodido de Grupo:" << cod_grupo << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;

				cout << endl;

				cout << "\n\t1)codigo de Grupo\n\t2)descripcion";
				cout << "\nElija la opcion a modificar: "; cin >> op;
				if (op == 1) {
					char Ncod_grup[4];
					cin.ignore();
					cout << "\nDigite nuevo codigo de Gupo: ";
					cin.getline(Ncod_grup, 4);
					temp << Ncod_grup << " " << descripcion  << endl;
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
					temp << cod_grupo << " " << Ndescripcion <<  endl;
					cout << endl;
				}
			}
			else {
				temp << cod_grupo << " " << descripcion <<  endl;
			}


			leer >> cod_grupo;

			if (encontrado == false) {
				cout << "\nGrupo no encontrado";
			}
		}
		leer.close();
		temp.close();
		remove("Grupo.txt");
		rename("Temp.txt", "Grupo.txt");
		system("pause");
	}

	struct Nodo {
		char cod_grupo[4];
		char descripcion[50];
	
		Nodo* siguiente;
	};

	void insertargrupo(Nodo*& lista, char _codgrup[4], char _descripcion[50]) {
		Nodo* nuevo_nodo = new Nodo();
		int i;
		for (i = 0; i < 50; i++) {
			nuevo_nodo->descripcion[i] = _descripcion[i];

		}
		for (i = 0; i < 4; i++) {
			nuevo_nodo->cod_grupo[i] = _codgrup[i];
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
			cout << "\nCodigo de Grupo: " << actual->cod_grupo << endl;
			cout << "\nDescripcion: " << actual->descripcion << endl;
			actual = actual->siguiente;
		}
		system("pause");
	}

	void mostrarlistGrupo() {
		Nodo* lista = NULL;
		leer.open("Grupo.txt");
		leer >> cod_grupo;
		while (!leer.eof()) {
			leer >> descripcion ;
			insertargrupo(lista, cod_grupo, descripcion);
			leer >> cod_grupo;
			
		}

		leer.close();
		system("pause");
		complementarAntesDemostrar(lista);
	}

};
