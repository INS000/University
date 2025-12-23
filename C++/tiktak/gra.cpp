#include <iostream>
#include "gra.hpp"
#include "komunikacja.hpp"
#include "represent.hpp"
#include "sztucz_int.hpp"

void graj(){
    char znak_gracza, znak_ai;
    if(user::chose_side()){
        znak_gracza = 'x';
        znak_ai = 'o';
    }
    else{
        znak_gracza = 'o';
        znak_ai = 'x';
    }
    stan_gry::stan_gry gra;
    sztucz_int::ai komp;
    std::pair<int, char> poz;
    if(znak_ai == 'o'){
        poz = komp.chose_choice(gra);
        gra.wstaw_znak(znak_ai, poz.first, poz.second);
        present::display(gra);
    }
    while (true)
    {
        poz = user::chose_place(gra);
        gra.wstaw_znak(znak_gracza, poz.first, poz.second);
        if(gra.kto_wygral() != 0){
            present::display(gra);
            return;
        }
        poz = komp.chose_choice(gra);
        gra.wstaw_znak(znak_ai, poz.first, poz.second);
        if(gra.kto_wygral() != 0){
            present::display(gra);
            return;
        }
        present::display(gra);
    }


}
