#pragma once

#include "../module/plugin.h"

#ifdef GUI_EXPORTS
#define GUI_API __declspec(dllexport)
#else
#define GUI_API __declspec(dllimport)
#endif // GUI_EXPORTS

namespace module {

class GUI_API window_maker : public basic_plugin {
public:
    const char* name() const;
    const char* version() const;

    int execute();

    window_maker();
    ~window_maker();
private:
    class Implement;
    Implement* impl;
};

} // namespace module
