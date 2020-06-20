// https://www.geeksforgeeks.org/copy-constructor-in-cpp/  

#include <iostream>

using namespace std;

struct Circle {
	int radius;
};

class Point {
private:
	int x;
	int y;
	int array[3];
	Circle *c;
public:
	Point(int x1, int y1) {
		x = x1;
		y = y1;
		array[0]=x; array[1]=y; array[2]=99;
		c = new Circle;
		c->radius=5;
	}

	Point(const Point &p2) {
		x = p2.x;
		y = p2.y;
		array[0]=100; array[1]=101; array[2]=102;
		c = new Circle;
		c->radius=5;
	}

	int getX() { return x; }
	int getY() { return y; }
	void printArray() { cout << array[0] << " " << array[1] << " " << array[2] << endl; }
	void printC() { cout << "C-radius=" << c->radius << endl;}

	void setX(int x1) {x=x1;}
	void setY(int y1) {y=y1;}
	void setArray2(int a) {array[2]=a;}
	void setC(int c1) {c->radius=c1;}

	int* getXaddress() {return &x;}
	int* getYaddress() {return &y;}
	void seeCaddress() {cout << "C address=" << &(c->radius) << endl;}

};

int main(int argc, char** argv) {
	Point p1(10,15);
	Point p2 = p1;

	cout << "p1.x=" << p1.getX() << " p1.y=" << p1.getY() << endl;
	cout << "p2.x=" << p2.getX() << " p2.y=" << p2.getY() << endl;
	cout << "address p1.x=" << p1.getXaddress() << endl;
	cout << "address p2.x=" << p2.getXaddress() << endl;
	p1.printArray();
	p2.printArray();
	p1.printC(); 
	p2.setArray2(9999);
	p1.seeCaddress();
	p2.seeCaddress();

	p1.setX(100); p1.setY(200);
	cout << "p1.x=" << p1.getX() << " p1.y=" << p1.getY() << endl;
	cout << "p2.x=" << p2.getX() << " p2.y=" << p2.getY() << endl;
	cout << "address p1.x=" << p1.getXaddress() << endl;
	cout << "address p2.x=" << p2.getXaddress() << endl;
	p1.printArray();
	p2.printArray();
	p1.setC(50);
	p1.printC();
	p2.printC();

	return 0;
}

