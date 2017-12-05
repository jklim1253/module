#include "window.h"

namespace gui
{

windowclass::windowclass(LPCTSTR name)
{
    WNDCLASSEX wcex;
    ::memset(&wcex, 0, sizeof(wcex));
    wcex.cbSize = sizeof(wcex);
    wcex.lpfnWndProc = &windowclass::procedure;
    wcex.hInstance = (HINSTANCE)::GetModuleHandle(NULL);
    wcex.lpszClassName = name;
    wcex.style = CS_VREDRAW | CS_HREDRAW;

    ::RegisterClassEx(&wcex);
}

LRESULT windowclass::procedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    if (uMsg == WM_DESTROY)
    {
        ::PostQuitMessage(0);
        return 0;
    }

    return ::DefWindowProc(hWnd, uMsg, wParam, lParam);
}

window::window(LPCTSTR name, INT width, INT height)
    : m_class(name)
    , m_hWnd(NULL)
{
    m_hWnd = ::CreateWindowEx(0, name, name, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                              width, height, NULL, NULL, (HINSTANCE)::GetModuleHandle(NULL), NULL);
}

void window::show()
{
    ::ShowWindow(m_hWnd, SW_SHOW);
}
void window::hide()
{
    ::ShowWindow(m_hWnd, SW_HIDE);
}

void application::loop()
{
    MSG msg;

    while (::GetMessage(&msg, NULL, 0, 0))
    {
        ::TranslateMessage(&msg);
        ::DispatchMessage(&msg);
    }
}

} // namespace gui
