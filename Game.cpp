#include "Game.h"
#include "Console.h"
#include <iostream>

using namespace std;

#define MINX 2
#define MAXX 35
#define MINY 2
#define MAXY 20

void VeKhung()
{
    for(int x=MINX;x<=MAXX;x++)
    {
        gotoxy(x,MINY);
        cout<<"+";

        gotoxy(x,MAXY);
        cout<<"+";
    }

    for(int y=MINY;y<=MAXY;y++)
    {
        gotoxy(MINX,y);
        cout<<"+";

        gotoxy(MAXX,y);
        cout<<"+";
    }
}
