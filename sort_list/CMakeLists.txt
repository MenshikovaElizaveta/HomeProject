cmake_minimum_required(VERSION 3.25) project(SortList C)

    enable_testing()

        add_executable(sort_list main.c list.c tests / test_list.c)

            add_test(NAME sorted_list_tests COMMAND sort_list-- test)
