#include <windows.h>
#include <math.h>

const        scrX = GetSystemMetrics(0),
             scrY = GetSystemMetrics(1);
const double _2pi = 2 * 3.141592,
             itvl = _2pi / scrX;

inline unsigned DrawPixel (HDC hdc, double x, double y, unsigned c)
{
    y = scrY/2 - y * scrY/3;
    return SetPixel ( hdc, x, y, c );
}

inline int DrawString ( HDC hdc, int x, int y, unsigned c, char * str, int len)
{
    y = scrY/2 - y * scrY/3 + 3;
    RECT rect = { x, y, x+40, y+16 };
    SetTextColor ( hdc, c );
    return DrawText ( hdc, str, len, &rect, 0 );
}

void PaintGraph(HWND hWnd)
{
    HDC hdc = GetDC(hWnd);

    // graph

        for (double f=0, x, y; f<_2pi; f+=itvl)
        {
            x = f / _2pi * scrX;

            DrawPixel ( hdc, x, 0,      0xcccccc );
            DrawPixel ( hdc, x, sin(f), 0xff8800 );
            DrawPixel ( hdc, x, cos(f), 0x8844ff );
        }

    // label

        SetBkMode(hdc, TRANSPARENT);
        x = 0;
        DrawString ( hdc, x, sin(0), 0xff8800, "sin", 3);
        DrawString ( hdc, x, cos(0), 0x8844ff, "cos", 3);
        x = scrX-40;
        DrawString ( hdc, x, +1, 0xcccccc, "+1.0f", 5);
        DrawString ( hdc, x, -1, 0xcccccc, "-1.0f", 5);

    ReleaseDC(hWnd, hdc);
}

LRESULT __stdcall WinProc ( HWND hWnd, unsigned msg, unsigned wpa, long lpa )
{
    if (msg == WM_PAINT)
    {
        PaintGraph(hWnd);
    }
    if (msg == WM_KEYDOWN && wpa == VK_ESCAPE)
    {
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc ( hWnd, msg, wpa, lpa );
}

int __stdcall WinMain ( HINSTANCE hInst, HINSTANCE, char * , int nCmd )
{
    WNDCLASS wc = { 0 };

        wc.lpszClassName = "exer1";
        wc.lpfnWndProc   = WinProc;
        wc.hInstance     = hInst;
        wc.hCursor       = LoadCursor(0, IDC_UPARROW);
        wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

    RegisterClass (&wc);

    HWND hWnd = CreateWindow("exer1", 0, WS_POPUP,
                0, 0, scrX, scrY,
                0, (HMENU)0, 0, 0);
    ShowWindow ( hWnd, nCmd );

    for (MSG msg; GetMessage(&msg, 0, 0, 0);)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

