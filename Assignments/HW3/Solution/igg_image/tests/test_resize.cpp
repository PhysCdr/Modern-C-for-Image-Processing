#include "../src/igg_image/image.h"
#include <gtest/gtest.h>

TEST(TestImageResize, UpScale){
	int rows = 10;
	int cols = 10;
	int scale = 2;
	igg::Image img{rows, cols, igg::DummyIoStrategy()};
	img.UpScale(scale);
	EXPECT_EQ(scale * rows, img.rows());
	EXPECT_EQ(scale * cols, img.cols());
}

TEST(TestImageResize, Downscale_EvenSize_EvenScale){
	int rows = 10;
	int cols = 10;
	int scale = 2;
	igg::Image img{rows, cols, igg::DummyIoStrategy()};
	img.DownScale(scale);
	if ((rows % scale) > 0){ rows = rows/scale + 1; } else {rows /= scale;}
	if ((cols % scale) > 0){ cols = cols/scale + 1; } else {cols /= scale;}
	EXPECT_EQ(rows, img.rows());
	EXPECT_EQ(cols, img.cols());
}

TEST(TestImageResize, Downscale_OddSize_EvenScale){
	int rows = 11;
	int cols = 11;
	int scale = 2;
	igg::Image img{rows, cols, igg::DummyIoStrategy()};
	img.DownScale(scale);
	if ((rows % scale) > 0){ rows = rows/scale + 1; } else {rows /= scale;}
	if ((cols % scale) > 0){ cols = cols/scale + 1; } else {cols /= scale;}
	EXPECT_EQ(rows, img.rows());
	EXPECT_EQ(cols, img.cols());
}

TEST(TestImageResize, Downscale_OddSize_OddScale){
	int rows = 11;
	int cols = 11;
	int scale = 3;
	igg::Image img{rows, cols, igg::DummyIoStrategy()};
	img.DownScale(scale);
	if ((rows % scale) > 0){ rows = rows/scale + 1; } else {rows /= scale;}
	if ((cols % scale) > 0){ cols = cols/scale + 1; } else {cols /= scale;}
	EXPECT_EQ(rows, img.rows());
	EXPECT_EQ(cols, img.cols());
}

TEST(TestImageResize, Downscale_EvenSize_OddScale){
	int rows = 10;
	int cols = 10;
	int scale = 3;
	igg::Image img{rows, cols, igg::DummyIoStrategy()};
	img.DownScale(scale);
	if ((rows % scale) > 0){ rows = rows/scale + 1; } else {rows /= scale;}
	if ((cols % scale) > 0){ cols = cols/scale + 1; } else {cols /= scale;}
	EXPECT_EQ(rows, img.rows());
	EXPECT_EQ(cols, img.cols());
}