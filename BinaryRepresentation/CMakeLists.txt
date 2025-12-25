cmake_minimum_required(VERSION 3.25) project(BinaryRepresentation C)

    enable_testing()

        add_executable(binary_representation main.c numsys.c tests / test_num.c)

            add_test(NAME binary_representation_tests COMMAND binary_representation-- test)
