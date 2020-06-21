// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <vector>

#include <string>

#include <memory>

#include "io_strategies/strategy.h"

namespace igg {

class Image {
 public:
  /// A struct within class Image that defines a pixel.
  struct Pixel {
    int red;
    int green;
    int blue;
  };

  Image();
  Image(int rows, int cols);
  int rows() const;
  int cols() const;
  Pixel& at(int row, int col);
  int ReadFromDisk(const std::string& file_name);
  int WriteToDisk(const std::string& file_name) const;
  void SetIoStrategy(const std::shared_ptr<IoStrategy>& strategy_ptr);



 private:

  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
  std::shared_ptr<IoStrategy> io_strategy_ = nullptr;
};

}  // namespace igg
