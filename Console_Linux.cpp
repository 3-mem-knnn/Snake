#ifndef _WIN32

#include "Console.h"
#include <chrono>
#include <iostream>
#include <thread>
#include <sys/select.h>
#include <termios.h>
#include <unistd.h>

using namespace std;

namespace
{
termios originalTerminal;
bool terminalConfigured = false;
}

void gotoxy(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

void ClearScreen()
{
    cout << "\033[2J\033[H";
}

void Delay(int ms)
{
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void InitConsole()
{
    if(isatty(STDIN_FILENO) && tcgetattr(STDIN_FILENO, &originalTerminal) == 0)
    {
        termios rawTerminal = originalTerminal;
        rawTerminal.c_lflag &= static_cast<tcflag_t>(~(ICANON | ECHO));
        rawTerminal.c_cc[VMIN] = 0;
        rawTerminal.c_cc[VTIME] = 0;

        terminalConfigured = tcsetattr(
            STDIN_FILENO,
            TCSANOW,
            &rawTerminal) == 0;
    }

    cout << "\033[?25l" << flush;
}

void RestoreConsole()
{
    if(terminalConfigured)
        tcsetattr(STDIN_FILENO, TCSANOW, &originalTerminal);

    cout << "\033[?25h" << flush;
}

bool KeyPressed()
{
    fd_set inputSet;
    FD_ZERO(&inputSet);
    FD_SET(STDIN_FILENO, &inputSet);

    timeval timeout = {0, 0};
    return select(STDIN_FILENO + 1, &inputSet, nullptr, nullptr, &timeout) > 0;
}

char ReadKey()
{
    char key = '\0';
    return read(STDIN_FILENO, &key, 1) == 1 ? key : '\0';
}

#endif
