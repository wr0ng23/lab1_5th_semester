//
// Created by kolya on 30.09.2022.
//

#ifndef TECH_PROG_LABS2_BAD_EXTRACTION_H
#define TECH_PROG_LABS2_BAD_EXTRACTION_H
#include <string_view>
#include <string>

class bad_extraction {
private:
    std::string m_error;
public:
    bad_extraction(std::string error);
    std::string_view get_error() const;
};


#endif //TECH_PROG_LABS2_BAD_EXTRACTION_H
