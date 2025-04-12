// Krrish Karwal

#include <iostream>
#include "functions.h"

using namespace std;

// Main program
int main()
{
    string fileName;
    cout << "Enter file to use: ";
    cin >> fileName;

    vector<CameraRecord> records;
    loadFile(fileName, records);

    int menuInput;

    // Main Menu
    while (true)
    {
        cout << "Select a menu option:" << endl;
        cout << "  1. Data overview" << endl;
        cout << "  2. Results by neighborhood" << endl;
        cout << "  3. Chart by month" << endl;
        cout << "  4. Search for cameras" << endl;
        cout << "  5. Exit" << endl;
        cout << "Your choice: ";
        cin >> menuInput;

        // Ignores any other input the user may have put in while entering a menu option
        cin.ignore();
    
        switch (menuInput)
        {
            case 1:
                dataOverview(records);
                break;
            case 2:
                resultsByNeighborhood(records);
                break;
            case 3:
                chartByMonth(records);
                break;
            case 4:
                searchForCameras(records);
                break;
            case 5:
                return 0;
        }
    }

    return 0;
}
