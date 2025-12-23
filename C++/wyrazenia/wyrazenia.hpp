#include <string>
#include <cmath>
#include <vector>
using namespace std;

class wyrazenie{
public:
    wyrazenie() = default;
    virtual double oblicz() = 0;
    virtual string zapis() = 0;
private:
    wyrazenie(wyrazenie &w) = delete;
    wyrazenie& operator= (const wyrazenie&) = delete;
};

class liczba : public wyrazenie{
    double wartosc;

public:
    liczba(double val);
    double oblicz();
    string zapis();

};

class stala : public wyrazenie{
protected:
    double con_val;
    string nazwa;

public:
    double oblicz();
    string zapis();
};

class pi final : public stala{
public:
    pi();
};

class e final : public stala{
public:
    e();
};

class fi final : public stala{
    const double fi_val = (1 + sqrt(5)) / 2;
public:
    fi();
};

class zmienna : public wyrazenie {
    string nazwa;
    // static vector<pair<string, double>> variab;
public:
    zmienna(string name);
    double oblicz();
    string zapis();
    static void new_val(string name, double val);
    static void set_val(string name, double val);
    static void erase_val(string name, double val);
};

