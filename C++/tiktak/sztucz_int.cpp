#include "sztucz_int.hpp"
#include <cstdlib>
#include <ctime>
#include <stdexcept>

sztucz_int::ai::ai(){
    srand(time(NULL));
}

void sztucz_int::ai::gen_choices(stan_gry::stan_gry gra){
    wolne_pola.clear();
    for(int i = 1; i <= 3; i++){
        for(int j = 0; j < 3; j++){
            if(gra.get_char(i, 'A' + j) == ' ')
                wolne_pola.push_back(std::make_pair(i, 'A' + j));
        }
    }
}

std::pair<int, char> sztucz_int::ai::chose_choice(stan_gry::stan_gry gra){
    gen_choices(gra);
    if(wolne_pola.size() == 0)
        throw std::invalid_argument("Brak wolnego pola");
    return wolne_pola[rand() % wolne_pola.size()];
}
