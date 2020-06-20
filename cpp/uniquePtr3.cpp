#include <iostream>
#include <string>
#include <memory>
#include <vector>

int main(int argc, char** argv)
{
	std::unique_ptr<std::string> pStr = std::make_unique<std::string>("Test");
	std::unique_ptr<std::string> pStr1 = std::make_unique<std::string>("Another String");

	auto pStr2 = std::make_unique<std::string>();
	*pStr2 += "string pStr2";
	
	std::cout << *pStr  << std::endl;
	std::cout << *pStr1 << std::endl;
	std::cout << *pStr2 << std::endl;

	std::vector<std::unique_ptr<std::string>> v;
	v.push_back(std::make_unique<std::string>("String3a"));
	v.push_back(std::make_unique<std::string>("String3b"));

	std::cout << *v[0] << std::endl;
	std::cout << *v[1] << std::endl;

	return 0;
}

