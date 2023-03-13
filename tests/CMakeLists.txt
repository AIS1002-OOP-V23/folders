

add_executable(test_folder test_folder.cpp)
target_link_libraries(test_folder PUBLIC folder Catch2::Catch2)
add_test(test_folder NAME test_folder COMMAND test_folder)
