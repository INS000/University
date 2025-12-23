#include<iostream>
#include "piksel.hpp"
using namespace std;


int main(){
    kolor k1 = kolor();
    kolortransparentny k2(255,0,0,255);
    kolornazwany k3(0,255,0,"zielony");
    kolornt k4(0,0,0,0,"czarny");
    piksel p1(400,300);
    pikselkolorowy p2(400,0,255,0,0,255); 
    cout << k1 << endl;
    k1.set_r(255);
    cout << "Po zmianie: " << k1 << endl << endl;
    cout << k2 << endl;
    k2.set_alfa(0);
    k2.set_r(0);
    cout << "Po zmianie : " << k2 << endl << endl;
   cout << k3 << endl;
    k3.set_name("niebieski");
    k3.set_b(255);
    k3.set_g(0);
    cout << "Po zmianie : " << k3 << endl << endl;
    cout << k4 << endl;
    k4.set_alfa(56);
    k4.set_r(255);
    k4.set_name("czerwony");
    cout << "Po zmianie : " << k4 << endl << endl;
    cout << "Odleglosc od gory: " << p1.edge_u() << endl;
    cout << "Odleglosc od dolu: " << p1.edge_d() << endl;
    cout << "Odleglosc od lewej: " << p1.edge_l() << endl;
    cout << "Odleglosc od prawej: " << p1.edge_r() << endl << endl;
    cout << p1 << endl << p2 << endl;
    cout << "Odleglosc miedzy p1 i p2: " << odleglosc(p1,p2) << endl << endl;
    p2.trans(0,200);
    cout << p2 << endl;
    cout << "Odleglosc miedzy p1 i p2 po pierwszym przesunieciu " << odleglosc(p1,p2) << endl << endl;
    wektor w(20, 30);
    p2.trans(w);
    cout << p2 << endl;
    cout << "Odleglosc miedzy p1 i p2 po drugim przesunieciu " << odleglosc(p1,p2) << endl << endl;
    cout << "Test wywalenia poza ekran";
    p2.trans(500,500);
    k1.set_b(256);
    k3.set_name("Biały");
    k2.set_alfa(256);
    cout << k1 << endl << k3 << endl << k2; 
    return 0;
}