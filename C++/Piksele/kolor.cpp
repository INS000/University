#include "kolor.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

kolor::kolor(){
    r = 0;
    g = 0;
    b = 0;
}

kolor::kolor(int red, int green, int blue){
    if(red > 255 || red < 0){
        throw std::invalid_argument("Red color value out of expected range");
    }
    if(green > 255 || green < 0){
        throw std::invalid_argument("Green color value out of expected range");
    }
    if(blue > 255 || blue < 0){
        throw std::invalid_argument("Blue color value out of expected range");
    }
    r = red;
    g = green;
    b = blue;
}

unsigned char kolor::get_r() const{
    return r;
}

unsigned char kolor::get_g() const{
    return g;
}

unsigned char kolor::get_b() const{
    return b;
}

void kolor::set_r(int red){
    if(red > 255 || red < 0){
        throw std::invalid_argument("Color value out of expected range");
    }
    r = red;
}

void kolor::set_g(int green){
    if(green > 255 || green < 0){
        throw std::invalid_argument("Color value out of expected range");
    }
    g = green;
}

void kolor::set_b(int blue){
    if(blue > 255 || blue < 0){
        throw std::invalid_argument("Color value out of expected range");
    }
    b = blue;
}

void kolor::saturation(int val){
    if((int)r + val > 255 || (int)r + val < 0){
        throw std::invalid_argument("Red color value out of expected range");
    }
    if((int)g + val > 255 || (int)g + val < 0){
        throw std::invalid_argument("Green color value out of expected range");
    }
    if((int)b + val > 255 || (int)b + val < 0){
        throw std::invalid_argument("Blue color value out of expected range");
    }

    r += val;
    g += val;
    b += val;
}

kolor kolor::fusion(const kolor &col1, const kolor &col2){
    return kolor(((int)col1.get_r() + (int)col2.get_r()) / 2,
                 ((int)col1.get_g() + (int)col2.get_g()) / 2,
                 ((int)col1.get_b() + (int)col2.get_b()) / 2);
}

std::ostream& operator<<(std::ostream& stream, const kolor &c){
    stream << "(R: " << (int)c.get_r() << ", G: " << (int)c.get_g() << ", B: " << (int)c.get_b() << ")";
    return stream; 
}

kolortransparentny::kolortransparentny() : kolor() {
    alfa = 255;
}

kolortransparentny::kolortransparentny(int red, int green, int blue, int a) : kolor(red, green, blue) {
    alfa = a;
}

unsigned char kolortransparentny::get_alfa() const {
    return alfa;
}

void kolortransparentny::set_alfa(int a){
    if(a > 255 || a < 0){
        throw std::invalid_argument("Transparancy value out of expected range");
    }
    alfa = a;
}

std::ostream& operator<<(std::ostream& stream, const kolortransparentny &c){
    stream << "(R: " << (int)c.get_r() << ", G: " << (int)c.get_g() << ", B: " << (int)c.get_b() << ", Alfa: " << (int)c.get_alfa() <<")";
    return stream; 
}

kolornazwany::kolornazwany() : kolor() {
    name = "";
}

kolornazwany::kolornazwany(int red, int green, int blue, std::string nam) : kolor(red, green, blue) {
    for(auto c : nam){
        if(c > 'z' || c < 'a')
            throw std::invalid_argument("Character out of expectet letters");
    }
    name = nam;
}

std::string kolornazwany::get_name() const {
    return name;
}

void kolornazwany::set_name(std::string nam) {
    for(auto c : nam){
        if(c > 'z' || c < 'a')
            throw std::invalid_argument("Character out of expectet letters");
    }
    name = nam;
}

std::ostream& operator<<(std::ostream& stream, const kolornazwany &c){
    stream << "(R: " << (int)c.get_r() << ", G: " << (int)c.get_g() << ", B: " << (int)c.get_b() << ", Name: " << c.get_name() <<")";
    return stream; 
}

kolornt::kolornt() : kolortransparentny(), kolornazwany() {};
kolornt::kolornt(int red, int green, int blue, int a, std::string nam):kolortransparentny(red, green, blue, a), kolornazwany(red, green, blue, nam) {};

std::ostream& operator<<(std::ostream& stream, const kolornt &c){
    stream << "(R: " << (int)c.get_r() << ", G: " << (int)c.get_g() << ", B: " << (int)c.get_b() << ", Alfa: " << (int)c.get_alfa() << ", Name: " << c.get_name() <<")";
    return stream; 
}

