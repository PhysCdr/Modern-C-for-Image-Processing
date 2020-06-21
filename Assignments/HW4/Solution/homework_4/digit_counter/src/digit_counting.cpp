#include <digit_counting.h>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

bool ReturnTrue(){ return  true;}

double Warp(double number, double factor){
	number += factor;
	number -= factor;
	return number;
}

int CountSameSignificantDigits(double a, double b){
	const int kPrecision = 100;
	std::stringstream sa;
	sa << std::setprecision(kPrecision) << std::fabs(a);
	std::string num_a = sa.str();

	std::stringstream sb;
	sb << std::setprecision(kPrecision) << std::fabs(b);
	std::string num_b = sb.str();

	int integer_part_a = 0;
	int fractional_part_a = 0;
	bool fraction_flag = false;
	for (auto& character : num_a){
		if (character == '.'){
			fraction_flag = true;
			continue;
		}

		if (fraction_flag){
			++fractional_part_a;
		} else {
			++integer_part_a;
		}
	}

	int integer_part_b = 0;
	int fractional_part_b = 0;
	fraction_flag = false;
	for (auto& character : num_b){
		if (character == '.'){
			fraction_flag = true;
			continue;
		}

		if (fraction_flag){
			++fractional_part_b;
		} else {
			++integer_part_b;
		}
	}

	if ((integer_part_a == integer_part_b) & (fractional_part_a == fractional_part_b)) {
		return kPrecision;
	} else {
		int num_common_integer_figs;
		int num_common_fraction_figs;

		if (integer_part_a < integer_part_b){
			num_common_integer_figs = integer_part_a;
		} else {
			num_common_integer_figs = integer_part_b;
		}

		if (fractional_part_a < fractional_part_b){
			num_common_fraction_figs = fractional_part_a;
		} else {
			num_common_fraction_figs = fractional_part_b;
		}
		return num_common_integer_figs + num_common_fraction_figs;
	}
}