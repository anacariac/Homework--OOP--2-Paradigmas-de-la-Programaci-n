#pragma once
#include "CuentaBancaria.hpp"

class CajadeAhorro: public CuentaBancaria{
    private:
        int cantRep = 0;
    public:
        //Constructor
        CajadeAhorro(string titular, double saldo);
        
        void retirar(double cant) override;
        void mostrarInfo() override;

        //Destrcutor
        ~CajadeAhorro() override;

        friend class CuentaCorriente;
    };