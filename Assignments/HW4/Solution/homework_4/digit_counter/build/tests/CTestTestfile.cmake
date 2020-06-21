# CMake generated Testfile for 
# Source directory: /home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/digit_counter/tests
# Build directory: /home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/digit_counter/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(digit_counter_test "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/digit_counter/bin/digit_counter_test")
set_tests_properties(digit_counter_test PROPERTIES  _BACKTRACE_TRIPLES "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/digit_counter/tests/CMakeLists.txt;14;add_test;/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/digit_counter/tests/CMakeLists.txt;0;")
subdirs("../gtest")
