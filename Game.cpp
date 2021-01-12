#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <conio.h>
#include <iomanip>

//Gracz podaje nazwe
std::string enterUsername() {
	std::string username;
	do {
		std::cout << "Podaj nazwe uzytkownika:";
		std::getline(std::cin, username);
	} while (username.empty());
	return username;
}

//losuje numer s³owa spoœród amountOfWords (czyli tyle ile jest s³ów w pliku policzone na sztywno)
int drawWordNumber(int amountOfWords) {
	std::random_device device;
	std::mt19937 generator(device());
	std::uniform_int_distribution <int > distribution(1, amountOfWords);
	return distribution(generator);
}

//Sprawdza czy plik sie otworzyl i pobiera randomowe slowo z losowej linijki
bool getRandomWord(std::string easyWordFile, std::string& randomWord) {
	std::fstream file;
	file.open(easyWordFile, std::ios::in);
	if (file.is_open()) {
		for (int i = 0; i < drawWordNumber(9); i++) {
			std::getline(file, randomWord);
		}
		file.close();
		return true;
	}
	std::cout << "Blad podczas wczytywania slowa" << std::endl;
	return false;
}

//Wypisuje slowo za pomoc¹ liter lub ukrytego znaku
void writeHiddenWord(char* chars, int size) {
	std::cout << "\n\n\n\n";
	std::cout << std::setw(60) << std::setfill(' ');
	for (int i = 0; i < size; i++)
		std::cout << chars[i] << " ";
	std::cout << std::endl;
}

//Pobiera znak od uzytkownika
char enterChar() {
	std::cout << "\n\n";
	std::cout << std::setw(70) << std::setfill(' ');
	std::cout << "Nacisnij literke";
	return tolower(_getch());
}

//Sprawdza czy podany znak jest prawidlowy
bool isCharCorrect(char ch, std::string word) {
	for (int i = 0; i < word.size(); i++) {
		if (ch == word.at(i))
			return true;
	}
	return false;
}

//Ods³ania poprawne znaki
void discoverChars(char ch, char* chars, std::string word) {
	for (int i = 0; i < word.size(); i++)
		if (ch == word.at(i))
			chars[i] = ch;
}

//Funkcja zamienia s³owo w znak ukryty znak
void hideWord(char* chars, std::string word) {
	for (int i = 0; i < word.size(); i++) {
		if (word.at(i) == ' ')
			chars[i] = ' ';
		else
			chars[i] = '_';
	}
}

//Ca³y wisielec
void fullHangman() {
	std::cout << std::setw(63) << std::setfill(' ') << " ____" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |  O" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " | /|" << (char)92 << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |  |" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " | / " << (char)92 << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "___  " << std::endl;
}

void seventhPartOfHangman() {
	std::cout << std::setw(63) << std::setfill(' ') << " ____" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |  O" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " | /|" << (char)92 << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |  |" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   "<< std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "___  " << std::endl;
}

void sixthPartOfHangman() {
	std::cout << std::setw(63) << std::setfill(' ') << " ____" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |  O" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |  |" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |  |" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "___  " << std::endl;
}

void fifthPartOfHangman() {
	std::cout << std::setw(63) << std::setfill(' ') << " ____" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |  O" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "___  " << std::endl;
}

void forthPartOfHangman() {
	std::cout << std::setw(63) << std::setfill(' ') << " ____" << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "___  " << std::endl;
}

void thirdPartOfHangman() {
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "___  " << std::endl;
}

void secondPartOfHangman() {
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << " |   " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "___  " << std::endl;
}

void firstPartOfHangman() {
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "     " << std::endl;
	std::cout << std::setw(63) << std::setfill(' ') << "___  " << std::endl;
}




