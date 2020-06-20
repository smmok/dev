#include <thread>
#include <future>
#include <iostream>
#include <functional>
#include <unistd.h>

void print_string(std::future<std::string> & fut)
{
	std::cout << "Waiting ...\n";
	std::cout << "Future=" << fut.get() << std::endl;
}

int main(int argc, char** argv)
{
	std::promise<std::string> prom;
	std::future<std::string>  fut = prom.get_future();
	std::thread th(print_string, std::ref(fut));

	usleep(1000000);
	prom.set_value("Testing123_QWERTY");

	th.join();

	return 0;
}

