#include "CuentaBancaria.hpp"
#include <iostream>

CuentaBancaria::CuentaBancaria(string titular, double balance): Titular(titular), balance(balance) {}

void CuentaBancaria::depositar(double cant){balance += cant;}

CuentaBancaria::~CuentaBancaria() {}