#include <iostream>
#include "history2.hpp"

using namespace std;

int main()
{
    liczba L;
    cout << L.get_val() << endl;
    L.set_val(5);
    L.set_val(4.2);
    L.set_val(3);
    L.set_val(7);
    L.set_val(4.4);
    L.set_val(90);
    cout << L.get_val() << endl << L.undo() << endl << L.undo() << endl << L.undo() << endl << L.undo() << endl;
    liczba L2(3.0);
    L2.set_val(5.0);
    liczba L3(L2);
    cout << L3.get_val() << endl;
    liczba L4;
    L4 = L3;
    cout << L4.get_val() << endl;
    L.set_val(8);
    cout << L.get_val() << endl;
    liczba L5(move(liczba(9)));
    cout << L5.get_val() << endl;
    liczba L6;
    L6 = liczba(10);
    cout << L6.get_val();
}