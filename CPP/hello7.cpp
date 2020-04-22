#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
	vector<string> inventory;

	cout << "Current equipment load: " << inventory.size() << endl;
	cout << "Picked up standard adventurer gear" << endl;

	inventory.push_back("sword");
	inventory.push_back("shield");
	inventory.push_back("potion");

	cout << "Current equipment load: " << inventory.size() << endl;
	cout << "Loadout: ";
	for (int i = 0; i < inventory.size(); i++) {
		if (i != inventory.size() - 1) {
			cout << inventory[i] << ", ";
		} else {
			cout << inventory[i] << endl;
		}
	}

	cout << "Used a potion" << endl;
	inventory.pop_back();
	cout << "Current equipment load: " << inventory.size() << endl;
	
	return 0;
}
