#include "../src/igg_image/image.h"
#include <gtest/gtest.h>
#include "../src/igg_image/io_strategies/png_strategy.h"
#include "../src/igg_image/io_strategies/ppm_strategy.h"

TEST(TestImageInit, Init_DummyStrategy){
	EXPECT_EQ(0, igg::Image({igg::DummyIoStrategy()}).rows());
	EXPECT_EQ(0, igg::Image({igg::DummyIoStrategy()}).cols());
}

TEST(TestImageInit, Init_PngStrategy){
	EXPECT_EQ(0, igg::Image({igg::PngIoStrategy()}).rows());
	EXPECT_EQ(0, igg::Image({igg::PngIoStrategy()}).cols());
}

	TEST(TestImageInit, Init_PpmStrategy){
	EXPECT_EQ(0, igg::Image{igg::PpmIoStrategy()}.rows());
	EXPECT_EQ(0, igg::Image{igg::PpmIoStrategy()}.cols());
}

TEST(TestImageInit, Init_rows_cols_DummyStrategy){
	EXPECT_EQ(10, igg::Image({10, 10, igg::DummyIoStrategy()}).rows());
	EXPECT_EQ(10, igg::Image({10, 10, igg::DummyIoStrategy()}).cols());
}

TEST(TestImageInit, Init_rows_cols_PngStrategy){
	EXPECT_EQ(10, igg::Image({10, 10, igg::PngIoStrategy()}).rows());
	EXPECT_EQ(10, igg::Image({10, 10, igg::PngIoStrategy()}).cols());
}

	TEST(TestImageInit, Init_rows_cols_PpmStrategy){
	EXPECT_EQ(10, igg::Image({10, 10, igg::PpmIoStrategy()}).rows());
	EXPECT_EQ(10, igg::Image({10, 10, igg::PpmIoStrategy()}).cols());
}