#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>

using namespace std;


class Horario {
private:
	char cod_Horario[10];
	char b_cod_horario[10];
	char descripcion[50];
	char dia[10];
	char horaInicio[5];
	char horaFin[5];
public:
	Horario() {
		int i;
		for (i = 0; i < 50; i++) {
			descripcion[i] = ' ';
		}
		for (i = 0; i < 5; i++) {
			horaInicio[i] = ' ';
			horaFin[i] = ' ';
		}
		for (i = 0; i < 10; i++) {
			dia[i] = ' ';
		}
		for (i = 0; i < 10; i++) {
			cod_Horario[i] = ' ';
			b_cod_horario[i] = ' ';
		}
	}
	~Horario() {
		cout << "\n<<Liberando espacio de memoria>>\n";
	}
	ofstream temp;
	ifstream leer;
	void agregarHorario(char _cod_hor[4], char _descrip[50],char _dia[10], char _hora_inicio[5], char _hora_fin[5]) {

		FILE* archivo;
		archivo = fopen("Horario.txt", "a");

		if (archivo == NULL) {
			printf("No se puede abrir el archivo !!!");
			exit(1);
		}
		fprintf(archivo, "%s ", _cod_hor);
		for (int i = 0; i < 50; i++) {
			if (_descrip[i] == ' ') {
				_descrip[i] = '_';
			}
		}
		fprintf(archivo, "%s ", _descrip);
		fprintf(archivo, "%s ", _dia);
		fprintf(archivo, "%s ", _hora_inicio);
		fprintf(archivo, "%s\n", _hora_fin);
		fclose(archivo);

	}

