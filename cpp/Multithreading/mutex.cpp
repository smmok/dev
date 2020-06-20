//
// cplusplus.com/reference/mutex/mutex/
//

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;

void print_block_wrong(int n, char c)
{
	for (int i=0; i<n; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		std::cout << c;
	}
	std::cout << std::endl;
}

void print_block (int n, char c)
{
	// critical section - exclusive access to std::cout signaled by locking mtx
	mtx.lock();
	for (int i=0; i<n; ++i)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		std::cout << c;
	}
	std::cout << std::endl;
	mtx.unlock();
}

int main(int argc, char** argv)
{
	std::cout << "========== without mutex ================\n";
	std::thread th1 (print_block_wrong,500, '1');
	std::thread th2 (print_block_wrong,500, '4');
	std::thread th3 (print_block_wrong,500, '8');
	th1.join();
	th2.join();
	th3.join();

	std::this_thread::sleep_for(std::chrono::milliseconds(500));

	std::cout << "========== with mutex ================\n";
	std::thread th4 (print_block, 500, 'I');
	std::thread th5 (print_block, 500, 'O');
	std::thread th6 (print_block, 500, 'w');
	th4.join();
	th5.join();
	th6.join();

	return 0;
}

