//
// Created by kolya on 03.10.2022.
//

#ifndef TECH_PROG_LABS2_MENU_H
#define TECH_PROG_LABS2_MENU_H

#include "keeper.h"

class menu {
private:
    keeper *keeper_;
public:
    menu();

    virtual ~menu();

    void start_program();

private:
    void display_menu() const;

    void is_counter_of_items_equals_zero() const;

    void input_fields_of_objects_and_creating_objects(int answer);

    void
    creating_objects(int answer, const std::string &name_of_instrument, const std::string &name_of_owner, double price,
                     int count_of_instruments);
};


#endif //TECH_PROG_LABS2_MENU_H
