#include "Snake.h"
#include "Console.h"
#include "Game.h"
#include <iostream>

using namespace std;

CONRAN::CONRAN()
{
    DoDai = 3;

    A[0] = {12,10};
    A[1] = {11,10};
    A[2] = {10,10};
    DuoiCu = A[DoDai-1];
}

void CONRAN::Ve() const
{
    for(int i=0;i<DoDai;i++)
    {
        gotoxy(A[i].x,A[i].y);
        cout<<(i==0 ? "O" : "X");
    }
}

void CONRAN::DiChuyen(int Huong)
{
    DuoiCu = A[DoDai-1];

    for(int i=DoDai-1;i>0;i--)
        A[i]=A[i-1];

    switch(Huong)
    {
        case 0: A[0].x++; break;
        case 1: A[0].y++; break;
        case 2: A[0].x--; break;
        case 3: A[0].y--; break;
        default: break;
    }
}

bool CONRAN::AnMoi(Food &food)
{
    if(A[0].x!=food.x || A[0].y!=food.y)
        return false;

    if(DoDai<SO_DOT_TOI_DA)
    {
        A[DoDai]=DuoiCu;
        DoDai++;
    }

    do
    {
        TaoMoi(food);
    }
    while(ChiemViTri(food.x,food.y));

    return true;
}

bool CONRAN::ChamTuong() const
{
    return A[0].x<=MINX || A[0].x>=MAXX ||
           A[0].y<=MINY || A[0].y>=MAXY;
}

bool CONRAN::CanThan() const
{
    for(int i=1;i<DoDai;i++)
        if(A[0].x==A[i].x && A[0].y==A[i].y)
            return true;

    return false;
}

bool CONRAN::ChiemViTri(int x, int y) const
{
    for(int i=0;i<DoDai;i++)
        if(A[i].x==x && A[i].y==y)
            return true;

    return false;
}
