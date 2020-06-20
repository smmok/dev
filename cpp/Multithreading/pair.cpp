#include <utility>
#include <iostream>

int main(int argc, char** argv)
{
	std::pair <int, char> PAIR1;
	PAIR1.first  = 100;
	PAIR1.second = 'G';
	std::cout << PAIR1.first << " " << PAIR1.second << std::endl;

	std::pair g2 = std::make_pair(100,'A');
	std::cout << g2.first << " " << g2.second << std::endl;

	std::pair g3(2000, "ZZ");
	std::cout << g3.first << " " << g3.second << std::endl;

	std::pair imag(20,30);
	std::cout << imag.first << "+" << imag.second << "=" \
			  << imag.first+imag.second << std::endl;

	return 0;
}

