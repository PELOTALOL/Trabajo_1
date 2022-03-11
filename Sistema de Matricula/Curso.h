#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>

using namespace std;

class Curso {
private:
	char cod_curso[10];
	char b_cod_cur[10];
	char nombre[50];
	char creditos[4];
	int cupo;
public:
	Curso() {
		int i;
		for (i = 0; i < 50; i++) {
			nombre[i] = ' ';
		}
		for (i = 0; i < 10; i++) {
			cod_curso[i] = ' ';
			b_cod_cur[i] = ' ';
		}
		for (i = 0; i < 4; i++) {
			creditos[i] = ' ';
		}
		cupo = 0;
	}
	~Curso() {
		cout << "\n<<Liberando espacio de memoria>>\n";
	}
	ofstream temp;
	ifstream leer;

	void agregarCurso(char _cod_cur[4],char _name[50],char _credi[2],int _cup) {

		FILE* archivo;
		archivo = fopen("Curso.txt", "a");

		if (archivo == NULL) {
			printf("No se puede abrir el archivo !!!");
			exit(1);
		}
		fprintf(archivo, "%s ", _cod_cur);
		for (int i = 0; i < 50; i++) {
			if (_name[i] == ' ') {
				_name[i] = '_';
			}
		}
		fprintf(archivo, "%s ", _name);
		fprintf(archivo, "%s ", _credi);
		fprintf(archivo, "%i\n", _cup);
		fclose(archivo);

	}

	void BuscarCurso() {
		leer.open("Curso.txt");
		leer >> cod_curso;
		cin.ignore();
		cout << "Ingrese Codigo de curso: ";
		cin.getline(b_cod_cur,10);
		int tam = strlen(b_cod_cur);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de curso 3 digitos max: "; cin.getline(b_cod_cur, 10);
			tam = strlen(b_cod_cur);
		}
		bool encontrado = false;
		while (!leer.eof()) {
			leer >> nombre >> creditos >> cupo;

			if (cod_curso[0]==b_cod_cur[0]&& cod_curso[1] == b_cod_cur[1] && cod_curso[2] == b_cod_cur[2]) {
				encontrado = true;
				cout << "\ncodido de curso:" << cod_curso << endl;
				for (int i = 0; i < 50; i++) {
					if (nombre[i] == '_') {
						nombre[i] = ' ';
					}
				}
				cout << "\nNombre: " << nombre << endl;
				cout << "\nCreditos: " << creditos << endl;
				cout << "\nCupos: " << cupo << endl;
				cout << endl;
			}
			
			if (encontrado == false) {
				cout << "\nCurso no encontrado";
			}

			leer >> cod_curso;
		}
		
