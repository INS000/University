#include<iostream>
#include "op2arg.hpp"

wyrazenie *w1 = new dziel(
      new mnoz(
        new odejmij(
          new zmienna("x") , 
          new liczba(1)), 
        new zmienna("x")),
      new liczba(2));

 wyrazenie *w2 = new dziel (
    new dodaj (
      new liczba(3), 
      new liczba(5)),
    new dodaj(
      new liczba(2), 
      new mnoz(
        new zmienna("x"), 
        new liczba(7))));

  wyrazenie *w3 = new odejmij (
    new dodaj(
      new liczba(2), 
      new mnoz(
        new zmienna("x"), 
        new liczba(7))),
    new dodaj(
      new mnoz(
        new zmienna("y"), 
        new liczba(3)), 
      new liczba(5)));

  wyrazenie *w4 = new dziel(
    new Cos(
      new mnoz(
        new dodaj(
          new zmienna("x"),
          new liczba(1)), 
        new pi())),
    new potega(
      new e(),
      new potega(
        new zmienna("x"), 
        new liczba(2))));

void testuj(double x, double y){
  zmienna::set_val("x", x);
  zmienna::set_val("y", y);
  cout << "x = " << x << endl << "y = " << y << endl << w1->zapis() << " = " << w1->oblicz() << endl << w2->zapis() << " = " << w2->oblicz() << endl << w3->zapis() << " = " << w3->oblicz() << endl << w4->zapis() << " = " << w4->oblicz() << endl << endl;
  
}

int main(){
    wyrazenie *w = new odejmij(
      new pi(),
      new dodaj(new liczba(2), new mnoz(new zmienna("h"), new liczba(7))));
  zmienna::new_val("h", 0);
  // cout << w->zapis() << endl;
  zmienna::set_val("h", 5);
  // cout <<"wartosc wyrazenia powyzej: " << w->oblicz() << endl;

  // cout << endl;
  
  // wyrazenie *pom1 = (new zmienna("x"));
  // wyrazenie *w1 = new dziel(
  //     new mnoz(
  //       new odejmij(
  //         new zmienna("x") , 
  //         new liczba(1)), 
  //       new zmienna("x")),
  //     new liczba(2));
  zmienna::new_val("x", 0);
  // cout << w1->zapis() << endl;
   zmienna::set_val("x", 1);
  // cout << "wartosc wyrazenia powyzej: " <<  w1->oblicz() << endl;

  // cout << endl;

  // wyrazenie *w2 = new dziel (
  //   new dodaj (
  //     new liczba(3), 
  //     new liczba(5)),
  //   new dodaj(
  //     new liczba(2), 
  //     new mnoz(
  //       new zmienna("x"), 
  //       new liczba(7))));
  zmienna::set_val("x", 4);
  // cout << w2->zapis() << endl;
  zmienna::set_val("x", 6);
  // cout<< "wartosc wyrazenia powyzej: " << w2->oblicz() << endl;

  // cout << endl;

  // wyrazenie *w3 = new odejmij (
  //   new dodaj(
  //     new liczba(2), 
  //     new mnoz(
  //       new zmienna("x"), 
  //       new liczba(7))),
  //   new dodaj(
  //     new mnoz(
  //       new zmienna("y"), 
  //       new liczba(3)), 
  //     new liczba(5)));
  // cout << w3->zapis() << endl;
  zmienna::set_val("x", 0);
  zmienna::new_val("y", 0);
  // cout << "wartosc wyrazenia powyzej: " << w3->oblicz() << endl;

  // cout << endl;
  
  // wyrazenie *pom2 = new zmienna("c");
  // wyrazenie *w4 = new dziel(
  //   new Cos(
  //     new mnoz(
  //       new dodaj(
  //         new zmienna("x"),
  //         new liczba(1)), 
  //       new pi())),
  //   new potega(
  //     new e(),
  //     new potega(
  //       new zmienna("x"), 
  //       new liczba(2))));
  // cout << w4->zapis() << endl;
  zmienna::set_val("x", 2);
  // cout << "wartosc wyrazenia powyzej: " << w4->oblicz() << endl;
  zmienna::set_val("x", 1);
  // cout << "wartosc wyrazenia powyzej: " << w4->oblicz() << endl;  
  cout << "//////////////////////////" <<endl;
  // zmienna::set_val("x", 0);
  // zmienna::set_val("y", 0);
  // cout << w1->zapis() << " = " << w1->oblicz() << endl << w2->zapis() << " = " << w2->oblicz() << endl << w3->zapis() << " = " << w3->oblicz() << endl << w->zapis() << " = " << w4->oblicz() << endl << endl;
  
  // // zmienna::set_val("x", 0);
  // zmienna::set_val("y", 0.5);
  // cout << w1->oblicz() << endl << w2->oblicz() << endl << w3->oblicz() << endl << w4->oblicz() << endl << endl;
  
  // zmienna::set_val("x", 0.5);
  // zmienna::set_val("y", 0);
  // cout << w1->oblicz() << endl << w2->oblicz() << endl << w3->oblicz() << endl << w4->oblicz() << endl << endl;
  
  // // zmienna::set_val("x", 0);
  // zmienna::set_val("y", 0.5);
  // cout << w1->oblicz() << endl << w2->oblicz() << endl << w3->oblicz() << endl << w4->oblicz() << endl << endl;
  


  // zmienna::set_val("x", 1);
  // zmienna::set_val("y", 1);
  // cout <<  w1->oblicz() << endl << w2->oblicz() << endl << w3->oblicz() << endl << w4->oblicz() << endl << endl;
  
  testuj(0, 0);
  testuj(0, 0.5);
  testuj(0.5, 0);
  testuj(0.5, 0.5);
  testuj(1, 1);
}