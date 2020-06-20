#include <iostream>
#include <future>
#include <chrono>
#include <thread>

int countdown(int from, int to)
{
	for (int i=from; i!=to; --i)
	{
		std::cout << i << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << "Lift off!\n";
	return from-to;
}

int main(int argc, char** argv)
{
	std::packaged_task<int(int,int)> tsk (countdown);
	std::future<int> fut = tsk.get_future();

	std::thread th(std::move(tsk),10,0);

	int value = fut.get();
	std::cout << "The countdown lasted for " << value << " seconds.\n";
	th.join();

	return 0;
}

