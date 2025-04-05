#pragma once
#include "CajadeAhorro.hpp"

class CuentaCorriente: public CuentaBancaria{
    private:
        shared_ptr<CajadeAhorro> caja; //smart pointer a caja de ahorro
    public:
        //Constructor
        CuentaCorriente(string titutlar, double saldo);
        CuentaCorriente(string titutlar, double saldo, shared_ptr<CajadeAhorro> caja);
        
        void retirar(double cant) override;
        void mostrarInfo() override;

        //Destructor
        ~CuentaCorriente() override;
    };
    