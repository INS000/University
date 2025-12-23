#include "represent.hpp"
#include <iostream>

void present::display(stan_gry::stan_gry gra){
    if(gra.kto_wygral() != 0){
        std::cout << "  A B C" << std::endl;
        for(int i = 1; i <= 3; i++){
            std::cout << i;
            for(int j = 0; j < 3; j++){
                std::cout << " " << gra.get_char(i, 'A' + j);
            }
            std::cout << std::endl;
        }
        if(gra.kto_wygral() == 'D')
            std::cout << "Gra zakonczyla sie remisem";
        std::cout << "Gra zostala wygrana przez " << gra.kto_wygral();
        return;
    }
    std::cout << "  A B C" << std::endl;
    for(int i = 1; i <= 3; i++){
        std::cout << i;
        for(int j = 0; j < 3; j++){
            std::cout << " " << gra.get_char(i, 'A' + j);
        }
        std::cout << std::endl;
    }
}
