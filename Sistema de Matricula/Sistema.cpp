#include <iostream>
#include <fstream>
#include <cstdio>
#include <string.h>
#include <stdio.h>
#include "Estudiante.h"
#include "Profesor.h"
#include "Curso.h"
#include "Horario.h"
#include "Aula.h"
#include "Grupo.h"
#include "Matricula.h"
#pragma warning(disable:4996)

using namespace std;

void menu() {
    cout << "\n----------Bienvenido al Sistema de Matricula de la Universidad Warner------" << endl;
    cout << "\n1)Buscar en archivos"<<endl;
    cout << "\n2)Insertar datos a un archivo " << endl;
    cout << "\n3)Modificar datos de un archivo" << endl;
    cout << "\n4)Elegir archivo a mostrar" << endl;
    cout << "\n5)Eliminar Datos de un archivo" << endl;
    cout << "\n6)Mostrar Lista enlazada de archivos" << endl;
    cout << "\n7)Matricular un nuevo Estudiante "<< endl;

    cout << "\n0)Salir" << endl;
}

int main() {
    
    int opcion;
    int tam;

    //Bloque para declarar las variables necesarias para agregar informacion a los archivos

    char nombre[50]; 
    char apellido1[50];
    char cedula[20];
    char apellido2[50];
    char cod_est[10];
    char cod_grupo[10]; 
    char telefono[20]; 
    char direccion[50];
    char codigoProfesor[10];
    char cod_curso[10];
    char creditos[10];
    int cupo;
    char cod_Horario[10];
	char descripcion[50];
	char dia[10];
	char horaInicio[10];
	char horaFin[10];
    char capacidad[10];
    char cod_aula[10];
    char cod_matricula[10];
    char comprobante[50];

    ////fin de bloque

    //incio de bloque para declaracion de clases
    Estudiante* e;
    e = new Estudiante();

    Profesor* p;
    p = new Profesor();

    Curso* c;
    c = new Curso();

    Horario* h;
    h = new Horario();

    Grupo* g;
    g = new Grupo();

    Aula* a;
    a = new Aula();

    Matricula* m;
    m = new Matricula();

    //////Fin de bloque

    while (true) {
        system("cls");

        menu();
        cout << "\nSeleccione su opcion: ";  cin >> opcion;
        switch (opcion) {
            case 1: {
                int op;
                cout << "\n\t1)Estudiante\n\t2)Profesor\n\t3)Curso\n\t4)Horario\n\t5)Grupo\n\t6)Aula\n\t7)Matricula";
                cout << "\nCual desea buscar: "; cin >> op;
                if (op == 1) {
                    e->BuscarEstudiante();
                }
                if (op == 2) {
                    p->BuscarProfesor();
                }
                if (op == 3) {
                    c->BuscarCurso();
                }
                if (op == 4) {
                    h->BuscarHorario();
                }
                if (op == 5) {
                    g->BuscarGrupo();
                }
                if (op == 6) {
                    a->BuscarAula();
                }
                if (op == 7) {
                    m->BuscarMatricula();
                }
                
            }
                break;
            case 2: {
                int op;
                cout << "\n\t1)Estudiante\n\t2)Profesor\n\t3)Curso\n\t4)Horario\n\t5)Grupo\n\t6)Aula";
                cout << "\nCual desea buscar: "; cin >> op;
                if (op == 1) {
                    cin.ignore();
                    cout << "\nDigite Nombre: "; cin.getline(nombre, 50);

                    cout << "\nDigite apellido 1: "; cin.getline(apellido1, 50);

                    cout << "\nDigite apellido 2: "; cin.getline(apellido2, 50);
 
                    cout << "\nDigite cedula: "; cin.getline(cedula, 20);
                    tam = strlen(cedula);
                    while (tam>9) {
                        cout << "La cedula no se puede guardar";
                        cout << "\nDigite nuevamente la cedula con 9 digitos max: "; cin.getline(cedula, 20);
                        tam = strlen(cedula);
                    }
                    cout << "\nCodigo estudiante: "; cin.getline(cod_est, 10);
                    tam = strlen(cod_est);
                    while (tam > 3) {
                        cout << "No se existe ningun codigo mayor a 3 digitos";
                        cout << "\nDigite nuevamente el codigo de aula 3 digitos max: "; cin.getline(cod_est, 10);
                        tam = strlen(cod_est);
                    }
                    cout << "\nCodigo grupo: "; cin.getline(cod_grupo, 10);
                    tam = strlen(cod_grupo);
                    while (tam > 3) {
                        cout << "No se existe ningun codigo mayor a 3 digitos";
                        cout << "\nDigite nuevamente el codigo de grupo 3 digitos max: "; cin.getline(cod_grupo, 10);
                        tam = strlen(cod_grupo);
                    }
                    cout << "\nTelefono: "; cin.getline(telefono, 20);
                    tam = strlen(telefono);
                    while (tam > 8) {
                        cout << "\nEl telefono no se puede guardar";
                        cout << "\nDigite nuevamente el numero de telefono 8 digitos max: "; cin.getline(telefono, 20);
                        tam = strlen(telefono);
                    }
                    cout << "\nDireccion: "; cin.getline(direccion, 50);

                    e->agregarEstudiante(nombre, apellido1, cedula, apellido2, cod_est, cod_grupo, telefono, direccion);
                }
                if (op == 2) {
                    cin.ignore();
                    cout << "\nDigite Nombre: "; cin.getline(nombre, 50);

                    cout << "\nDigite apellido 1: "; cin.getline(apellido1, 50);

                    cout << "\nDigite apellido 2: "; cin.getline(apellido2, 50);

                    cout << "\nDigite cedula: "; cin.getline(cedula, 20);
                    tam = strlen(cedula);
                    while (tam > 9) {
                        cout << "La cedula no se puede guardar";
                        cout << "\nDigite nuevamente la cedula con 9 digitos max: "; cin.getline(cedula, 20);
                        tam = strlen(cedula);
                    }
                    cout << "\nCodigo de profesor: "; cin.getline(codigoProfesor, 4);
                    tam = strlen(codigoProfesor);
                    while (tam > 3) {
                        cout << "No se existe ningun codigo mayor a 3 digitos";
                        cout << "\nDigite nuevamente el codigo de profesor 3 digitos max: "; cin.getline(codigoProfesor, 10);
                        tam = strlen(codigoProfesor);
                    }

                    cout << "\nCodigo grupo: "; cin.getline(cod_grupo, 4);
                    tam = strlen(cod_grupo);
                    while (tam > 3) {
                        cout << "No se existe ningun codigo mayor a 3 digitos";
                        cout << "\nDigite nuevamente el codigo de grupo 3 digitos max: "; cin.getline(cod_grupo, 10);
                        tam = strlen(cod_grupo);
                    }
                    cout << "\nTelefono: "; cin.getline(telefono, 20);
                    tam = strlen(telefono);
                    while (tam > 8) {
                        cout << "\nDigite nuevamente el numero de telefono 8 digitos max: "; cin.getline(telefono, 20);
                        tam = strlen(telefono);
                    }
                    cout << "\nDireccion: "; cin.getline(direccion, 50);

                    p->agregarProfesor(nombre, apellido1, cedula, apellido2, codigoProfesor, telefono, direccion);
                }
                if (op == 3) {
                    cin.ignore();
                    cout << "\nDigite codigo de curso: "; cin.getline(cod_curso, 4);
                    tam = strlen(cod_curso);
                    while (tam > 3) {
                        cout << "No se existe ningun codigo mayor a 3 digitos";
                        cout << "\nDigite nuevamente el codigo de curso 3 digitos max: "; cin.getline(cod_curso, 10);
                        tam = strlen(cod_curso);
                    }
                    cout << "\nDigite nombre : "; cin.getline(nombre, 50);

                    cout << "\nDigite la cantidad de creditos: "; cin.getline(creditos, 10);
                    tam = strlen(creditos);
                    while (tam > 3) {
                        cout << "\nDigite nuevamente la cantidad de creditos 3 digitos max: "; cin.getline(creditos, 10);
                        tam = strlen(creditos);
                    }
                    cout << "\nCupo: "; cin >> cupo;
                    while (cupo > 99 || cupo < 0) {
                        cout << "\ndigite nuevamente la cantidad de cupos que contenga como maximo 2 digitos: "; cin >> cupo;
                    }
                    c->agregarCurso(cod_curso, nombre, creditos,cupo);
                }
                if (op == 4) {
                    cin.ignore();
                    cout << "\nDigite codigod de horario: "; cin.getline(cod_Horario, 10);
                    tam = strlen(cod_Horario);
                    while (tam > 3) {
                        cout << "No se existe ningun codigo mayor a 3 digitos";
                        cout << "\nDigite nuevamente el codigo de horario 3 digitos max: "; cin.getline(cod_Horario, 10);
                        tam = strlen(cod_Horario);
                    }
                    cout << "\nDigite dia: "; cin.getline(dia, 10);

                    cout << "\nCdigite hora de inicio ejm(0420): "; cin.getline(horaInicio, 10);
                    tam = strlen(horaInicio);
                    while (tam > 4) {
                 
                        cout << "\nDigite nuevamente la hora inicio 4 digitos max: "; cin.getline(horaInicio, 10);
                        tam = strlen(horaInicio);
                    }
                    cout << "\ndigite hora final ejm(0610): "; cin.getline(horaFin, 10);
                    tam = strlen(horaFin);
                    while (tam > 4) {
                        cout << "\nDigite nuevamente la hora fin 4 digitos max: "; cin.getline(horaFin, 10);
                        tam = strlen(horaFin);
                    }
                    cout << "\nDigite descripcion: "; cin.getline(descripcion, 50);

                    h->agregarHorario(cod_Horario, descripcion, dia , horaInicio, horaFin);
                }
                if (op == 5) {
                    cin.ignore();
                    cout << "\nDigite codigod de grupo: "; cin.getline(cod_grupo, 10);
                    tam = strlen(cod_grupo);
                    while (tam > 3) {
                        cout << "No se existe ningun codigo mayor a 3 digitos";
                        cout << "\nDigite nuevamente el codigo de grupo 3 digitos max: "; cin.getline(cod_grupo, 10);
                        tam = strlen(cod_grupo);
                    }
                    cout << "\nDigite descripcion: "; cin.getline(descripcion, 50);
                    g->agregarGrupo(cod_grupo, descripcion);
                }
                if (op == 6) {
                    cin.ignore();
                    cout << "\nDigite codigo de aula: "; cin.getline(cod_aula, 10);
                    tam = strlen(cod_aula);
                    while (tam > 3) {
                        cout << "No se existe ningun codigo mayor a 3 digitos";
                        cout << "\nDigite nuevamente el codigo de aula 3 digitos max: "; cin.getline(cod_aula, 10);
                        tam = strlen(cod_aula);
                    }
                    cout << "\ndigite capacidad de aula: "; cin.getline(capacidad, 10);
                    tam = strlen(capacidad);
                    while (tam > 3) {
                       
                        cout << "\nDigite nuevamente la capacidad 3 digitos max: "; cin.getline(capacidad, 10);
                        tam = strlen(capacidad);
                    }
                    cout << "\nDigite descripcion: "; cin.getline(descripcion, 50);
                    a->agregarAula(cod_aula, descripcion, capacidad);
                }
               
            }
                  break;
            case 3: {
                int op;
                cout << "\n\t1)Estudiante\n\t2)Profesor\n\t3)Curso\n\t4)Horario\n\t5)Grupo\n\t6)Aula\n\t7)Matricula";
                cout << "\nElija el archivo: "; cin >> op;
                if (op == 1) {
                    e->modificarEstudiante();
                }
                if (op == 2) {
                    p->modificarProfesor();
                }
                if (op == 3) {
                    c->modificarCurso();
                }
                if (op == 4) {
                    h->modificarHorario();
                }
                if (op == 5) {
                    g->modificarGrupo();
                }
                if (op == 6) {
                    a->modificarAula();
                }
                if (op == 7) {
                    m->modificarMatricula();
                }
            }
                break;
            case 4: {
                system("cls");
                e->mostrarEstudiante();
            }
                  break;
            case 5: {
                int op;
                cout << "\n\t1)Estudiante\n\t2)Profesor\n\t3)Curso\n\t4)Horario\n\t5)Grupo\n\t6)Aula\n\t7)Matricula";
                cout << "\nElija el archivo: "; cin >> op;
                if (op == 1) {  
                    e->eliminarEstudiante();
                    
                    c->aumentarCupoCurso(e->getnum());
                }
                if (op == 2) {
                    p->eliminarProfesor();
                }
                if (op == 3) {
                    c->eliminarCurso();
                }
                if (op == 4) {
                    h->eliminarHorario();
                }
                if (op == 5) {
                    g->eliminarGrupo();
                }
                if (op == 6) {
                    a->eliminarAula();
                }
                if (op == 7) {
                    m->Desmatricular();
                }

            }
                  break;
            case 6: {
                int op;
                cout << "\n\t1)Estudiante\n\t2)Profesor\n\t3)Curso\n\t4)Horario\n\t5)Grupo\n\t6)Aula\n\t7)Matricula";
                cout << "\nCual lista desea ver: "; cin >> op;
                if (op == 1) {
                    e->mostrarlistEstudiante();
                }
                if (op == 2) {
                    p->mostrarlistProfesor();
                }
                if (op == 3) {
                    c->mostrarlistCurso();
                }
                if (op == 4) {
                    h->mostrarlistHorario();
                }
                if (op == 5) {
                    g->mostrarlistGrupo();
                }
                if (op == 6) {
                    a->mostrarlistAula();
                }
                if (op == 7) {
                    m->mostrarlistMatricula();
                }

            }
                break;
            case 7: {
                cin.ignore();
                cout << "\nIngrese codigo de matricula: ";
                cin.getline(cod_matricula,10);
                tam = strlen(cod_matricula);
                while (tam > 3) {
                    cout << "\nDigite nuevamente el codigo de matricula 3 digitos max: "; cin.getline(cod_matricula, 10);
                    tam = strlen(cod_matricula);
                }
                cout << "\nIngrese codigo de estudiante: ";
                cin.getline(cod_est,10);
                tam = strlen(cod_est);
                while (tam > 3) {
                  cout << "\nDigite nuevamente el codigo de estudiante 3 digitos max: "; cin.getline(cod_est, 10);
                    tam = strlen(cod_est);
                }
                cout << "\nDigite codigo de grupo: ";
                cin.getline(cod_grupo,10);
                tam = strlen(cod_grupo);
                while (tam > 3) {
                  
                    cout << "\nDigite nuevamente el codigo de grupo 3 digitos max: "; cin.getline(cod_grupo, 10);
                    tam = strlen(cod_grupo);
                }
                cout << "\nIngrese codigo de curso: ";
                cin.getline(cod_curso,4);
                tam = strlen(cod_curso);
                while (tam > 3) {
                    cout << "La cedula no se puede guardar";
                    cout << "\nDigite nuevamente el codigo de curso 3 digitos max: "; cin.getline(cod_curso, 10);
                    tam = strlen(cod_curso);
                }
                cout << "\nIngrese codigo de profesor: ";
                cin.getline(codigoProfesor,10);
                tam = strlen(codigoProfesor);
                while (tam > 4) {
                  ;
                    cout << "\nDigite nuevamente el codigo de profesor 3 digitos max: "; cin.getline(codigoProfesor, 10);
                    tam = strlen(codigoProfesor);
                }
                cout << "\nIngrese codigo de Horario: ";
                cin.getline(cod_Horario,10);
                tam = strlen(cod_Horario);
                while (tam > 3) {
          
                    cout << "\nDigite nuevamente el codigo de horario 3 digitos max: "; cin.getline(cod_Horario, 10);
                    tam = strlen(cod_Horario);
                }
                cout << "\nIngrese comprobante: ";
                cin.getline(comprobante,50);
                m->Matricular(cod_matricula, cod_est, cod_grupo, cod_curso, codigoProfesor, cod_Horario, comprobante);
                c->resducirCupoCurso(m->getnum());
            }
                  break;
            case 8:
                
                break;

            case 0:
                cout << "\n\tGracias Por utilizar nuestro sistema de matricula\n";
                return false;
                break;

            default:
                cout << "\nopcion incorrecta"<<endl;
                system("pause");
                break;
        }
    }
   
     return 0;

}