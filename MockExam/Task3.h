#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <random>
#include <ctime>
#include <string>

char t3Input;
int t3Temp1;
int t3Temp2;

namespace Task3Random {
	std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}
int pointPlacement() {
	std::uniform_int_distribution<>die{ 1,8 };
	return die(Task3Random::mersenne);
}

void Task3();
void Task3() {
	int t3Points = 0;

	char grid[10][10] = {
	 {'|','#','#','#','#','#','#','#','#','|'},
	 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
	 {'|','#','#',' ','#','#','#','#','#','|'},
	 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
	 {'|',' ','|',' ','|','#','#','#','|','|'},
	 {'|',' ','|',' ','|',' ',' ',' ','|','|'},
	 {'|',' ','|',' ',' ',' ',' ',' ',' ','|'},
	 {'|',' ',' ',' ',' ',' ',' ',' ',' ','|'},
	 {'|',' ',' ','#','#','#','#','#',' ','|'},
	 {'|','#','#','#','#','#','#','#','#','|'},
	};

	int posX = 2; int posY = 2;
	char player = 'E';
	for (int i = 0; i < 5; i++) {
		t3Temp1 = pointPlacement();
		t3Temp2 = pointPlacement();
		while (grid[t3Temp1][t3Temp2] == '#' || grid[t3Temp1][t3Temp2] == '|') {
			while (t3Temp1 == posX && t3Temp2 == posY) {
				t3Temp1 = pointPlacement();
				t3Temp2 = pointPlacement();
			}
			t3Temp1 = pointPlacement();
			t3Temp2 = pointPlacement();
		}
		grid[t3Temp1][t3Temp2] = '-';
	}
	do {
		system("cls");
		std::cout << "Use W-A-S-D to move around\n\nPress Q to Quit\n\n";
		grid[posX][posY] = player;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				std::cout << grid[i][j];
			}
			std::cout << '\n';
		}


		std::cout << "\nPlayer Score: " << t3Points << '\n';

		t3Input = _getch();

		switch (t3Input)
		{
		case'w':case'W':
			if (grid[posX - 1][posY] == '#' || grid[posX - 1][posY] == '|') {
				posX;
				break;
			}
			else {
				grid[posX][posY] = ' ';
				posX--;
			}
			break;
		case's':case'S':
			if (grid[posX + 1][posY] == '#' || grid[posX + 1][posY] == '|') {
				posX;
				break;
			}
			else {
				grid[posX][posY] = ' ';
				posX++;
			}
			break;
		case'd':case'D':
			if (grid[posX][posY + 1] == '#' || grid[posX][posY + 1] == '|') {
				posX;
				break;
			}
			else {
				grid[posX][posY] = ' ';
				posY++;
			}
			break;
		case'a':case'A':
			if (grid[posX][posY - 1] == '#' || grid[posX][posY - 1] == '|') {
				posX;
				break;
			}
			else {
				grid[posX][posY] = ' ';
				posY--;
			}
			break;
		case'q':case'Q':
			return;
			break;
		default:
			break;
		}
		if (grid[posX][posY] == '-') {
			t3Points += 5;
		}
	} while (true);
}
