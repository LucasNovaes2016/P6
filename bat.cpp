#include <iostream>

using namespace std;

class Animal {
public:
	Animal() {cout << "Animal constructor... Done!" << endl;};
};

class Mammal : public Animal {
public:
	Mammal() {cout << "Mamal constructor... Done!" << endl;}
	virtual void breathe() {cout << "It breathes..." << endl;};

};

class WingedAnimal : public Animal {
public:
	WingedAnimal() {cout << "WingedAnimal constructor... Done!" << endl;}
	virtual void flap() {cout << "It flaps..." << endl;};
};

class Bat : public Mammal, public WingedAnimal {

};

int main() {
	Bat bat;
    //Animal &mammal= bat;

}