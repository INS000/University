#ifndef odc_
#define odc_
#include "punkt.hpp"


prosta pros2pkt(punkt p1, punkt p2);

class odcinek
{
private:
    punkt a, b;
public:
    odcinek(double x1, double y1, double x2, double y2);
    
    odcinek(const punkt &p1, const punkt &p2);

    odcinek(const odcinek &o);

    void set_a(double xval, double yval);

    void set_b(double xval, double yval);

    punkt get_a() const;
    punkt get_b() const;

    odcinek& operator=(const odcinek &o);
    friend std::ostream& operator<<(std::ostream& stream, const odcinek &o);

    void spin(punkt p, double angle);
    
    void trans(wektor &v);

    void sym_pkt(punkt p);

    double dlugosc_odc();
    
    bool if_in(const punkt &p);

    void sym_os(const prosta &p);
};

#endif