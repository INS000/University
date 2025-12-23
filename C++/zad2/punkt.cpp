#include "punkt.hpp"
#include <cmath>

punkt::punkt()
    {
        x = 0;
        y = 0;
    }

punkt::punkt(double xx, double yy) 
    {
        x = xx;
        y = yy;
    }

punkt::punkt(const punkt &p)
    {
        x = p.x;
        y = p.y;
    }

void punkt::set_x(double xval)
{
    this->x = xval;
}
void punkt::set_y(double yval)
{
    this->y = yval;
}

double punkt::get_x() const
{
    return x;
}
double punkt::get_y() const
{
    return y;
}

punkt& punkt::operator=(const punkt &p){
    x = p.x;
    y = p.y;
    return *this;
    }

bool punkt::operator==(const punkt &p){
    if(x == p.x && y == p.y)
        return true;
    return false;
}

std::ostream& operator<<(std::ostream& stream, const punkt &p){
    stream << "(" << p.x << ", " << p.y << ")";
    return stream; 
}

void punkt::trans(const wektor &v){
    x += v.get_x();
    y += v.get_y();
}

void punkt::spin(const punkt &p, double angle){
    double rad = M_PI * angle / 180;
    x = p.x + cos(rad) * (x - p.x) - sin(rad) * (y - p.y);
    y = p.y + sin(rad) * (x - p.x) + cos(rad) * (y - p.y);
}

void punkt::sym_pkt(const punkt &p){
    x = 2 * p.x - x;
    y = 2 * p.y - y;
}


void punkt::sym_os(const prosta &p)
{
    prosta prostop(-1 * p.get_b(), p.get_a(), p.get_b() * x - p.get_a() * y );
    punkt przeciecie(-((p.get_c() * prostop.get_b() - prostop.get_c() * p.get_b() )/(p.get_a()*prostop.get_b() - prostop.get_a() *p.get_b())), (-(p.get_a() * prostop.get_c() - prostop.get_a() *p.get_c())/(p.get_a() * prostop.get_b() - prostop.get_a() * p.get_b())));
    if(p.get_a() * x + p.get_b() * y + p.get_c() ==  0){
        return;
    }
    if(przeciecie.get_x() ==  -x ){
        y = (-1) * y;
        return;
    }
    if(przeciecie.get_y() == y){
        x = (-1) * x;
        return;
    }

    x = 2 * przeciecie.get_x() - x;
    y = 2 * przeciecie.get_y() - y;
}

