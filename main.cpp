#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void showMenu() {
cout << "   HOSPITAL STORE & INVENTORY SYSTEM   " << endl;
cout << "1. Add New Item / Restock " << endl;
cout << "2. Deduct Item / (Nurse Intake) " << endl;
cout << "3. Check Low Stock / Finished Alerts " << endl;
cout << "4. Exit System " << endl;
}

void addItem() {
    string itemName;
    int quantity;
    int alertLimit;

    cout << "\n   ADD NEW ITEM / RESTOCK   " << endl;
    cout << "Enter item Name: ";
    getline(cin >> ws, itemName);

    cout << "Enter current quantity in store: ";
    cin >> quantity;

    cout << "Enter low stack alert limit: ";
    cin >> alertLimit;

    ofstream inventoryFile("inventory.txt", ios::app);

    if (inventoryFile.is_open()) {
            inventoryFile << itemName << ":" << quantity << ":" << alertLimit << endl;
            inventoryFile.close();
            cout << "\n Success! " << itemName << " saved to hospital database.\n\n ";
    }
    else {
        cout << "\nError: could not open database file\n\n ";
    }
}

void deductItem() {
    string searchName, itemName;
    int deductQty, quantity, alertLimit;
    bool found = false;

    cout << "\n   DEDUCT ITEM (NURSE INTAKE)   " << endl;
    cout << "Enter name to deduct from: ";
    getline(cin >> ws, searchName);

    cout << "Enter quantity taken by nurse: ";
    cin >> deductQty;

    ifstream file ("inventory.txt");
    ofstream tempFile("temp.txt");

    if (file.is_open() && tempFile.is_open()) {
        string line;

        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string qStr, aStr;

            getline(ss, itemName, ':');
            getline(ss, qStr, ':');
            getline(ss, aStr, ':');

            quantity = stoi(qStr);
            alertLimit = stoi(aStr);

            if (itemName == searchName) {
                found = true;
                if (deductQty > quantity) {
                    cout << "\nError: Not enough stock! Only " << quantity << " available.\n\n ";
                } else {
                    quantity -= deductQty;
                    cout << "\nSuccess! Deducted " << deductQty << " units from " << itemName << ".\n\n ";
                }
            }
            tempFile << itemName << ":" << quantity << ":" << alertLimit << endl;
        }
        file.close();
        tempFile.close();

        remove("inventory.txt");
        rename("temp.txt", "inventory.txt");

        if (!found) {
            cout << "\nItem not found in database!\n\n ";
        }
    } else {
        cout << "\nError: Could not access database files!\n\n ";
    }
}

void checkAlerts() {
    string itemName;
    int quantity, alertLimit;
    bool activeAlerts = false;

    cout << "\n   LOW STOCK & FINISHED ALERTS   " << endl;

    ifstream file ("inventory.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;

            stringstream ss(line);
            string qStr, aStr;

            getline(ss, itemName, ':');
            getline(ss, qStr, ':');
            getline(ss, aStr, ':');

            quantity = stoi(qStr);
            alertLimit = stoi(aStr);

            if (quantity == 0) {
                cout << "CRITICAL: " << itemName << " is completely finished! Remaining stock: 0 units.\n\n ";
                activeAlerts = true;
            }
            else if (quantity <= alertLimit) {
                cout << "WARNING: " << itemName << " is running low. Remaining Stock: " << quantity << " units\n\n ";
                activeAlerts = true;
            }
        }
        file.close();

        if (activeAlerts == false) {
            cout << "\nAll systems clear! Every item has plenty of stock.\n\n ";
        }
        } else {
            cout << "\nError: Could not access database file!\n\n ";
        }
}
int main() {

    int choice = 0;

    while (choice != 4) {
        showMenu();
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (choice == 1) {
            addItem();
        }
        else if (choice == 2) {
            deductItem();
        }
        else if (choice == 3) {
            checkAlerts();
        }
        else if (choice == 4) {
            cout << "\nExiting System. Goodbye!\n ";
        }
        else {
            cout << "\nInvalid choice! Please choose between 1 and 4.\n\n ";
        }
    }
}
