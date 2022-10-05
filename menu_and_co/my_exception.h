//
// Created by kolya on 03.10.2022.
//

#ifndef TECH_PROG_LABS2_MY_EXCEPTION_H
#define TECH_PROG_LABS2_MY_EXCEPTION_H

#include <exception>
#include <iostream>

class my_exception : public std::exception {
private:
    std::string message_of_error_;
    bool critical_error_;
public:
    my_exception(std::string error, bool critical_error) : message_of_error_(error), critical_error_(critical_error) {}

    /*
     * true -> restart program
     * false -> continue work
     */
    [[nodiscard]] bool is_critical_error() const;

    [[nodiscard]] std::string get_error() const;
};


#endif //TECH_PROG_LABS2_MY_EXCEPTION_H
