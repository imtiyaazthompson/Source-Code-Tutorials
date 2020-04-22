#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
	int ammo = 273;
	typedef short int tiny_t; //seperate to declaration
	tiny_t lives = 3;
	double fuel;
	char callsign = 'c';
	bool is_alive = true;

	cout << "Bullets in the chamber: " << ammo << endl;
	cout << "Lives left: " << lives << endl;
	cout << "Rookie " << callsign << ", is he still kicking? " << is_alive << endl;

	cout << "Rookie, how much fuel you still packing? " << endl;
	cout << "Fuel: ";
	cin >> fuel;
	cout << "Copy that, Rookie has " << fuel << " left" << endl;
	return 0;
}
