#include "tabbit.hpp"
#include <algorithm>
#include <string>

// wyzerowana tablica bitow [0...rozm]
tab_bit::tab_bit(int rozm){
    dl = rozm;
    int t_size = rozm / rozmiarSlowa;
    if(rozm % rozmiarSlowa)
        t_size++;
    tab = new slowo[t_size];
    for(int i = 0; i < t_size; i++)
        tab[i] = 0;
}

// tablica bitów [0...rozmiarSlowa]
tab_bit::tab_bit(slowo tb){
    dl = rozmiarSlowa;
    tab = new slowo[1];
    tab[0] = tb;
}

// zainicjalizowana wzorcem
tab_bit::tab_bit(std::initializer_list<bool>lista) : tab_bit((int)lista.size()){
    dl = lista.size();
    int bit_ind = 0;
    for(bool bit : lista)
        pisz(bit_ind++, bit);
}

// konstruktor kopiujący
tab_bit::tab_bit(const tab_bit& tb){
    dl = tb.dl;
    int tab_size = dl / rozmiarSlowa;
    if(tab_size % rozmiarSlowa)
        tab_size++;
    tab = new slowo[tab_size];
    for(int i = 0; i < tab_size; i++){
        tab[i] = tb.tab[i];
    }
}

// konstruktor przenoszący
tab_bit::tab_bit(tab_bit &&tb){
    dl = tb.dl;
    tab = tb.tab;
    tb.tab = nullptr;
}

// przypisanie kopiujące
tab_bit& tab_bit::operator=(const tab_bit &tb){
    if (this == &tb)
        return *this;
    delete[] tab;
    dl = tb.dl;
    int tab_size = dl / rozmiarSlowa;
    if(tab_size % rozmiarSlowa)
        tab_size++;
    tab = new slowo[tab_size];
    for(int i = 0; i < tab_size; i++)
        tab[i] = tb.tab[i];
    return *this;
}

// przypisanie przenoszące
tab_bit& tab_bit::operator=(tab_bit &&tb){
    if (this == &tb)
      return *this;
    delete[] tab;
    dl = tb.dl;
    tab = tb.tab;
    tb.tab = nullptr;
    return *this;
}

// destruktor
tab_bit::~tab_bit(){
    if(tab != nullptr)
        delete[] tab;
}

// metoda pomocnicza do odczytu bitu
bool tab_bit::czytaj (int i) const{
    if (i < 0 || i >= dl)
        throw std::out_of_range("indesk spoza zakresu");
    return (tab[i / rozmiarSlowa] & (1ull << (i % rozmiarSlowa))) != 0;
}

// metoda pomocnicza do zapisu bitu
bool tab_bit::pisz(int i, bool b){
    if (i < 0 || i >= dl)
        throw std::out_of_range("indesk spoza zakresu");
    slowo maska = 1ull << (i % rozmiarSlowa);
    tab[i / rozmiarSlowa] = b ? tab[i / rozmiarSlowa] | maska : tab[i / rozmiarSlowa] & ~maska;
    return b;
}

// indeksowanie dla stałych tablic bitowych
bool tab_bit::operator[] (int i) const{
    return czytaj(i);
}

// indeksowanie dla zwykłych tablic bitowych
tab_bit::ref tab_bit::operator[] (int i){
    return ref(i, *this);
}

// rozmiar tablicy w bitach
inline int tab_bit::rozmiar () const{
    return dl;
}

tab_bit tab_bit::operator|(const tab_bit &tb){
    if(rozmiar() != tb.rozmiar())
        throw std::invalid_argument("rozmiary sie roznia");

    tab_bit wyn(rozmiar());
    for (int i = 0; i < rozmiar(); i++) 
        wyn.pisz(i, czytaj(i) | tb.czytaj(i));
    return wyn;
}

tab_bit& tab_bit::operator|=(const tab_bit &tb){
    if(rozmiar() != tb.rozmiar())
        throw std::invalid_argument("rozmiary sie roznia");

    for (int i = 0; i < rozmiar(); i++) 
        pisz(i, czytaj(i) | tb.czytaj(i));
    return *this;
}

tab_bit tab_bit::operator&(const tab_bit &tb){
    if(rozmiar() != tb.rozmiar())
        throw std::invalid_argument("rozmiary sie roznia");

    tab_bit wyn(rozmiar());
    for (int i = 0; i < rozmiar(); i++) 
        wyn.pisz(i, czytaj(i) & tb.czytaj(i));
    return wyn;
}

tab_bit& tab_bit::operator&=(const tab_bit &tb){
    if(rozmiar() != tb.rozmiar())
        throw std::invalid_argument("rozmiary sie roznia");

    for (int i = 0; i < rozmiar(); i++) 
        pisz(i, czytaj(i) & tb.czytaj(i));
    return *this;
}

tab_bit tab_bit::operator^(const tab_bit &tb){
    if(rozmiar() != tb.rozmiar())
        throw std::invalid_argument("rozmiary sie roznia");

    tab_bit wyn(rozmiar());
    for (int i = 0; i < rozmiar(); i++) 
        wyn.pisz(i, czytaj(i) ^ tb.czytaj(i));
    return wyn;
}

tab_bit& tab_bit::operator^=(const tab_bit &tb){
    if(rozmiar() != tb.rozmiar())
        throw std::invalid_argument("rozmiary sie roznia");

    for (int i = 0; i < rozmiar(); i++) 
        pisz(i, czytaj(i) ^ tb.czytaj(i));
    return *this;
}

tab_bit tab_bit::operator!(){
    tab_bit wyn(rozmiar());
    for (int i = 0; i < rozmiar(); i++) 
        wyn.pisz(i, !czytaj(i));
    return wyn;
}

std::istream &operator>>(std::istream &we, tab_bit &tb){
    std::string pom;
    we >> pom; 
    int pom_size = pom.length();
    for(int ind; ind < pom_size; ind++){
        if(pom[ind]=='1')
        {
            tb.pisz(ind,true);
        }
        else if(pom[ind]=='0')
        {
            tb.pisz(ind,false);
        }
        else{
            throw std::invalid_argument("Znak w słowie spoza oczekiwanego zakresu");
        }
    }
    return we;
}

std::ostream &operator<<(std::ostream &wy, const tab_bit &tb){
    for(int ind = 0; ind < tb.dl; ind++) 
        wy << tb.czytaj(ind);
    return wy;
}

tab_bit::ref::operator bool() const { 
    return tab.czytaj(id); 
}

tab_bit::ref& tab_bit::ref::operator=(bool b) {
    tab.pisz(id, b);
    return *this;
}

tab_bit::ref& tab_bit::ref::operator=(const ref &r) {
    if (this == &r)
        return *this; 
    bool b = r.operator bool();
    tab.pisz(id, b);  
    return *this;
}