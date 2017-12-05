#include "gui.h"
#include "window.h"

#include <iostream>

namespace module {

class window_maker::Implement {
public :
    int execute()
    {
        std::cout << "window_maker start==============================================================" << std::endl;
        using namespace gui;
        window win(_T("Test"), 400, 300);
        win.show();

        application app;
        app.loop();

        std::cout << "window_maker end================================================================" << std::endl;
        return 0;
    }
};

window_maker::window_maker() : impl(new Implement) { }
window_maker::~window_maker() { if (impl) { delete impl; impl = 0; } }

const char * window_maker::name() const { return "window_maker"; }
const char * window_maker::version() const { return "1.0"; }
int window_maker::execute() { return impl->execute(); }


} // namespace module

