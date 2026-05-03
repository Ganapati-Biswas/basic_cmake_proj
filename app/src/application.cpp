#include "../include/app/application.hpp"
#include <iostream>

namespace app {

Application::Application() = default;

void Application::run() {
    logger_.log("Application started");

    int result = math_.add(3, 4000);

    logger_.log("Computation done");
    std::cout << "Result: " << result << std::endl;

    logger_.log("Application finished");
}

}


/*
Notes: 
clang++ -I./app/include -I./statlib/include -I./mylib/include -c app/src/application.cpp -o application.o
*/