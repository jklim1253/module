#include "converter.h"
#include <iostream>
#include <string>

namespace module {

class converter::Implement {
public:
    void push(const std::string& message) {
        m_message = message;
    }
    friend std::ostream& operator << (std::ostream& os, const converter::Implement& obj) {
        os << "length : " << obj.m_message.length();

        return os;
    }

private:
    std::string m_message;
};

converter::converter()
    : impl(new Implement)
{
}

converter::~converter()
{
    if (impl) {
        delete impl;
        impl = 0;
    }
}

const char * converter::name() const
{
    return "converter";
}

const char * converter::version() const
{
    return "1.0";
}

int converter::execute()
{
    std::cout << "converter start=================================================================" << std::endl;
    std::string line;
    while (std::getline(std::cin, line) && line != "quit") {
        impl->push(line);
        std::cout << *impl << std::endl;
    }

    std::cout << "converter end===================================================================" << std::endl;
    return 0;
}

} // namespace module