void drawHangmanElements(int elements) {
	std::cout << "\n\n\n\n";
	if (elements > 0) {
		if (elements == 8) {
			fullHangman();
		}
		else if (elements == 7) {
			seventhPartOfHangman();
		}
		else if (elements == 6) {
			sixthPartOfHangman();
		}
		else if (elements == 5) {
			fifthPartOfHangman();
		}
		else if (elements == 4) {
			forthPartOfHangman();
		}
		else if (elements == 3) {
			thirdPartOfHangman();
		}
		else if (elements == 2) {
			secondPartOfHangman();
		}
		else if (elements == 1) {
			firstPartOfHangman();
		}
	}
	else {
		std::cout << std::setw(60) << std::setfill(' ') << "     " << std::endl;
		std::cout << std::setw(60) << std::setfill(' ') << "     " << std::endl;
		std::cout << std::setw(60) << std::setfill(' ') << "     " << std::endl;
		std::cout << std::setw(60) << std::setfill(' ') << "     " << std::endl;
		std::cout << std::setw(60) << std::setfill(' ') << "     " << std::endl;
		std::cout << std::setw(60) << std::setfill(' ') << "     " << std::endl;
	}
}

//Funkcja sprawdza, czy gra jest zakoñczona
bool endOfGame(int errors, char* chars, std::string word) {
	std::cout << "\n\n";
	if (errors == 8) {
		std::cout << "\n\n";
		fullHangman();
		std::cout << "\n\n\n\n";
		std::cout << std::setw(60) << std::setfill(' ') << "Przegrales!" << std::endl;
		return true;
	}
	for (int i = 0; i < word.size(); i++)
		if (chars[i] != word.at(i))
			return false;
	std::cout << std::setw(60) << std::setfill(' ') << "Wygrales!" << std::endl;
	return true;
}


void showWrongLetters(char* chars, int errors) {
	std::cout << "\n\n";
	std::cout << std::setw(57) << std::setfill(' ');
	if (errors == 0)
		std::cout << "";
	else {
		for (int i = 0; i < errors; i++)
			std::cout << chars[i] << " ";
	}
	std::cout << std::endl;
}

bool isPlayerWinner(std::string player, char* chars, std::string word) {
	std::cout << "\n\n";
	for (int i = 0; i < word.size(); i++)
		if (chars[i] != word.at(i))
			return false;
	std::cout << "Wygrales!\n";
	return true;
}

bool isPlayerLooser(int errors) {
	clearScreen();
	std::cout << "\n\n";
	if (errors == 8) {
		fullHangman();
		std::cout << "\nPrzegrales!\n";
		return true;
	}
	return false;
}

void saveResult(std::string player, int points) {
	std::fstream resultFile;
	resultFile.open("result.txt", std::ios::app);

	if (resultFile.is_open()) {
		resultFile << points << "\n";
		resultFile << player << "\n";
		resultFile.close();
	}
}

bool endOfGame(std::string username, char* chars, std::string randomWord, int points, int errors) {
	if (isPlayerWinner(username, chars, randomWord)) {
		saveResult(username, points);
		return true;
	}
	else if (isPlayerLooser(errors))
		return true;

	return false;
}

void game(std::string username, std::string levelFileName, int levelPoints) {
	int numberOfErrors{};
	std::string randomWord;

	if (getRandomWord(levelFileName, randomWord)) {

		char* chars = new char[randomWord.size()];

		char wrongChars[8];

		int points = levelPoints;

		//Znak, który jest wprowadzany przez gracza
		char ch;

		bool end = false;

		hideWord(chars, randomWord);

		while (!end) {
			clearScreen();
			writeHiddenWord(chars, randomWord.size());

			drawHangmanElements(numberOfErrors);

			showWrongLetters(wrongChars, numberOfErrors);

			ch = enterChar();

			if (isCharCorrect(ch, randomWord))
				discoverChars(ch, chars, randomWord);
			else {
				wrongChars[numberOfErrors] = ch;
				numberOfErrors += 1;
				points -= 1;
			}

			if (endOfGame(username, chars, randomWord, points, numberOfErrors))
				end = true;

		}
		system("pause");
	}
}

//Wprowadzenie nazwy gracza oraz rozpoczêcie gry
void startGame(std::string levelFileName, int points) {
	clearScreen();
	std::string username = enterUsername();
	game(username, levelFileName, points);
}