#include "game.h"
#include "helper.h"
#include "board.h"
#include "helper.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exit;
using std::vector;
using std::getline;
using std::isdigit;

int mainMenu() {
    string inp;
    bool firstTime = true;

    // Display the menu once, outside of the loop
    cout << "Welcome to Vacuum Cleaning Game!" << endl;
    cout << "-----------------------------" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Show student information" << endl;
    cout << "3. Quit" << endl;
    cout << "-----------------------------" << endl;

    while (inp.length() != 1 || isdigit(inp[0]) == false || inp[0] < '1' || inp[0] > '3') {
        if (!firstTime){
            cout << endl;
            Helper::printInvalidInput();
        }
        cout << "Please enter your choice: ";
        Helper::readInput(inp);
        firstTime = false;
    }
    int choice = stoi(inp); // Convert string to integer
    return choice;
};

void displayStudentInfo() {
    cout << "-----------------------------------" << endl;
    cout << "Name: Tran Hoang Son" << endl;
    cout << "Student ID: s3978450" << endl;
    cout << "Email: s3978450@rmit.edu.vn" << endl;
    cout << "-----------------------------------" << endl;
};

int main() 
{
    // Main menu loop:

    while (true) {
        int choice = mainMenu();
        string command = " ";
        
        if (choice == 1) {
            while (command != "quit"){
                Game game;
                game.start(command);
                if (command != "quit"){
                    game.play();
                }
                cout << "\nTotal player moves: " << game.getPlayerMoves() << endl;
                command = "quit";
            }
        } else if (choice == 2) {
            displayStudentInfo();
            Helper::waitForEnter();
        } else if (choice == 3) {
            cout << "Exiting program..." << endl;
            return EXIT_SUCCESS;
        }
    }        
    return EXIT_SUCCESS;
}

