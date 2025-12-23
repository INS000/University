#include"komunikacja.hpp"
#include<iostream>

bool user::chose_side(){
    std::cout << "Wybierasz kolko ( o ) czy krzyzyk ( x ):" << std::endl;
    char c;
    while(true){
        std::cin >> c;
        if(c != 'o' && c != 'x')
            std::cerr << "Podano zly znak, sprobuj ponownie" << std::endl;
        else{
            if(c == 'o')
                return 0;
            return 1;
        }
    }
}

std::pair<int, char> user::chose_place(stan_gry::stan_gry gra){
    std::cout << "Podaj kolumne i wiersz na ktorym chcesz stawic znak" << std::endl;
    char col, c1, c2;
    int row;
    while (true)
    {
        std::cin >> c1 >> c2;
        if(isdigit(c1)){
            row = c1 - '0';
            col = c2;
        }
        else{
            row = c2 - '0';
            col = c1;
        }
        col = toupper(col);
        // std::cin >> col >> row;
        if(col < 'A' || col > 'C' || row < 1 || row > 3 || gra.get_char(row, col) != ' ')
            std::cerr << "Podano zle wspolrzedne, sprobuj ponownie" << std::endl;
        else{
            return std::make_pair(row, col);
        }
    }
}
