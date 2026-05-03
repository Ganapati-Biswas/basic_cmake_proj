#include "statlib/logger.hpp"
#include <iostream>

namespace statlib {

void Logger::log(const std::string& msg) const {
    std::cout << "[LOG]: " << msg << std::endl;
}

}

/*
Notes:
clang++ -I./statlib/include -c statlib/src/logger.cpp -o logger.o
ar rcs build/static/libstatlib.a logger.o
*/
