#include "kolor.hpp"
#include "wektor.hpp"

class piksel
{
protected:
    int x, y;
    static const int rozm_x = 800, rozm_y = 600;

public:
    piksel();
    piksel(int nx, int ny);

    int get_x() const;
    int get_y() const;

    void set_x(int nx);
    void set_y(int ny);

    int edge_l();
    int edge_r();
    int edge_d();
    int edge_u();

    friend std::ostream &operator<<(std::ostream &output, const piksel &p);
};

std::ostream &operator<<(std::ostream &output, const piksel &p);

class pikselkolorowy : public piksel
{
    kolortransparentny c;

public:
    pikselkolorowy();
    pikselkolorowy(int nx, int ny, int red, int green, int blue, int a);

    unsigned char get_r() const;
    unsigned char get_g() const;
    unsigned char get_b() const;
    unsigned char get_alfa() const;
    
    void set_r(int red);
    void set_g(int green);
    void set_b(int blue);
    void set_alfa(int a);

    void trans(const wektor& v);
    void trans(int vx, int vy);

    friend std::ostream &operator<<(std::ostream &output, const piksel &p);
};

std::ostream &operator<<(std::ostream &output, const piksel &p);

int odleglosc(const piksel &p, const piksel &q);

