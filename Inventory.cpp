#include<iostream>
#include<string>
#include<list>
#include <fstream>
// For Sleep
#include <windows.h>

using namespace std;

list<string> inventory;

int main() {
    cout << "Hello and welcome to PlusPlus inventory tracker." << endl;
    string userInput;
    bool going = true;
    while (going == true)
    {
        cout << "What would you like to do?" << endl;
        cout << "0 - Quit the program." << endl;
        cout << "1 - Add an item." << endl;
        cout << "2 - Remove an item." << endl;
        cout << "3 - Check inventory." << endl;
        cout << "CLEAR - clear inventory." << endl;
        cin >> userInput;
        cout << endl;

        // 0
        if (userInput == "0")
        {
            cout << "Would you like to save this inventory to a new file record?" << endl;
            cout << "1: Yes" << endl;
            cout << "2: No" << endl;
            int response;
            cin >> response;
            if (response == 1)
            {
                // Create (if needed) and open a text file
                ofstream MyFile("Inventory.txt");

                // Write (and/or overwrite) to the file
                for (const auto& element : inventory)
                {
                    MyFile << element << " ";
                }

                // Close the file
                MyFile.close();
            }
            else
            {
                cout << "Tossing the inventory into the infinite void..." << endl;
                Sleep(800);
            }
            cout << endl;
            going = false;
        }
        // 1
        else if (userInput == "1")
        {
            string itemName;
            int itemCount;
            cout << "Please name the item." << endl;
            cin >> itemName;
            cout << "Please enter how many of this item you would like to add." << endl;
            cin >> itemCount;

            for (int i=0; i<itemCount; i++)
            {
                inventory.push_back(itemName);
            }
            cout << endl;
        }
        // 2
        else if (userInput == "2")
        {
            cout << "Please type the name of the item you would like to remove." << endl;
            cout << "Please make sure the item is entered exactly how it was typed earlier (ITEM is not the same as Item)." << endl;
            cout << "This will remove ALL instances of the item from the inventory." << endl;
            string secondInput;
            cin >> secondInput;
            
            bool found = false;
            for (const auto& element : inventory)
            {
                if (element == secondInput)
                {
                    found=true;
                    break;
                }
            }
            if (found == true)
            {
                inventory.remove(secondInput);
            }
            
            cout << "Process complete (any matching items were removed)." << endl;
            cout << endl;
            Sleep(2000);
        }
        // 3
        else if (userInput == "3")
        {
            for (const auto& element : inventory)
            {
                cout << element << " ";
            }
            cout << endl;
            cout <<endl;
        }
        // CLEAR
        else if (userInput == "CLEAR")
        {
            cout << "Are you sure you would like to empty the entire inventory?" << endl;
            cout << "1: Yes" << endl;
            cout << "2: No" << endl;
            int response;
            cin >> response;
            if (response == 1)
            {
                inventory.clear();
                cout << "The inventory has been cleared." << endl;
            }
            cout << endl;
        }
        else
        {
            cout << "Invalid input.  Please try again." << endl;
        }
    }
    

    return 0;
}