//
// https://www.bogotobogo.com/cplusplus/C11/5_C11_Move_Semantics_Rvalue_Reference.php
//

#include <iostream>

void f(int& i)
{
	std::cout << "lvalue ref: " << i << "\n";
}

void f(int&& i)
{
	std::cout << "rvalue ref: " << i << "\n";
}

int main(int argc, char** argv)
{
	int i=77;
	f(i);
	f(99);

	f(std::move(i));

	return 9;
}


