#include "CuentaCorriente.hpp"
#include <iostream>

CuentaCorriente::CuentaCorriente(string t, double s): CuentaBancaria(t,s) {}

CuentaCorriente::CuentaCorriente(string t, double s, shared_ptr<CajadeAhorro> c): CuentaBancaria(t,s), caja(c) {}

void CuentaCorriente::retirar(double cant){
    if(cant > balance){
        if (caja) {
            try {
                caja->retirar(cant - balance);
                cout << "Retiro exitoso desde Caja de Ahorro. Nuevo balance en Caja de Ahorro: $" << caja->balance << endl;
                balance = 0;// se retira lo que quedaba de la cuenta corriente
            } catch (runtime_error &e) {
                cout << "Error: " << e.what() << endl;
                return;
            }
        } else {
            cout << "Saldo insuficiente en ambas cuentas." << endl;
            return;
        }
    } else {
        balance -= cant;
    }
    cout << "Retiro exitoso de Cuenta Corriente. Nuevo balance: $" << balance << endl;
}


void CuentaCorriente::mostrarInfo(){
    cout<<"Nombre del titular de la cuenta: "<<Titular<<"\nTipo de caja: Cuenta Corriente\nBalance: "<<balance<<endl;
}

CuentaCorriente::~CuentaCorriente(){}