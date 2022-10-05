//
// Created by kolya on 28.09.2022.
//

#ifndef TECH_PROG_LABS2_KEEPER_H
#define TECH_PROG_LABS2_KEEPER_H

#include "../music_instruments/percussion_instrument.h"
#include "../music_instruments/string_instrument.h"
#include "../music_instruments/wind_instrument.h"
#include "my_exception.h"

class keeper {
private:
    orchestra **array_of_music_instruments_;
    int capacity_;
    int counter_of_items_ = 0;

    void resize_of_array();

public:
    keeper();

    keeper(int initial_capacity);

    keeper(const keeper& keeper2);

    ~keeper();

    void add_new_item(orchestra *new_item);

    void delete_item();

    void write_in_file(const std::string &name_of_file);

    void read_from_file(const std::string &name_of_file);

    void display_data();

    void display_data(int number);

    void edit_data(int number);

    int get_counter_of_items() const;

    [[nodiscard]] keeper *clone() const;
};

bool ends_with(std::string const &value, std::string const &ending);

#endif //TECH_PROG_LABS2_KEEPER_H
