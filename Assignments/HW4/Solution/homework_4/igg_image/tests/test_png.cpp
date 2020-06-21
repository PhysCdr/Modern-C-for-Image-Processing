#include "../src/igg_image/image.h"
#include "../src/igg_image/io_strategies/png_strategy.h"
#include <gtest/gtest.h>
#include <memory>

TEST(TestPngStrategy, Read_PngStrategy){
	igg::Image img;
	img.SetIoStrategy(std::make_shared<igg::PngIoStrategy>());
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/igg_image/data/Screenshot.png";
	EXPECT_EQ(0, img.ReadFromDisk(filename));
}

TEST(TestPngStrategy, Write_PngStrategy){
	igg::Image img(10, 10);
	img.SetIoStrategy(std::make_shared<igg::PngIoStrategy>());
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW4/Solution/homework_4/igg_image/data/ScreenshotTest.png";
	EXPECT_EQ(0, img.WriteToDisk(filename));
}