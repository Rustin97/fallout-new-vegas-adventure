#include <iostream>
#include <cctype> // for tolower()
#include "adventure.h"

using namespace std;

int main() {
    Player player;
    player.score = 0;
    player.faction = "";

    cout << "Welcome to Fallout: New Vegas Adventure!\n";

    // Ask the user if they want to load a saved game.
    char loadChoice;
    cout << "Do you want to load a saved game? (Y/N): ";
    cin >> loadChoice;
    loadChoice = tolower(loadChoice);

    if (loadChoice == 'y') {
        loadGame(player);
    }

    // Get the player's name.
    cout << "\nEnter your Courier name: ";
    cin >> ws;  // clear any whitespace
    getline(cin, player.name);

    // Display introduction and play each mission.
    displayIntro();
    mission1(player);
    mission2(player);
    mission3(player);
    mission4(player);
    mission5(player);

    // Save progress.
    saveGame(player);

    // Ask if the player wants to play again (recursive input validation).
    if (askPlayAgain()) {
        cout << "\nRestarting game...\n\n";
        main();  // For simplicity in this demo, we call main recursively.
    } else {
        cout << "\nThanks for playing, " << player.name << "!\n";
    }

    return 0;
}