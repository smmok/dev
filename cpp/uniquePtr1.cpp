#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

int main(int argcs, char** argv)
{
	auto str = unique_ptr<char[]>{new char[100]};
	auto array = unique_ptr<int[]>{new int[10]};
	unique_ptr<int[]> one = unique_ptr<int[]>{new int[1]};
	unique_ptr<int[]> two = unique_ptr<int[]>{new int[2]};

	strcpy(str.get(),"This is a test.\n");
	cout << "str=" << str.get() << endl;

	for (int i=0; i<5; i++)
		array[i] = 10+i;
	for (int i=0; i<5; i++)
		cout << "array[" << i << "]=" << array[i] << endl;

	one[0] = 1000;
	cout << "one=" << one[0] << endl;

	two[0] = 2000;
	two[1] = 2001;
	cout << "two=" << two[0] << ", " << two[1] << endl;

	return 0;
}

