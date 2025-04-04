#include "CuentaBancaria.hpp"
#include "CajadeAhorro.hpp"
#include "CuentaCorriente.hpp"
#include <iostream>

int main(){
    auto cajaAhorro = make_shared<CajadeAhorro>("Juan Perez", 500);
    CuentaCorriente cuentaCorriente("Juan Perez", 300, cajaAhorro);

    cout << "--- Estado inicial ---" << endl;
    cajaAhorro->mostrarInfo();
    cuentaCorriente.mostrarInfo();

    cout << "\n--- Depósito en Caja de Ahorro ---" << endl;
    cajaAhorro->depositar(200);
    cajaAhorro->mostrarInfo();

    cout << "\n--- Retiro de Cuenta Corriente (sin usar Caja de Ahorro) ---" << endl;
    cuentaCorriente.retirar(200);
    cuentaCorriente.mostrarInfo();

    cout << "\n--- Retiro de Cuenta Corriente (usando Caja de Ahorro) ---" << endl;
    cuentaCorriente.retirar(200);
    cuentaCorriente.mostrarInfo();
    cajaAhorro->mostrarInfo();

    cout << "\n--- Mostrando info varias veces para probar límite ---" << endl;
    cajaAhorro->mostrarInfo();
    cajaAhorro->mostrarInfo();
    cajaAhorro->mostrarInfo();
    cajaAhorro->mostrarInfo();
    return 0;
}