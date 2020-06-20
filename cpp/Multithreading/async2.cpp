#include <future>
#include <iostream>

int get_string(std::string & str)
{
	std::string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return s.find(str);
}

int main(int argc, char** argv)
{
	std::string str = "VWX";
	std::future<int> fut = async(get_string, std::ref(str));

	int pos = fut.get();
	std::cout << "Position of " << str << " is " << pos << std::endl;

	return 0;
}

