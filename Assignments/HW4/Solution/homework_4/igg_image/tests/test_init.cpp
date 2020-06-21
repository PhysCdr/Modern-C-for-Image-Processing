#include "../src/igg_image/image.h"
#include <gtest/gtest.h>

TEST(TestImageInit, Init_NoStrategy){
	EXPECT_EQ(0, igg::Image().rows());
	EXPECT_EQ(0, igg::Image().cols());
}

TEST(TestImageInit, Init_rows_cols_NoStrategy){
	EXPECT_EQ(10, igg::Image({10, 10}).rows());
	EXPECT_EQ(10, igg::Image({10, 10}).cols());
}