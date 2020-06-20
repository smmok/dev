//
// https://www.bogotobogo.com/cplusplus/C11/5_C11_Move_Semantics_Rvalue_Reference.php
//

#include <iostream>

using namespace std;

class A
{
public:
	// constructor
	explicit A(size_t length):
		mLength(length), mData(new int[length]) {}

	// move constructor
	A(A&& other)
	{
		mData = other.mData;
		mLength = other.mLength;
		other.mData = nullptr;
		other.mLength = 0;
	}

	// move assignment
	A& operator=(A&& other) noexcept
	{
		mData = other.mData;
		mLength = other.mLength;
		other.mData = nullptr;
		other.mLength = 0;
		return *this;
	}

	size_t getLength() { return mLength; }

	void swap(A& other)
	{
		A temp = move(other);
		other = move(*this);
		*this = move(temp);
	}

	int* get_mData() { return mData; }

private:
	
	int *mData;
	size_t mLength;
};

int main(int argc, char** argv)
{
	A a(11), b(22);
	cout << a.getLength() << ' ' << b.getLength() << endl;
	cout << a.get_mData() << ' ' << b.get_mData() << endl;
	swap(a,b);
	cout << a.getLength() << ' ' << b.getLength() << endl;
	cout << a.get_mData() << ' ' << b.get_mData() << endl;
	cout << endl;

	return 0;
}

	
