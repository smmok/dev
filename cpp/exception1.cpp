#include <iostream>
#include <exception>

using namespace std;

struct DivisionByZero : public exception 
{
	const char * what() const throw()
	{
		return "Division by zero exception!";
	}
};

double division(int a, int b)
{
	if (b==0)
		throw "Division by zero condition!";
	return (a/b);
}

double division1(int a, int b)
{
	if (b==0)
		throw DivisionByZero();
	return a/b;
}

void printResult(int x, int y, int z)
{
	cout << x << "/" << y << "=" << z << endl;
}

int main(int argc, char** argv)
{
	int x=50;
	int y=10;
	double z=0;
	
	int x1=50;
	int y1=0;

	cout << "=======================\n";

	try {
		z = division(x,y);
		printResult(x,y,z);	
		z = division(x1,y1);
		printResult(x1,y1,z);	
	} catch (const char* msg) {
		cerr << "Exception message: " << msg << endl;
	} catch (DivisionByZero& e) {
		cout << "e.what()= " << e.what() << endl;
	}

	cout << "=======================\n";

	try {
		z = division1(x,y);
		printResult(x,y,z);	
		z = division1(x1,y1);
		printResult(x1,y1,z);	
	} catch (const char* msg) {
		cerr << "Exception message: " << msg << endl;
	} catch (DivisionByZero& e) {
		cout << "e.what()= " << e.what() << endl;
	}

	return 0;
}
	
