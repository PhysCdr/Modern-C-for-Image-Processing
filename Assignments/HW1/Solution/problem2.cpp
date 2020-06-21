#include <iostream>
#include <tr1/cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(nullptr)); // use current time as seed for random generator
    int secret = std::rand() % 100;
    int guess;
	while (true){
		std::cin >> guess;
		if (secret > guess){
			std::cout << "Your number is smaller" << std::endl;
		}

		if (secret < guess){
			std::cout << "Your number is larger" << std::endl;
		}

		if (secret == guess){
			std::cout << "You won" << std::endl;
			break;
		}
	}
	return 0;
}