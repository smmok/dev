// https://www.geeksforgeeks.org/copy-constructor-in-cpp/

#include <iostream>

using namespace std;

class Point
{
private:
	int x;
	int y;
public:
	Point(int x1, int y1)
	{
		x = x1;
		y = y1;
	}

	Point(const Point &p2)
	{
		x = p2.x;
		y = p2.y;
	}

	int getX() { return x; }
	int getY() { return y; }
};

int main(int argc, char** argv)
{
	Point p1(10,15);
	Point p2 = p1;

	cout << "p1.x=" << p1.getX() << ", p1.y=" << p1.getY() << endl;
	cout << "p2.x=" << p2.getX() << ", p2.y=" << p2.getY() << endl;

	return 0;
}

