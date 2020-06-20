// this_thread::sleep_until example
//
// cplusplus.com/reference/thread/this_thread/sleep_until
//

#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <ctime>

int main(int argc, char** argv)
{
	//using std::chrono::system_clock;
	std::time_t tt = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now());
	struct std::tm * ptm = std::localtime(&tt);
	std::cout << "Current time: " << std::put_time(ptm,"%D %T") << std::endl;

	std::cout << "Waiting for next minute to begin ...\n";
	++ptm->tm_min;
	ptm->tm_sec=0;
	std::this_thread::sleep_until (std::chrono::system_clock::from_time_t (mktime(ptm)));
	std::cout << std::put_time(ptm,"%D %T") << " reached!\n";

	tt = std::chrono::system_clock::to_time_t (std::chrono::system_clock::now());
	ptm = std::localtime(&tt);
	ptm->tm_sec=30;
	std::cout << "Waiting for 30 seconds ...\n";
	std::this_thread::sleep_until (std::chrono::system_clock::from_time_t (mktime(ptm)));
	std::cout << std::put_time(ptm,"%D %T") << " reached!\n";

	return 0;
}

