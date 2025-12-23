#include "trojkat.hpp"
#include<stdexcept>
#include<cmath>

const double eps = 0.0001;

trojkat::trojkat(double x1, double y1, double x2, double y2, double x3, double y3)
    {
        a.set_x(x1);
        a.set_y(y1);
        b.set_x(x2);
        b.set_y(y2);
        c.set_x(x3);
        c.set_y(y3);
        prosta pr1 = pros2pkt(a, b), pr2 = pros2pkt(b, c), pr3 = pros2pkt(c, a);
        if(fabs(pr1.get_a() - pr2.get_a()) < eps || fabs(pr3.get_a() - pr2.get_a()) < eps || fabs(pr1.get_a() - pr3.get_a()) < eps )
            throw invalid_argument("boki sa wspoliniowe");
        if(a == b || b == c || c == a)
            throw std::invalid_argument("rowne wierzcholi");
    }
    
trojkat::trojkat(const punkt &p1, const punkt &p2, const punkt &p3)
    {
        a = p1;
        b = p2;
        c = p3;
        prosta pr1 = pros2pkt(p1, p2), pr2 = pros2pkt(p2, p3), pr3 = pros2pkt(p3, p1);
        if(fabs(pr1.get_a() - pr2.get_a()) < eps || fabs(pr3.get_a() - pr2.get_a()) < eps || fabs(pr1.get_a() - pr3.get_a()) < eps )
            throw invalid_argument("boki sa wspoliniowe");
        if(a == b || b == c || c == a)
            throw std::invalid_argument("rowne wierzcholi");

    }

trojkat::trojkat(const trojkat &tr){
    a = tr.a;
    b = tr.b;
    c = tr.c;
}

void trojkat::set_a(double xval, double yval)
{
    a.set_x(xval);
    a.set_y(yval);
}
void trojkat::set_b(double xval, double yval)
{
    b.set_x(xval);
    b.set_y(yval);
}
void trojkat::set_c(double xval, double yval)
{
    c.set_x(xval);
    c.set_y(yval);
}

punkt trojkat::get_a()
{
    return a;
}
punkt trojkat::get_b()
{
    return b;
}
punkt trojkat::get_c()
{
    return c;
}

trojkat& trojkat::operator=(const trojkat &o){
    a = o.a;
    b = o.b;
    c = o.c;
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const trojkat &p){
    stream << "{ " << p.a <<", " << p.b << ", " << p.c << " }";
    return stream;
}

#include "odcinek.hpp"

double trojkat::obwod()
{
    odcinek o1(a, b);
    odcinek o2(c, b);
    odcinek o3(c, a);
    return o1.dlugosc_odc() + o2.dlugosc_odc() + o3.dlugosc_odc();
}

double trojkat::pole()
{
    double obw = this->obwod() / 2;
    double b1 = odleglosc(a, b), b2 = odleglosc(b, c), b3 = odleglosc(c, a);
    return sqrt(obw * (obw - b1) * (obw - b2) * (obw - b3));
}

void trojkat::spin(punkt p, double angle){
    double rad = M_PI * angle / 180;
    a.set_x( p.get_x() + cos(rad) * ( a.get_x() - p.get_x() ) - sin(rad) * ( a.get_y() - p.get_y() ) );
    a.set_y( p.get_y() + sin(rad) * ( a.get_x() - p.get_x() ) + cos(rad) * ( a.get_y() - p.get_y() ) );
    b.set_x( p.get_x() + cos(rad) * ( b.get_x() - p.get_x() ) - sin(rad) * ( b.get_y() - p.get_y() ) );
    b.set_y( p.get_y() + sin(rad) * ( b.get_x() - p.get_x() ) + cos(rad) * ( b.get_y() - p.get_y() ) );
    c.set_x( p.get_x() + cos(rad) * ( c.get_x() - p.get_x() ) - sin(rad) * ( c.get_y() - p.get_y() ) );
    c.set_y( p.get_y() + sin(rad) * ( c.get_x() - p.get_x() ) + cos(rad) * ( c.get_y() - p.get_y() ) );
}    

void trojkat::trans(wektor &v){
    a.set_x(a.get_x() + v.get_x());
    a.set_y(a.get_y() + v.get_y());
    b.set_x(b.get_x() + v.get_x());
    b.set_y(b.get_y() + v.get_y());
    c.set_x(c.get_x() + v.get_x());
    c.set_y(c.get_y() + v.get_y());
}

void trojkat::sym_pkt(punkt p){
    a.set_x(2 * p.get_x() - a.get_x());
    a.set_y(2 * p.get_y() - a.get_y());
    b.set_x(2 * p.get_x() - b.get_x());
    b.set_y(2 * p.get_y() - b.get_y());
    c.set_x(2 * p.get_x() - c.get_x());
    c.set_y(2 * p.get_y() - c.get_y());
}

bool trojkat::if_pkt_in(punkt p){
    trojkat t1(a, b, p);
    trojkat t2(c, b, p);
    trojkat t3(a, c, p);
    double pt = pole();
    if(fabs(t1.pole() + t2.pole() + t3.pole() - pt) < eps)
        return true;
    return false;
}
void trojkat::sym_os(prosta p){
    a.sym_os(p);
    b.sym_os(p);
    c.sym_os(p);
}




