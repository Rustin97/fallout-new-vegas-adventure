#ifndef ADVENTURE_H
#define ADVENTURE_H

#include <string>
using namespace std;

// There are 5 missions in this adventure.
const int NUM_MISSIONS = 5;

// Structure to hold the player's data.
struct Player {
    string name;
    string faction;
    int score;
};

// Display the introduction text.
void displayIntro();

// Mission functions for each stage of the story.
void mission1(Player &player);
void mission2(Player &player);
void mission3(Player &player);
void mission4(Player &player);
void mission5(Player &player);

// File handling functions.
void saveGame(const Player &player);
void loadGame(Player &player);

// Overloaded printMessage functions.
// One prints the message once and the other prints it a specified number of times.
void printMessage(const string &msg);
void printMessage(const string &msg, int times);

// Recursively asks the player if they want to play again.
bool askPlayAgain();

#endif // ADVENTURE_H