	void BuscarHorario() {
		leer.open("Horario.txt");
		leer >> cod_Horario;
		cin.ignore();
		cout << "Ingrese Codigo del Horario: ";
		cin.getline(b_cod_horario, 10);
		int tam = strlen(b_cod_horario);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de horario 3 digitos max: "; cin.getline(b_cod_horario, 10);
			tam = strlen(b_cod_horario);
		}
		bool encontrado = false;
		while (!leer.eof()) {
			leer >> descripcion >> dia >> horaInicio >> horaFin;

			if (cod_Horario[0] == b_cod_horario[0] && cod_Horario[1] == b_cod_horario[1] && cod_Horario[2] == b_cod_horario[2] ) {
				encontrado = true;
				cout << "\ncodido de Horario:" << cod_Horario << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;
				cout << "\nDia: " << dia << endl;
				cout << "\nHora de inicio: " << horaInicio << endl;
				cout << "\nHora Final: " << horaFin << endl;
				cout << endl;
			}
			if(encontrado == false) {
				cout << "\nHorario no encontrado\n";
			}

			leer >> cod_Horario;
		}
		leer.close();
		system("pause");
	}

	void eliminarHorario() {
		temp.open("temp.txt");
		leer.open("Horario.txt");
		leer >> cod_Horario;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese codigo de curso a eliminar: ";
		cin.getline(b_cod_horario, 10);
		int tam = strlen(b_cod_horario);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de horario 3 digitos max: "; cin.getline(b_cod_horario, 10);
			tam = strlen(b_cod_horario);
		}
		while (!leer.eof()) {
			encontrado = true;
			leer >> descripcion >> dia >> horaInicio >> horaFin;

			if (cod_Horario[0] == b_cod_horario[0] && cod_Horario[1] == b_cod_horario[1] && cod_Horario[2] == b_cod_horario[2]) {

				cout << "\ncodido de Horario:" << cod_Horario << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;
				cout << "\nDia: " << dia << endl;
				cout << "\nHora de inicio: " << horaInicio << endl;
				cout << "\nHora Final: " << horaFin << endl;
				cout << endl;

				cout << "\n\n-----Horario Eliminado----" << endl;
				cout << endl;
			}
			else {
				temp << cod_Horario << " " << descripcion << " " << dia << " " << horaInicio << " " << horaFin << endl;
			}

			leer >> cod_Horario;

			if (encontrado == false) {
				cout << "\nHorario no encontrado\n";
			}
		}
		leer.close();
		temp.close();
		remove("Horario.txt");
		rename("Temp.txt", "Horario.txt");
		system("pause");
	}

	void modificarHorario() {
		int op;
		temp.open("temp.txt");
		leer.open("Horario.txt");
		leer >> cod_Horario;
		cin.ignore();
		bool encontrado = false;
		cout << "Ingrese codigo de curso: ";
		cin.getline(b_cod_horario, 10);
		int tam = strlen(b_cod_horario);
		while (tam > 3) {
			cout << "No se existe ningun codigo mayor a 3 digitos";
			cout << "\nDigite nuevamente el codigo de horario 3 digitos max: "; cin.getline(b_cod_horario, 10);
			tam = strlen(b_cod_horario);
		}
		while (!leer.eof()) {
			leer >> descripcion >> dia >> horaInicio >> horaFin;

			if (cod_Horario[0] == b_cod_horario[0] && cod_Horario[1] == b_cod_horario[1] && cod_Horario[2] == b_cod_horario[2]) {
				encontrado = true;
				cout << "\ncodido de Horario:" << cod_Horario << endl;
				for (int i = 0; i < 50; i++) {
					if (descripcion[i] == '_') {
						descripcion[i] = ' ';
					}
				}
				cout << "\nDescripcion: " << descripcion << endl;
				cout << "\nDia: " << dia << endl;
				cout << "\nHora de inicio: " << horaInicio << endl;
				cout << "\nHora Final: " << horaFin << endl;
				cout << endl;
				cout << "\n\t1)codigo de horario\n\t2)descripcion\n\t3)Dia\n\t4)Hora inicio\n\t5)Hora Final";
				cout << "Elija la opcion a modificar: "; cin >> op;
				if (op == 1) {
					char Ncod_hor[4];
					cin.ignore();
					cout << "\nDigite nuevo codigo de horario: ";
					cin.getline(Ncod_hor, 4);
					temp << Ncod_hor << " " << descripcion << " " << dia << " " << horaInicio << " " << horaFin << endl;
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
					temp << cod_Horario << " " << Ndescripcion << " " << dia << " " << horaInicio << " " << horaFin << endl;
					cout << endl;
				}

				if (op == 3) {
					char Ndia[10];
					cin.ignore();
					cout << "\nDigite un nuevo dia: ";
					cin.getline(Ndia, 10);
					temp << cod_Horario << " " << descripcion << " " << Ndia << " " << horaInicio << " " << horaFin << endl;
					cout << endl;
				}
				if (op == 4) {
					char NhoraInicio[4];
					cin.ignore();
					cout << "\nDigite nueva hora de inicio: ";
					cin.getline(NhoraInicio, 4);
					temp << cod_Horario << " " << descripcion << " " << dia << " " << NhoraInicio << " " << horaFin << endl;
					cout << endl;
				}
				if (op == 4) {
					char Nhorafin[4];
					cin.ignore();
					cout << "\nDigite nueva hora fin: ";
					cin.getline(Nhorafin, 4);
					temp << cod_Horario << " " << descripcion << " " << dia << " " << horaInicio << " " << Nhorafin << endl;
					cout << endl;
				}

			}
			else {
				temp << cod_Horario << " " << descripcion << " " << dia << " " << horaInicio << " " << horaFin << endl;
			}


			leer >> cod_Horario;

			if (encontrado == false) {
				cout << "\nHorario no encontrado\n";
			}
		}
		leer.close();
		temp.close();
		remove("Horario.txt");
		rename("Temp.txt", "Horario.txt");
		system("pause");
	}

	struct Nodo {
		char cod_horario[4];
		char descripcion[50];
		char dia[10];
		char horainicio[5];
		char horafin[5];
		Nodo* siguiente;
	};

	void insertarHorario(Nodo*& lista, char _cod_horario[3], char _descripcion[50], char _dia[10], char _horainicio[3],char _horafin[3]) {
		Nodo* nuevo_nodo = new Nodo();
		int i;
		for (i = 0; i < 50; i++) {
			nuevo_nodo->descripcion[i] = _descripcion[i];

		}
		for (i = 0; i < 5; i++) {
			
			nuevo_nodo->horainicio[i] = _horainicio[i];
			nuevo_nodo->horafin[i] = _horafin[i];
		}
		for (i = 0; i < 10; i++) {
			nuevo_nodo->dia[i] = _dia[i];
		}
		for (i = 0; i < 4; i++) {
			nuevo_nodo->cod_horario[i] = _cod_horario[i];
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
			cout << "\nCodigo de Horario: " << actual->cod_horario << endl;
			cout << "\nDescripcion: " << actual->descripcion << endl;
			cout << "\nDia: " << actual->dia << endl;
			cout << "\nHora de inicio: " << actual->horainicio << endl;
			cout << "\nHora fin: " << actual->horafin << endl;

			actual = actual->siguiente;
		}
		system("pause");
	}

	void mostrarlistHorario() {
		Nodo* lista = NULL;
		leer.open("Horario.txt");
		leer >> cod_Horario;
		while (!leer.eof()) {
			leer >> descripcion >> dia >> horaInicio >> horaFin;
			insertarHorario(lista, cod_Horario, descripcion, dia, horaInicio, horaFin);
			leer >> cod_Horario;
			
		}

		leer.close();
		system("pause");
		complementarAntesDemostrar(lista);
	}
};
