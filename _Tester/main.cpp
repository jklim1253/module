#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <algorithm>
#include <functional>

#include "../module/plugin.h"
#include "../converter/converter.h"
#include "../gui/gui.h"

#define LIB_PATH "../Debug/"

#pragma comment(lib, LIB_PATH "module.lib")
#pragma comment(lib, LIB_PATH "converter.lib")
#pragma comment(lib, LIB_PATH "gui.lib")

template<typename LIST, typename First, typename Second, typename ...Last>
void loader(LIST& depot)
{
    depot.push_back(std::make_shared<First>());
    loader<LIST, Second, Last...>(depot);
}
template<typename LIST, typename Last>
void loader(LIST& depot)
{
    depot.push_back(std::make_shared<Last>());
}

int main() {
    typedef std::list<std::shared_ptr<module::basic_plugin>> LIST;
    LIST plugins;

    loader<LIST,
        module::converter,
        module::window_maker
    >(plugins);

    for (auto& e : plugins) {
        std::cout << e->name() << "-" << e->version() << std::endl;
        //e->execute();
    }

    std::string command;

    auto executor = [&](const std::string& name) -> std::function<int()> {
        auto target = std::find_if(plugins.begin(), plugins.end(), [&](const LIST::value_type& e) {
            if (name == e->name())
                return true;
            return false;
        });

        if (target == plugins.end())
            return std::function<int()>();

        return std::bind(&module::basic_plugin::execute, *target);
    };

    while (std::getline(std::cin, command) && command != "quit")
    {
        if (command == "window")
        {
            executor("window_maker")();
        }
        else if (command == "converter")
        {
            executor("converter")();
        }
    }
    

    return 0;
}