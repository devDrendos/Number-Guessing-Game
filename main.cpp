//
// Created by Drendos
//

// Header Files:

#include "main.h" // Main Header File
#include "numberGuessingGame.h" // Number Guessing Game Header File
#include <iostream> // Input & Output Header File
#include <limits> // Query Property Header File

// Main Function used to execute the Number Guessing Game
// Contains the logic used to operate the menu
int main() {
    std::cout << "<<<<<<< Guess The Number >>>>>>>" << std::endl; // Outputs the title of the game
    int choice; // An intger variable is declared, this will hold the choice the user makes

    do { // Beggining of the Do-While loop
        std::cout << "1. Play - Computer Generates Range" << std::endl; // Outputs Option 1
        std::cout << "2. Play - Player Chooses Range" << std::endl; // Outputs Option 2
        std::cout << "3. Help" << std::endl; // Outputs Option 3
        std::cout << "4. Quit" << std::endl; // Outputs Option 4
        std::cout << "What would you like to do?" << std::endl;

        while (!(std::cin >> choice)) { // This inner while loop ensures that the program does not accept an non numeric value
            std::cout << "Error! You must enter a numeric value!" << std::endl; // If an non numeric value is entered, an error message is displayed
            std::cin.clear(); // The input stream is cleared using '.clear()'
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // The input buffer is cleared
        }

        switch (choice) { // Switch Case responsible for executing the corresponding function depending on which choice the user has selected
            case 1: // Case 1 will make a call to the computer driven game mode
                numberGameCompChoice();
            break;
            case 2: // Case 2 will make a call to the user and computer driven game mode
                numberGameUserChoice();
            break;
            case 3: // Case 3 will make a call to the function responsible for displaying how to play the game
                gameInstructions();
            break;
            case 4: // Case 4 is responsible for displaying a goodbye message to the user
                std::cout << "Goodbye!" << std::endl;
            break;
            default: // The Default Case is responsible for displaying an error message if the user chooses an invalid option
                std::cout << "This was not an option!" << std::endl;
            break;
        }
    } while (choice != 4); // The Do-While loop will execute as long as the user does not choose '4'
    return 0;
}