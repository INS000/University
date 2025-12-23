#include "wymierna.hpp"
#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <cmath>

#include <unordered_map>
#include <vector>

obliczenia::wyjatek_wymierny::wyjatek_wymierny(const std::string &err): logic_error(err) {}

obliczenia::przekorczenie_zakresu::przekorczenie_zakresu(const std::string &err): wyjatek_wymierny(err) {}

obliczenia::dzielenie_przez_0::dzielenie_przez_0(const std::string &err): wyjatek_wymierny(err) {}

int obliczenia::wymierna::get_licz() const{
    return licz;
}

int obliczenia::wymierna::get_mian() const{
    return mian;
}

int obliczenia::nwd(ll a, ll b){
    return (a == 0) ? b : nwd(b % a, a);
}

int obliczenia::nww(ll a, ll b){
    return a * b / nwd(a, b);
}

obliczenia::wymierna::wymierna(ll l, ll m){
    if(m == 0)
        throw dzielenie_przez_0("Nie mozna dzielic przez 0");
    if(m < 0){
        m *= -1;
        l *= -1;
    }
    ll pom = nwd(abs(l), abs(m));
    l /= pom;
    m /= pom;
    if(m > INT_MAX || l < INT_MIN || l > INT_MAX)
        throw przekorczenie_zakresu("Ulamka nie da sie zapisac za pomoca int");
    licz = l;
    mian = m;
}

obliczenia::wymierna::wymierna(ll calk) : wymierna(calk, 1){};

obliczenia::wymierna::wymierna() : wymierna(0){};

void obliczenia::wymierna::operator+=(wymierna const& wym2){
    *this = *this + wym2;
}

void obliczenia::wymierna::operator-=(wymierna const& wym2){
    *this = *this - wym2;
}

void obliczenia::wymierna::operator*=(wymierna const& wym2){
    *this = *this * wym2;
}

void obliczenia::wymierna::operator/=(wymierna const& wym2){
    *this = *this / wym2;
}

obliczenia::wymierna::operator double() const{
    return (double)licz / mian;
}

obliczenia::wymierna::operator int() const{
    return round((double)*this);
}

obliczenia::wymierna obliczenia::operator+(wymierna const& wym1, wymierna const& wym2){
    ll pom = nww(wym1.get_mian(), wym2.get_mian());
    ll l1 = wym1.get_licz() * pom / wym1.get_mian();
    ll l2 = wym2.get_licz() * pom / wym2.get_mian();
    return wymierna(l1 + l2, pom);
}

obliczenia::wymierna obliczenia::operator-(wymierna const& wym1, wymierna const& wym2){
    ll pom = nww(wym1.get_mian(), wym2.get_mian());
    ll l1 = wym1.get_licz() * pom / wym1.get_mian();
    ll l2 = wym2.get_licz() * pom / wym2.get_mian();
    return wymierna(l1 - l2, pom);
}

obliczenia::wymierna obliczenia::operator*(wymierna const& wym1, wymierna const& wym2){
    return wymierna(wym1.get_licz() * wym2.get_licz(), wym1.get_mian() * wym2.get_mian());
}

obliczenia::wymierna obliczenia::operator/(wymierna const& wym1, wymierna const& wym2){
    return wymierna(wym1.get_licz() * wym2.get_mian(), wym1.get_mian() * wym2.get_licz());
}

obliczenia::wymierna obliczenia::operator-(wymierna const& wym1){
    return wymierna(-wym1.get_licz(), wym1.get_mian());
}

obliczenia::wymierna obliczenia::operator!(wymierna const& wym1){
    return wymierna(wym1.get_mian(), wym1.get_licz());
}

std::ostream& obliczenia::operator<< (std::ostream& wyj, const wymierna& w) {
    int l = w.get_licz();
    int m = w.get_mian();
    if (l < 0) {
        wyj << "-";
        l = -l;
    }
    int calk = l / m;
    wyj << calk;
    int resz = l % m;
    if (resz != 0) {
        wyj << ".";
        std::unordered_map<int, int> pozycje;
        std::vector<int> cyfry;
        while (resz != 0) {
            if (pozycje.find(resz) != pozycje.end()) {
                int pozycja = pozycje[resz];
                for (int i = 0; i < cyfry.size(); i++) {
                    if (i == pozycja)
                        wyj << "(";
                    wyj << cyfry[i];
                }
                wyj << ")";
                return wyj;
            }
            pozycje[resz] = cyfry.size();
            int cyfra = (resz * 10) / m;
            cyfry.push_back(cyfra);
            resz = (resz * 10) % m;
        }
        for (int i = 0; i < cyfry.size(); i++) {
            wyj << cyfry[i];
        }
    }
    return wyj;
}
