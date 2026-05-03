#pragma once

#include <mylib/math_utils.hpp>
#include <statlib/logger.hpp>
namespace app {

class Application {
public:
    Application();

    void run();

private:
    mylib::MathUtils math_;
    statlib::Logger logger_;
};

}
