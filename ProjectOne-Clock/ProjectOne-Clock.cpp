// ProjectOne-Clock.cpp
// Jarrod Thomisee

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

void printTime(tm *current_time) {
	char buffer_24[256];
	char buffer_12[256];
	strftime(buffer_12, 80, "%I:%M:%S %p", current_time);
	strftime(buffer_24, 80, "%H:%M:%S", current_time);
	system("cls");
	cout << "\n\n\n**************************     **************************\n";
	cout << "*      12-Hour Clock     *     *      24-Hour Clock     *\n";
	cout << "*      " << buffer_12 << "       *     *      " << buffer_24 << "          *";
	cout << "\n**************************";
	
	cout << "     **************************";
}

void addHour(tm* current_time) {

	current_time->tm_hour = (current_time->tm_hour + 1) % 24;
}

void addMinute(tm* current_time) {

	if (current_time->tm_min == 59) {
		addHour(current_time);
	}
	current_time->tm_min = (current_time->tm_min + 1) % 60;
}

void addSecond(tm* current_time) {

	if (current_time->tm_sec == 59) {
		addMinute(current_time);
	}
	current_time->tm_sec = (current_time->tm_sec + 1) % 60;
}

void menu() {
	cout << "\n\n\n\n**************************\n";
	cout << "*  1 - Add One Hour      *\n";
	cout << "*  2 - Add One Minute    *\n";
	cout << "*  3 - Add One Second    *\n";
	cout << "*  4 - Exit Program      *\n";
	cout << "**************************\n";
}

int getUserChoice() {
	int choice = 0;
	cout << "Which do you want to do? ";
	cin >> choice;

	return choice;
}

int main()
{
	time_t t = time(NULL);
	tm* tm_local = localtime(&t);
	printTime(tm_local);

	int choice = 0;
	while (choice != 4) {
		menu();
		choice = getUserChoice();

		switch (choice) {
		case 1:
			addHour(tm_local);
			printTime(tm_local);
			break;
		case 2:
			addMinute(tm_local);
			printTime(tm_local);
			break;
		case 3:
			addSecond(tm_local);
			printTime(tm_local);
			break;
		case 4:
			break;
		default:
			cout << "Invalid Choice";
			printTime(tm_local);
			break;

		}
	}
	return 0;
}