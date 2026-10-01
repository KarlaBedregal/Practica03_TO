#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehiculo {
protected:
    string marca;

public:
    Vehiculo(const string& marca) : marca(marca) {}
    virtual ~Vehiculo() {}

    virtual void acelerar() const = 0;
    virtual void frenar() const = 0;

    string getMarca() const { return marca; }
};

class Automovil : public Vehiculo {
private:
    int numeroPuertas;

public:
    Automovil(const string& marca, int puertas)
        : Vehiculo(marca), numeroPuertas(puertas) {}

    void acelerar() const override {
        cout << "[Automovil " << marca << " - " << numeroPuertas
             << " puertas] Pisa el acelerador y sube a 100 km/h de forma suave." << endl;
    }

    void frenar() const override {
        cout << "[Automovil " << marca
             << "] Frena con sus frenos de disco y ABS hasta detenerse." << endl;
    }
};

class Motocicleta : public Vehiculo {
private:
    int cilindrada; // cc

public:
    Motocicleta(const string& marca, int cc)
        : Vehiculo(marca), cilindrada(cc) {}

    void acelerar() const override {
        cout << "[Motocicleta " << marca << " - " << cilindrada
             << " cc] Gira el punio y acelera rapido entre los autos." << endl;
    }

    void frenar() const override {
        cout << "[Motocicleta " << marca
             << "] Usa freno delantero y trasero a la vez para no derrapar." << endl;
    }
};

class Camion : public Vehiculo {
private:
    double capacidadToneladas;

public:
    Camion(const string& marca, double capacidad)
        : Vehiculo(marca), capacidadToneladas(capacidad) {}

    void acelerar() const override {
        cout << "[Camion " << marca << " - " << capacidadToneladas
             << " t] Acelera lento por el peso de la carga." << endl;
    }

    void frenar() const override {
        cout << "[Camion " << marca
             << "] Activa el freno de aire y necesita mas distancia para parar." << endl;
    }
};

int main() {
    vector<Vehiculo*> vehiculos;

    vehiculos.push_back(new Automovil("Toyota", 4));
    vehiculos.push_back(new Motocicleta("Honda", 250));
    vehiculos.push_back(new Camion("Volvo", 30));

    cout << "===== SISTEMA DE VEHICULOS =====" << endl << endl;

    // cada objeto ejecuta su propia version de acelerar y frenar
    for (Vehiculo* v : vehiculos) {
        v->acelerar();
        v->frenar();
        cout << "--------------------------------" << endl;
    }

    for (Vehiculo* v : vehiculos) {
        delete v;
    }
    vehiculos.clear();

    return 0;
}
