#include "igg_image/io_strategies/ppm_strategy.h"

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using std::ifstream;
using std::ofstream;
using std::string;
using std::to_string;
using std::ios_base;
using std::stringstream;
using std::endl;

namespace igg {

bool PpmIoStrategy::Write(const std::string& file_name,
                          const ImageData& data) const {

  ofstream outfile(file_name);

  // Write file header
  outfile << "P3" << endl;
  outfile << data.cols << " " << data.rows << endl;
  outfile << data.max_val << endl;

  string line = "";
  string pixel_rgb = "";
  std::vector<int> red = data.data[0];
  std::vector<int> green = data.data[1];
  std::vector<int> blue = data.data[2];

  int len = red.size();
  const int kLineLength = 70;

  for (int i = 0; i < len; ++i)
  {
    pixel_rgb = to_string(red[i]) + " " + to_string(green[i]) + " " + to_string(blue[i]) + "    ";
    if ((line.length() + pixel_rgb.length()) > kLineLength){
      outfile << line << endl;
      line = pixel_rgb;
    } else if (i == (len - 1)){
      line += pixel_rgb;
      outfile << line << endl;
      line = "";
    } else {
      line += pixel_rgb;
    }
  }

  return true;
}

ImageData PpmIoStrategy::Read(const std::string& file_name) const {

  string line;
  ifstream input(file_name, ios_base::in);

  // read the header
  std::vector<string> header(3, "");
  int header_line = 0;

  while (header_line < 3){
    std::getline(input, line);
    if (line[0] != '#') // skip comment lines
    {
      header[header_line] = line;
      ++header_line;
    }
  }

  // convert header to cols (width), rows (height), and max_value
  ImageData image_data;
  stringstream line_stream(header[1]);
  line_stream >> image_data.cols >> image_data.rows;
  line_stream = stringstream(header.back());
  line_stream >> image_data.max_val;

  // read the remainder of the file into one string
  string rgb_pixels = "";
  while ( getline (input , line)) {
    rgb_pixels += line;
    rgb_pixels += " ";
  }

  // convert rgb_pixels to image_data.data
  int len = image_data.rows * image_data.cols;
  std::vector<int> red(len, 0);
  std::vector<int> green(len, 0);
  std::vector<int> blue(len, 0);

  stringstream rgb_pixel_stream(rgb_pixels);

  for (int i = 0; i < len; ++i)
  {
    rgb_pixel_stream >> red[i] >> green[i] >> blue[i];
  }
  image_data.data = {red, green, blue};
  return image_data;
}

}  // namespace igg