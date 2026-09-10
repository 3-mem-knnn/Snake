#include "Food.h"
#include "Console.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void TaoMoi(Food &food)
{
    food.x = rand()%(MAXX-MINX-1)+MINX+1;
    food.y = rand()%(MAXY-MINY-1)+MINY+1;
}

void VeMoi(const Food &food)
{
    gotoxy(food.x,food.y);
    cout<<"*";
}
