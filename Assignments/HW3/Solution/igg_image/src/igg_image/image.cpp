#include "image.h"

namespace  igg
{
	int max(const std::vector<Image::Pixel>& data){
		int maxval = -1;
		for (const auto& pixel : data)
		{
			if(pixel.red > maxval){
				maxval = pixel.red;
			} 
			if (pixel.green > maxval) {
				maxval = pixel.green;
			} 
			if (pixel.blue > maxval) {
				maxval = pixel.blue;
			}
		}
		return maxval;
	}

	Image::Image(const IoStrategy& io_strategy): io_strategy_{io_strategy} {};
  	Image::Image(int rows, int cols, const IoStrategy& io_strategy): rows_{rows}, cols_{cols}, io_strategy_{io_strategy} {
  		Pixel empty_pixel{0, 0, 0};
  		std::vector<Pixel> empty_data(rows * cols, empty_pixel);
  		data_ = empty_data;
  	};
  	int Image::rows() const { return rows_; }
	int Image::cols() const { return cols_; }
	Image::Pixel& Image::at(int row, int col){ return data_[row * cols_ + col]; }

	void Image::DownScale(int scale){
		
		std::vector<int> scaled_rows;
		std::vector<int> scaled_cols;

		for (int i = 0; i < rows_; i+=scale)
		{
			scaled_rows.emplace_back(i);
		}

		for (int i = 0; i < cols_; i+=scale)
		{
			scaled_cols.emplace_back(i);
		}

		int num_rows = scaled_rows.size();
		int num_cols = scaled_cols.size();

		std::vector<Pixel> data;
		data.reserve(num_cols * num_rows);

		for (const auto& row : scaled_rows)
		{
			for (const auto& col : scaled_cols)
			{
				data.emplace_back(data_[cols_ * row + col]);
			}
		}

		data_ = data;
		rows_ = num_rows;
		cols_ = num_cols;
		max_val_ = max(data);

	}
	  void Image::UpScale(int scale){
		
		std::vector<int> scaled_rows;
		std::vector<int> scaled_cols;

		for (int i = 0; i < scale * rows_; ++i)
		{
			scaled_rows.emplace_back(i / scale);
		}

		for (int i = 0; i < scale * cols_; ++i)
		{
			scaled_cols.emplace_back(i / scale);
		}

		int num_rows = scaled_rows.size();
		int num_cols = scaled_cols.size();

		std::vector<Pixel> data;
		data.reserve(num_cols * num_rows);

		for (const auto& row : scaled_rows)
		{
			for (const auto& col : scaled_cols)
			{
				data.emplace_back(data_[cols_ * row + col]);
			}
		}

		data_ = data;
		rows_ = num_rows;
		cols_ = num_cols;

	}
	void Image::ReadFromDisk(const std::string& file_name) {
		ImageData img = io_strategy_.Read(file_name);
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


	}
  	bool Image::WriteToDisk(const std::string& file_name) const {
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
		bool success = io_strategy_.Write(file_name, ImageData({rows_, cols_, max_val_, {red, green, blue}}));
		return success;
  	}
} // namespace igg