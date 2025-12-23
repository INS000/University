#include <iostream>
#include "history.hpp"

liczba::liczba(double l){
    actual = l;
    history = new double(his_size);
    contain = 0;
    element = -1;
    
}

liczba::liczba() : liczba(0){};

liczba::liczba(const liczba& l){
    actual = l.actual;
    history = new double(his_size);
    contain = 0;
    element = -1;
}

liczba::liczba(liczba && l){
    actual = l.actual;
    history = l.history;
    contain = l.contain;
    element = l.element;
    l.history = nullptr;
}

const liczba& liczba::operator=(const liczba& l){
    actual = l.actual;
    history = new double(his_size);
    for(int i = 0; i < his_size; i++)
        history[i] = l.history[i];
    contain = l.contain;
    element = l.element;
    return *this;
}

const liczba& liczba::operator=(liczba&& l){
    actual = l.actual;
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
    return actual;
}


void liczba::set_val(double l){
    element = (element + 1) % his_size;
    history[element] = actual;
    actual = l;
    if(contain < his_size)
        contain++;
}

double liczba::undo(){
    if(contain > 0){
        actual = history[element];
        element = (element - 1) % his_size;
        if(element < 0)
            element += his_size;
        contain--;
    }
    else
        std::cerr << "Brak elementow w kolejce" << std::endl;
    return actual;
        
}

