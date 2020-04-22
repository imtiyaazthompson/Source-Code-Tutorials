#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	string user_choice;
	string unjumbled_word = "constantinople";
	string jumbled_word = unjumbled_word;
	int turns = 0;
	int word_len = unjumbled_word.size();

	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < word_len; i++) {
		//random swaps
		//Indexing strings return chars
		char tmp = jumbled_word[i];
		int r = rand() % word_len;
		jumbled_word[i] = jumbled_word[r];
		jumbled_word[r] = tmp;
	}

	cout << "Unjumble this word: " << jumbled_word << endl;
	cout << "\'quit\' to exit" << endl;
	do {
		cout << "Answer: ";
		cin >> user_choice;
		turns++;

		if (user_choice == "quit") {
			break;
		} else if (user_choice != unjumbled_word) {
			cout << "Try again" << endl;
		}
	} while (user_choice != unjumbled_word);

	if (user_choice == "quit") {
		cout << "You quit after " << turns << " turns" << endl;
	} else {
		cout << "Congratulations, you completed after " << turns << " turns" << endl;
	}
	return 0;
}
