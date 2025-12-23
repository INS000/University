#ifndef pros_
#define pros_


class prosta
{
private:
    double a, b, c;
public:
    prosta(double x, double y, double z);
    
    prosta &operator=(const prosta &p);

    void set_a(double aval);
    void set_b(double bval);
    void set_c(double cval);

    double get_a() const;
    double get_b() const;
    double get_c() const;
};

#endif