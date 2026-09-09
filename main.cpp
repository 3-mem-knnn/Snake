#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#include "Snake.h"
#include "Food.h"
#include "Game.h"
#include "Console.h"

using namespace std;

int main()
{
    srand(time(NULL));

    CONRAN r;
    Food food;

    TaoMoi(food);

    int Huong=0;

    while(true)
    {
        ClearScreen();

        VeKhung();
        VeMoi(food);
        r.Ve();

        r.DiChuyen(Huong);
        r.AnMoi(food);

        Delay(300);
    }

    return 0;
}
