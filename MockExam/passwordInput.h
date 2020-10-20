#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>


bool passwordCorrect = false;
int pwMoves;
int pwTries = 3;
char pwPlacement = '*';
char passwordInput;
int placement;
std::vector <char> pwTable;
std::vector <bool> pwTableTaken(9);

void enterPassword();
void enterPassword() {
	do {

		system("cls");
		std::cout << "Please enter the password\n";
		std::cout << "Move around with W-A-S-D\n\n";
		pwTable = { '1','2','3','4','5','6','7','8','9' };
		pwTable.at(placement) = pwPlacement;
		pwTableTaken.at(placement) = true;

		for (int i = 0; i < 9; i++) {
			if (i % 3 == 0 && i != 0) {
				std::cout << "\n";
			}

			std::cout << pwTable.at(i) << ' ';
		}
		std::cout << '\n';
		if (pwMoves == 4) {
			std::cout << '\n';
			if (pwTableTaken.at(0) && pwTableTaken.at(1) && pwTableTaken.at(2) && pwTableTaken.at(3) && pwTableTaken.at(4)) {
				passwordCorrect = true;
				std::cout << "Welcome\n";
				system("pause");
				return;
			}
			else {
				for (int i = 0; i < pwTable.size(); i++) {
					pwTableTaken.at(i) = false;
				}
				pwTries--;
				placement = 0;
				pwMoves = 0;
				std::cout << "Wrong Input\n";
				system("pause");
			}
		}
		if (pwTries == 0) {
			std::cout << "\nToo many tries, you're locked out\n\n";
			passwordCorrect = false;
			return;
		}


		passwordInput = _getch();

		switch (passwordInput)
		{
		case'w':case'W':
			if (placement <= 2) {
				break;
			}
			placement -= 3;
			pwMoves++;
			break;

		case's':case'S':
			if (placement >= 6) {
				break;
			}
			placement += 3;
			pwMoves++;
			break;

		case'd':case'D':
			if (placement == 2 || placement == 5 || placement == 8) {
				break;
			}
			placement += 1;
			pwMoves++;
			break;

		case'a':case'A':
			if (placement == 0 || placement == 3 || placement == 6) {
				break;
			}
			placement -= 1;
			pwMoves++;
			break;

		/*case'e':case'E':
			if (pwMoves == 4) {
				std::cout << '\n';
				if (pwTableTaken.at(0) && pwTableTaken.at(1) && pwTableTaken.at(2) && pwTableTaken.at(3) && pwTableTaken.at(4)) {
					passwordCorrect = true;
					return;
				}
				else {
					for (int i = 0; i < pwTable.size(); i++) {
						pwTableTaken.at(i) = false;
					}
					pwTries--;
					placement = 0;
					pwMoves = 0;
					std::cout << "Wrong\nPress Enter to Coninue\n";
					std::cin.ignore();
				}
			}
			else {
				for (int i = 0; i < pwTable.size(); i++) {
					pwTableTaken.at(i) = false;
				}
				pwTries--;
				placement = 0;
				pwMoves = 0;
				std::cout << "Wrong\nPress Enter to Coninue\n";
				std::cin.ignore();
			}
			break;*/

		default:
			break;
		}


	} while (true);

	return;
}
