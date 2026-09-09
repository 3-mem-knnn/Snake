#ifndef _WIN32

#include "Console.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

void gotoxy(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

void ClearScreen()
{
    system("clear");
}

void Delay(int ms)
{
    usleep(ms * 1000);
}

#endif
