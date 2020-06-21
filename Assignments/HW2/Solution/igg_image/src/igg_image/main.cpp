#include "image.h"
#include <iostream>
#include <string>
#include <vector>

using namespace igg;

int main()
{
	Image img{};
	std::string filename = "../data/lena.ascii.pgm";
	img.ReadFromPgm(filename);
	std::cout << img.rows() << "x" << img.cols() << std::endl;
	std::cout << "At get "<< img.at(0,0) << std::endl;
	std::vector<int> histogram = img.ComputeHistogram(10);
	std::cout << "Hist before " << std::endl;
	for (const auto& count : histogram)
	{
		std::cout << count << std::endl;
	}
	img.at(0, 0) = 0;
	std::cout << "At set " << img.at(0,0) << std::endl;
	histogram = img.ComputeHistogram(10);
	std::cout << "Hist after " << std::endl;
	for (const auto& count : histogram)
	{
		std::cout << count << std::endl;
	}
	img.UpScale(2);
	filename = "../data/lenaUp.ascii.pgm";
	bool success = img.WriteToPgm(filename);
	std::cout << "Upscaled " << success << std::endl;
	img.DownScale(4);
	filename = "../data/lenaDown.ascii.pgm";
	success = img.WriteToPgm(filename);
	std::cout << "Downscaled " << success << std::endl;


	return 0;
}