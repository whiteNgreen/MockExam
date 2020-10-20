#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <random>
#include <ctime>

std::vector <int> vDiceRolls(2000);
std::vector <int> rollsPrint(6);
namespace Task1Random {
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}
int diceRoll() {
	std::uniform_int_distribution<>die{ 1,6 };
	return die(Task1Random::mersenne);
}
void Task1();
void Task1() {
	system("cls");
	//	Resets both vectors
	for (int i = 0; i < vDiceRolls.size(); i++) {
		vDiceRolls.at(i) = 0;
	}
	for (int i = 0; i < rollsPrint.size(); i++) {
		rollsPrint.at(i) = 0;
	}

	for (int i = 0; i < vDiceRolls.size(); i++) {
		vDiceRolls.at(i) = diceRoll();
	}

	for (int i = 0; i < vDiceRolls.size(); i++) {
		for (int j = 0; j < rollsPrint.size(); j++) {
			if (vDiceRolls.at(i) == j + 1) {
				rollsPrint.at(j)++;
			}
		}
	}

	for (int i = 0; i < rollsPrint.size(); i++) {
		std::cout << i + 1 << ": " << rollsPrint.at(i) << " times\n";
	}
	std::cout << '\n' << "The dice was rolled " << vDiceRolls.size() << " times\n";
	std::cout << '\n';

	system("pause");
}

