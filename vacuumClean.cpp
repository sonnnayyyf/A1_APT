#include "game.h"
#include "helper.h"

using std::string;
using namespace std;

void displayMainMenu() {
    cout << "Welcome to Vacuum Cleaning Game!" << endl;
    cout << "-----------------------------" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Show student information" << endl;
    cout << "3. Quit" << endl;
    cout << "Please enter your choice: ";
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
    int choice;

    // Main menu loop:

    while (true) {
        displayMainMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                
            case 2:
                displayStudentInfo();
                while (true) {
                    cout << "Please enter 0 to return to the main menu: ";
                    std::cin >> choice;
                    if (choice == 0) // Exit student info display
                        break;
                    else
                        std::cout << "Invalid choice. Please enter 0 to return to the main menu." << std::endl;
                }
                break;
            case 3:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                
                break;
        }
    }

    return EXIT_SUCCESS;
}

