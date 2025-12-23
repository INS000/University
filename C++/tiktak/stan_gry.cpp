#include "stan_gry.hpp"
#include <stdexcept>

stan_gry::stan_gry::stan_gry()
{
    pozostale = 9;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            plansza[i][j] = ' ';
        }
    }
}

bool stan_gry::stan_gry::finished(){
    return pozostale == 0;
}

char stan_gry::stan_gry::kto_wygral(){
    for(int i = 0; i < 3; i++){
        if(plansza[i][0] == plansza[i][1] && plansza[i][1] == plansza[i][2] && 
        plansza[i][1] != ' ')
            return plansza[i][0];
        if(plansza[0][i] == plansza[1][i] && plansza[1][i] == plansza[2][i] &&
         plansza[2][i] != ' ')
            return plansza[0][i];
    }
    if(((plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2]) ||
        (plansza[2][0] == plansza[1][1] && plansza[1][1] == plansza[0][2])) &&
        plansza[1][1] != ' ')
        return plansza[1][1];
    if(finished())
        return 'D';
    else
        return 0;
}

void stan_gry::stan_gry::wstaw_znak(char znak, int wie, char kol){
    if(finished()){
        throw std::invalid_argument("nie ma wolnego miejsca do wstawienia znaku");
    }

    if(znak != 'o' && znak != 'x'){
        throw std::invalid_argument("znak nie jest kolkiem lub krzyzykiem");
    }

    if(kol < 'A' || kol > 'C' || wie < 1 || wie > 3){
        throw std::invalid_argument("zle id komorki do wstawienia");
    }

    if(plansza[wie - 1][kol - 'A'] !=  ' '){
        throw std::invalid_argument("komorka nie jest pusta");
    }

    plansza[wie - 1][kol - 'A'] = znak;
    pozostale--;
}

char stan_gry::stan_gry::get_char(int wie, char kol){
    if(kol < 'A' || kol > 'C' || wie < 1 || wie > 3){
        throw std::invalid_argument("zle id komorki");
    }

    return plansza[wie - 1][kol - 'A'];
}
