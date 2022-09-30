//
// Created by kolya on 28.09.2022.
//

#include "percussion_instrument.h"

percussion_instrument::percussion_instrument() {
    type_ = "";
    std::cout << "Вызван конструктор без параметров для класса ударных!\n";
}

percussion_instrument::percussion_instrument(const std::string name_of_instrument, double price,
                                             const std::string name_of_owner, int count_of_instruments,
                                             const std::string type) : orchestra(name_of_instrument, price,
                                                                                 name_of_owner, count_of_instruments) {
    type_ = type;
    std::cout << "Вызван конструктор c параметрами для класса ударных!\n";
}

percussion_instrument::percussion_instrument(const percussion_instrument &percussion_instrument2) :
        orchestra(percussion_instrument2) {
    type_ = percussion_instrument2.type_;
    std::cout << "Вызван конструктор копирования для класса ударных!\n";
}

std::string percussion_instrument::get_type() const {
    return type_;
}

void percussion_instrument::set_type(const std::string type) {
    type_ = type;
}

percussion_instrument::~percussion_instrument() {
    std::cout << "Вызван деструктор для класса ударных!\n";
}

percussion_instrument &percussion_instrument::operator=(const percussion_instrument &percussion_instrument2) {
    orchestra::operator=(percussion_instrument2);
    std::cout << "Вызван оператор присваивания для класса ударных!\n";
    type_ = percussion_instrument2.type_;
    return *this;
}

void percussion_instrument::display_data() {
    orchestra::display_data();
    std::cout << "type_: " << type_ << '\n';
}

void percussion_instrument::read_from_file(std::fstream& file) {
    orchestra::read_from_file(file);
    file >> type_;
}

void percussion_instrument::write_to_file(std::fstream& file) {
    orchestra::write_to_file(file);
    file << type_;
}

void percussion_instrument::write_class_name_to_file(std::fstream &file) {
    file << '\n' << 1 << '\n';
}
