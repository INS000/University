#include<stdexcept>
#define ll long long

namespace obliczenia{
    int nwd(ll a, ll b);
    int nww(ll a, ll b);
    
    class wyjatek_wymierny: public std::logic_error{
    public:
        wyjatek_wymierny(const std::string &err);
    };

    class przekorczenie_zakresu: public wyjatek_wymierny{
    public:
        przekorczenie_zakresu(const std::string &err);
    };

    class dzielenie_przez_0: public wyjatek_wymierny{
    public:
        dzielenie_przez_0(const std::string &err);
    };

    class wymierna {
        int licz, mian;
    public:
        int get_licz() const;
        int get_mian() const;

        wymierna(ll l, ll m);
        wymierna(ll calk);
        wymierna();

        friend wymierna operator+(wymierna const& wym1, wymierna const& wym2);
        friend wymierna operator-(wymierna const& wym1, wymierna const& wym2);
        friend wymierna operator*(wymierna const& wym1, wymierna const& wym2);
        friend wymierna operator/(wymierna const& wym1, wymierna const& wym2);

        void operator+=(wymierna const& wym2);
        void operator-=(wymierna const& wym2);
        void operator*=(wymierna const& wym2);
        void operator/=(wymierna const& wym2);

        friend wymierna operator-(wymierna const& wym1);
        friend wymierna operator!(wymierna const& wym1);

        explicit operator double() const;
        explicit operator int() const;

        friend std::ostream &operator<<(std::ostream &wyj, const wymierna &w);
    };

    wymierna operator+(wymierna const& wym1, wymierna const& wym2);
    wymierna operator-(wymierna const& wym1, wymierna const& wym2);
    wymierna operator*(wymierna const& wym1, wymierna const& wym2);
    wymierna operator/(wymierna const& wym1, wymierna const& wym2);

    wymierna operator-(wymierna const& wym1);
    wymierna operator!(wymierna const& wym1);

    std::ostream &operator<<(std::ostream &wyj, const wymierna &w);
}
