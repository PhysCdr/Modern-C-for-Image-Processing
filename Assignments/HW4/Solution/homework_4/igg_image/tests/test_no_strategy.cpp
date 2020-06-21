#include "../src/igg_image/image.h"
#include <gtest/gtest.h>

TEST(TestNoStrategy, Read_NoStrategy){
	igg::Image img;
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/igg_image/data/pbmlib.ascii.ppm";
	EXPECT_EQ(1, img.ReadFromDisk(filename));
}

TEST(TestNoStrategy, Write_NoStrategy){
	igg::Image img(10, 10);
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/igg_image/data/pbmlibTest.ascii.ppm";
	EXPECT_EQ(1, img.WriteToDisk(filename));
}