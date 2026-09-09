#ifdef _WIN32

#include "Console.h"
#include <windows.h>
#include <cstdlib>

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

#endif
