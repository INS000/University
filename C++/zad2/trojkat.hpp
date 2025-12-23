#ifndef troj_
#define troj_
using namespace std;
#include "global.hpp"


class trojkat
{
private:
    punkt a, b, c;
public:
    trojkat(double x1, double y1, double x2, double y2, double x3, double y3);

    trojkat(const punkt &p1, const punkt &p2, const punkt &p3);

    trojkat(const trojkat &tr);

    void set_a(double xval, double yval);
    void set_b(double xval, double yval);
    void set_c(double xval, double yval);

    punkt get_a();
    punkt get_b();
    punkt get_c();

    trojkat& operator=(const trojkat &o);
    friend std::ostream& operator<<(std::ostream& stream, const trojkat &p);

    double obwod();

    double pole();

    void spin(punkt p, double angle);   

    void trans(wektor &v);

    void sym_pkt(punkt p);

    bool if_pkt_in(punkt p);
    void sym_os(prosta p);
};



#endif

