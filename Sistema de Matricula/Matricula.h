#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
#pragma warning(disable:4996)
using namespace std;

class Matricula {
private:
	char cod_matricula[10];
	char b_cod_matricula[10];
	char cod_estudiante[4];
	char cod_grupo[4];
	char cod_curso[4];
	char cod_profesor[4];
	char cod_horario[4];
	char comprobante[50];
	int num;
public:
	Matricula() {
		int i;
		for (i = 0; i < 4; i++) {
			
			cod_estudiante[i] = ' ';
			cod_grupo[i] = ' ';
			cod_curso[i] = ' ';
			cod_profesor[i] = ' ';
			cod_horario[i] = ' ';
		}
		for (i = 0; i < 50; i++) {
			comprobante[i] = ' ';
		}
		for (i = 0; i < 10; i++) {
			cod_matricula[i] = ' ';
			b_cod_matricula[i] = ' ';
		}
		num = 0;
	}
	~Matricula() {
		cout << "\n<<Liberando espacio de memoria>>\n";
	}
	int getnum() {
		return num;
	}
	ofstream temp;
	ifstream leer;

	void Matricular(char _cod_matricula[4],char _cod_estudiante[4],char _cod_grupo[4],char _cod_curso[4],char _cod_profesor[4],char _cod_horario[4],char _comprobante[50]){
		FILE* archivo;
		archivo = fopen("Matricula.txt", "a");

		if (archivo == NULL) {
			printf("No se puede abrir el archivo !!!");
			exit(1);
		}
		fprintf(archivo, "%s ", _cod_matricula);
		fprintf(archivo, "%s ", _cod_estudiante);
		fprintf(archivo, "%s ", _cod_grupo);
		fprintf(archivo, "%s ", _cod_curso);
		fprintf(archivo, "%s ", _cod_profesor);
		fprintf(archivo, "%s ", _cod_horario);
		for (int i = 0; i < 50; i++) {
			if (_comprobante[i] == ' ') {
				_comprobante[i] = '_';
			}
		}
		num = atoi(_cod_grupo);
		fprintf(archivo, "%s\n", _comprobante);
		fclose(archivo);

	}

