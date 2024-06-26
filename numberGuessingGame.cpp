//
// Created by Drendos
//

// Header Files:

#include "numberGuessingGame.h" // Number Guessing Game Header File
#include <iostream> // Input & Output Header File
#include <random> // Random Header File
#include <stdexcept> // Exceptions Header File

// Function responsible for the game mode where the user chooses a randomly generated number between a preset range
// (1 - 100), and the user attempts to guess this number.
void numberGameCompChoice() { // Returns 'void', no value.
    std::cout << "Thinking of numbers.." << std::endl; // Displays that the computer is generating a number

    try { // Beggining of the try block, monitoring for exceptions that may be thrown.
        std::random_device rd; // Generates the random number which is used to seed the random number engine.
        std::mt19937 gen(rd()); // Mersenne Twister Engine/Algorithm which is seeded with 'rd'.

        std::uniform_int_distribution<int> dis(1, 100); // Defines the range/distribution of numbers the random number can be between.

        int randomNumber = dis(gen); // Assigns the randomly generated number using the random engine 'gen' to the newly declared and initialized integer variable 'randomNumber'.
        int guess; // Declares an integer variable 'guess' which will hold the number the user guesses.
        int attempts = 0; // Declares and initializes an intger variable 'attempts' to 0 which will represent the number of attempts it takes the user to guess the number.
        bool gameOver = false; // Declares and initializes a boolean variable to false which will represent whether the game has ended or not.

        while (!gameOver) { // While loop which will execute as long as 'gameOver' is not true, where 'gameOver' will only be true if the user guesses the correct number.
            std::cout << "Enter your guess: (Between 1 - 100): " << std::endl; // Output prompting the user to enter a number between 1 and 100.

            while (!(std::cin >> guess)) { // Inner While Loop used to validate the value the user enters as their guess.
                std::cout << "Error! You must enter a numeric value." << std::endl; // If the user enters an invalid value, the condition will evaluate to true, continuing the validation loop.
                std::cin.clear(); // Clears the error state/flag.
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the invalid input entered by the user from the input stream.
            }

            attempts++; // For every attempt the user makes, the 'attempts' variable is incremented.

            if (guess < 1 || guess > 100) { // If statement checks if the user makes an invalid guess, lower or higher than the given range.
                throw std::out_of_range("This number is out of range. Must be between 1 - 100!"); // If the user enters an invalid number, an out of range exception is thrown.
            }

            if (guess < randomNumber) { // This if statement checks if the users guess is less than the randomly generated number.
                std::cout << "Your guess was too low! Try again!" << std::endl; // The user will be prompted that their guess was too low.
            } else if (guess > randomNumber) { // If the users guess was larger than the random number, they will be prompted that the guess was too high.
                std::cout << "Your guess was too high! Try again!" << std::endl;
            } else { // If the user guesses the correct number, the else block is executed.
                std::cout << "Congratulations! You guessed the random number: " << randomNumber << ", in " << attempts << " attempts!" << std::endl; // The user will be prompted that they guessed the correct number, in however many attempts.
                gameOver = true; // Since the user has guessed the correct number, the game will end and they will be brought back to the menu option.
            }
        }
    } catch (const std::exception& e) { // The catch block will 'catch' any exceptions that may have been thrown inside of the try block.
        std::cerr << "An Exception was caught! This was why: " << e.what() << std::endl; // If an exception was thrown and caught by the catch block, an error message is output and the reason for the error will be too.
    }
}

