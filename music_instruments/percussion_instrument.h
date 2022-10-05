//
// Created by kolya on 28.09.2022.
//
#ifndef TECH_PROG_LABS2_PERCUSSION_INSTRUMENT_H
#define TECH_PROG_LABS2_PERCUSSION_INSTRUMENT_H

#include "orchestra.h"


class percussion_instrument : public orchestra {
private:
    std::string type_;

    [[nodiscard]] int choice_of_field() const override;

    void display_class_name() const override;

    void write_class_name_to_file(std::fstream &file) const override;

public:
    percussion_instrument();

    percussion_instrument(std::string name_of_instrument, double price, std::string name_of_owner,
                          int count_of_instruments, std::string type);

    percussion_instrument &operator=(const percussion_instrument &percussion_instrument2);

    percussion_instrument(const percussion_instrument &percussion_instrument2);

    ~percussion_instrument() override;

    [[nodiscard]] std::string get_type() const;

    void set_type(std::string type);

    void display_data() const override;

    [[nodiscard]] percussion_instrument *clone() const override;

    void edit_data() override;

    void read_from_file(std::fstream &file) override;

    void write_to_file(std::fstream &file) const override;
};


#endif //TECH_PROG_LABS2_PERCUSSION_INSTRUMENT_H
