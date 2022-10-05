//
// Created by kolya on 03.10.2022.
//

#include "my_exception.h"


std::string my_exception::get_error() const {
    return message_of_error_;
}

bool my_exception::is_critical_error() const {
    return critical_error_;
}

