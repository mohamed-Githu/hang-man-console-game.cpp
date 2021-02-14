#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <fstream>

int wins = 0;
int losts = 0;
int blood = 7;
int count_letters;

using namespace std;

void winsAndlosts()
{
	cout << " Wins : " << wins << endl;
	cout << "Losts : " << losts << "\n\n";
}

int random()
{
	srand(time(NULL));
	return rand() % 994;
}

string word(int random_number)
{
	ifstream file("words.txt");
	int index = 0;
	string temp;

	file >> temp;

	while (index != random_number)
	{
		file >> temp;
		index++;
	}

	count_letters = temp.length();

	return temp;
}

void print_letters(string& guess)
{

	for (int x = 0; x < guess.length(); x++)
	{
		cout << guess[x] << " ";
	}
}

void print_result(string& guess, string& word)
{
	for (int x = 0; x < word.size(); x++)
	{
		bool con = false;
		for (int y = 0; y < guess.size(); y++)
		{
			if (word[x] == guess[y])
				con = true;
		}
		if (con)
			cout << word[x] << " ";
		else
			cout << "_ ";
	}
}

void check_letter(string& guess, string& letter, string& word)
{
	bool esisteNelleLettre = false;
	bool esisteNellaParola = false;
	int rightLetters = 0;

	for (int x = 0; x < guess.length(); x++)
	{
		if (letter[0] == guess[x])
			esisteNelleLettre = true;
	}


	for (int x = 0; x < word.length(); x++)
	{
		if (letter[0] == word[x]) {
			esisteNellaParola = true;
			rightLetters++;
		}
	}

	if (!esisteNellaParola && !esisteNelleLettre)
	{
		guess += letter[0];
		blood--;
	}
	else if (esisteNellaParola && !esisteNelleLettre)
	{
		guess += letter[0];
		count_letters -= rightLetters;
	}
}

void print_man(int x)
{
	switch (x)
	{
	case 7:
		cout << "\t____________\n";
		cout << "\t|          |\n";
		cout << "\t|\n";
		cout << "\t|\n";
		cout << "\t|\n";
		cout << "\t|\n";
		cout << "\t|\n";
		break;
	case 6:
		cout << "\t____________\n";
		cout << "\t|          |\n";
		cout << "\t|          O\n";
		cout << "\t|\n";
		cout << "\t|\n";
		cout << "\t|\n";
		cout << "\t|\n";
		break;
	case 5:
		cout << "\t____________\n";
		cout << "\t|          |\n";
		cout << "\t|          O\n";
		cout << "\t|          |\n";
		cout << "\t|\n";
		cout << "\t|\n";
		cout << "\t|\n";
		break;
	case 4:
		cout << "\t____________\n";
		cout << "\t|          |\n";
		cout << "\t|          O\n";
		cout << "\t|          |\n";
		cout << "\t|          |\n";
		cout << "\t|\n";
		cout << "\t|\n";
		break;
	case 3:
		cout << "\t____________\n";
		cout << "\t|          |\n";
		cout << "\t|          O\n";
		cout << "\t|          |\n";
		cout << "\t|         /|\n";
		cout << "\t|\n";
		cout << "\t|\n";
		break;
	case 2:
		cout << "\t____________\n";
		cout << "\t|          |\n";
		cout << "\t|          O\n";
		cout << "\t|          |\n";
		cout << "\t|         /|\\\n";
		cout << "\t|\n";
		cout << "\t|\n";
		break;
	case 1:
		cout << "\t____________\n";
		cout << "\t|          |\n";
		cout << "\t|          O\n";
		cout << "\t|          |\n";
		cout << "\t|         /|\\\n";
		cout << "\t|         /\n";
		cout << "\t|\n";
		break;
	case 0:
		cout << "\t____________\n";
		cout << "\t|          |\n";
		cout << "\t|          O\n";
		cout << "\t|          |\n";
		cout << "\t|         /|\\\n";
		cout << "\t|         / \\\n";
		cout << "\t|\n";
		break;
	}
}