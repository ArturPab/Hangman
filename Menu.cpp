#include "Menu.h"
#include "Game.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <string>

//Klawisze sterowania w Menu gry
enum class MenuControl
{
	KEY_UP = 119,
	KEY_DOWN = 115,
	ENTER = 13,
	ESC = 27
};

//Typ wyliczeniowy dla strza³ki w menu
enum class Menu {
	START = 1,
	TABLE = 2,
	RULES = 3,
	EXIT = 4
};

enum class Level {
	EASY = 1,
	MEDIUM = 2,
	HARD = 3
};
std::string getArrow() {
	return "  <-";
}

void clearScreen() {
	system("cls");
}

//Rysowanie menu
void drawMenu(Menu option) {

	clearScreen();
	std::cout << "\n\n\n\n";
	std::cout << std::setw(60) << std::setfill(' ') << "START";
	if (option == Menu::START)
		std::cout << getArrow();
	std::cout << std::endl;

	std::cout << std::setw(65) << std::setfill(' ') << "TABELA WYNIKOW";
	if (option == Menu::TABLE)
		std::cout << getArrow();
	std::cout << std::endl;

	std::cout << std::setw(63) << std::setfill(' ') << "ZASADY GRY";
	if (option == Menu::RULES)
		std::cout << getArrow();
	std::cout << std::endl;

	std::cout << std::setw(61) << std::setfill(' ') << "WYJSCIE";
	if (option == Menu::EXIT)
		std::cout << getArrow();
	std::cout << std::endl;

	std::cout << "\n\n\n\n";
}

//Podkreœlenie, która opcja w menu jest aktualnie wybrana
Menu changeMenuValue(int c, Menu option) {
	if (c == static_cast<int>(MenuControl::KEY_UP)) {
		if (option == Menu::START)
			option = Menu::EXIT;
		else if (option == Menu::EXIT)
			option = Menu::RULES;
		else if (option == Menu::RULES)
			option = Menu::TABLE;
		else if (option == Menu::TABLE)
			option = Menu::START;
	}
	else if (c == static_cast<int>(MenuControl::KEY_DOWN)) {
		if (option == Menu::EXIT)
			option = Menu::START;
		else if (option == Menu::START)
			option = Menu::TABLE;
		else if (option == Menu::TABLE)
			option = Menu::RULES;
		else if (option == Menu::RULES)
			option = Menu::EXIT;
	}

	return option;
}

//Funkcja sprawdza czy zosta³a naciœniêta strza³ka w górê albo w dó³ (W albo S)
bool ifArrow(int c) {
	if (c == static_cast<int>(MenuControl::KEY_UP) || c == static_cast<int>(MenuControl::KEY_DOWN))
		return true;
	return false;
}

//Funkcja sprawdza czy zosta³ naciœniêty ENTER
bool ifEnter(int c) {
	if (c == static_cast<int>(MenuControl::ENTER))
		return true;
	return false;
}

//Funkcja sprawdza czy zosta³ naciœniêty klawisz Escape
bool ifEscape(int c) {
	if (c == static_cast<int>(MenuControl::ESC))
		return true;
	return false;
}

//Wyswietla zasady gry
void openRules() {
	clearScreen();
	std::string rules;
	std::ifstream file;
	file.open("rules.txt", std::ios::in);
	do {
		if (file.is_open()) {
			while (!file.eof()) {
				getline(file, rules);
				std::cout << std::setw(10) << std::setfill(' ') << rules << std::endl;
			}
		}
	} while (!ifEscape(tolower(_getch())));
	file.close();
}

//Sprawdza czy juz dany gracz jest w najlepszych rezultatach
bool findBestPlayer(std::string* bestPlayers, std::string player) {
	for (int i = 0; i < 5; i++) {
		if (player == bestPlayers[i])
			return true;
	}
	return false;
}

void showBest(std::string bestPlayer, int best) {
	std::cout << bestPlayer << "\t" << best << std::endl;
}

void openResultTable() {
	do {
		clearScreen();
		std::fstream resultFile;
		int best{};

		std::string bestPlayer;
		int* bestResults = new int[5];
		std::string points;
		std::string* bestPlayers = new std::string[5];
		std::string player;
		for (int i = 0; i < 5; i++) {
			bestPlayer = "";
			best = 0;
			resultFile.open("result.txt", std::ios::in);
			if (resultFile.is_open()) {
				while (!resultFile.eof()) {
					std::getline(resultFile, points);
					std::getline(resultFile, player);
					if (atoi(points.c_str()) > best)
						if (!findBestPlayer(bestPlayers, player)) {
							bestPlayer = player;
							best = atoi(points.c_str());
						}
				}
			}
			resultFile.close();
			if (best != 0) {
				showBest(bestPlayer, best);
				bestPlayers[i] = bestPlayer;
				bestResults[i] = best;
			}
		}
		delete [] bestPlayers;
		delete [] bestResults;
	} while (!ifEscape(_getch()));
	
}

Level changeLevelMenuValue(int c, Level option) {
	if (c == static_cast<int>(MenuControl::KEY_UP)) {
		if (option == Level::EASY)
			option = Level::HARD;
		else if (option == Level::HARD)
			option = Level::MEDIUM;
		else if (option == Level::MEDIUM)
			option = Level::EASY;
	}
	else if (c == static_cast<int>(MenuControl::KEY_DOWN)) {
		if (option == Level::HARD)
			option = Level::EASY;
		else if (option == Level::EASY)
			option = Level::MEDIUM;
		else if (option == Level::MEDIUM)
			option = Level::HARD;
	}

	return option;
}

//Rysowanie wyboru poziomu trudnoœci
void drawLevelMenu(Level option) {

	clearScreen();
	std::cout << "\n\n\n\n";
	std::cout << std::setw(60) << std::setfill(' ') << "LATWY";
	if (option == Level::EASY)
		std::cout << getArrow();
	std::cout << std::endl;

	std::cout << std::setw(61) << std::setfill(' ') << "SREDNI";
	if (option == Level::MEDIUM)
		std::cout << getArrow();
	std::cout << std::endl;

	std::cout << std::setw(61) << std::setfill(' ') << "TRUDNY";
	if (option == Level::HARD)
		std::cout << getArrow();
	std::cout << std::endl;

	std::cout << "\n\n\n\n";
}

void chooseLevel() {
	Level move = Level::EASY;
	
	int c;

	bool exit = false;

	do {
		drawLevelMenu(move);
		c = tolower(_getch());
		if (ifArrow(c))
			move = changeLevelMenuValue(c, move);
		else if (ifEnter(c)) {
			if (move == Level::EASY) {
				startGame("easy.txt", 8);
				exit = true;
			}
			else if (move == Level::MEDIUM) {
				startGame("medium.txt", 22);
				exit = true;
			}
			else if (move == Level::HARD) {
				startGame("hard.txt", 36);
				exit = true;
			}
		}
		else if (ifEscape(c)) {
			exit = true;
		}
	} while (!exit);
}

void menu() {
	Menu move = Menu::START;
	int c;
	bool exit = false;
	do {
		drawMenu(move);
		c = tolower(_getch());
		if (ifArrow(c))
			move = changeMenuValue(c, move);
		else if (ifEnter(c)) {
			if (move == Menu::EXIT)
				exit = true;
			else if (move == Menu::RULES)
				openRules();
			else if (move == Menu::START)
				chooseLevel();
			else if (move == Menu::TABLE)
				openResultTable();
		}
	} while (!exit);
}

void openMenu() {
	menu();
}