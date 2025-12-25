cmake_minimum_required(VERSION 3.25) project(BinaryRepresentation C)

    enable_testing()

        include_directories($ { CMAKE_SOURCE_DIR })

            add_executable(binary_representation main.c numsys.c tests / test_num.c)

                add_test(NAME binary_representation_tests COMMAND binary_representation-- test)

                    set_tests_properties(
                        binary_representation_tests PROPERTIES PASS_REGULAR_EXPRESSION "All tests passed")
