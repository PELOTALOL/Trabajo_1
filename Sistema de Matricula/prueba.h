#include <iostream>

using namespace std;
	
class prueba {
private:

public:
    ifstream leer;
	void probar() {
        leer.open("Estudiante.txt");
        leer >> cod_est;
        cin.ignore();
        bool encontrado = false;
        cout << "Ingrese cedula: ";
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
                cout << "\nDireccion: " << direccion << "\n";

                cout << endl;
            }
            if (encontrado == false) {
                cout << "\nEstudiante no encontrado";
            }

            leer >> cod_est;
        }
        leer.close();
        system("pause");
    }
	}
};