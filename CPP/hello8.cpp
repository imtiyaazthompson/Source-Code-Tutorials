#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

int main()
{
	vector<string> basket;
	vector<string>::iterator i;
	vector<string>::const_iterator j;
	string user_input;

	cout << "Items in basket: " << basket.size() << endl;
	cout << "Add some fruit, type \'stop\' when finished" << endl;

	while (true) {
		cout << "Fruit: ";
		cin >> user_input;
	
		if (user_input == "stop") {
			break;
		} else {
			basket.push_back(user_input);
		}
	}

	cout << "Items in basket: " << basket.size() << endl;
	for (j = basket.begin(); j != basket.end(); j++) {
		if (j != basket.end() - 1) {
			cout << *j << ", ";
		} else {
			cout << *j << endl;
		}
	}

	cout << "Replace the fruit in the beginning with bread" << endl;
	i = basket.begin();
	*i = "bread";
	
	cout << "Items in basket: " << basket.size() << endl;
	for (j = basket.begin(); j != basket.end(); j++) {
		if (j != basket.end() - 1) {
			cout << *j << ", ";
		} else {
			cout << *j << endl;
		}
	}

	return 0;
}
