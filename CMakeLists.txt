cmake_minimum_required(VERSION 3.13)
project(MY_PRINTF C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MY_PRINTF
        annonce_flags.c
        choose_type.c
        fills.c
        ft_printf.c
        ft_printf.h
        ft_rapist.c
        ft_uns_digits.c
        ft_write_pt1.c
        ft_write_pt2.c
        ft_write_pt3.c
        lib_fn1.c
        lib_fn2.c
        lib_fn3.c
        min.c
        perc_and_char.c
        pt_digit.c
        pt_pointer.c
        pt_string.c
        write_main_press.c
        write_press.c)
