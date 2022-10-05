//
// Created by kolya on 28.09.2022.
//
#ifndef TECH_PROG_LABS2_ORCHESTRA_H
#define TECH_PROG_LABS2_ORCHESTRA_H

#include <fstream>
#include "../menu_and_co/checking_accuracy_of_the_input.h"
#include "../menu_and_co/safe_input_from_file.h"

class orchestra {
private:
    std::string name_of_instrument_;
    std::string name_of_owner_;
    double price_;
    int count_of_instruments_;

    //Writting class name on the first line in file_
    //(1 - percussion_instrument, 2 - string_instrumnet, 3 - wind_instrument)
    virtual void write_class_name_to_file(std::fstream &file) const = 0;

    virtual void display_class_name() const = 0;

protected:
    orchestra();

    orchestra(const std::string &name_of_instrument, double price, const std::string &name_of_owner,
              int count_of_instruments);

    int setting_values_for_fields();

    [[nodiscard]] virtual int choice_of_field() const = 0;

public:
    orchestra &operator=(const orchestra &orchestra2);

    orchestra(const orchestra &o2);

    virtual ~orchestra() = 0;

    virtual void edit_data() = 0;

    virtual void display_data() const;

    [[nodiscard]] virtual orchestra *clone() const = 0;

    [[nodiscard]] std::string get_name_of_instrument() const;

    void set_name_of_instrumnet(const std::string &name_of_instrument);

    [[nodiscard]] double get_price() const;

    void set_price(double price);

    [[nodiscard]] std::string get_name_of_owner() const;

    void set_name_of_owner(const std::string &name_of_owner);

    int get_count() const;

    void set_count(int count);

    virtual void read_from_file(std::fstream &file);

    virtual void write_to_file(std::fstream &file) const;
};


#endif //TECH_PROG_LABS2_ORCHESTRA_H
