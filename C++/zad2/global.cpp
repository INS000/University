#include "global.hpp"
#include <cmath>

prosta pros2pkt(punkt p1, punkt p2)
{
    double a = p2.get_y() - p1.get_y();
    double b = p1.get_x() - p2.get_x();
    double c = (a * p1.get_x() + b * p1.get_y()) * (-1);
    prosta pom(a, b, c);
    return pom;
}

double odleglosc(punkt a, punkt b){
    return sqrt( (a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()) );
}

bool between(punkt p, punkt a, punkt b){
    if((p.get_x() >= a.get_x() && p.get_x() <= b.get_x()) || (p.get_x() <= a.get_x() && p.get_x() >= b.get_x()))
        return true;
    return false;
}

// bool czy_rownolegle(odcinek o1, odcinek o2)
// {
//     prosta p1 = pros2pkt(o1.get_a(), o1.get_b()), p2 = pros2pkt(o2.get_a(), o2.get_b());
//     if(fabs(p1.get_a() * p2.get_b() - p2.get_a() * p1.get_b()) < eps)
//         return true;
//     return false;
// }

// bool czy_prostopadle(odcinek o1, odcinek o2)
// {
//     prosta p1 = pros2pkt(o1.get_a(), o1.get_b()), p2 = pros2pkt(o2.get_a(), o2.get_b());
//     if(fabs(p1.get_a() * p2.get_a() + p1.get_b() * p2.get_b()) < eps)
//         return true;
//     return false;
// }

// bool czy_tro_zaw(trojkat t1, trojkat t2){
//     if(t1.if_pkt_in(t2.get_a()) && t1.if_pkt_in(t2.get_b()) && t1.if_pkt_in(t2.get_c()))
//         return true;
//     return false;
// }

// bool czy_tro_roz(trojkat t1, trojkat t2){
//     if(t1.if_pkt_in(t2.get_a()) || t1.if_pkt_in(t2.get_b()) || t1.if_pkt_in(t2.get_c()))
//         return false;
//     return true;
// }