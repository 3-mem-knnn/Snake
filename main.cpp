#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>

#include "Snake.h"
#include "Food.h"
#include "Game.h"
#include "Console.h"

using namespace std;

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    CONRAN r;
    Food food;

    do
    {
        TaoMoi(food);
    }
    while(r.ChiemViTri(food.x,food.y));

    int Huong=0;
    bool thoat=false;

    InitConsole();
    ClearScreen();

    while(!thoat)
    {
        while(KeyPressed())
        {
            char phimTho=ReadKey();
            if(phimTho=='\0')
            {
                thoat=true;
                break;
            }

            char phim=static_cast<char>(
                tolower(static_cast<unsigned char>(phimTho)));
            int huongMoi=-1;

            if(phim=='d') huongMoi=0;
            if(phim=='x' || phim=='s') huongMoi=1;
            if(phim=='a') huongMoi=2;
            if(phim=='w') huongMoi=3;
            if(phim=='q') thoat=true;

            if(huongMoi!=-1 && (huongMoi+2)%4!=Huong)
                Huong=huongMoi;
        }

        if(thoat)
            break;

        r.DiChuyen(Huong);
        r.AnMoi(food);

        ClearScreen();
        VeKhung();
        VeMoi(food);
        r.Ve();

        gotoxy(MAXX+3,MINY+1);
        cout<<"Do dai: "<<r.DoDai;
        gotoxy(MAXX+3,MINY+3);
        cout<<"A/W/D/X hoac S: di chuyen";
        gotoxy(MAXX+3,MINY+4);
        cout<<"Q: thoat"<<flush;

        if(r.ChamTuong() || r.CanThan())
            break;

        Delay(180);
    }

    gotoxy(1,MAXY+2);
    RestoreConsole();

    if(thoat)
        cout<<"Da thoat game.\n";
    else
        cout<<"Game over! Do dai cua ran: "<<r.DoDai<<"\n";

    return 0;
}
