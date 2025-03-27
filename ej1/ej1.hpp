#pragma once
#include <string>
using namespace std;

class TIME{
private:
    size_t hour;
    size_t minute;
    size_t seconds;
    bool M;

public:
    TIME();
    TIME(size_t h);
    TIME(size_t h, size_t m);
    TIME(size_t h, size_t m, size_t s);
    TIME(size_t h, size_t m, size_t s, bool M);
    

};