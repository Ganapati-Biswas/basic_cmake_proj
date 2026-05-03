#include "app/application.hpp"

int main() {
    app::Application app;
    app.run();
    return 0;
}

/*
Compilation command - clang++ -I./app/include -I./mylib/include -I./statlib/include -c app/main.cpp -o main.o

Link everything to make final exe - clang++ main.o application.o ./build/static/libstatlib.a -L./build/shared -lmylib -o myapp
*/