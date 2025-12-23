#ifndef punkt_
#define punkt_
#include "wektor.hpp"
#include "prosta.hpp"
#include<ostream>


class punkt{
private:
    double x, y;
public:
    punkt();

    punkt(double xx, double yy);

    punkt(const punkt &p);

    void set_x(double xval);
    void set_y(double yval);

    double get_x() const;
    double get_y() const;

    punkt &operator=(const punkt &p);
    
    bool operator==(const punkt &p);

    friend std::ostream& operator<<(std::ostream& stream, const punkt &p);

    void trans(const wektor &v);

    void spin(const punkt &p, double angle);
    void sym_pkt(const punkt &p);

    void sym_os(const prosta &p);
};

#endif

