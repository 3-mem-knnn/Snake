#ifndef SNAKE_H
#define SNAKE_H

#include "Food.h"

struct Point
{
    int x;
    int y;
};

class CONRAN
{
public:
    Point A[100];
    int DoDai;

    CONRAN();

    void Ve();
    void DiChuyen(int Huong);
    void AnMoi(Food food);
};

#endif
