// 
// cplusplus.com/reference/deque/deque/emplace_front
//
#include <iostream>
#include <deque>
#include <iterator>

int main(int argc, char** argv)
{
	std::deque<int> mydeque(2,100);
	mydeque.push_front(200);
	mydeque.push_front(300);
	mydeque.emplace_front(500);
	mydeque.emplace_back(1);

	std::cout << "mydeque contains:";
	for (std::deque<int>::iterator it = mydeque.begin(); it!=mydeque.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::deque<int> d2 = {10,20,30};
	d2.emplace_front(111);
	d2.emplace_front(222);
	d2.push_front(555);
	d2.push_back(5);

	std::cout << "d2 contains:";
	for (std::deque<int>::iterator it = d2.begin(); it!=d2.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;

	std::cout << "d2 contains:";
	for (auto& it: d2)
		std::cout << ' ' << it;
	std::cout << std::endl;

	std::cout << "d2 contains:";
	std::ostream_iterator<int> out_it (std::cout,":");
	std::copy(d2.begin(), d2.end(), out_it);

	std::cout << std::endl;
	
	return 0;
}


