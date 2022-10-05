cmake_minimum_required(VERSION 3.23)
project(tech_prog_labs2)

set(CMAKE_CXX_STANDARD 20)

add_executable(tech_prog_labs2 main.cpp music_instruments/orchestra.cpp music_instruments/orchestra.h music_instruments/percussion_instrument.cpp music_instruments/percussion_instrument.h music_instruments/string_instrument.cpp music_instruments/string_instrument.h music_instruments/wind_instrument.cpp music_instruments/wind_instrument.h menu_and_co/keeper.cpp menu_and_co/keeper.h menu_and_co/safe_input.h menu_and_co/menu.cpp menu_and_co/menu.h menu_and_co/checking_accuracy_of_the_input.cpp menu_and_co/checking_accuracy_of_the_input.h menu_and_co/my_exception.cpp menu_and_co/my_exception.h menu_and_co/safe_input_from_file.h)
