//
// Created by kolya on 28.09.2022.
//

#include "Keeper.h"

void Keeper::add_new_item() {
    int answer;
    while (true) {
        system("cls");
        std::cout << "Введите тип каких инструментов хотите добавить в программу:\n"
                  << "1 - Ударные\n2 - Струнные\n3 - Звуковые\n";
        answer = input<int>();
        if (answer > 3 || answer < 1) {
            std::cout << "Ошибка в введенных данных!\n";
        } else break;
    }

    static int cnt = 0;
    switch (answer) {
        case 1: {
            std::cout << "Вы выбрали добавление ударных инструментов в оркестр.\n";
            mass_of_percussion_instruments[cnt++] = new percussion_instrument;
            break;
        }
        case 2: {
            std::cout << "Вы выбрали добавление струнных инструментов в оркестр.\n";
            mass_of_string_instrument[cnt++] = new string_instrument;
            break;
        }case 3: {
            std::cout << "Вы выбрали добавление духовых инструментов в оркестр.\n";
            mass_of_wind_instruments[cnt++] = new wind_instrument;
            break;
        }
    }
}

void Keeper::set_capacity_of_every_type() {
    while (true) {
        system("pause");
        system("cls");
        std::cout << "Количество ударных\n";
        capacity_of_percussion_instruments = input<int>();
        if (capacity_of_percussion_instruments > 0) {
            mass_of_percussion_instruments = new percussion_instrument *[capacity_of_percussion_instruments];
            break;
        }
        else {
            std::cout << "Повторите попытку ввода!\n";
        }
    }

    while (true) {
        system("pause");
        system("cls");
        std::cout << "Количество струнных\n";
        capacity_of_string_instruments = input<int>();
        if (capacity_of_string_instruments > 0) {
            mass_of_string_instrument = new string_instrument *[capacity_of_string_instruments];
            break;
        }
        else {
            std::cout << "Повторите попытку ввода!\n";
        }
    }

    while (true) {
        system("pause");
        system("cls");
        std::cout << "Количество духовых\n";
        capacity_of_wind_instruments = input<int>();
        if (capacity_of_wind_instruments > 0) {
            mass_of_wind_instruments = new wind_instrument *[capacity_of_wind_instruments];
            break;
        }
        else {
            std::cout << "Повторите попытку ввода!\n";
        }
    }
    system("pause");
}
