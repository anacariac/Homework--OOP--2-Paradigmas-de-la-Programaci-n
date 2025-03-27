#include "ej1.hpp"
#include <iostream>
#include <iomanip>

TIME::TIME(): hour(0), minute(0), seconds(0), M(false) {}

TIME::TIME(size_t h): hour(h), minute(0), seconds(0), M(false){}

TIME::TIME(size_t h,size_t m): hour(h), minute(m), seconds(0), M(false){}

TIME::TIME(size_t h,size_t m,size_t s): hour(h), minute(m), seconds(s), M(false){}

TIME::TIME(size_t h,size_t m,size_t s, bool M): hour(h), minute(m), seconds(s), M(M){}

