#include "wyrazenia.hpp"
// #include <vector>
#include <stdexcept>

liczba::liczba(double val) : wartosc(val) {}

double liczba::oblicz() { return wartosc; }
string liczba::zapis() { return to_string(wartosc); }

double stala::oblicz() { return con_val; }
string stala::zapis() { return nazwa; }

pi::pi(){
    con_val = M_PI;
    nazwa = "(pi)";
}

e::e(){
    con_val = M_E;
    nazwa = "(e)";
}

fi::fi(){
    con_val = fi_val;
    nazwa = "(pi)";
}

// vector<pair<string, double>> zmienna::variab;
vector<pair<string, double>> variab;

zmienna::zmienna(string name) : nazwa(name) {}

double zmienna::oblicz() {
    for(pair<string, double>&a : variab){
        if(a.first == nazwa)
            return a.second;
    }
    return 0;
}

string zmienna::zapis() { return nazwa; }

void zmienna::new_val(string name, double val){
    for(pair<string, double>&a : variab){
        if(a.first == name){
            throw invalid_argument("Podana zmienna już istnieje");
        }    
    }
    variab.push_back(make_pair(name, val));
}

void zmienna::set_val(string name, double val){
    for(pair<string, double>&a : variab){
        if(a.first == name){
            a.second = val;
            return;
        }    
    }
    throw invalid_argument("Podana zmienna nie zostala zainicjalizowana");
}

void zmienna::erase_val(string name, double val){
    for(auto i = variab.begin(); i !=variab.end(); i++){
        if(i->first == name){
            variab.erase(i);
            return;
        }    
    }
    throw invalid_argument("Podana zmienna nie zostala zainicjalizowana");
}