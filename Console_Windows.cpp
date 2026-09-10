#ifdef _WIN32

#include "Console.h"
#include <windows.h>
#include <cstdlib>
#include <conio.h>

namespace
{
void SetCursorVisible(bool visible)
{
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;

    if(GetConsoleCursorInfo(output, &cursorInfo))
    {
        cursorInfo.bVisible = visible;
        SetConsoleCursorInfo(output, &cursorInfo);
    }
}
}

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ClearScreen()
{
    system("cls");
}

void Delay(int ms)
{
    Sleep(ms);
}

void InitConsole()
{
    SetCursorVisible(false);
}

void RestoreConsole()
{
    SetCursorVisible(true);
}

bool KeyPressed()
{
    return _kbhit() != 0;
}

char ReadKey()
{
    return static_cast<char>(_getch());
}

#endif
