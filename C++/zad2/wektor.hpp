#ifndef wek_
#define wek_

class wektor
{
private:
    double x, y;
public:
    wektor(double xx, double yy) : x(xx), y(yy) {}
    wektor(const wektor &v) : x(v.x), y(v.y) {}

    void set_x(double xval);
    void set_y(double yval);

    double get_x() const;
    double get_y() const;

    wektor &operator=(const wektor &v){
        x = v.x;
        y = v.y;
        return *this;
    } 
    
};

#endif