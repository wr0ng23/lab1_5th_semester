//
// Created by kolya on 03.10.2022.
//

#include "menu.h"

void menu::start_program() {
    // для сохранения исходного состояния программы при попытки чтения из файла
    keeper* save_keeper = nullptr;

    while (true) {
        try {
            system("cls");
            display_menu();
            int reply = input<int>();

            switch (reply) {
                case 1: {
                    std::cout << "Введите объект какого музыкального инструмента вы хотели бы добавить:\n"
                              << "1) Ударный\n2) Струнный\n3) Духовой\n";
                    int answer = checking_accuracy_of_the_input(1, 3);
                    input_fields_of_objects_and_creating_objects(answer);
                    break;
                }
                case 2:
                    keeper_->delete_item();
                    break;
                case 3: {
                    is_counter_of_items_equals_zero();
                    std::cout << "Созданных объектов в программе: " << keeper_->get_counter_of_items() << "\n"
                              << "Введите номер объекта, который хотите изменить(от 1 до "
                              << keeper_->get_counter_of_items()
                              << ")\n";
                    int answer = checking_accuracy_of_the_input(1, keeper_->get_counter_of_items());
                    keeper_->edit_data(answer - 1);
                    break;
                }
                case 4:
                    keeper_->display_data();
                    break;
                case 5: {
                    is_counter_of_items_equals_zero();
                    std::cout << "Введите информацию о каком объекте хотите увидеть(цифра от 1 до "
                              << keeper_->get_counter_of_items() << ")\n";
                    int answer = checking_accuracy_of_the_input(1, keeper_->get_counter_of_items());
                    keeper_->display_data(answer - 1);
                    break;
                }
                case 6: {
                    is_counter_of_items_equals_zero();
                    std::cout << "Имя файла в формате(имя_файла.txt)\n";
                    std::string name_of_file = input<std::string>();
                    keeper_->write_in_file(name_of_file);
                    break;
                }
                case 7: {
                    std::cout << "Имя файла в формате(имя_файла.txt)\n";
                    std::string name_of_file = input<std::string>();

                    //удаление старого исходного состояния, если такое имеется
                    delete save_keeper;

                    // сохранение исходного состония программы перед чтением из файла
                    save_keeper = keeper_->clone();
                    keeper_->read_from_file(name_of_file);
                    break;
                }
                case 8:
                    std::cout << "Выход из программы..\n";
                    system("pause");
                    exit(1);
                default:
                    std::cout << "Введена неверная цифра! Повторите попытку.\n";
            }
        } catch (my_exception &e) {
            std::cout << e.get_error();
            if (e.is_critical_error()) {
                // в случае неудачной попытки, удаляется текущее состояние программы и загружается сохранение
                delete keeper_;
                keeper_ = save_keeper->clone();
                std::cout << "Программа сброшена до начального состояния!\n";
            }
        }
        system("pause");
    }

}

void menu::creating_objects(int answer, const std::string &name_of_instrument, const std::string &name_of_owner,
                            double price, int count_of_instruments) {

    // Ввод полей дочерних классов и созадние объекта
    if (answer == 1) {
        std::cout << "5) type_\n";
        auto type = input<std::string>();

        // Вызов конструктора с параметрами для класса percussion_instrument и доавбление его в keeper
        keeper_->add_new_item(new percussion_instrument(name_of_instrument, price, name_of_owner,
                                                        count_of_instruments, type));
    } else if (answer == 2) {
        std::cout << "5) manufacturers_name_\n";
        auto manufacturers_name = input<std::string>();

        std::cout << "6) description_\n";
        auto description = input<std::string>();

        // Вызов конструктора с параметрами для класса string_instrument и доавбление его в keeper
        keeper_->add_new_item(new string_instrument(name_of_instrument, price, name_of_owner,
                                                    count_of_instruments, manufacturers_name, description));
    } else if (answer == 3) {
        std::cout << "5) manufacturers_name_\n";
        auto manufacturers_name = input<std::string>();

        std::cout << "6) defects_\n";
        auto defects = input<std::string>();

        // Вызов конструктора с параметрами для класса wind_instrument и доавбление его в keeper
        keeper_->add_new_item(new wind_instrument(name_of_instrument, price, name_of_owner, count_of_instruments,
                                                  manufacturers_name, defects));
    }
}

void menu::input_fields_of_objects_and_creating_objects(int answer) {
    system("cls");
    // Инициализация полей базового класса orchestra
    std::cout << "1) name_of_instrument_\n";
    auto name_of_instrument = input<std::string>();

    std::cout << "2) name_of_owner_\n";
    auto name_of_owner = input<std::string>();

    std::cout << "3) price_\n";
    auto price = input<double>();

    std::cout << "4) count_of_instruments_\n";
    auto count_of_instruments = input<int>();

    // Передача управления функции по инициализации полей базового класса и созданию объектов
    creating_objects(answer, name_of_instrument, name_of_owner, price, count_of_instruments);
}

void menu::display_menu() const {
    std::cout << "1) Добавить новый музыкальный инструмент в оркестр\n"
              << "2) Удалить последний музыкальный инструмент из оркестра\n"
              << "3) Изменить поля конкретного музыкального инструмента\n"
              << "4) Вывести информацию о всех музыкальных инструментах на экран\n"
              << "5) Вывести информацию о конкрентом музыкальном инструменте на экран\n"
              << "6) Сохранить текущие музыкальные инструменты в файл\n"
              << "7) Загрузить информацию о музыкальных инстурментах из файла\n"
              << "8) Выход из программы\n";
}

void menu::is_counter_of_items_equals_zero() const {
    if (keeper_->get_counter_of_items() == 0) {
        throw my_exception("В программе пока отсутствуют музыкальные инструменты!\n", false);
    }
}

menu::~menu() {
    delete keeper_;
}

menu::menu() {
    keeper_ = new keeper;
}
