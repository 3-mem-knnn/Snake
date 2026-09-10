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
    static constexpr int SO_DOT_TOI_DA = 100;

    Point A[SO_DOT_TOI_DA];
    int DoDai;

    CONRAN();

    void Ve() const;
    void DiChuyen(int Huong);
    bool AnMoi(Food &food);
    bool ChamTuong() const;
    bool CanThan() const;
    bool ChiemViTri(int x, int y) const;

private:
    Point DuoiCu;
};

#endif
