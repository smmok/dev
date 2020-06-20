#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <unistd.h>

void print_int(std::future<int>& fut)
{
	int x = fut.get();
	std::cout << "Thread printing value: " << x << "\n";
}

void initializer(std::promise<int> & promObj, int value)
{
	unsigned int microseconds = 3000000;
	usleep(microseconds);
	std::cout << "Setting value " << value << " inside thread." << std::endl;
	promObj.set_value(value);
}

int main(int argc, char** argv)
{
	unsigned int microseconds = 5000000;

	// http://www.cplusplus.com/reference/future/promise/
	std::promise<int> prom;
	std::future<int> fut = prom.get_future();
	std::thread th1 (print_int, std::ref(fut));
	prom.set_value(10);
	th1.join();

	std::promise<int> prom2;
	std::future<int> fut2 = prom2.get_future();
	std::thread th2 (print_int, std::ref(fut2));
	prom2.set_value(20);
	th2.join();

	// https://thispointer.com/c11-multithreading-part-8-stdfuture-stdpromise-and-returning-values-from-thread/
	std::promise<int> prom3;
	std::future<int>  fut3 = prom3.get_future();
	std::thread th3 (print_int, std::ref(fut3));
	std::thread th4 (initializer, std::ref(prom3), 50);
	th4.join();
	th3.join();

	std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();
	std::thread thread5(initializer, std::ref(promiseObj), 30);
	usleep(microseconds);	
	std::cout << "futureObj.get()= " << futureObj.get() << std::endl;
	thread5.join();

	return 0;
}

