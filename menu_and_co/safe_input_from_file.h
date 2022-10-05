//
// Created by kolya on 05.10.2022.
//

#ifndef TECH_PROG_LABS2_SAFE_INPUT_FROM_FILE_H
#define TECH_PROG_LABS2_SAFE_INPUT_FROM_FILE_H

#include <fstream>
#include "my_exception.h"

inline void is_error(std::fstream &file);

template<typename T>
T safe_input_from_file(std::fstream &file) {
    T answer;
    file >> answer;
    is_error(file);
    return answer;
}

template<>
inline std::string safe_input_from_file<std::string>(std::fstream &file) {
    std::string answer;
    std::getline(file, answer);
    is_error(file);
    return answer;
}

inline void is_error(std::fstream &file) {
    if (!file.good()) {
        file.close();
        throw my_exception("Часть данных из файла плохо обрабатывается!\n", true);
    }
}

#endif //TECH_PROG_LABS2_SAFE_INPUT_FROM_FILE_H
