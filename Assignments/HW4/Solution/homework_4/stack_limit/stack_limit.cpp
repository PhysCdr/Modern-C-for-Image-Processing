#include <iostream>

int main()
{	
	size_t typesize = sizeof(double);
	int size = (100 * 1024) / typesize; // the length of a 100kB array
	int allocated = 0;
	int arr_size = size;
	while (true){
		double arr[arr_size];
		std::fill(arr, arr + size, 0);
		arr_size += size;
		allocated += 100;
		std::cerr << allocated << " kB occupied in the stack\n";
	}
	return 0;
}