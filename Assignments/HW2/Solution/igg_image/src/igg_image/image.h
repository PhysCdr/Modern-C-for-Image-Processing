// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <vector>

#include <string>

namespace igg {

class Image {
 public:
  Image();
  Image(int rows, int cols);
  int rows() const;
  int cols() const;
  int& at(int row, int col);
  void DownScale(int scale);
  void UpScale(int scale);
  void ReadFromPgm(const std::string& file_name);
  bool WriteToPgm(const std::string& file_name) const;
  std::vector<int> ComputeHistogram(int bins) const;

 private:

  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg

