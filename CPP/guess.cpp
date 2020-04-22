#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	//Seed RNG
	srand(static_cast<unsigned int>(time(0)));
	//Generate Random Number from 1 to 100
	int magic_number = (rand()%100) + 1;
	//Variable to get user choice
	int user_choice;
	int turns = 0;
	int closeness = 0; //Variable used to track how close you are to the magic number
	bool is_first_guess = true; //Only display closeness from second guess onward

	//Introduction
	cout << "Can you guess the magic number between 1 and 100?" << endl;

	//First get user choice then loop
	do {
		cout << "Guess: ";
		//Get user number
		cin >> user_choice;
		//Increment turn counter
		turns++;
	
		//Calculate new closeness
		int previous_closeness = closeness;
		if (user_choice > magic_number) {
			closeness = user_choice - magic_number;
		} else if (user_choice < magic_number) {
			closeness = magic_number - user_choice;
		}

		//Evaluate closeness only from the second guess onward
		if (is_first_guess == false) {
			if (closeness < previous_closeness) {
				cout << "Getting closer..." << endl;
			} else if (closeness > previous_closeness){
				cout << "Getting farther..." << endl;
			}
		} else {
			is_first_guess = false;
		}
	
		if (user_choice != magic_number) {
			//Give feedback
			cout << "Wrong! Guess again\n" << endl;
		}
	} while (user_choice != magic_number);

	cout << "Congratualtions, you guessed it right after " << turns << " turns" << endl;
	return 0;
}
