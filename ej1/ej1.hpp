#pragma once
#include <string>
using namespace std;

class TIME{
private:
    size_t hour;
    size_t minute;
    size_t seconds;
    string am_pm;
    void validation(size_t h, size_t m = 0 , size_t s =0, string am_pm = "a.m");
    

public:
    TIME();
    TIME(size_t h);
    TIME(size_t h, size_t m);
    TIME(size_t h, size_t m, size_t s);
    TIME(size_t h, size_t m, size_t s, string M);

    void setHour(size_t h);
    void setMinute(size_t m);
    void setSeconds(size_t s);
    void setMeridian(const string& M);

    size_t getHour();
    size_t getMinute();
    size_t getSeconds();
    string getMeridian();
    
    void printTime();
};

void testTime();