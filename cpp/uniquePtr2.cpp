#include <iostream>
#include <memory>

using namespace std;

class Animal {
public:
	int legs;

	Animal(int numlegs) {
		legs = numlegs;
	}

	int getLegs() {return legs;}
};

int main(int argc, char** argv)
{
	unique_ptr<Animal> A1(new Animal(6));
	
	cout << "Animal Legs=" << A1->getLegs() << endl;

	return 0;
}

