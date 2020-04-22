#include <iostream>
using std::cout;

int main()
{
	const int ROWS = 5;
	const int COLS = 10;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j< COLS; j++) {
			cout << i << "," << j << " ";
		}
		cout << "\n";
	}
}
