//
// Created by kolya on 28.09.2022.
//
#ifndef TECH_PROG_LABS2_WIND_INSTRUMENT_H
#define TECH_PROG_LABS2_WIND_INSTRUMENT_H

#include "orchestra.h"


class wind_instrument : public orchestra {
private:
    std::string manufacturers_name_;
    std::string defects_;

    [[nodiscard]] int choice_of_field() const override;

    void display_class_name() const override;

    void write_class_name_to_file(std::fstream &file) const override;

public:
    wind_instrument();

    wind_instrument(std::string name_of_instrument, double price, std::string name_of_owner, int count_of_instruments,
                    std::string manufacturers_name, std::string defects);

    wind_instrument(const wind_instrument &wind_instrument2);

    ~wind_instrument() override;

    wind_instrument &operator=(const wind_instrument &wind_instrument2);

    [[nodiscard]] std::string get_manufacturers_name() const;

    void set_manufacturers_name(std::string manufacturers_name);

    [[nodiscard]] std::string get_defects() const;

    void set_defects(std::string defects);

    void display_data() const override;

    void read_from_file(std::fstream &file) override;

    void write_to_file(std::fstream &file) const override;

    [[nodiscard]] wind_instrument *clone() const override;

    void edit_data() override;
};


#endif //TECH_PROG_LABS2_WIND_INSTRUMENT_H
