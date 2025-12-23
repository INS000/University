#include <iostream>
#include "history_v2.hpp"

liczba::liczba(double l){
    history = new double(his_size);
    contain = 1;
    element = 0;
    history[element] = l;

}

liczba::liczba() : liczba(0){};

liczba::liczba(const liczba& l){
    history = new double(his_size);
    contain = 1;
    element = 0;
    history[element] = l.history[l.element];
}

liczba::liczba(liczba && l){
    history = l.history;
    contain = l.contain;
    element = l.element;
    l.history = nullptr;
}

const liczba& liczba::operator=(const liczba& l){
    history = new double(his_size);
    for(int i = 0; i < his_size; i++)
        history[i] = l.history[i];
    contain = l.contain;
    element = l.element;
    return *this;
}

const liczba& liczba::operator=(liczba&& l){
    history = l.history;
    contain = l.contain;
    element = l.element;
    l.history = nullptr;
    return *this;
}

liczba::~liczba(){
    delete[] history;
}

double liczba::get_val(){
    return history[element];
}


void liczba::set_val(double l){
    element = (element + 1) % his_size;
    history[element] = l;
    if(contain < his_size)
        contain++;
}

double liczba::undo(){
    if(contain > 1){
        element = (element - 1) % his_size;
        if(element < 0)
            element += his_size;
        contain--;
    }
    else
        std::cerr << "Brak elementow w kolejce" << std::endl;
    return history[element];

}

