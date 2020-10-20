#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <random>
#include <ctime>
#include <string>


std::vector <int> oneToTwenty(10);
std::vector <std::string> asterixPrint;
std::string t2Temp;

namespace Task2Random {
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}
int task2RandomNumber() {
	std::uniform_int_distribution<>die{ 1,20 };
	return die(Task2Random::mersenne);
}

void Task2();
void Task2() {
	t2Temp.clear();
	asterixPrint.clear();


	system("cls");
	for (int i = 0; i < oneToTwenty.size(); i++) {
		oneToTwenty.at(i) = task2RandomNumber();
	}

	for (int i = 0; i < oneToTwenty.size(); i++) {
		t2Temp.clear();
		for (int j = 0; j < oneToTwenty.at(i); j++) {
			t2Temp += "*";
		}
		asterixPrint.push_back(t2Temp);
	}

	for (int i = 0; i < oneToTwenty.size(); i++) {
		std::cout << oneToTwenty.at(i) << '\t';

		std::cout << asterixPrint.at(i) << '\n';


		std::cout << '\n';
	}
	std::cout << "Next up is sorting these vectors\n";
	system("pause");
	system("cls");

	std::sort(oneToTwenty.begin(), oneToTwenty.end());
	std::sort(asterixPrint.begin(), asterixPrint.end());
	for (int i = 0; i < oneToTwenty.size(); i++) {
		std::cout << oneToTwenty.at(i) << '\t';

		std::cout << asterixPrint.at(i) << '\n';


		std::cout << '\n';
	}

	system("pause");

}
