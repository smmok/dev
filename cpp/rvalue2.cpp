//
// https://www.bogotobogo.com/cplusplus/C11/5_C11_Move_Semantics_Rvalue_Reference.php
//

#include <iostream>

void printReference(int& value)
{
	std::cout << "lvalue: value=" << value << std::endl;
}

void printReference(int&& value)
{
	std::cout << "rvalue: value=" << value << std::endl;
}

int getValue()
{
	int temp_ii = 99;
	return temp_ii;
}

int main(int argc, char** argv)
{
	int ii = 22;
	printReference(ii);
	printReference(getValue());
	return 0;
}

