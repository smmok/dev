#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;

void printer(int num, std::string str)
{
	mtx.lock();
	for (int i=0; i<num; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		std::cout << str;
	}
	std::cout << std::endl;
	mtx.unlock();
}

void printer_nomutex(int num, std::string str)
{
	for (int i=0; i<num; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		std::cout << str;
	}
	std::cout << std::endl;
}

int main(int argc, char** argv)
{
	std::thread th1(printer, 50, "|");
	std::thread th2(printer, 50, "=");
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	std::thread th3(printer_nomutex, 50, "|");
	std::thread th4(printer_nomutex, 50, "-");

	th1.join();
	th2.join();
	th3.join();
	th4.join();

	return 0;
}

