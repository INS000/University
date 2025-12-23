#include "prosta.hpp"


prosta::prosta(double x, double y, double z){
        a = x;
        b = y;
        c = z;
    }
    
    prosta& prosta::operator=(const prosta &p){
        a = p.a;
        b = p.b;
        c = p.c;
        return *this;
    }

void prosta::set_a(double aval)
{
    a = aval;
}
void prosta::set_b(double bval)
{
    b = bval;
}
void prosta::set_c(double cval)
{
    c = cval;
}


double prosta::get_a() const
{
    return a;
}
double prosta::get_b() const
{
    return b;
}
double prosta::get_c() const
{
    return c;
}

