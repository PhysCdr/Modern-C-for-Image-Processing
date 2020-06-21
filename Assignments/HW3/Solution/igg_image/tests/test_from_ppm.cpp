#include "../src/igg_image/image.h"
#include "../src/igg_image/io_strategies/ppm_strategy.h"
#include <gtest/gtest.h>

TEST(TestPpmStrategy, Read){
	igg::Image img{igg::PpmIoStrategy()};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW3/Solution/igg_image/data/pbmlib.ascii.ppm";
	img.ReadFromDisk(filename);
	EXPECT_LT(0, img.rows());
	EXPECT_LT(0, img.cols());
}