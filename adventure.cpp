#include "adventure.h"
#include <iostream>
#include <fstream>
#include <cctype> // for tolower()

using namespace std;

// Overloaded function: prints the message once.
void printMessage(const string &msg) {
    cout << msg;
}

// Overloaded function: prints the message 'times' number of times.
void printMessage(const string &msg, int times) {
    for (int i = 0; i < times; i++) {
        cout << msg;
    }
}

// Displays the game introduction.
void displayIntro() {
    printMessage("Welcome, Courier, to the Mojave Wasteland!\n");
    printMessage("In this adventure inspired by Fallout: New Vegas, you'll complete 5 missions that shape your destiny.\n");
    printMessage("Your choices determine your fate—and your final score.\n\n");
}

// Mission 1: The Awakening.
void mission1(Player &player) {
    printMessage("Mission 1: The Awakening\n");
    printMessage("You awaken on a dusty road with a pounding headache. Memories are hazy...\n");
    printMessage("Do you:\n");
    printMessage("  1. Search the surroundings for clues.\n");
    printMessage("  2. Press on, hoping to find help.\n");

    int choice;
    // Input validation for choice.
    while (true) {
        cout << "Enter your choice (1 or 2): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
            continue;
        }
        if (choice == 1 || choice == 2)
            break;
        else
            cout << "Please choose either 1 or 2.\n";
    }

    if (choice == 1) {
        printMessage("You discover a torn note hinting at an old betrayal. (+20 points)\n");
        player.score += 20;
    } else {
        printMessage("You ignore the clues and move on quickly. (+10 points)\n");
        player.score += 10;
    }
}

// Mission 2: The Ambush.
void mission2(Player &player) {
    printMessage("\nMission 2: The Ambush\n");
    printMessage("While traversing the Mojave, you’re ambushed by ruthless raiders!\n");
    printMessage("Do you:\n");
    printMessage("  1. Stand your ground and fight.\n");
    printMessage("  2. Try to hide and evade the enemy.\n");

    int choice;
    while (true) {
        cout << "Enter your choice (1 or 2): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
            continue;
        }
        if (choice == 1 || choice == 2)
            break;
        else
            cout << "Please choose either 1 or 2.\n";
    }

    if (choice == 1) {
        printMessage("You engage in battle and defeat the raiders with valor. (+30 points)\n");
        player.score += 30;
    } else {
        printMessage("You slip away quietly, but the chance for glory is missed. (+15 points)\n");
        player.score += 15;
    }
}

// Mission 3: Factions and Allegiance.
void mission3(Player &player) {
    printMessage("\nMission 3: Factions and Allegiance\n");
    printMessage("At a crossroads of destiny, several factions vie for control of New Vegas.\n");
    printMessage("Choose your faction:\n");

    const int NUM_FACTIONS = 4;
    string factions[NUM_FACTIONS] = {
        "New California Republic (NCR)",
        "Caesar's Legion",
        "Mr. House",
        "Independent (Yes Man)"
    };

    for (int i = 0; i < NUM_FACTIONS; i++) {
        cout << "  " << i + 1 << ". " << factions[i] << "\n";
    }

    int choice;
    while (true) {
        cout << "Enter your faction choice (1-" << NUM_FACTIONS << "): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number between 1 and " << NUM_FACTIONS << ".\n";
            continue;
        }
        if (choice >= 1 && choice <= NUM_FACTIONS)
            break;
        else
            cout << "Please choose a valid option.\n";
    }

    player.faction = factions[choice - 1];
    printMessage("Faction selected: " + player.faction + "\n");

    // Award bonus points based on faction choice.
    if (player.faction == "New California Republic (NCR)")
        player.score += 25;
    else if (player.faction == "Caesar's Legion")
        player.score += 20;
    else if (player.faction == "Mr. House")
        player.score += 30;
    else
        player.score += 15;
}

// Mission 4: The Casino Heist.
void mission4(Player &player) {
    printMessage("\nMission 4: The Casino Heist\n");
    printMessage("New Vegas glitters with neon lights—and rumors fly of a daring casino heist.\n");
    printMessage("Do you:\n");
    printMessage("  1. Formulate a high-risk plan for a massive payoff.\n");
    printMessage("  2. Gather intelligence and proceed carefully.\n");

    int choice;
    while (true) {
        cout << "Enter your choice (1 or 2): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
            continue;
        }
        if (choice == 1 || choice == 2)
            break;
        else
            cout << "Please choose either 1 or 2.\n";
    }

    if (choice == 1) {
        printMessage("Your daring heist pays off big! (+40 points)\n");
        player.score += 40;
    } else {
        printMessage("You play it safe, earning moderate rewards. (+25 points)\n");
        player.score += 25;
    }
}

// Mission 5: The Final Confrontation.
void mission5(Player &player) {
    printMessage("\nMission 5: The Final Confrontation\n");
    printMessage("The final showdown is at hand. Your decisions here determine your fate once and for all.\n");
    printMessage("Do you:\n");
    printMessage("  1. Launch a head-on assault against your enemies.\n");
    printMessage("  2. Outsmart your foes with brilliant tactics.\n");

    int choice;
    while (true) {
        cout << "Enter your choice (1 or 2): ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter 1 or 2.\n";
            continue;
        }
        if (choice == 1 || choice == 2)
            break;
        else
            cout << "Please choose either 1 or 2.\n";
    }

    if (choice == 1) {
        printMessage("Your brute force victory earns you epic renown! (+50 points)\n");
        player.score += 50;
    } else {
        printMessage("Your intelligence wins the day with a clever victory. (+35 points)\n");
        player.score += 35;
    }

    printMessage("\nGame Over. Final Score: " + to_string(player.score) + "\n");
}

// Saves the current game state to a file.
void saveGame(const Player &player) {
    ofstream outFile("savegame.txt");
    if (!outFile) {
        cout << "Error saving game.\n";
        return;
    }
    outFile << player.name << "\n"
            << player.faction << "\n"
            << player.score << "\n";
    outFile.close();
    cout << "Game saved successfully.\n";
}

// Loads a saved game from file, if available.
void loadGame(Player &player) {
    ifstream inFile("savegame.txt");
    if (!inFile) {
        cout << "No saved game found.\n";
        return;
    }
    getline(inFile, player.name);
    getline(inFile, player.faction);
    inFile >> player.score;
    inFile.close();
    cout << "Loaded Game Data:\n";
    cout << "  Courier Name: " << player.name << "\n";
    cout << "  Faction: " << player.faction << "\n";
    cout << "  Score: " << player.score << "\n";
}

// Recursively asks if the user wants to play again.
bool askPlayAgain() {
    char choice;
    cout << "\nWould you like to play again? (Y/N): ";
    cin >> choice;
    choice = tolower(choice);
    if (choice == 'y')
        return true;
    else if (choice == 'n')
        return false;
    else {
        cout << "Invalid input. ";
        return askPlayAgain();
    }
}
