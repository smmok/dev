#include <thread>
#include <future>
#include <iostream>
#include <unistd.h>

unsigned int microseconds = 1000000;

void print_int(std::future<int> & fut)
{
	int x = fut.get();
	usleep(microseconds);
	std::cout << "Future value=" << x << std::endl;
}

void set_int(std::promise<int> & prom, int value)
{
	prom.set_value(value);
	std::cout << "Set value=" << value << std::endl;
}

int main(int argc, char** argv)
{
	std::promise<int> prom;
	std::future<int>  fut = prom.get_future();
	std::thread th1(print_int, std::ref(fut));
	std::thread th2(set_int, std::ref(prom), 123);

	th1.join();
	th2.join();

	return 0;
}

