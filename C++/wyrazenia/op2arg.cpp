#include "op2arg.hpp"
#include<stdexcept>

operator2arg::operator2arg(wyrazenie *wyr1, wyrazenie *wyr2) : operator1arg(wyr1) {
    arg2 = wyr2;
}
operator2arg::~operator2arg() { delete arg2; }

dodaj::dodaj(wyrazenie *wyr1, wyrazenie *wyr2) : operator2arg(wyr1, wyr2) {};
double dodaj::oblicz() { return arg1->oblicz() + arg2->oblicz(); }
string dodaj::zapis() { return "(" + arg1->zapis() +  " + " + arg2->zapis() + ")"; }

odejmij::odejmij(wyrazenie *wyr1, wyrazenie *wyr2) : operator2arg(wyr1, wyr2) {};
double odejmij::oblicz() { return arg1->oblicz() - arg2->oblicz(); }
string odejmij::zapis() { return "(" + arg1->zapis() +  " - " + arg2->zapis() + ")"; }

mnoz::mnoz(wyrazenie *wyr1, wyrazenie *wyr2) : operator2arg(wyr1, wyr2) {};
double mnoz::oblicz() { return arg1->oblicz() * arg2->oblicz(); }
string mnoz::zapis() { return "(" + arg1->zapis() +  " * " + arg2->zapis() + ")"; }

dziel::dziel(wyrazenie *wyr1, wyrazenie *wyr2) : operator2arg(wyr1, wyr2) {};
double dziel::oblicz() { 
    if(arg2->oblicz() == 0)
        throw invalid_argument("Nie można dzielic przez 0");
    return arg1->oblicz() / arg2->oblicz(); 
}
string dziel::zapis() { return "(" + arg1->zapis() +  " / " + arg2->zapis() + ")"; }

logarytm::logarytm(wyrazenie *wyr1, wyrazenie *wyr2) : operator2arg(wyr1, wyr2) {};
double logarytm::oblicz() {
    if(arg1->oblicz() <= 0 || arg1->oblicz() == 1 || arg2->oblicz() <= 0)
        throw invalid_argument("Nie można zlogarytmowac liczby");
    return log(arg2->oblicz()) / log(arg1->oblicz());
}
string logarytm::zapis() { return "(log" + arg1->zapis() +  " (" + arg2->zapis() + "))"; }

double modulo::oblicz() {
    double wyn = fmod(arg1->oblicz(), arg2->oblicz());
    return wyn >= 0 ? wyn : wyn + arg2->oblicz();
}
string modulo::zapis() { return "(" + arg1->zapis() +  " mod " + arg2->zapis() + ")"; }

potega::potega(wyrazenie *wyr1, wyrazenie *wyr2) : operator2arg(wyr1, wyr2) {};
double potega::oblicz() {
    return pow(arg1->oblicz(), arg2->oblicz());
}
string potega::zapis() { return "(" + arg1->zapis() +  " ^ " + arg2->zapis() + ")"; }

