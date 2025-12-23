#include "odcinek.hpp"
#include<stdexcept>
#include<cmath>
#include "global.hpp"



odcinek::odcinek(double x1, double y1, double x2, double y2)
    {
        a.set_x(x1);
        a.set_y(y1);
        b.set_x(x2);
        b.set_y(y2);
        if(a == b)
            throw std::invalid_argument("nie mozna utworzyc odcinka o dlugosci 0");
    }

odcinek::odcinek(const punkt &p1, const punkt &p2) 
    {
        a = p1;
        b = p2;
    }

odcinek::odcinek(const odcinek &o)
{
    a = o.a;
    b = o.b;
}

void odcinek::set_a(double xval, double yval)
{
    a.set_x(xval);
    a.set_y(yval);
}

void odcinek::set_b(double xval, double yval)
{
    b.set_x(xval);
    b.set_y(yval);
}

punkt odcinek::get_a() const
{
    return a;
}
punkt odcinek::get_b() const
{
    return b;
}

odcinek& odcinek::operator=(const odcinek &o){
    a = o.a;
    b = o.b;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const odcinek &o){
    stream << "{ " << o.a << ", " << o.b << " }";
    return stream;
}


void odcinek::spin(punkt p, double angle){
    double rad = M_PI * angle / 180;
    // this->set_a(p.get_x() + cos(rad) * ( a.get_x() - p.get_x() ) - sin(rad) * ( a.get_y() - p.get_y() ), p.get_y() + sin(rad) * ( a.get_x() - p.get_x() ) + cos(rad) * ( a.get_y() - p.get_y() ));
    // this->set_b(p.get_x() + cos(rad) * ( b.get_x() - p.get_x() ) - sin(rad) * ( b.get_y() - p.get_y() ), p.get_y() + sin(rad) * ( b.get_x() - p.get_x() ) + cos(rad) * ( b.get_y() - p.get_y() ));
    a.set_x( p.get_x() + cos(rad) * ( a.get_x() - p.get_x() ) - sin(rad) * ( a.get_y() - p.get_y() ) );
    a.set_y( p.get_y() + sin(rad) * ( a.get_x() - p.get_x() ) + cos(rad) * ( a.get_y() - p.get_y() ) );
    b.set_x( p.get_x() + cos(rad) * ( b.get_x() - p.get_x() ) - sin(rad) * ( b.get_y() - p.get_y() ) );
    b.set_y( p.get_y() + sin(rad) * ( b.get_x() - p.get_x() ) + cos(rad) * ( b.get_y() - p.get_y() ) );
}

void odcinek::trans(wektor &v){
    a.set_x(a.get_x() + v.get_x());
    a.set_y(a.get_y() + v.get_y());
    b.set_x(b.get_x() + v.get_x());
    b.set_y(b.get_y() + v.get_y());
}

void odcinek::sym_pkt(punkt p){
    a.set_x(2 * p.get_x() - a.get_x());
    a.set_y(2 * p.get_y() - a.get_y());
    b.set_x(2 * p.get_x() - b.get_x());
    b.set_y(2 * p.get_y() - b.get_y());
}

double odcinek::dlugosc_odc(){
    return odleglosc(a, b);
}

bool odcinek::if_in(const punkt &p)
{
    const double eps = 0.0001;
    prosta pom = pros2pkt(a, b);
    if(fabs(p.get_x() * pom.get_a() + p.get_y() * pom.get_b() + pom.get_c()) < eps && between(p, a, b))
        return true;
    return false;
}

void odcinek::sym_os(const prosta &p){
    a.sym_os(p);
    b.sym_os(p);
}


