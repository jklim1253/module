#pragma once

#ifdef MODULE_EXPORTS
#   define MODULE_API __declspec(dllexport)
#else
#   define MODULE_API __declspec(dllimport)
#endif // MODULE_EXPORTS

namespace module {

MODULE_API int version();

struct basic_plugin {
    virtual const char* name() const = 0;
    virtual const char* version() const = 0;

    virtual int execute() = 0;
};

} // namespace module
