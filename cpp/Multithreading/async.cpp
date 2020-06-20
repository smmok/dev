#include <future>
#include <iostream>
#include <cstdint>
#include <unistd.h>

unsigned int microseconds = 1;
static   int printDotNow = 0;

int printDot(char c)
{
	while (true)
	{
		usleep(5000);
		if (printDotNow==1)
			std::cout << c;
		if (printDotNow==-1)
			return 0;
	}
}

bool is_prime(uint64_t x)
{
	std::cout << "Calculating. Please wait.\n";
	printDotNow=1;
	for (uint64_t i=2; i<x; ++i)
	{
		// usleep(microseconds);
		if (x%i==0)
		{
			printDotNow=-1;
			return false;
		}
	}
	printDotNow=-1;
	return true;
}

void printResult(std::future<bool> & fut, uint64_t value)
{
	std::cout << "Checking...\n";
	std::thread thd1(printDot, '+');
	bool ret = fut.get();
	thd1.join();

	if (ret)
		std::cout << "\n" << value << " is a prime.\n";
	else
		std::cout << "\n" << value << " is not a prime.\n";
}


int main(int argc, char** argv)
{
	// cplusplus.com/reference/future/async/

	uint64_t value = 313222313;

	std::future<bool> fut = std::async(is_prime, value);
	std::thread th1(printResult, std::ref(fut), value);
	th1.join();

	value = 313222313;
	std::future<bool> fut2 = std::async(is_prime, value);
	std::thread th2(printResult, std::ref(fut2), value);
	th2.join();

	return 0;
}

