//
// cplusplus.com/reference/thread/this_thread/get_id
//

#include <thread>
#include <iostream>
#include <chrono>

std::thread::id main_thread_id = std::this_thread::get_id();

void is_this_main_thread()
{
	if (main_thread_id == std::this_thread::get_id())
	{
		std::cout << "This is main thread.\n";
		std::cout << "Main thread=" << main_thread_id << "  ";
		std::cout << "This thread=" << std::this_thread::get_id() << std::endl;
	}
	else
		std::cout << "This is not main thread.\n";
		std::cout << "Main thread=" << main_thread_id << "  ";
		std::cout << "This thread=" << std::this_thread::get_id() << std::endl;
}

int main(int argc, char** argv)
{
	std::cout << "Calling: is_this_main_thread(): ";
	is_this_main_thread();
	std::cout << std::endl;
	
	std::cout << "Calling: th(is_this_main_thread(): ";
	std::thread th(is_this_main_thread);
	th.join();

	std::cout << "\nGetting ID in main: " << std::this_thread::get_id() << std::endl;

	return 0;
}

