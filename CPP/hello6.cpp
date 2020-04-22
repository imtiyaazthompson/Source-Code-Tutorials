#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	const int MAX = 10;
	string inventory[MAX];

	for (int i = 0; i < MAX; i++) {
		cout << "Item Name: ";
		cin >> inventory[i];
		cout << inventory[i] << " added." << endl;
	}

	return 0;
}
