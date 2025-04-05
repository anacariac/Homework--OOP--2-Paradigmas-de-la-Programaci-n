#include "CajadeAhorro.hpp"
#include <iostream>

CajadeAhorro::CajadeAhorro(string t, double s): CuentaBancaria(t,s) {}

void CajadeAhorro::retirar(double cant){
    if(cant > balance) throw runtime_error("Saldo insuficiente.");

    balance-=cant;
}

void CajadeAhorro::mostrarInfo(){
    if(cantRep >= 2){
        cout<<"Excedió la cantidad de veces que podía ver su información. Se descontarán $20 de su cuenta.";
        retirar(20);
    }
    cout<<"Nombre del titular de la cuenta: "<<Titular<<"\nTipo de caja: Caja de Ahorro\nBalance: "<<balance<<endl;
    cantRep++;
}

CajadeAhorro::~CajadeAhorro(){}