// Function responsible for the game mode where the user chooses a randomly generated number between a range which is
// entered by the user. The user will attempt to guess this number.
void numberGameUserChoice() {
    int highNum; // Declaration of a variable of type int which will be the lowest number the random number could be.
    int lowNum; // Declaration of a a variable of type int which will be the largest number the randomly generated number can be.

    std::cout << "Enter the lowest number it can be: " << std::endl; // Prompts the user to enter the lowest number in the range.
    while (!(std::cin >> lowNum)) { // While loop used to validate the input from the user.
        std::cout << "Error! You must enter a numeric value." << std::endl; // If the user enters an invalid value, the condition will evaluate to true, continuing the validation loop.
        std::cin.clear(); // Clears the flags/state of the error from the input stream.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores any other invalid input from the input buffer.
    }

    std::cout << "Enter the highest number it can be: "  << std::endl; // Prompts the user to enter the largest number in the range that the random number could be.

    while (!(std::cin >> highNum)) { // While loop used to validate the input from the user.
        std::cout << "Error! You must enter a numeric value." << std::endl; // If the user enters an invalid value, the condition will evaluate to true, continuing the validation loop.
        std::cin.clear(); // Clears the flags/state of the error from the input stream.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores any other invalid input from the input buffer.
    }

    try { // Start of the try block which, any exception thrown will be caught by the catch block
        if (lowNum >= highNum) { // This if statement checks if the value entered as the lowest number in the range is greater than, or equal to the highest number in range.
            throw std::invalid_argument("The lower number must be less than the higher number! Try again!"); // If this is the case, an invalid argument exception is thrown.
        }

        std::cout << "Thinking of a number.." << std::endl; // Prompts the user that a random number is being generated.

        std::random_device rd; // Generates the random number which is used to seed the random number engine.
        std::mt19937 gen(rd()); // Mersenne Twister Engine/Algorithm which is seeded with 'rd'.

        std::uniform_int_distribution<int> dis(lowNum, highNum); // Defines the range/distribution of numbers the random number can be between depending on the values of 'lowNum' and 'highNum'.

        int randomNumber = dis(gen); // Assigns the randomly generated number using the random engine 'gen' to the newly declared and initialized integer variable 'randomNumber'.
        int guess; // Declares a variable of type int 'guess' which will be the number the user guesses.
        int attempts = 0; // Declares and initializes a variable of type int 'attempts' which will represent the number of attempts it took the user to guess the random number.
        bool gameOver = false; // Declares and initializes a boolean variable 'gameOver' which is set to false, representing the state of the game.

        while (!gameOver) { // While loop which will execute as long as 'gameOver' is not true, where 'gameOver' will only be true if the user guesses the correct number.
            std::cout << "Enter your guess: (Between " << lowNum << " - " << highNum << " ) " << std::endl; // Prompts the user to guess the random number between the two values they entered.

            while (!(std::cin >> guess)) { // While loop used to validate the guess from the user.
                std::cout << "Error! You must enter a numeric value." << std::endl;  // If the user enters an invalid value, the condition will evaluate to true, continuing the validation loop.
                std::cin.clear(); // Clears the flags/state of the error from the input stream.
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignores any other invalid input from the input buffer.
            }

            attempts++; // Number of attempts 'attempts' is incremnted by 1 to reflect the fact the user has made a guess.

            if (guess < lowNum || guess > highNum) { // This if statement checks if the guess the user made is less than the lowest possible value, or larger than the highest possible value in range.
                throw std::out_of_range("This number is out of range. Must be between " + std::to_string(lowNum) + " - " + std::to_string(highNum)); // If this is the case, an out of range exception is thrown.
            }

            if (guess < randomNumber) { // This if statement checks if the users guess is less than the random number, prompting them that the guess they made was too low.
                std::cout << "Your guess was too low! Try again!" << std::endl; // Prompting user that guess was too low.
            } else if (guess > randomNumber) { // This Else if statemetn checks the users guess was larger than the random number.
                std::cout << "Your guess was too high! Try again!" << std::endl; // The user will be prompted that the guess was too high if this was the case.
            } else { // The else block will be executed if the user has guessed the correct number.
                std::cout << "Congratulations! You guessed the random number: " << randomNumber << ", in " << attempts << " attempts!" << std::endl; // The user is prompted that they have chosen the correct number, in the number of attempts.
                gameOver = true; // The user chose the correct number, resulting in the end of the game.
            }
        }
    } catch (const std::exception& e) { // The catch block will 'catch' any exceptions as a result of the code in the try block.
        std::cerr << "An Exception was caught! This was why: " << e.what() << std::endl; // If an exception is caught, the user is prompted with a message and the reason for the exception.
    }
}

// This function is responsible for displaying instructions as to how the user can play the game.
void gameInstructions() {
    // All of the code below this point outputs explainations to the user plays the game.
    std::cout << "<<<< HOW TO PLAY >>>>" << std::endl;
    std::cout << "The goal is to guess the correct number." << std::endl;
    std::cout << "You have the option to let the computer choose a number between a set range of 1 - 100." << std::endl;
    std::cout << "You also have the option to set the range yourself, and let the computer choose between this range." << std::endl;
    std::cout << "Choose the corresponding number to your game mode of choice!" << std::endl;
    std::cout << "<<<< HAVE FUN >>>>" << std::endl;
}

