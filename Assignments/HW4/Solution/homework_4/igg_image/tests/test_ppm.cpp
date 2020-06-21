#include "../src/igg_image/image.h"
#include "../src/igg_image/io_strategies/ppm_strategy.h"
#include <gtest/gtest.h>
#include <memory>

TEST(TestPpmStrategy, Read_PpmStrategy){
	igg::Image img;
	img.SetIoStrategy(std::make_shared<igg::PpmIoStrategy>());
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/igg_image/data/pbmlib.ascii.ppm";
	EXPECT_EQ(0, img.ReadFromDisk(filename));
}

TEST(TestPpmStrategy, Write_PpmStrategy){
	igg::Image img(10, 10);
	img.SetIoStrategy(std::make_shared<igg::PpmIoStrategy>());
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/igg_image/data/pbmlibTest.ascii.ppm";
	EXPECT_EQ(0, img.WriteToDisk(filename));
}