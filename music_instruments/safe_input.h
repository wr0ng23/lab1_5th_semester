//
// Created by kolya on 28.09.2022.
//

#ifndef TECH_PROG_LABS2_SAFE_INPUT_H
#define TECH_PROG_LABS2_SAFE_INPUT_H
#include <iostream>


template <typename T>
T input()
{
    T answer;
    while (true)
    {
        std::cin.unsetf(std::ios::skipws);
        std::cout << "Ввод: ";
        std::cin >> answer;
        if (std::cin.good())
        {
            std::cin.ignore(100, '\n');
            return answer;
        }
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Повторите попытку ввода, произошла ошибка!" << std::endl;
    }
}


#endif //TECH_PROG_LABS2_SAFE_INPUT_H
