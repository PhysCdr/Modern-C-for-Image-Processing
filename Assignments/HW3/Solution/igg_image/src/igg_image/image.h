// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <vector>

#include <string>

#include "io_strategies/strategy.h"

#include "io_strategies/dummy_strategy.h"

namespace igg {

class Image {
 public:
  /// A struct within class Image that defines a pixel.
  struct Pixel {
    int red;
    int green;
    int blue;
  };

  Image(const IoStrategy& io_strategy);
  Image(int rows, int cols, const IoStrategy& io_strategy);
  int rows() const;
  int cols() const;
  Pixel& at(int row, int col);
  void DownScale(int scale);
  void UpScale(int scale);
  void ReadFromDisk(const std::string& file_name);
  bool WriteToDisk(const std::string& file_name) const;



 private:

  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
  const IoStrategy& io_strategy_{DummyIoStrategy()};
};

}  // namespace igg
