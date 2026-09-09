#include "Food.h"
#include "Console.h"
#include <iostream>
#include <cstdlib>

using namespace std;

#define MINX 2
#define MAXX 35
#define MINY 2
#define MAXY 20

void TaoMoi(Food &food)
{
    food.x = rand()%(MAXX-MINX-1)+MINX+1;
    food.y = rand()%(MAXY-MINY-1)+MINY+1;
}

void VeMoi(Food food)
{
    gotoxy(food.x,food.y);
    cout<<"@";
}
