//
// https://thispointer.com/c11-how-to-create-vector-of-thread-objects/
// 
// g++ -o vecThread vecThread.cpp -std=C++17 -lpthread
//
// ./vecThread
// From Thread ID : 140299756570368
// From Thread ID : 140299765024512
// From Thread ID : 140299731207936
// From Thread ID : 140299739662080
// From Thread ID : 140299748116224
//
#include <functional>
#include <thread>
#include <mutex>
#include <vector>
#include <iostream>
#include <chrono>

int main()
{
	// Create a vector of threads
	std::vector<std::thread> vecOfThreads;
 
	// Create a function object
	std::function < void() > func = []() {
		//Do Some Important Work
		// Sleep for 2 second
		std::this_thread::sleep_for (std::chrono::seconds(2));
		//Print Thread ID
		std::cout << "From Thread ID : "<<std::this_thread::get_id() << "\n";
		};
 
	// Add a Thread object to vector
	vecOfThreads.push_back(std::thread(func));
 
	// Create 3 differet thread objects
	std::thread th1(func);
	std::thread th2(func);
	std::thread th3(func);
 
	// Move all three thread objects to vector
	vecOfThreads.push_back(std::move(th1));
	vecOfThreads.push_back(std::move(th2));
	vecOfThreads.push_back(std::move(th3));
 
	std::thread th4(func);
 
	//Destructor of already existing thread object will call terminate
	//vecOfThreads[1] = std::move(th4);
 
	// First join the existing object
	if (vecOfThreads[1].joinable())
		vecOfThreads[1].join();
 
	// Replace the joined thread object
	vecOfThreads[1] = std::move(th4);
 
	// Can not copy vector of thread , COMPILE TIME ERROR
	//std::vector<std::thread> newVecThreads = vecOfThreads;
 
	// Can Only move vector of thread
	std::vector<std::thread> newVecThreads = std::move(vecOfThreads);
 
	/** Wait for all the threads in vector to join **/
 
	// Iterate over the thread vector
	for (std::thread & th : newVecThreads)
	{
		// If thread Object is Joinable then Join that thread.
		if (th.joinable())
			th.join();
	}
 
	return 0;
}
