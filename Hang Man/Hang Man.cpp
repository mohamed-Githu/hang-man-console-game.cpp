#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include "Header.h"

extern int blood;
extern int count_letters;
extern int wins;
extern int losts;

using namespace std;

int main() {

	bool answer = true;

	while (answer)
	{
		int ans;

		string gues, le;
		string parola = word(random());
		system("CLS");

		while (blood >= 0)
		{
			winsAndlosts();

			if (blood == 0)
			{
				losts++;

				system("cls");

				winsAndlosts();
				print_man(blood);

				cout << "\n\nthe word is : " << parola;

				cout << "\n\nEnterd letters : ";
				print_letters(gues);

				break;
			}

			print_man(blood);

			cout << "\n\nGuess the word : ";
			print_result(gues, parola);

			cout << "\n\nEnterd letters : ";
			print_letters(gues);

			cout << "\n\nEnter a letter : ";
			cin >> le;
			le[0] = tolower(le[0]);

			check_letter(gues, le, parola);

			if (count_letters == 0)
			{
				wins++;

				system("cls");

				winsAndlosts();

				print_man(blood);

				cout << "\n\nThe word is : ";
				print_result(gues, parola);

				cout << "\n\nEnterd letters : ";
				print_letters(gues);

				break;
			}

			system("CLS");
		}

		if (blood > 0)
		{
			cout << "\n\nYOU WON !\nWanna try agaim ?\nYES [1]     NO [2]\nAnswer : ";
			cin >> ans;
		}
		else
		{
			cout << "\n\nYOU LOST !\nWanna try agaim ?\nYES [1]     NO [2]\nAnswer : ";
			cin >> ans;
		}

		answer = ans == 1 ? true : false;

		blood = 7;
	}

	return 0;
}