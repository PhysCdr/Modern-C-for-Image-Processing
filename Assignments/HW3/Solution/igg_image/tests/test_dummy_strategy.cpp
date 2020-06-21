#include "../src/igg_image/image.h"
#include <gtest/gtest.h>

TEST(TestDummyStrategy, Read){
	igg::Image img{10, 10, igg::DummyIoStrategy()};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW3/Solution/igg_image/data/Screenshot.png";
	img.ReadFromDisk(filename);
	EXPECT_EQ(0, img.rows());
	EXPECT_EQ(0, img.cols());
}

TEST(TestDummyStrategy, Write){
	igg::Image img{igg::DummyIoStrategy()};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW3/Solution/igg_image/data/Screenshot.png";
	EXPECT_TRUE(img.WriteToDisk(filename));
}