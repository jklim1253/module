#pragma once

#include <Windows.h>
#include <tchar.h>

namespace gui
{

class windowclass
{
public :
    windowclass(LPCTSTR name);

    static LRESULT CALLBACK procedure(HWND, UINT, WPARAM, LPARAM);
};

class window
{
public :
    window(LPCTSTR name, INT width, INT height);

    void show();
    void hide();

private :
    HWND m_hWnd;
    windowclass m_class;
};

class application
{
public :
    void loop();
};


} // namespace gui
