#include <gtest/gtest.h>
#include "igg_image/image.h"
#include <vector>
#include <string>

using namespace igg;

TEST(TestImage, ReadPgm){
	Image img{};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW2/Solution/igg_image/data/lena.ascii.pgm";
	img.ReadFromPgm(filename);
	EXPECT_LT(0, img.rows());
	EXPECT_LT(0, img.cols());
}

TEST(TestImage, WritePgm){
	Image img{};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW2/Solution/igg_image/data/lena.ascii.pgm";
	img.ReadFromPgm(filename);
	filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW2/Solution/igg_image/data/lenaTest.ascii.pgm";
	EXPECT_TRUE(img.WriteToPgm(filename));
}

TEST(TestImage, Pixel_At){
	Image img{};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW2/Solution/igg_image/data/lena.ascii.pgm";
	img.ReadFromPgm(filename);
	img.at(0,0) = 255;
	EXPECT_EQ(255, img.at(0,0));
}

TEST(TestImage, ImageConstructor){
	Image img{10, 10};
	EXPECT_EQ(10, img.cols());
	EXPECT_EQ(10, img.rows());
}

TEST(TestImage, UpScale){
	Image img{};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW2/Solution/igg_image/data/lena.ascii.pgm";
	img.ReadFromPgm(filename);
	int rows = img.rows();
	int cols = img.cols();
	img.UpScale(2);

	EXPECT_EQ(img.rows(), 2*rows);
	EXPECT_EQ(img.cols(), 2*cols);
}

TEST(TestImage, DownScale){
	Image img{};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW2/Solution/igg_image/data/lena.ascii.pgm";
	img.ReadFromPgm(filename);
	int rows = img.rows();
	int cols = img.cols();
	img.DownScale(2);

	EXPECT_EQ(img.rows(), rows/2);
	EXPECT_EQ(img.cols(), cols/2);
}

TEST(TestImage, Histogram){
	Image img{};
	std::string filename = "/home/dmitriy/Documents/Learning/Uni-Bonn/ModernC++/Assignments/HW2/Solution/igg_image/data/lena.ascii.pgm";
	img.ReadFromPgm(filename);
	std::vector<int> hist = img.ComputeHistogram(10);
	int total_counts = 0;
	for (const auto& count : hist)
	{
		total_counts += count;
	}
	EXPECT_EQ(total_counts, img.rows() * img.cols());
}