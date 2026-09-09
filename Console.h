#ifndef CONSOLE_H
#define CONSOLE_H

void gotoxy(int x, int y);
void ClearScreen();
void Delay(int ms);
void InitConsole();
void RestoreConsole();
bool KeyPressed();
char ReadKey();

#endif
