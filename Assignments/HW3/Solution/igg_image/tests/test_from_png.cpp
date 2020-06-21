#include "../src/igg_image/image.h"
#include "../src/igg_image/io_strategies/png_strategy.h"
#include <gtest/gtest.h>

TEST(TestPngStrategy, Read){
	igg::Image img{igg::PngIoStrategy()};
	img.ReadFromDisk("/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW3/Solution/igg_image/data/Screenshot.png");
	EXPECT_LT(0, img.rows());
	EXPECT_LT(0, img.cols());
}