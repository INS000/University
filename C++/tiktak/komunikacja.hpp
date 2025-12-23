#pragma once
#include<utility>
#include "stan_gry.hpp"

namespace user{
    bool chose_side();
    std::pair<int, char> chose_place(stan_gry::stan_gry gra);
}
