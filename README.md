# Hangman
Console game developed in C++.

This project was created as a final project for studies.

## General Info
Project that I realized is a game called "Hangman". The goal of the game is to guessing letters to find the word. Difficult of word depends on choose level.

## Assumptions
- Main menu, where it is possible to move by clicking W and S, it has following options:
  - Start game
  - Score table
  - Rules
  - Exit
- The game lasts up to eight wrong letters or to guess the whole word
- Correct and wrong letters appears on the screen
- Score is saved in result.txt
- Score table consists of five best results
- Score depends on difficulty level
- Word difficulty level is choose by player on start of the game

## Files
- Hangman.cpp - main source file, where the program starts - during starting the program, it starts function menu() from Menu.cpp
- Menu.h - header file, which has menu() function. It connects Menu.cpp with Hangman.cpp
- Menu.cpp - source file, created mainly for moving in Menu. It has functions, which create menu and Enum classes to move by W and S, it also has openResultTable() function to read score file. OpenRules() function displays rules. Start option starts chooseLevel() function, where is startGame(std::string levelFileName) function (levelFileName depends on choose level by player.
- Game.h - header file, which has startGame() function. It connects Game.cpp with Menu.cpp
- Game.cpp - source file, which has funtions that create the Hangman game. It reads words from hard.txt, medium.txt, easy.txt and save scores to result.txt. Drawing a part of hangman depends on number of mistake, which had been made. When player would guess the letter, it will appear in all correct places.
- Result.txt – text file with players and scores
- Rules.txt – text file with rules
- Easy.txt – text file with easy words
- Medium.txt – text file with medium words
- Hard.txt – text file with hard words

## Summary
Application can be expanded into graphic form to be more comfortable for players and look more clearer. 

