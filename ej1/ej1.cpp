#include "ej1.hpp"
#include <iostream>
#include <iomanip>

void TIME::validation(size_t h, size_t m = 0, size_t s =0, string am_pm = "a.m"){
    if(h<1 || h>12) throw invalid_argument("Hora fuera de rango");
    if(m > 60) throw invalid_argument("Minutos fuera de rango");
    if(s > 60) throw invalid_argument("Segundos fuera de rango");
    if(am_pm != "a.m" || am_pm != "p.m") throw invalid_argument("Formato invalido (debe usar 'a.m' o 'p.m')");
}

TIME::TIME(): hour(0), minute(0), seconds(0), am_pm("a.m") {}

TIME::TIME(size_t h){
    validation(h);
    hour =h;
    minute = 0;
    seconds = 0; 
    am_pm = "a.m";
}

TIME::TIME(size_t h, size_t m){
    validation(h,m);
    hour = h;
    minute = m;
    seconds =0;
    am_pm = "a.m";
}

TIME::TIME(size_t h,size_t m,size_t s){
    validation(h,m,s);
    hour = h;
    minute = m;
    seconds = s;
    am_pm = "a.m";
}

TIME::TIME(size_t h,size_t m,size_t s, string M): hour(h), minute(m), seconds(s), am_pm(M){
    validation(h,m,s,M);
    hour = h;
    minute = m;
    seconds = s;
    am_pm = M;
}

void TIME::setHour(size_t h){
    validation(h, minute, seconds, am_pm);
    hour = h;
}

void TIME::setMinute(size_t m){
    validation(hour, m, seconds, am_pm);
    minute = m;
}

void TIME::setSeconds(size_t s){
    validation(hour, minute, s, am_pm);
    seconds = s;
}

void TIME::setMeridian(const string& M){
    validation(hour, minute, seconds, M);
    am_pm = M;
}

size_t TIME::getHour() {return hour;}

size_t TIME::getMinute() {return minute;}

size_t TIME::getSeconds() {return seconds;}

string TIME::getMeridian() {return am_pm;}
