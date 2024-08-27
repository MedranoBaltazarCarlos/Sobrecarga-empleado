#include <iostream>
#include <cstring>

using namespace std;

class Empleado {
private:
    int ClavEmpleado;
    char Nombre[50];
    char Domicilio[100];
    float Sueldo;
    char ReportaA[50];

public:
    // Constructor
    Empleado(int clave = 0, const char* nombre = "", const char* domicilio = "", float sueldo = 0.0, const char* reportaA = "") {
        ClavEmpleado = clave;
        strcpy(Nombre, nombre);
        strcpy(Domicilio, domicilio);
        Sueldo = sueldo;
        strcpy(ReportaA, reportaA);
    }

    // Sobrecarga de operadores
    bool operator==(const Empleado& other) const {
        return ClavEmpleado == other.ClavEmpleado;
    }

    bool operator!=(const Empleado& other) const {
        return !(*this == other);
    }

    bool operator<(const Empleado& other) const {
        return Sueldo < other.Sueldo;
    }

    bool operator>(const Empleado& other) const {
        return Sueldo > other.Sueldo;
    }

    Empleado operator+(const Empleado& other) const {
        Empleado nuevo;
        nuevo.Sueldo = this->Sueldo + other.Sueldo;
        return nuevo;
    }

    friend istream& operator>>(istream& in, Empleado& empleado) {
        cout << "Ingrese la clave del empleado: ";
        in >> empleado.ClavEmpleado;
        in.ignore();
        cout << "Ingrese el nombre del empleado: ";
        in.getline(empleado.Nombre, 50);
        cout << "Ingrese el domicilio del empleado: ";
        in.getline(empleado.Domicilio, 100);
        cout << "Ingrese el sueldo del empleado: ";
        in >> empleado.Sueldo;
        in.ignore();
        cout << "Ingrese a quien reporta el empleado: ";
        in.getline(empleado.ReportaA, 50);
        return in;
    }

    friend ostream& operator<<(ostream& out, const Empleado& empleado) {
        out << "Clave Empleado: " << empleado.ClavEmpleado << endl;
        out << "Nombre: " << empleado.Nombre << endl;
        out << "Domicilio: " << empleado.Domicilio << endl;
        out << "Sueldo: " << empleado.Sueldo << endl;
        out << "Reporta A: " << empleado.ReportaA << endl;
        return out;
    }

    // Métodos para modificar atributos
    void CambiarDomicilio(const char* nuevoDomicilio) {
        strcpy(Domicilio, nuevoDomicilio);
    }

    void ActualizarSueldo(float porcentajeIncremento) {
        Sueldo += Sueldo * (porcentajeIncremento / 100);
    }

    void CambiarReportaA(const char* nuevoReportaA) {
        strcpy(ReportaA, nuevoReportaA);
    }

    // Método para obtener la clave
    int ObtenerClave() const {
        return ClavEmpleado;
    }
};

int main() {
    // Declarar objetos JefePlanta y JefePersonal
    Empleado JefePlanta(1, "Juan Perez", "Calle Principal 123", 50000, "Director General");
    Empleado JefePersonal(2, "Maria Lopez", "Avenida Secundaria 456", 45000, "Director de Recursos Humanos");

    int opcion;
    int clave;
    char nuevoDomicilio[100];
    float porcentajeIncremento;
    char nuevoReportaA[50];

    do {
        cout << "\nMenu de Opciones:\n";
        cout << "1. Cambiar domicilio de un empleado\n";
        cout << "2. Actualizar sueldo de un empleado\n";
        cout << "3. Imprimir datos de un empleado\n";
        cout << "4. Cambiar la persona a quien reporta un empleado\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el nuevo domicilio: ";
                cin.ignore();
                cin.getline(nuevoDomicilio, 100);
                if (clave == JefePlanta.ObtenerClave()) {
                    JefePlanta.CambiarDomicilio(nuevoDomicilio);
                } else if (clave == JefePersonal.ObtenerClave()) {
                    JefePersonal.CambiarDomicilio(nuevoDomicilio);
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;

            case 2:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el porcentaje de incremento: ";
                cin >> porcentajeIncremento;
                if (clave == JefePlanta.ObtenerClave()) {
                    JefePlanta.ActualizarSueldo(porcentajeIncremento);
                } else if (clave == JefePersonal.ObtenerClave()) {
                    JefePersonal.ActualizarSueldo(porcentajeIncremento);
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;

            case 3:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                if (clave == JefePlanta.ObtenerClave()) {
                    cout << JefePlanta;
                } else if (clave == JefePersonal.ObtenerClave()) {
                    cout << JefePersonal;
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;

            case 4:
                cout << "Ingrese la clave del empleado: ";
                cin >> clave;
                cout << "Ingrese el nuevo nombre de la persona a quien reporta: ";
                cin.ignore();
                cin.getline(nuevoReportaA, 50);
                if (clave == JefePlanta.ObtenerClave()) {
                    JefePlanta.CambiarReportaA(nuevoReportaA);
                } else if (clave == JefePersonal.ObtenerClave()) {
                    JefePersonal.CambiarReportaA(nuevoReportaA);
                } else {
                    cout << "Empleado no encontrado.\n";
                }
                break;

            case 5:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion no valida.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}
