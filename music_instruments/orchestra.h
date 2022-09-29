//
// Created by kolya on 28.09.2022.
//
#ifndef TECH_PROG_LABS2_ORCHESTRA_H
#define TECH_PROG_LABS2_ORCHESTRA_H
#include <iostream>
#include <fstream>

class orchestra {
protected:
    std::string name_of_instrument_;
    std::string name_of_owner_;
    double price_;
    int count_of_instruments_;
public:
    orchestra();

    virtual ~orchestra() = 0;

    orchestra(std::string name_of_instrument, double price, std::string name_of_owner, int count_of_instruments);

    orchestra(const orchestra& o2);

    std::string get_name_of_instrument() const;

    void set_name_of_instrumnet(std::string name_of_instrument);

    double get_price() const;

    void set_price(double price);

    std::string get_name_of_owner() const;

    void set_name_of_owner(std::string name_of_owner);

    int get_count() const;

    void set_count(int count);

    orchestra& operator=(const orchestra &orchestra2);

    virtual void display_data();

    virtual void read_from_file(std::fstream& file);

    virtual void write_to_file(std::fstream& file);
};


#endif //TECH_PROG_LABS2_ORCHESTRA_H
