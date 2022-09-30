//
// Created by kolya on 28.09.2022.
//
#ifndef TECH_PROG_LABS2_PERCUSSION_INSTRUMENT_H
#define TECH_PROG_LABS2_PERCUSSION_INSTRUMENT_H

#include "orchestra.h"


class percussion_instrument : public orchestra {
private:
    std::string type_;
public:
    ~percussion_instrument() override;

    percussion_instrument();

    percussion_instrument(std::string name_of_instrument, double price, std::string name_of_owner,
                          int count_of_instruments, std::string type);

    percussion_instrument(const percussion_instrument &percussion_instrument2);

    percussion_instrument& operator=(const percussion_instrument &percussion_instrument2);

    std::string get_type() const;

    void set_type(std::string type);

    void display_data();

    void read_from_file(std::fstream& file) override;

    void write_to_file(std::fstream& file) override;

    void write_class_name_to_file(std::fstream &file) override;
};


#endif //TECH_PROG_LABS2_PERCUSSION_INSTRUMENT_H
