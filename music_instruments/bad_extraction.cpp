//
// Created by kolya on 30.09.2022.
//

#include "bad_extraction.h"

std::string_view bad_extraction::get_error() const {
    return m_error;
}

bad_extraction::bad_extraction(std::string error) {
    m_error = error;
}
