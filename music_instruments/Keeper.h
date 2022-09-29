//
// Created by kolya on 28.09.2022.
//

#ifndef TECH_PROG_LABS2_KEEPER_H
#define TECH_PROG_LABS2_KEEPER_H
#include "safe_input.h"
#include "percussion_instrument.h"
#include "string_instrument.h"
#include "wind_instrument.h"

class Keeper {
private:
    int capacity_of_percussion_instruments;
    int capacity_of_string_instruments;
    int capacity_of_wind_instruments;
    percussion_instrument** mass_of_percussion_instruments;
    string_instrument** mass_of_string_instrument;
    wind_instrument** mass_of_wind_instruments;
public:
    void add_new_item();
    void set_capacity_of_every_type();
};


#endif //TECH_PROG_LABS2_KEEPER_H
