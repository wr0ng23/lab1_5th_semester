//
// Created by kolya on 28.09.2022.
//

#ifndef TECH_PROG_LABS2_KEEPER_H
#define TECH_PROG_LABS2_KEEPER_H

#include <fstream>
#include "safe_input.h"
#include "percussion_instrument.h"
#include "string_instrument.h"
#include "wind_instrument.h"

//#include "bad_extraction.h"

class Keeper {
private:
    orchestra **array_of_music_instruments;
    std::fstream file;

    void resize_of_array();

    int capacity;
    int counter_of_items = 0;
public:
    Keeper();

    Keeper(int initial_capacity);

    ~Keeper();

    void add_new_item(orchestra *new_item);

    void delete_item();

    void write_in_file();

    void read_from_file();
};


#endif //TECH_PROG_LABS2_KEEPER_H
