//
// Created by kolya on 28.09.2022.
//

#include "orchestra.h"

std::string orchestra::get_name_of_instrument() const {
    return name_of_instrument_;
}

void orchestra::set_name_of_instrumnet(std::string name_of_instrument) {
    name_of_instrument_ = name_of_instrument;
}

double orchestra::get_price() const {
    return price_;
}

void orchestra::set_price(const double price) {
    price_ = price;
}

std::string orchestra::get_name_of_owner() const {
    return name_of_owner_;
}

void orchestra::set_name_of_owner(const std::string name_of_owner) {
    name_of_owner_ = name_of_owner;
}

int orchestra::get_count() const {
    return count_of_instruments_;
}

void orchestra::set_count(const int count) {
    count_of_instruments_ = count;
}

orchestra::orchestra(const std::string name_of_instrument, double price, const std::string name_of_owner,
                     int count_of_instruments) {
    std::cout << "Вызван конструктор с параметрами базового класса!\n";
    name_of_instrument_ = name_of_instrument;
    price_ = price;
    name_of_owner_ = name_of_owner;
    count_of_instruments_ = count_of_instruments;
}

orchestra::orchestra() {
    std::cout << "Вызван конструктор без параметров базового класса!\n";
    name_of_instrument_ = "";
    price_ = 0.0;
    name_of_owner_ = "";
    count_of_instruments_ = 0;
}

orchestra::orchestra(const orchestra &o2) {
    std::cout << "Вызван конструктор копирования базового класса!\n";
    name_of_instrument_ = o2.name_of_instrument_;
    price_ = o2.price_;
    name_of_owner_ = o2.name_of_owner_;
    count_of_instruments_ = o2.count_of_instruments_;
}

orchestra::~orchestra() {
    std::cout << "Вызван деструктор базового класса!\n";
}

orchestra &orchestra::operator=(const orchestra &orchestra2) {
    this->name_of_owner_ = orchestra2.name_of_owner_;
    this->name_of_instrument_ = orchestra2.name_of_instrument_;
    this->price_ = orchestra2.price_;
    this->count_of_instruments_ = orchestra2.count_of_instruments_;
    return *this;
}

void orchestra::display_data() {
    std::cout << "name_of_instrument_: " << name_of_instrument_ << "\nname_of_owner_: " << name_of_owner_
              << "\nprice_: " << price_ << "\ncount_of_instruments_: " << count_of_instruments_ << '\n';
}

void orchestra::read_from_file(std::fstream &file) {
    file >> name_of_instrument_ >> name_of_owner_ >> price_ >> count_of_instruments_;
}

void orchestra::write_to_file(std::fstream &file) {
    file << name_of_instrument_ << '\n' << name_of_owner_ << '\n'
         << price_ << '\n' <<  count_of_instruments_ << '\n';
}
