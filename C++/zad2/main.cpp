
#include<iostream>
#include<cmath>
#include<stdexcept>
#include "trojkat.hpp"
#include "odcinek.hpp"

using namespace std;

#define eps 0.0001

bool czy_rownolegle(odcinek o1, odcinek o2)
{
    prosta p1 = pros2pkt(o1.get_a(), o1.get_b()), p2 = pros2pkt(o2.get_a(), o2.get_b());
    if(fabs(p1.get_a() * p2.get_b() - p2.get_a() * p1.get_b()) < eps)
        return true;
    return false;
}

bool czy_prostopadle(odcinek o1, odcinek o2)
{
    prosta p1 = pros2pkt(o1.get_a(), o1.get_b()), p2 = pros2pkt(o2.get_a(), o2.get_b());
    if(fabs(p1.get_a() * p2.get_a() + p1.get_b() * p2.get_b()) < eps)
        return true;
    return false;
}

bool czy_tro_zaw(trojkat t1, trojkat t2){
    if(t1.if_pkt_in(t2.get_a()) && t1.if_pkt_in(t2.get_b()) && t1.if_pkt_in(t2.get_c()))
        return true;
    return false;
}

bool czy_tro_roz(trojkat t1, trojkat t2){
    if(t1.if_pkt_in(t2.get_a()) || t1.if_pkt_in(t2.get_b()) || t1.if_pkt_in(t2.get_c()))
        return false;
    return true;
}

int main(){
    punkt pp(1,3);
    punkt q(4,7);
    wektor v(2,4);
    punkt p = pp;

    // //TESTY KLASY PUNKT
    cout << "Testy punktu:" << endl;
    p.trans(v);
    cout<< p <<endl;
    p.spin(q,90);
    cout<< p <<endl;
    p.sym_pkt(q);
    cout<< p <<endl;
    prosta pr(1,-1,0);
    p.sym_os(pr);
    cout<< p <<endl<<endl;

    // //TESTY KLASY ODCINEK
    cout << "Testy odcinka: " << endl;
    p = pp;
    odcinek o(p,q);
    o.trans(v);
    cout << o << endl;
    cout << odleglosc(p,q) << endl;
    punkt r(2.5,5);
    cout << o.if_in(r)<<endl;
    punkt a(2,0);
    punkt b(2,2);
    punkt c(-1,1);
    punkt d(1,1);
    odcinek o1(a,b);
    odcinek o2(c,d);
    cout << czy_rownolegle(o1,o2) <<endl;
    punkt e(3,2);
    punkt f(5,4);
    punkt g(6,1);
    punkt h(2,5);
    odcinek o3(e,f);
    odcinek o4(g,h);
    cout << czy_prostopadle(o3,o4) << endl;
    o.spin(a, 90);
    cout << o << endl;
    o.trans(v);
    cout << o << endl;
    o.sym_os(pr);
    cout << o << endl;
    o.sym_pkt(g);
    cout << o << endl << o.dlugosc_odc() << endl << endl;

    // //TESTY KLASY TROJKAT
    cout << "Testy trojkata:" << endl;
    punkt p1(-3,0);
    punkt p2(3,0);
    punkt p3(0,3);
    punkt p4(-2,0);
    punkt p5(2,0);
    punkt p6(0,2);
    punkt p7(4,5);
    punkt p8(2,8);
    punkt p9(6,12);
    trojkat t1(p1,p2,p3);
    trojkat t2(p4,p5,p6);
    trojkat t3(p7,p8,p9);
    punkt p10(0,1);
    cout<<t1.obwod()<<" "<<t2.obwod()<<endl;
    cout<<t1.pole()<<" "<<t2.pole()<<endl;
    cout<<t1.if_pkt_in(p10)<<endl;
    cout<<czy_tro_roz(t1,t3)<<endl;
    cout<<czy_tro_zaw(t1,t3)<<endl;
    t1.spin(c, 180);
    cout << t1 << endl;
    t1.trans(v);
    cout << t1 << endl;
    t1.sym_os(pr);
    cout << t1 << endl;
    t1.sym_pkt(c);
    cout << t1 << endl;
    trojkat t4(p1, p2, p4);

}