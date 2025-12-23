#include "op1arg.hpp"
#include <stdexcept>
#define ang_to_rad M_PI / 180

operator1arg::~operator1arg() { delete arg1; }
operator1arg::operator1arg(wyrazenie *wyr) { arg1 = wyr; }

Sin::Sin(wyrazenie *wyr1) : operator1arg(wyr1) {}
double Sin::oblicz() { return sin(arg1->oblicz() ); }
string Sin::zapis() { return "(sin(" + arg1->zapis() + "))"; }

Cos::Cos(wyrazenie *wyr1) : operator1arg(wyr1) {}
double Cos::oblicz() { return cos(arg1->oblicz() ); }
string Cos::zapis() { return "(cos(" + arg1->zapis() + "))"; }

Exp::Exp(wyrazenie *wyr1) : operator1arg(wyr1) {}
double Exp::oblicz() { return exp(arg1->oblicz()); }
string Exp::zapis() { return "(e^" + arg1->zapis() + ")"; }

Ln::Ln(wyrazenie *wyr1) : operator1arg(wyr1) {}
double Ln::oblicz() { return log(arg1->oblicz()); }
string Ln::zapis() { return "(ln(" + arg1->zapis() + "))"; }

Bezwzgl::Bezwzgl(wyrazenie *wyr1) : operator1arg(wyr1) {}
double Bezwzgl::oblicz() { return abs(arg1->oblicz()); }
string Bezwzgl::zapis() { return "(|" + arg1->zapis() + "|)"; }

Przeciw::Przeciw(wyrazenie *wyr1) : operator1arg(wyr1) {}
double Przeciw::oblicz() { return -1 * arg1->oblicz(); }
string Przeciw::zapis() { return "((-1) * " + arg1->zapis() + ")"; }

Odwrot::Odwrot(wyrazenie *wyr1) : operator1arg(wyr1) {}
double Odwrot::oblicz() {
    if(arg1->oblicz() == 0)
        throw invalid_argument("Nie można dzielic przez 0");
    return 1 / arg1->oblicz(); 
}
string Odwrot::zapis() { return "(1 / (" + arg1->zapis() + "))"; }

