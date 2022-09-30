//
// Created by kolya on 28.09.2022.
//

#include "wind_instrument.h"

std::string wind_instrument::get_manufacturers_name() const {
    return manufacturers_name_;
}

void wind_instrument::set_manufacturers_name(const std::string manufacturers_name) {
    manufacturers_name_ = manufacturers_name;
}

std::string wind_instrument::get_defects() const {
    return defects_;
}

void wind_instrument::set_defects(const std::string defects) {
    defects_ = defects;
}

wind_instrument::wind_instrument() {
    std::cout << "Вызван конструктор без параметров для класса духовых!\n";
    manufacturers_name_ = "";
    defects_ = "";
}

wind_instrument::wind_instrument(const std::string name_of_instrument, double price, const std::string name_of_owner,
                                 int count_of_instruments, std::string manufacturers_name, const std::string defects)
        : orchestra(name_of_instrument, price, name_of_owner, count_of_instruments) {
    manufacturers_name_ = manufacturers_name;
    defects_ = defects;
    std::cout << "Вызван конструктор с параметрами для класса духовых!\n";
}

wind_instrument::wind_instrument(const wind_instrument &wind_instrument2) : orchestra(wind_instrument2) {
    manufacturers_name_ = wind_instrument2.manufacturers_name_;
    defects_ = wind_instrument2.defects_;
}

wind_instrument &wind_instrument::operator=(const wind_instrument &wind_instrument2) {
    orchestra::operator=(wind_instrument2);
    std::cout << "Вызван оператор присваивания для класса духовых!\n";
    this->defects_ = wind_instrument2.defects_;
    this->manufacturers_name_ = wind_instrument2.manufacturers_name_;
    return *this;
}

wind_instrument::~wind_instrument() {
    std::cout << "Вызван деструктор для класса духовых!\n";
}

void wind_instrument::display_data() {
    orchestra::display_data();
    std::cout << "manufacturers_name_: " << manufacturers_name_ << "\ndefects_: " << defects_ << '\n';
}

void wind_instrument::read_from_file(std::fstream& file) {
    orchestra::read_from_file(file);
    file >> manufacturers_name_ >> defects_;
}

void wind_instrument::write_to_file(std::fstream& file) {
    orchestra::write_to_file(file);
    file << manufacturers_name_ << '\n' << defects_;
}

void wind_instrument::write_class_name_to_file(std::fstream &file) {
    file << '\n' << 3 << '\n';
}
