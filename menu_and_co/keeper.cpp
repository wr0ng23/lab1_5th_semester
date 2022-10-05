//
// Created by kolya on 28.09.2022.
//

#include "keeper.h"

void keeper::delete_item() {
    if (counter_of_items_ == 0) {
        throw my_exception("Пока что в программе нет элементов для удаления!\n", false);
    }
    delete array_of_music_instruments_[counter_of_items_ - 1];
    counter_of_items_--;
    std::cout << "Элемент успешно удален!\n";
}

void keeper::add_new_item(orchestra *new_item) {
    if (capacity_ == counter_of_items_) {
        resize_of_array();
    }

    array_of_music_instruments_[counter_of_items_] = new_item;
    counter_of_items_++;
    std::cout << "Элемент успешно добавлен в массив!\n";
}

keeper::keeper() {
    capacity_ = 10;
    array_of_music_instruments_ = new orchestra *[capacity_];
}

keeper::keeper(int initial_capacity) {
    capacity_ = initial_capacity;
    array_of_music_instruments_ = new orchestra *[capacity_];
}

void keeper::resize_of_array() {
    int new_size = capacity_ + 10;
    auto bigger_array = new orchestra *[new_size];

    for (int i = 0; i < counter_of_items_; i++) {
        bigger_array[i] = array_of_music_instruments_[i]->clone();
    }

    for (int i = 0; i < counter_of_items_; i++) {
        delete array_of_music_instruments_[i];
    }
    delete[] array_of_music_instruments_;
    capacity_ = new_size;
    array_of_music_instruments_ = bigger_array;
    std::cout << "Размера массива увеличен до " << capacity_ << "\n";
}

void keeper::read_from_file(const std::string &name_of_file) {
    std::fstream file;

    if (!ends_with(name_of_file, ".txt")) {
        throw my_exception("Файл имеет неподдерживаемый тип, вводите имя файла с расширением .txt!\n",
                           false);
    }

    file.open(name_of_file, std::ios::in);
    if (!file.is_open()) {
        file.close();
        throw my_exception("Ошибочное открытие файла!\n", true);
    }

    std::string class_name;
    while (std::getline(file, class_name)) {

        if (counter_of_items_ == capacity_) {
            resize_of_array();
        }

        if (class_name == "1") {
            array_of_music_instruments_[counter_of_items_] = new percussion_instrument;
        } else if (class_name == "2") {
            array_of_music_instruments_[counter_of_items_] = new string_instrument;
        } else if (class_name == "3") {
            array_of_music_instruments_[counter_of_items_] = new wind_instrument;
        } else {
            file.close();
            throw my_exception("Считывается странный объект из файла, выход!\n", true);
        }

        array_of_music_instruments_[counter_of_items_++]->read_from_file(file);
    }

    std::cout << "Данные успешно считаны из файла!\n\n";
    file.close();
}

void keeper::write_in_file(const std::string &name_of_file) {
    if (!ends_with(name_of_file, ".txt")) {
        throw my_exception("Файл имеет неподдерживаемый тип, вводите имя файла с расширением .txt!\n",
                           false);
    }

    std::fstream file;
    file.open(name_of_file, std::ios::out);
    if (!file.is_open()) {
        file.close();
        throw my_exception("Ошибочное открытие файла!\n", true);
    }

    for (int i = 0; i < counter_of_items_; i++) {
        array_of_music_instruments_[i]->write_to_file(file);
    }
    std::cout << "Данные успешно были записаны в файл!\n\n";
    file.close();
}

keeper::~keeper() {
    std::cout << "Вызван деструктор для класса keeper!\n";
    for (int i = 0; i < counter_of_items_; i++) {
        delete array_of_music_instruments_[i];
    }
    delete[] array_of_music_instruments_;
}

void keeper::display_data() {
    if (counter_of_items_ == 0) {
        throw my_exception("Пока что элементов в программе нет!\n", false);
    }

    std::cout << "\n\nСозданных объектов в программе: " << counter_of_items_ << "\n";
    for (int i = 0; i < counter_of_items_; i++) {
        array_of_music_instruments_[i]->display_data();
    }
}

void keeper::edit_data(int number) {
    array_of_music_instruments_[number]->edit_data();
    std::cout << "Данные об объекте изменены упешно!\n";
}

void keeper::display_data(int number) {
    array_of_music_instruments_[number]->display_data();
}

int keeper::get_counter_of_items() const {
    return counter_of_items_;
}

keeper::keeper(const keeper &keeper2) {
    std::cout << "Вызван конструктор копирования для класса keeper!\n";
    capacity_ = keeper2.capacity_;
    counter_of_items_ = keeper2.counter_of_items_;
    array_of_music_instruments_ = new orchestra *[capacity_];
    for (int i = 0; i < counter_of_items_; i++) {
        array_of_music_instruments_[i] = (keeper2.array_of_music_instruments_[i])->clone();
    }
}

keeper *keeper::clone() const {
    return new keeper(*this);
}

bool ends_with(std::string const &value, std::string const &ending) {
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}
