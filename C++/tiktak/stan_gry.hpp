#pragma once
namespace stan_gry
{
    class stan_gry
    {
    private:
        char plansza[3][3];
        int pozostale;
    public:
        stan_gry();
        // ~stan_gry();
        bool finished();
        char kto_wygral();
        void wstaw_znak(char znak, int wie, char kol);
        char get_char(int wie, char kol);
    };
}
