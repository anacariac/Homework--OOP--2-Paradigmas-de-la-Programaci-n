#include "ej4.hpp"
#include <iostream>

CuentaBancaria::CuentaBancaria(string titular, double balance): Titular(titular), balance(balance) {}

void CuentaBancaria::depositar(double cant){balance += cant;}

CajadeAhorro::CajadeAhorro(string t, double s): CuentaBancaria(t,s) {}

void CajadeAhorro::retirar(double cant){
    if(cant > balance) throw runtime_error("Saldo insuficiente.");

    balance-=cant;
}

void CajadeAhorro::mostrarInfo(){
    if(cantRep > 2){
        cout<<"Excedió la cantidad de veces que podía ver su información. Se descontarán $20 de su cuenta.";
        retirar(20);
    }
    cout<<"Nombre del titular de la cuenta: "<<Titular<<"\nTipo de caja: Caja de Ahorro\nBalance: "<<balance<<endl;
    cantRep++;
}

CuentaCorriente::CuentaCorriente(string t, double s, shared_ptr<CajadeAhorro> c): CuentaBancaria(t,s), caja(c) {}

void CuentaCorriente::retirar(double cant){
    if(cant > balance){
        caja->retirar(cant);
        cout << "Retiro exitoso desde Caja de Ahorro. Nuevo balance en Caja de Ahorro: $" << caja->balance << endl;
    }
    balance-=cant;
    cout << "Retiro exitoso de Cuenta Corriente. Nuevo balance: $" << balance << endl;
}


void CuentaCorriente::mostrarInfo(){
    cout<<"Nombre del titular de la cuenta: "<<Titular<<"\nTipo de caja: Cuenta Corriente\nBalance: "<<balance<<endl;
}

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