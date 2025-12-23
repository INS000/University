#include "op1arg.hpp"

class operator2arg : public operator1arg {
protected:
    wyrazenie *arg2;

public:
    operator2arg(wyrazenie *wyr1, wyrazenie *wyr2);
    virtual ~operator2arg();
    
};

class dodaj : public operator2arg {
public:
    dodaj(wyrazenie *wyr1, wyrazenie *wyr2);
    double oblicz();
    string zapis();
};

class odejmij : public operator2arg {
public:
    odejmij(wyrazenie *wyr1, wyrazenie *wyr2);
    double oblicz();
    string zapis();
};

class mnoz : public operator2arg {
public:
    mnoz(wyrazenie *wyr1, wyrazenie *wyr2);
    double oblicz();
    string zapis();
};

class dziel : public operator2arg {
public:
    dziel(wyrazenie *wyr1, wyrazenie *wyr2);
    double oblicz();
    string zapis();
};

class logarytm : public operator2arg {
public:
    logarytm(wyrazenie *wyr1, wyrazenie *wyr2);
    double oblicz();
    string zapis();
};

class modulo : public operator2arg {
public:
    modulo(wyrazenie *wyr1, wyrazenie *wyr2);
    double oblicz();
    string zapis();
};

class potega : public operator2arg {
public:
    potega(wyrazenie *wyr1, wyrazenie *wyr2);
    double oblicz();
    string zapis();
};

