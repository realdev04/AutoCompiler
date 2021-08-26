#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>

using namespace std;

#ifdef _DEBUG_
    #define TODEBUG(func) func;
#else
    #define TODEBUG(func)
#endif

#define PRINT cout << 
#define CXXC "g++ "

#endif