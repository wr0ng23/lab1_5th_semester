//
// Created by kolya on 28.09.2022.
//

#include "string_instrument.h"

std::string string_instrument::get_manufacturers_name() const {
    return manufacturers_name_;
}

void string_instrument::set_manufacturers_name(const std::string manufacturers_name) {
    manufacturers_name_ = manufacturers_name;
}

std::string string_instrument::get_description() const {
    return description_;
}

void string_instrument::set_description(const std::string description) {
    description_ = description;
}

string_instrument::string_instrument() {
    manufacturers_name_ = "";
    description_ = "";
    std::cout << "Вызван конструктор без параметров для класса струнных!\n";
}

string_instrument::string_instrument(const std::string name_of_instrument, double price,
                                     const std::string name_of_owner,
                                     int count_of_instruments, const std::string manufacturers_name,
                                     const std::string description) : orchestra(name_of_instrument, price,
                                                                                name_of_owner, count_of_instruments) {
    manufacturers_name_ = manufacturers_name;
    description_ = description;
    std::cout << "Вызван конструктор с параметрами для класса струнных!\n";
}

string_instrument::string_instrument(const string_instrument &string_instrument2) : orchestra(string_instrument2) {
    manufacturers_name_ = string_instrument2.manufacturers_name_;
    description_ = string_instrument2.description_;
    std::cout << "Вызван конструктор копирования для класса струнных!\n";
}

string_instrument::~string_instrument() {
    std::cout << "Вызван деструктор для класса струнных!\n";
}

string_instrument &string_instrument::operator=(const string_instrument &string_instrument2) {
    orchestra::operator=(string_instrument2);
    std::cout << "Вызван оператор присваивания класса струнных!\n";
    manufacturers_name_ = string_instrument2.manufacturers_name_;
    description_ = string_instrument2.description_;
    return *this;
}

void string_instrument::display_data() {
    orchestra::display_data();
    std::cout << "manufacturers_name_: " << manufacturers_name_ << "\ndescription_: " << description_ << '\n';
}

void string_instrument::read_from_file(std::fstream& file) {
    orchestra::read_from_file(file);
    file >> manufacturers_name_ >> description_;
}

void string_instrument::write_to_file(std::fstream& file) {
    orchestra::write_to_file(file);
    file << manufacturers_name_ << '\n' << description_;
}

void string_instrument::write_class_name_to_file(std::fstream &file) {
    file << '\n' << 2 << '\n';
}
