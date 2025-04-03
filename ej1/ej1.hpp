#pragma once
#include <string>
using namespace std;

class TIME{
private:
    size_t hour;
    size_t minute;
    size_t seconds;
    string am_pm;
    /*
    Función que valida si los datos (hora, minuto, segundo, periodo) son correctos
    */
    void validation(size_t h, size_t m = 0 , size_t s =0, string am_pm = "a.m");

public:
    TIME();// Constructor por default (00:00:00 a.m)
    TIME(size_t h); // Constructor con parámetro hora
    TIME(size_t h, size_t m);// Constructor con parámetro hora y minutos
    TIME(size_t h, size_t m, size_t s);// Constructor con parámetro hora, minutos y segundos
    TIME(size_t h, size_t m, size_t s, string M);// Constructor con parámetro hora, minuto, segundos y periodo

    //SETTERS
    void setHour(size_t h);
    void setMinute(size_t m);
    void setSeconds(size_t s);
    void setMeridian(string& M);

    //GETTERS
    size_t getHour();
    size_t getMinute();
    size_t getSeconds();
    string getMeridian();
    
    /*
    Función que imprime el objeto Tiempo en formato de 24hs
    */
    void printTime();
};

void testTime();