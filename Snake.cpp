#include "Snake.h"
#include "Console.h"
#include <iostream>

using namespace std;

CONRAN::CONRAN()
{
    DoDai = 3;

    A[0] = {10,10};
    A[1] = {11,10};
    A[2] = {12,10};
}

void CONRAN::Ve()
{
    for(int i=0;i<DoDai;i++)
    {
        gotoxy(A[i].x,A[i].y);
        cout<<"X";
    }
}

void CONRAN::DiChuyen(int Huong)
{
    for(int i=DoDai-1;i>0;i--)
        A[i]=A[i-1];

    if(Huong==0) A[0].x++;
    if(Huong==1) A[0].y++;
    if(Huong==2) A[0].x--;
    if(Huong==3) A[0].y--;
}

void CONRAN::AnMoi(Food food)
{
    if(A[0].x==food.x && A[0].y==food.y)
        DoDai++;
}
