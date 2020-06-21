#include "image.h"
#include "io_strategies/png_strategy.h"
#include "io_strategies/ppm_strategy.h"
#include <iostream>
#include <string>

using igg::Image;
using igg::PngIoStrategy;
using std::cout;
using std::endl;
int main()
{
	std::string file_name;
	file_name = "../data/Screenshot.png";
	Image img{igg::PngIoStrategy()};
	img.ReadFromDisk(file_name);
	cout << img.cols() << "x" << img.rows() << endl;

	img.UpScale(2);
	std::string file_nameUp = "../data/ScreenshotUp.png";
	bool success = img.WriteToDisk(file_nameUp);
	cout << success << endl;

	img.DownScale(4);
	std::string file_nameDown = "../data/ScreenshotDown.png";
	success = img.WriteToDisk(file_nameDown);
	cout << success << endl;

	{
		std::string file_name = "../data/pbmlib.ascii.ppm";
		Image img{igg::PpmIoStrategy()};
		img.ReadFromDisk(file_name);
		cout << "Ppm"<< img.cols() << "x" << img.rows() << endl;

		img.DownScale(2);
		file_name = "../data/pbmlib_Down.ascii.ppm";
		bool success = img.WriteToDisk(file_name);
		cout << success << endl;
	}

	return 0;
}