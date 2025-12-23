#include "piksel.hpp"
#include <iostream>
#include <stdexcept>
#include <cmath>

piksel::piksel(){
    x = 0;
    y = 0;
}

piksel::piksel(int nx, int ny){
    if(nx < 0 || nx >= rozm_x){
        throw std::invalid_argument("X out of expected range");
    }
    if(ny < 0 || ny >= rozm_y){
        throw std::invalid_argument("Y out of expected range");
    }
    x = nx;
    y = ny;
}

int piksel::get_x() const{
    return x;
}

int piksel::get_y() const{
    return y;
}

void piksel::set_x(int nx){
    x = nx;
}

void piksel::set_y(int ny){
    y = ny;
}

int piksel::edge_l(){
    return x + 1;
}

int piksel::edge_r(){
    return rozm_x - x;
}

int piksel::edge_d(){
    return y + 1;
}

int piksel::edge_u(){
    return rozm_y - y;
}

std::ostream &operator<<(std::ostream &output, const piksel &p){
    output << "(X: " << p.get_x() << ", Y: " << p.get_y() << ")";
         return output;
}

pikselkolorowy::pikselkolorowy() : piksel() {};

pikselkolorowy::pikselkolorowy(int nx, int ny, int red, int green, int blue, int a) :
    piksel(nx, ny), c(red, green, blue, a) {};

unsigned char pikselkolorowy::get_r() const{
    return c.get_r();
}

unsigned char pikselkolorowy::get_g() const{
    return c.get_g();
}

unsigned char pikselkolorowy::get_b() const{
    return c.get_b();
}

void pikselkolorowy::set_r(int red){
    if(red > 255 || red < 0){
        throw std::invalid_argument("Color value out of expected range");
    }
    c.set_r(red);
}

void pikselkolorowy::set_g(int green){
    if(green > 255 || green < 0){
        throw std::invalid_argument("Color value out of expected range");
    }
    c.set_g(green);
}

void pikselkolorowy::set_b(int blue){
    if(blue > 255 || blue < 0){
        throw std::invalid_argument("Color value out of expected range");
    }
    c.set_b(blue);
}

unsigned char pikselkolorowy::get_alfa() const {
    return c.get_alfa();
}

void pikselkolorowy::set_alfa(int a){
    if(a > 255 || a < 0){
        throw std::invalid_argument("Transparancy value out of expected range");
    }
    c.set_alfa(a);
}

void pikselkolorowy::trans(const wektor& v){
    if(x + v.get_x() >= rozm_x || x + v.get_x() < 0 ||  y + v.get_y() >= rozm_y || y + v.get_y() < 0)
        throw std::invalid_argument("Pixel after translation out of resolution range");
    set_x(get_x() + v.get_x());
    set_y(get_y() + v.get_y());
}

void pikselkolorowy::trans(int vx, int vy){
    if(x + vx >= rozm_x || x + vx < 0 ||  y + vy >= rozm_y || y + vy < 0)
        throw std::invalid_argument("Pixel after translation out of resolution range");
    set_x(get_x() + vx);
    set_y(get_y() + vy);
}

std::ostream &operator<<(std::ostream &output, const pikselkolorowy &p){
    output << "(X: " << p.get_x() << ", Y: " << p.get_y() << "R: " << (int)p.get_r() << ", G: " << (int)p.get_g() << ", B: " << (int)p.get_b() << ", Alfa: " << (int)p.get_alfa() << ")";
         return output;
}

int odleglosc(const piksel &p, const piksel &q){
    double o1 = p.get_x() - q.get_x(), o2 = p.get_y() - q.get_y();
    double odl = round(sqrt(o2 * o2 + o1 * o1));
    return (int)odl;
}