	void Desmatricular() {
		temp.open("temp.txt");
		leer.open("Matricula.txt");
		leer >> cod_matricula;
		cin.ignore();
		bool encontrado = false;
		cout << "\nIngrese  codigo de matricula para poder desmatricular: ";
		cin.getline(b_cod_matricula, 10);
		int tam = strlen(b_cod_matricula);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de matricula 3 digitos max: "; cin.getline(b_cod_matricula, 10);
			tam = strlen(b_cod_matricula);
		}
		while (!leer.eof()) {
			leer >> cod_estudiante >> cod_grupo >> cod_curso >> cod_profesor >>  cod_horario >>comprobante;

			if (cod_matricula[0] == b_cod_matricula[0] && cod_matricula[1] == b_cod_matricula[1] && cod_matricula[2] == b_cod_matricula[2] ) {
				encontrado = true;
				cout << "\ncodido de la matricula:" << cod_matricula << endl;
				cout << "\ncodigo del Estudiante:" << cod_estudiante << endl;
				cout << "\ncodigo del grupo: " << cod_grupo << endl;
				cout << "\ncodigo del curso: " << cod_curso << endl;
				cout << "\ncodigo del profesor: " << cod_profesor << endl;
				cout << "\ncodigo del horario: " << cod_horario << endl;
				
				for (int i = 0; i < 50; i++) {
					if (comprobante[i] == ' ') {
						comprobante[i] = '_';
					}
				}
				cout << "\nComprobante: " << comprobante << endl;
				
				
				cout << "\nSe ha desmatriculado correctamente";
				cout << endl;
			}
			else {
				temp << cod_matricula << " " << cod_estudiante << " " << cod_grupo << " " << cod_curso << " " << cod_profesor << " " << cod_horario << " " << comprobante << endl;
			}


			leer >> cod_matricula;

			if (encontrado == false) {
				cout << "\nNo se ha encontrado la matricula\n";
			}
		}
		leer.close();
		temp.close();
		remove("Matricula.txt");
		rename("Temp.txt", "Matricula.txt");
		system("pause");
	}

	void modificarMatricula() {
		int op;
		temp.open("temp.txt");
		leer.open("Matricula.txt");
		leer >> cod_matricula;
		cin.ignore();
		bool encontrado = false;
		cout << "\nIngrese  codigo de matricula para poder desmatricular: ";
		cin.getline(b_cod_matricula, 10);
		int tam = strlen(b_cod_matricula);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de matricula 3 digitos max: "; cin.getline(b_cod_matricula, 10);
			tam = strlen(b_cod_matricula);
		}
		while (!leer.eof()) {
			leer >> cod_estudiante >> cod_grupo >> cod_curso >> cod_profesor >> cod_horario >> comprobante;

			if (cod_matricula[0] == b_cod_matricula[0] && cod_matricula[1] == b_cod_matricula[1] && cod_matricula[2] == b_cod_matricula[2]) {
				encontrado = true;
				cout << "\ncodido de la matricula:" << cod_matricula << endl;
				cout << "\ncodigo del Estudiante:" << cod_estudiante << endl;
				cout << "\ncodigo del grupo: " << cod_grupo << endl;
				cout << "\ncodigo del curso: " << cod_curso << endl;
				cout << "\ncodigo del profesor: " << cod_profesor << endl;
				cout << "\ncodigo del horario: " << cod_horario << endl;

				for (int i = 0; i < 50; i++) {
					if (comprobante[i] == ' ') {
						comprobante[i] = '_';
					}
				}
				cout << "\nComprobante: " << comprobante << endl;
				cout << "\n\t1)Cod_matricula\n\t2)Cod_estudiante\n\t3)Cod_grupo\n\t4)Cod_curso\n\t5)Cod_profesor\n\t6)Cod_horario\n\t7)Comprobante\n";
				cout << "Elija la opcion a modificar: "; cin >> op;
				if (op == 1) {
					char Ncodmatricla[4];
					cin.ignore();
					cout << "\nDigite nuevo Codigo de matricula: ";
					cin.getline(Ncodmatricla, 4);
					temp << Ncodmatricla << " " << cod_estudiante << " " << cod_grupo << " " << cod_curso << " " << cod_profesor << " " << cod_horario << " " << comprobante << endl;
					cout << endl;
				}
				if (op == 2) {
					char NcodEst[4];
					cin.ignore();
					cout << "\nDigite nuevo Codigo de estudiante: ";
					cin.getline(NcodEst, 4);
					temp << cod_matricula << " " << NcodEst << " " << cod_grupo << " " << cod_curso << " " << cod_profesor << " " << cod_horario << " " << comprobante << endl;
					cout << endl;
				}
				if (op == 3) {
					char NcodGrup[4];
					cin.ignore();
					cout << "\nDigite nuevo Codigo de grupo: ";
					cin.getline(NcodGrup, 4);
					temp << cod_matricula << " " << cod_estudiante << " " << NcodGrup << " " << cod_curso << " " << cod_profesor << " " << cod_horario << " " << comprobante << endl;
					cout << endl;
				}
				if (op == 4) {
					char Ncodcurso[4];
					cin.ignore();
					cout << "\nDigite nuevo Codigo de curso: ";
					cin.getline(Ncodcurso, 4);
					temp << cod_matricula << " " << cod_estudiante << " " << cod_grupo << " " << Ncodcurso << " " << cod_profesor << " " << cod_horario << " " << comprobante << endl;
					cout << endl;
				}
				if (op == 5) {
					char Ncodprofesor[4];
					cin.ignore();
					cout << "\nDigite nuevo Codigo de profesor: ";
					cin.getline(Ncodprofesor, 4);
					temp << cod_matricula << " " << cod_estudiante << " " << cod_grupo << " " << cod_curso << " " << Ncodprofesor << " " << cod_horario << " " << comprobante << endl;
					cout << endl;
				}
				if (op == 6) {
					char Ncodhorario[4];
					cin.ignore();
					cout << "\nDigite nuevo Codigo de horario: ";
					cin.getline(Ncodhorario, 4);
					temp << cod_matricula << " " << cod_estudiante << " " << cod_grupo << " " << cod_curso << " " << cod_profesor << " " << Ncodhorario << " " << comprobante << endl;
					cout << endl;
				}
				if (op == 7) {
					char Ncomprobante[50];
					cin.ignore();
					cout << "\nDigite nuevo Comprobante: ";
					cin.getline(Ncomprobante, 50);
					for (int i = 0; i < 50; i++) {
						if (Ncomprobante[i] == ' ') {
							Ncomprobante[i] = '_';
						}
					}
					temp << cod_matricula << " " << cod_estudiante << " " << cod_grupo << " " << cod_curso << " " << cod_profesor << " " << cod_horario << " " << Ncomprobante << endl;
					cout << endl;
				}

			}
			else {
				temp << cod_matricula << " " << cod_estudiante << " " << cod_grupo << " " << cod_curso << " " << cod_profesor << " " << cod_horario << " " << comprobante << endl;
			}


			leer >> cod_matricula;

			if (encontrado == false) {
				cout << "\nNo se ha encontrado la matricula\n";
			}
		}
		leer.close();
		temp.close();
		remove("Matricula.txt");
		rename("Temp.txt", "Matricula.txt");
		system("pause");
	}

	void BuscarMatricula() {
		leer.open("Matricula.txt");
		leer >> cod_matricula;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese  codigo de matricula para poder desmatricular: ";
		cin.getline(b_cod_matricula, 10);
		int tam = strlen(b_cod_matricula);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de matricula 3 digitos max: "; cin.getline(b_cod_matricula, 10);
			tam = strlen(b_cod_matricula);
		}
		while (!leer.eof()) {
			leer >> cod_estudiante >> cod_grupo >> cod_curso >> cod_profesor >> cod_horario >> comprobante;

			if (cod_matricula[0] == b_cod_matricula[0] && cod_matricula[1] == b_cod_matricula[1] && cod_matricula[2] == b_cod_matricula[2]) {
				encontrado = true;
				cout << "\ncodido de la matricula:" << cod_matricula << endl;
				cout << "\ncodigo del Estudiante:" << cod_estudiante << endl;
				cout << "\ncodigo del grupo: " << cod_grupo << endl;
				cout << "\ncodigo del curso: " << cod_curso << endl;
				cout << "\ncodigo del profesor: " << cod_profesor << endl;
				cout << "\ncodigo del horario: " << cod_horario << endl;

				for (int i = 0; i < 50; i++) {
					if (comprobante[i] == ' ') {
						comprobante[i] = '_';
					}
				}
				cout << "\nComprobante: " << comprobante << endl;


				cout << endl;
			}
			if (encontrado == false) {
				cout << "\nNo se ha encontrado la matricula\n";
			}

			leer >> cod_matricula;
		}
		leer.close();
		system("pause");
	}

	struct Nodo {
		char cod_matricula[4];
		char b_cod_matricula[4];
		char cod_estudiante[4];
		char cod_grupo[4];
		char cod_curso[4];
		char cod_profesor[4];
		char cod_horario[4];
		char comprobante[50];
		Nodo* siguiente;
	};

	void insertarmatricula(Nodo*& lista, char _cod_matricula[4], char _cod_estudiante[4], char _cod_grupo[4], char _cod_curso[4], char _cod_profesor[4], char _cod_horario[4], char _comprobante[50]) {
		Nodo* nuevo_nodo = new Nodo();
		int i;
		for (i = 0; i < 50; i++) {
			nuevo_nodo->comprobante[i] = _comprobante[i];
		}
		for (i = 0; i < 4; i++) {
			nuevo_nodo->cod_estudiante[i] = _cod_estudiante[i];
			nuevo_nodo->cod_grupo[i] = _cod_grupo[i];
			nuevo_nodo->cod_horario[i] = _cod_horario[i];
			nuevo_nodo->cod_curso[i] = _cod_curso[i];
			nuevo_nodo->cod_matricula[i] = _cod_matricula[i];
			nuevo_nodo->cod_profesor[i] = _cod_profesor[i];
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
			cout << "\ncodido de la matricula:" << actual->cod_matricula << endl;
			cout << "\ncodigo del Estudiante:" << actual->cod_estudiante << endl;
			cout << "\ncodigo del grupo: " << actual->cod_grupo << endl;
			cout << "\ncodigo del curso: " << actual->cod_curso << endl;
			cout << "\ncodigo del profesor: " << actual->cod_profesor << endl;
			cout << "\ncodigo del horario: " << actual->cod_horario << endl;
			cout << "\nComprobante: " << actual->comprobante << endl;
			actual = actual->siguiente;
		}
		system("pause");
	}

	void mostrarlistMatricula() {
		Nodo* lista = NULL;
		leer.open("Matricula.txt");
		leer >> cod_matricula;
		while (!leer.eof()) {
			leer >> cod_estudiante >> cod_grupo >> cod_curso >> cod_profesor >> cod_horario >> comprobante;
			insertarmatricula(lista, cod_matricula, cod_estudiante, cod_grupo, cod_curso, cod_profesor, cod_horario, comprobante);
			leer >> cod_matricula;
			
		}

		leer.close();
		system("pause");
		complementarAntesDemostrar(lista);
	}

	
};
