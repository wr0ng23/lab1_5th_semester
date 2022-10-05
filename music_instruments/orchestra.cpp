//
// Created by kolya on 28.09.2022.
//

#include "orchestra.h"

std::string orchestra::get_name_of_instrument() const {
    return name_of_instrument_;
}

void orchestra::set_name_of_instrumnet(const std::string &name_of_instrument) {
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

void orchestra::set_name_of_owner(const std::string &name_of_owner) {
    name_of_owner_ = name_of_owner;
}

int orchestra::get_count() const {
    return count_of_instruments_;
}

void orchestra::set_count(const int count) {
    count_of_instruments_ = count;
}

orchestra::orchestra(const std::string &name_of_instrument, double price, const std::string &name_of_owner,
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
    name_of_owner_ = orchestra2.name_of_owner_;
    name_of_instrument_ = orchestra2.name_of_instrument_;
    price_ = orchestra2.price_;
    count_of_instruments_ = orchestra2.count_of_instruments_;
    return *this;
}

void orchestra::display_data() const {
    std::cout << "\n";
    display_class_name();
    std::cout << "1) name_of_instrument_: " << name_of_instrument_ << "\n2) name_of_owner_: " << name_of_owner_
              << "\n3) price_: " << price_ << "\n4) count_of_instruments_: " << count_of_instruments_ << '\n';
}

void orchestra::read_from_file(std::fstream &file) {
    /*std::getline(file, name_of_instrument_);
    std::getline(file, name_of_owner_);*/
    name_of_instrument_ = safe_input_from_file<std::string>(file);
    name_of_owner_ = safe_input_from_file<std::string>(file);

    //file >> price_ >> count_of_instruments_;
    price_ = safe_input_from_file<double>(file);
    count_of_instruments_ = safe_input_from_file<int>(file);

    file.ignore(); // удаление разделителя из буфера после считывания последнего поля
}

void orchestra::write_to_file(std::fstream &file) const {
    write_class_name_to_file(file);
    file << name_of_instrument_ << '\n' << name_of_owner_ << '\n'
         << price_ << '\n' << count_of_instruments_ << '\n';
}

int orchestra::setting_values_for_fields() {
    display_data();
    std::cout << "Какое поле объекта хотите изменить\n";
    int answer = choice_of_field();

    if (answer == 1) {
        std::cout << "Новое значение поля name_of_instrument_\n";
        name_of_instrument_ = input<std::string>();
    } else if (answer == 2) {
        std::cout << "Новое значение поля name_of_owner_\n";
        name_of_owner_ = input<std::string>();
    } else if (answer == 3) {
        std::cout << "Новое значение поля price_\n";
        price_ = input<double>();
    } else if (answer == 4) {
        std::cout << "Новое значение поля count_of_instruments_\n";
        count_of_instruments_ = input<int>();
    }
    return answer;
}