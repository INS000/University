#include "wektor.hpp"

wektor::wektor() : x(0), y(0){};

wektor::wektor(int nx, int ny) : x(nx), y(ny){};

void wektor::set_x(int xval)
{
    x = xval;
}

void wektor::set_y(int yval)
{
    y = yval;
}

int wektor::get_x() const
{
    return x;
}

int wektor::get_y() const
{
    return y;
}