#pragma once
#include <string>
#include <memory>
using namespace std;

class CuentaBancaria{
protected:
    double balance;
    string Titular;
public:
    CuentaBancaria(string titular, double balance);
    void depositar(double cant);
    virtual void retirar(double cant) = 0;
    virtual void mostrarInfo() = 0;
};

class CajadeAhorro: public CuentaBancaria{
private:
    int cantRep = 0;
public:
    CajadeAhorro(string titular, double saldo);
    void retirar(double cant) override;
    void mostrarInfo() override;
    friend class CuentaCorriente;
};

class CuentaCorriente: public CuentaBancaria{
private:
    shared_ptr<CajadeAhorro> caja;
public:
    CuentaCorriente(string titutlar, double saldo, shared_ptr<CajadeAhorro> caja);
    void retirar(double cant) override;
    void mostrarInfo() override;
};

