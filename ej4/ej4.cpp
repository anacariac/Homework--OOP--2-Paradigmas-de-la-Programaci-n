#include "ej4.hpp"
#include <iostream>

CuentaBancaria::CuentaBancaria(string titular, double balance): Titular(titular), balance(balance) {}

void CuentaBancaria::depositar(double cant){balance += cant;}

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


void CuentaCorriente::retirar(double cant){
    if(cant > balance) throw runtime_error("Saldo insuficiente.");
    balance-=cant;
}


void CuentaCorriente::mostrarInfo(){
    cout<<"Nombre del titular de la cuenta: "<<Titular<<"\nTipo de caja: Cuenta Corriente\nBalance: "<<balance<<endl;
}