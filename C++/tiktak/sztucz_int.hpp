#pragma once
#include "stan_gry.hpp"
#include <vector>
#include <utility>

namespace sztucz_int {
    class ai {
        std::vector<std::pair<int, char>> wolne_pola;

        public:
        ai();
        void gen_choices(stan_gry::stan_gry gra);
        std::pair<int, char> chose_choice(stan_gry::stan_gry gra);
    };
}
