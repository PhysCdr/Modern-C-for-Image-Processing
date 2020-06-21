add_subdirectory(/usr/src/gtest
                 ${PROJECT_BINARY_DIR}/gtest)
include(CTest) # Include testing cmake package.
set(TEST_BINARY ${PROJECT_NAME}_test)
add_executable(
 ${TEST_BINARY}
 test_warp.cpp
 test_sig_figs.cpp
)
target_link_libraries(${TEST_BINARY}
  digit_counting
  gtest gtest_main
)
add_test(
  NAME ${TEST_BINARY}
  COMMAND ${EXECUTABLE_OUTPUT_PATH}/${TEST_BINARY})