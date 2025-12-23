#include "wyrazenia.hpp"

class operator1arg : public wyrazenie {
protected:
    wyrazenie *arg1;

public:
    operator1arg(wyrazenie *wyr);
    virtual ~operator1arg();
    
};

class Sin : public operator1arg {
public:
    Sin(wyrazenie *wyr1);
    double oblicz();
    string zapis();
};

class Cos : public operator1arg {
public:
    Cos(wyrazenie *wyr1);
    double oblicz();
    string zapis();
};

class Exp : public operator1arg {
public:
    Exp(wyrazenie *wyr1);
    double oblicz();
    string zapis();
};

class Ln : public operator1arg {
public:
    Ln(wyrazenie *wyr1);
    double oblicz();
    string zapis();
};

class Bezwzgl : public operator1arg {
public:
    Bezwzgl(wyrazenie *wyr1);
    double oblicz();
    string zapis();
};

class Przeciw : public operator1arg {
public:
    Przeciw(wyrazenie *wyr1);
    double oblicz();
    string zapis();
};

class Odwrot : public operator1arg {
public:
    Odwrot(wyrazenie *wyr1);
    double oblicz();
    string zapis();
};

