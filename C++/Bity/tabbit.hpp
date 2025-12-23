#include<iostream>


class tab_bit
{
typedef uint64_t slowo; // komorka w tablicy
static const int rozmiarSlowa = sizeof(slowo) * 8; // rozmiar slowa w bitach
friend std::istream & operator >> (std::istream &we, tab_bit &tb);
friend std::ostream & operator << (std::ostream &wy, const tab_bit &tb);
class ref // klasa pomocnicza do adresowania bitów
{
    friend class tab_bit;
    tab_bit &tab;
    int id;
    ref(int i, tab_bit &t) : tab(t), id(i) {};
    public:
        operator bool() const;
        ref &operator=(bool b);
        ref &operator=(const ref &r);
};
protected:
    int dl; // liczba bitów
    slowo *tab; // tablica bitów
public:
    explicit tab_bit (int rozm); // wyzerowana tablica bitow [0...rozm]
    explicit tab_bit (slowo tb); // tablica bitów [0...rozmiarSlowa]
    tab_bit (std::initializer_list<bool> lista);// zainicjalizowana wzorcem
    tab_bit (const tab_bit &tb); // konstruktor kopiujący
    tab_bit (tab_bit &&tb); // konstruktor przenoszący
    tab_bit & operator = (const tab_bit &tb); // przypisanie kopiujące
    tab_bit & operator = (tab_bit &&tb); // przypisanie przenoszące
    ~tab_bit (); // destruktor
private:
    bool czytaj (int i) const; // metoda pomocnicza do odczytu bitu
    bool pisz (int i, bool b); // metoda pomocnicza do zapisu bitu
public:
    bool operator[] (int i) const; // indeksowanie dla stałych tablic bitowych
    ref operator[] (int i); // indeksowanie dla zwykłych tablic bitowych
    inline int rozmiar () const; // rozmiar tablicy w bitach
public:
    tab_bit operator|(const tab_bit &tb);
    tab_bit &operator|=(const tab_bit &tb);
    tab_bit operator&(const tab_bit &tb);
    tab_bit &operator&=(const tab_bit &tb);
    tab_bit operator^(const tab_bit &tb);
    tab_bit &operator^=(const tab_bit &tb);
    tab_bit operator!();
// public:
// friend istream &operator>>(std::istream &we, tab_bit &tb);
// friend ostream &operator<<(std::ostream &wy, const tab_bit &tb);

};

std::istream &operator>>(std::istream &we, tab_bit &tb);
std::ostream &operator<<(std::ostream &wy, const tab_bit &tb);