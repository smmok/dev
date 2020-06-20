#include <iostream>
#include <memory>

using namespace std;

class A {
public:
	void show() { cout << "A::show()" << endl; }
};

int main(int argc, char** argv)
{
	shared_ptr<A> p1(new A);
	cout << p1.get() << endl;
	p1->show();

	shared_ptr<A> p2(p1);
	p2->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;

	cout << "p1.use_count=" << p1.use_count() << endl;
	cout << "p2.use_count=" << p2.use_count() << endl;

	p1.reset();
	cout << "p1.get()=" << p1.get() << endl;
	cout << "p2.use_count=" << p2.use_count() << endl;
	cout << "p2.get()=" << p2.get() << endl;

	return 0;
}

