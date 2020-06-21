#include "image.h"

namespace  igg
{
	Image::Image() {};
  	Image::Image(int rows, int cols): rows_{rows}, cols_{cols} {
  		Pixel empty_pixel{0, 0, 0};
  		std::vector<Pixel> empty_data(rows * cols, empty_pixel);
  		data_ = empty_data;
  	};
  	int Image::rows() const { return rows_; }
	int Image::cols() const { return cols_; }
	Image::Pixel& Image::at(int row, int col){ return data_[row * cols_ + col]; }
	void Image::SetIoStrategy(const std::shared_ptr<IoStrategy>& strategy_ptr) {io_strategy_ = strategy_ptr;}
	int Image::ReadFromDisk(const std::string& file_name) {
		if (!io_strategy_) // if the io_strategy is a nullptr
		{
			return 1;
		}

		ImageData img = io_strategy_ -> Read(file_name);
		rows_ = img.rows;
		cols_ = img.cols;
		max_val_ = img.max_val;

		std::vector<int> red = img.data[0];
		std::vector<int> green = img.data[1];
		std::vector<int> blue = img.data[2];
		data_.clear();
		int len = red.size();
		for (int i = 0; i < len; ++i)
		{
			data_.emplace_back(Pixel({red[i], green[i], blue[i]}));
		}
		return 0;

	}

  	int Image::WriteToDisk(const std::string& file_name) const {
  		if (!io_strategy_) // if the io_strategy is a nullptr
		{
			return 1;
		}
  		int len = data_.size();
  		std::vector<int> red(len, 0);
		std::vector<int> green(len, 0);
		std::vector<int> blue(len, 0);

		for (int i = 0; i < len; ++i)
		{
			red[i] = data_[i].red;
			green[i] = data_[i].green;
			blue[i] = data_[i].blue;
		}
		bool success = io_strategy_ -> Write(file_name, ImageData({rows_, cols_, max_val_, {red, green, blue}}));
		if (success){
			return 0;
		} else {
			return 1;
		}
  	}
} // namespace igg