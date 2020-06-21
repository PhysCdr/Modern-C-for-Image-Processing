#include "image.h"
#include "io_strategies/png_strategy.h"
#include "io_strategies/ppm_strategy.h"
#include <iostream>
#include <string>
#include <memory>

using igg::Image;
using igg::PngIoStrategy;
using std::cout;
using std::endl;
int main()
{
	{
		std::string file_name;
		file_name = "../data/Screenshot.png";
		Image img{};
		img.SetIoStrategy(std::make_shared<igg::PngIoStrategy>());
		img.ReadFromDisk(file_name);
		cout << img.cols() << "x" << img.rows() << endl;
	}

	{
		std::string file_name = "../data/pbmlib.ascii.ppm";
		Image img{};
		img.SetIoStrategy(std::make_shared<igg::PpmIoStrategy>());
		img.ReadFromDisk(file_name);
		cout << "Ppm"<< img.cols() << "x" << img.rows() << endl;
	}

	return 0;
}