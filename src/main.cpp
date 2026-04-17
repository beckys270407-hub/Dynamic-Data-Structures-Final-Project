#include "tree.hpp"
#include <iostream>
#include <limits> 

using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void pause() {
    cout << "\nPress Enter to return to the menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    Tree mafia;
    mafia.loadCSV("bin/data.csv");

    int opt = 0;
    while (opt != 4) {
        clearScreen();
        cout << "========================================" << endl;
        cout << "       MAFIA SUCCESSION SYSTEM         " << endl;
        cout << "========================================" << endl;
        cout << "1. View Current Succession Line" << endl;
        cout << "2. Edit Family Member Status" << endl;
        cout << "3. Trigger Manual Succession Check" << endl;
        cout << "4. Exit System" << endl;
        cout << "========================================" << endl;
        cout << "Selection: ";
        
        if (!(cin >> opt)) { 
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        clearScreen(); 

        switch (opt) {
            case 1:
                cout << "--- CURRENT SUCCESSION LINE ---\n" << endl;
                mafia.showSuccession(mafia.getRoot());
                pause();
                break;
            case 2:
                int id;
                cout << "Enter the ID of the member to edit: ";
                cin >> id;
                mafia.editNode(id);
                pause();
                break;
            case 3:
                cout << "Running automatic succession protocols..." << endl;
                mafia.updateBoss();
                pause();
                break;
            case 4:
                cout << "Terminating system. Goodbye, Don." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                pause();
                break;
        }
    }
    return 0;
}