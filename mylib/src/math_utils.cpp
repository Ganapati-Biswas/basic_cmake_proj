#include "../include/mylib/math_utils.hpp"

namespace mylib {

int MathUtils::add(int a, int b) const {
    return a + b;
}

}


/* 
Notes:
To generate a shared libray from this file clang compile command - 
clang++ -dynamiclib -fPIC mylib/src/math_utils.cpp -o build/shared/libmylib.dylib

-dynamiclib = tells the compiler to generate a shared library
-fPIC = Generate Position Independent Code.
*/