		leer.close();
		system("pause");
	}

	void eliminarCurso() {
		temp.open("temp.txt");
		leer.open("Curso.txt");
		leer >> cod_curso;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese codigo de curso a eliminar: ";
		cin.getline(b_cod_cur, 10);
		int tam = strlen(b_cod_cur);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de curso 3 digitos max: "; cin.getline(b_cod_cur, 10);
			tam = strlen(b_cod_cur);
		}
		while (!leer.eof()) {
			leer >> nombre >> creditos >> cupo;

			if (cod_curso[0] == b_cod_cur[0] && cod_curso[1] == b_cod_cur[1] && cod_curso[2] == b_cod_cur[2]) {

				cout << "\ncodido de curso:" << cod_curso << endl;
				for (int i = 0; i < 50; i++) {
					if (nombre[i] == '_') {
						nombre[i] = ' ';
					}
				}
				cout << "\nNombre: " << nombre << endl;
				cout << "\nCreditos: " << creditos << endl;
				cout << "\nCupos: " << cupo << endl;
				cout << endl;
			
				cout << "\n\n-----Curso Eliminado----"<<endl;
				cout << endl;
			}
			else {
				temp <<cod_curso << " " << nombre << " " << creditos << " " << cupo << endl;
			}

			leer >> cod_curso;

			if (encontrado == false) {
				cout << "\nCurso no encontrado";
			}
		}
		leer.close();
		temp.close();
		remove("Curso.txt");
		rename("Temp.txt", "Curso.txt");
		system("pause");
	}

	void modificarCurso() {
		int op;
		temp.open("temp.txt");
		leer.open("Curso.txt");
		leer >> cod_curso;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese codigo de curso: ";
		cin.getline(b_cod_cur, 10);
		int tam = strlen(b_cod_cur);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de curso 3 digitos max: "; cin.getline(b_cod_cur, 10);
			tam = strlen(b_cod_cur);
		}
		while (!leer.eof()) {
			leer >> nombre >> creditos >> cupo;

			if (cod_curso[0] == b_cod_cur[0] && cod_curso[1] == b_cod_cur[1] && cod_curso[2] == b_cod_cur[2]) {
				encontrado = true;
				cout << "\ncodido de curso:" << cod_curso << endl;
				for (int i = 0; i < 50; i++) {
					if (nombre[i] == '_') {
						nombre[i] = ' ';
					}
				}
				cout << "\nNombre: " << nombre << endl;
				cout << "\nCreditos: " << creditos << endl;
				cout << "\nCupos: " << cupo << endl;
				cout << endl;
				cout << "\n\t1)codigo de curso\n\t2)nombre\n\t3)Creditos\n\t4)Cupos";
				cout << "Elija la opcion a modificar: "; cin >> op;
				if (op == 1) {
					char Ncodcur[4];
					cin.ignore();
					cout << "\nDigite nuevo codigo de curso: ";
					cin.getline(Ncodcur, 4);
					temp << Ncodcur << " " << nombre << " " << creditos << " " << cupo << endl;
					cout << endl;
				}

				
				
				if (op == 2) {
					char Nnombre[50];
					cin.ignore();
					cout << "\nDigite nuevo nombre: ";
					cin.getline(Nnombre, 50);
					for (int i = 0; i < 50; i++) {
						if (Nnombre[i] == ' ') {
							Nnombre[i] = '_';
						}
					}
					temp << cod_curso << " " << Nnombre << " " << creditos << " " << cupo << endl;
					cout << endl;
				}

				if (op == 3) {
					char Ncreditos[2];
					cin.ignore();
					cout << "\nDigite nueva cantidad de creditos: ";
					cin.getline(Ncreditos, 2);
					temp << cod_curso << " " << nombre << " " << Ncreditos << " " << cupo << endl;
					cout << endl;
				}
				if (op == 4) {
					int Ncupo;
					cout << "\nDigite nueva cantidad de cupos: ";
					cin >> Ncupo;
					temp << cod_curso << " " << nombre << " " << creditos << " " << Ncupo << endl;
					cout << endl;
				}

			}
			else {
				temp << cod_curso << " " << nombre << " " << creditos << " " << cupo << endl;
			}


			leer >> cod_curso;

			if (encontrado == false) {
				cout << "\nCurso no encontrado";
			}
		}
		leer.close();
		temp.close();
		remove("Curso.txt");
		rename("Temp.txt","Curso.txt");
		system("pause");
	}

	struct Nodo {
		char cod_curso[4];
		char nombre[50];
		char creditos[2];
		int cupo;
		Nodo* siguiente;
	};

	void insertarCurso(Nodo*& lista, char _cod_cur[4], char _name[50], char _credi[2], int _cup) {
		Nodo* nuevo_nodo = new Nodo();
		int i;
		for (i = 0; i < 50; i++) {
			nuevo_nodo->nombre[i] = _name[i];
			
		}
		for (i = 0; i < 4; i++) {
			nuevo_nodo->cod_curso[i] = _cod_cur[i];
		}
		for (i = 0; i < 2; i++) {
			nuevo_nodo->creditos[i] = _credi[i];
		}
		
			nuevo_nodo->cupo = cupo;
		
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
			cout << "\nCodigo de Curso: " << actual->cod_curso << endl;
			cout << "\nNombre: " << actual->nombre << endl;
			cout << "\nCreditos: " << actual->creditos << endl;
			cout << "\nCupos: " << actual->cupo << endl;
			
			actual = actual->siguiente;
		}
		system("pause");
	}

	void mostrarlistCurso() {
		Nodo* lista = NULL;
		leer.open("Curso.txt");
		leer >> cod_curso;
		while (!leer.eof()) {
			leer >> nombre >> creditos >> cupo ;
			insertarCurso(lista, cod_curso, nombre, creditos, cupo);
			leer >> cod_curso;
			
		}

		leer.close();
		system("pause");
		complementarAntesDemostrar(lista);
	}
	
	void aumentarCupoCurso(int num) {
		int op;
		temp.open("temp.txt");
		leer.open("Curso.txt");
		leer >> cod_curso;
	
		Estudiante e;
		while (!leer.eof()) {
			leer >> nombre >> creditos >> cupo;

			sprintf(b_cod_cur, "%d",num );

			if (cod_curso[0] == b_cod_cur[0] && cod_curso[1] == b_cod_cur[1] ) {
				
				op = 4;
				if (op == 4) {
					int Ncupo=cupo+1;
					temp << cod_curso << " " << nombre << " " << creditos << " " << Ncupo << endl;
					cout << endl;
				}

			}
			else {
				temp << cod_curso << " " << nombre << " " << creditos << " " << cupo << endl;
			}

			leer >> cod_curso;

		}
		leer.close();
		temp.close();
		remove("Curso.txt");
		rename("Temp.txt", "Curso.txt");
		system("pause");
		
	}
	
	void resducirCupoCurso(int num) {

		int op;
		temp.open("temp.txt");
		leer.open("Curso.txt");
		leer >> cod_curso;

		Estudiante e;
		while (!leer.eof()) {
			leer >> nombre >> creditos >> cupo;

			sprintf(b_cod_cur, "%d", num);

			if (cod_curso[0] == b_cod_cur[0] && cod_curso[1] == b_cod_cur[1]) {

				op = 4;
				if (op == 4) {
					int Ncupo = cupo - 1;
					temp << cod_curso << " " << nombre << " " << creditos << " " << Ncupo << endl;
					cout << endl;
				}

			}
			else {
				temp << cod_curso << " " << nombre << " " << creditos << " " << cupo << endl;
			}

			leer >> cod_curso;

		}
		leer.close();
		temp.close();
		remove("Curso.txt");
		rename("Temp.txt", "Curso.txt");
		system("pause");

	}
};