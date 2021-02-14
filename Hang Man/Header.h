#pragma once
#include <string>

using namespace std;

void winsAndlosts();
int random();
string word(int);
void print_letters(string& guess);
void print_result(string& guess, string& word);
void print_man(int);
void check_letter(std::string& guess, string& letter, string& word);