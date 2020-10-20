// MockExam
#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <random>
#include <ctime>
#include <string>

#include "passwordInput.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"


char menuInput;


int main()
{
	enterPassword();
	if (passwordCorrect) {
		do {
			system("cls");
			std::cout << "Which task would you like to see?\n1. Task 1\n2. Task 2\n3. Task 3 & 4\n4. Exit\n";

			menuInput = _getch();

			switch (menuInput)
			{
			case'1':
				Task1();
				break;
			case'2':
				Task2();
				break;
			case'3':
				Task3();
				break;
			case'4':
				return 0;
				break;
			default:
				std::cout << "Wrong input\tTry again\n";
				system("pause");
				break;
			}
		} while (true);
	}else if (!passwordCorrect) {
		return 0;
	}
	return 0;
}


