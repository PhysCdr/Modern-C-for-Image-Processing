#include "image.h"
#include "io_tools.h"

namespace  igg
{
	int max(const std::vector<int>& data){
		int maxval = -1;
		for (const auto& pixel : data)
		{
			if(pixel > maxval){
				maxval = pixel;
			} 
		}
		return maxval;
	}

	int min(const std::vector<int>& data){
		int minval = max(data);
		for (const auto& pixel : data)
		{
			if(pixel < minval){
				minval = pixel;
			} 
		}
		return minval;
	}

	Image::Image() {};
  	Image::Image(int rows, int cols): rows_{rows}, cols_{cols} {data_.reserve(rows * cols); };
  	int Image::rows() const { return rows_; }
	int Image::cols() const { return cols_; }
	int& Image::at(int row, int col){ return data_[row * cols_ + col]; }

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

		std::vector<int> data;
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

		std::vector<int> data;
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
	void Image::ReadFromPgm(const std::string& file_name) {
		io_tools::ImageData img = io_tools::ReadFromPgm(file_name);
		rows_ = img.rows;
		cols_ = img.cols;
		max_val_ = img.max_val;
		data_ = img.data;


	}
  	bool Image::WriteToPgm(const std::string& file_name) const {
		bool success = io_tools::WriteToPgm(io_tools::ImageData({rows_, cols_, max_val_, data_}), file_name);
		return success;
  	}

  	std::vector<int> Image::ComputeHistogram(int bins) const {
  		std::vector<int> histogram(bins, 0);
  		int minval = min(data_);
  		float bin_width = (float)( max_val_ - minval) / bins;

  		std::vector<float> bin_edges(bins+1, 0);
  		for (int i = 0; i < (bins+1); ++i)
  		{
  			bin_edges[i] = i * bin_width + minval;
  		}
  		for (const auto& pixel : data_)
  		{
  			if ((float)pixel <= bin_edges[1]){
  					++histogram[0];
  				} else {
  					for (int i = 2; i < (bins+1); ++i)
		  			{
		  				if (((float)pixel > bin_edges[i-1]) & ((float)pixel <= bin_edges[i] )){
		  					++histogram[i-1];
		  					break;
		  				}
		  			}
  				}
  		}
  		return histogram;
  	}
} // namespace igg