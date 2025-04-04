#pragma once
#include <string>
#include <memory>
using namespace std;

class CuentaBancaria{
    protected:
        string Titular;
        double balance;
    public:
        CuentaBancaria(string titular, double balance);
        void depositar(double cant);
        virtual void retirar(double cant) = 0;
        virtual void mostrarInfo() = 0;
    };

