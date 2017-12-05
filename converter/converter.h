#pragma once

#include "../module/plugin.h"

#ifdef CONVERTER_EXPORTS
#define CONVERTER_API __declspec(dllexport)
#else
#define CONVERTER_API __declspec(dllimport)
#endif // MODULE_EXPORTS

namespace module
{

class CONVERTER_API converter : public basic_plugin {
public :
    const char* name() const;
    const char* version() const;

    int execute();

    converter();
    ~converter();
private :
    class Implement;
    Implement* impl;
};

} // namespace module
