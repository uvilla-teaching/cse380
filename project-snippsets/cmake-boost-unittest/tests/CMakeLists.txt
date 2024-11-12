add_executable(my_tests my_tests.cpp)
target_link_libraries(my_tests ${Boost_LIBRARIES})

enable_testing()
add_test(NAME my_tests COMMAND my_tests)
