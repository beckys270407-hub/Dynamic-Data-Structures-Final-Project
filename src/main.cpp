#include "tree.hpp"
#include <iostream>

using namespace std;

int main() {
    Tree mafia;
    mafia.loadCSV("bin/data.csv");

    int opt = 0;
    while (opt != 4) {
        cout << "\n--- MAFIA SYSTEM ---\n1. Succession Line\n2. Edit Member\n3. Manual Check\n4. Exit\nSelection: ";
        cin >> opt;
        if (opt == 1) mafia.showSuccession(mafia.getRoot());
        else if (opt == 2) {
            int id; cout << "Enter ID: "; cin >> id;
            mafia.editNode(id);
        }
        else if (opt == 3) mafia.updateBoss();
    }
    return 0;
}
