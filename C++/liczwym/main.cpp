#include<iostream>
#include"wymierna.hpp"
using namespace std;
using namespace obliczenia;

int main()
{
    // wymierna w1(3,4);
    // cout << w1 << endl; //test konstruktora zwyklego
    // cout << w1.get_licz() << " " << w1.get_mian() << endl; //test obu getterow
    // wymierna w2(6);
    // cout << w2 << endl; //test konstruktora 1-arg i usuwania 1 z mianownika
    // wymierna w3;
    // cout << w3.get_licz() << " " << w3.get_mian() << endl; //test konstruktora na domyslnych wartosciach
    // wymierna w4(2,-3);
    // cout << w4 << endl; //test usuwania minusa z mianownika
    // cout << -w1 << endl; //test operatora liczby przeciwnej
    // cout << !w1 << endl; //test operatora odwrotnosci
    // wymierna w5(10,20);
    // cout << w5 << endl; //test skracania ulamka
    // wymierna w6 = w1;
    // cout << w6 << endl; //test konstruktora kopiujacego
    // cout << w1 + w4 << endl; //test dodawania
    // cout << w1 - w4 << endl; //test odejmowania
    // cout << w1 * w4 << endl; //test mnozenia
    // cout << w1 / w4 << endl; //test dzielenia
    // wymierna w(1,3);
    // cout << w << endl;
    // wymierna ww(2359348,99900);
    // cout << ww << endl;

    // TESTY BLEDOW I WYJATKOW
    // wymierna w7(3,0);
    // cout << w7 << endl; //test dzielenia przez 0 w konstruktorze
    // cout << w1/w3 << endl; //test dzielenia przez 0 jako mnozenie przez odwr




    cout<<" * test konstruktorow *"<<endl;
    wymierna a(3, 4);
    wymierna b(1, 2);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl << endl;
    cout<<" * test operatorow binarnych i unarnych *"<<endl;
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a * b = " << a * b << endl;
    cout << "a / b = " << a / b << endl;
    cout << "!a = " << !a << endl;
    cout << "-a = " << -a << endl << endl;
    cout<<"* test operatorow rzutowania *"<<endl;
    cout << "(double)a = " << (double)a << endl;
    cout << "(int)a = " << (int)a << endl << endl;
    cout<<"* test operatora strumieniowego *"<<endl;
    wymierna okresowa(1, 3);
    cout << "okresowa = " << okresowa << endl;
    wymierna okresowa2(2359348, 99900);
    cout << "okresowa2 = " << okresowa2 << endl << endl;
    cout << "* test konstruktora kopiujacego i konstruktora dla liczb calkowitych*"<<endl;
    wymierna kopia = a;
    cout << "kopia = " << kopia << endl;
    wymierna calkowita(9,3);
    cout << "calkowita = " << calkowita << endl;
    wymierna calkowita2(2);
    cout << "calkowita2 = " << calkowita2 << endl << endl;

    cout << "* test operatorow +=, -=, *=, /= *"<<endl;
    wymierna x(1, 2);
    wymierna y(1, 3);
    cout << "x = " << x << endl;
    x += y;
    cout << "x += y = " << x << endl;
    x -= y;
    cout << "x -= y = " << x << endl;
    x *= y;
    cout << "x *= y = " << x << endl;
    x /= y;
    cout << "x /= y = " << x << endl;

    x += 1;
    cout << "x = " << x << endl;

    // TESTY BLEDOW I WYJATKOW
    // wymierna g(3,0); //test dzielenia przez 0 w konstruktorze

    // wymierna h;   //test dzielenia przez 0 oraz konstruktora domyslnego
    // cout << x / h << endl; 
}
