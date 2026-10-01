#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Empleado {
protected:
    string nombre;

public:
    Empleado(const string& nombre) : nombre(nombre) {}
    virtual ~Empleado() {}

    // virtual puro, cada tipo de empleado lo calcula a su manera
    virtual double calcularSalario() const = 0;
    virtual string getTipo() const = 0;

    void mostrarInformacion() const {
        cout << "Nombre : " << nombre << endl;
        cout << "Tipo   : " << getTipo() << endl;
        cout << fixed << setprecision(2);
        cout << "Salario: S/ " << calcularSalario() << endl;
    }
};

class EmpleadoTiempoCompleto : public Empleado {
private:
    double salarioFijo;

public:
    EmpleadoTiempoCompleto(const string& nombre, double salarioFijo)
        : Empleado(nombre), salarioFijo(salarioFijo) {}

    double calcularSalario() const override {
        return salarioFijo;
    }

    string getTipo() const override {
        return "Tiempo completo";
    }
};

class EmpleadoMedioTiempo : public Empleado {
private:
    int horasTrabajadas;
    double pagoPorHora;

public:
    EmpleadoMedioTiempo(const string& nombre, int horas, double pagoHora)
        : Empleado(nombre), horasTrabajadas(horas), pagoPorHora(pagoHora) {}

    double calcularSalario() const override {
        return horasTrabajadas * pagoPorHora;
    }

    string getTipo() const override {
        return "Medio tiempo";
    }
};

class EmpleadoPorComision : public Empleado {
private:
    double salarioBase;
    double ventas;
    double porcentajeComision; // 10 = 10%

public:
    EmpleadoPorComision(const string& nombre, double base,
                        double ventas, double porcentaje)
        : Empleado(nombre), salarioBase(base),
          ventas(ventas), porcentajeComision(porcentaje) {}

    double calcularSalario() const override {
        return salarioBase + ventas * (porcentajeComision / 100.0);
    }

    string getTipo() const override {
        return "Por comision";
    }
};

int main() {
    vector<Empleado*> empleados;

    empleados.push_back(new EmpleadoTiempoCompleto("Ana Torres", 3500.00));
    empleados.push_back(new EmpleadoMedioTiempo("Luis Quispe", 80, 15.50));
    empleados.push_back(new EmpleadoPorComision("Maria Flores", 1200.00, 20000.00, 10));

    cout << "===== SISTEMA DE EMPLEADOS =====" << endl << endl;

    double total = 0;
    for (Empleado* e : empleados) {
        e->mostrarInformacion(); // aqui se ve el polimorfismo
        total += e->calcularSalario();
        cout << "--------------------------------" << endl;
    }
    cout << "Total en planilla: S/ " << total << endl;

    for (Empleado* e : empleados) {
        delete e;
    }
    empleados.clear();

    return 0;
}
