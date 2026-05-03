#pragma once
#include <string>

namespace statlib {

class Logger {
public:
    void log(const std::string& msg) const;
};

}