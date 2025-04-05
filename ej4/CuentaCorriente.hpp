#pragma once
#include "CajadeAhorro.hpp"

class CuentaCorriente: public CuentaBancaria{
    private:
        shared_ptr<CajadeAhorro> caja;
    public:
        CuentaCorriente(string titutlar, double saldo);
        CuentaCorriente(string titutlar, double saldo, shared_ptr<CajadeAhorro> caja);
        void retirar(double cant) override;
        void mostrarInfo() override;
        ~CuentaCorriente() override;
    };
    