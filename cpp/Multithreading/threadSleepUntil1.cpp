#include <iomanip>
#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>

int main(int argc, char** argv)
{
	std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::tm* ptm = std::localtime(&tt);
	std::cout << "Current time: " << std::put_time(ptm,"%X\n");

	ptm->tm_min = ptm->tm_min + 1;
	ptm->tm_sec = 65;

	std::cout << "Waiting for 5 secs past min\n";

	std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(mktime(ptm)));

	std::cout << std::put_time(ptm,"%X") << " reached.\n";

	return 0;
}


