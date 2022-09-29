//
// Created by kolya on 28.09.2022.
//

#include "Keeper.h"

void Keeper::delete_item() {
    if (counter_of_items == 0) {
        throw std::underflow_error("Нельзя удалить элемент из массива, он пуст!\n");
    }
    delete array_of_music_instruments[counter_of_items];
    counter_of_items--;
}

void Keeper::add_new_item(orchestra *new_item) {
    if (capacity == counter_of_items) {
        resize_of_array();
    }
    array_of_music_instruments[counter_of_items] = new_item;
    counter_of_items++;
    std::cout << "Элемент успешно добавлен в массив!\n";
}

Keeper::Keeper() {
    capacity = 10;
    array_of_music_instruments = new orchestra *[capacity];
}

Keeper::Keeper(int initial_capacity) {
    capacity = initial_capacity;
    array_of_music_instruments = new orchestra * [capacity];
}

void Keeper::resize_of_array() {
    int new_size = capacity + 10;
    auto bigger_array = new orchestra *[new_size];

    for (int i = 0; i < capacity; i++) {
        bigger_array[i] = array_of_music_instruments[i];
    }

    for (int i = 0; i < capacity; i++) {
        delete array_of_music_instruments[i];
    }
    delete[] array_of_music_instruments;
    capacity = new_size;
    array_of_music_instruments = bigger_array;
}

void Keeper::read_from_file() {
    file.open("output.txt", std::ios::in);
    if (!file.is_open()) {
        std::cout << "Incorrect file opening\n";
        exit(1);
    }

    for (int i = 0; i < counter_of_items; i++) {
        array_of_music_instruments[i]->read_from_file(file);
    }
}

void Keeper::write_in_file() {
    file.open("input.txt", std::ios::out);
    if (!file.is_open()) {
        std::cout << "Incorrect file opening\n";
        exit(1);
    }

    for (int i = 0; i < counter_of_items; i++) {
        array_of_music_instruments[i]->write_to_file(file);
    }
}
