/* Krrish Karwal

This is a program designed to analyze the data collected by red light cameras scattered around Chicago.
Red light cameras have existed in Chicago since 2003 and have since collected data on the amount of traffic violations carried out at various intersections across the city.
Each red light camera object in this program has 7 attributes
    Intersection - The intersection at which a given camera is located at.
    Address - The address of a given camera.
    Camera ID - A unique 4-digit number is given to each camera to distinguish them from other cameras.
    Date - This is used to track the date when counting violations on a given day
    Violations - Used to keep track of violations on a daily basis.
    Neighborhood - The neighborhood a given camera is located in.
These attributes serve as the basis of which this program analyzes data from.

To use this program, you first need to input a file containing red light data for the program to read from.
Once that is done, the program will display a menu with 5 options:
    1: Data overview
        This option displays the number of camera records contained in the inputted file, the number of unique cameras found in the file, the total violations added up from the file, 
        and information denoting what intersection had the most violations in one day.
    2: Results by Neighborhood
        This option lists each neighborhood, the number of cameras in each neighborhood, and the number of violations given per neighborhood.
    3: Chart by Month
        This option displays a chart showing the amount of violations per month of the year. Each * in the chart equates to 1000 violations.
    4: Search for Cameras
        This option allows the user to search for a red light camera of their choosing. After entering a search term, the program then searches and displays all cameras that contain  the search term in either the
        intersection or neighborhood section of the camera's data.
    5: Exit
        This option simply exits the program, leaving the user with nothing more to do.

Due to the complexity of this program, it has been split into multiple files for ease of management and readability:
    CameraRecord.h and CameraRecord.cpp contain all the data related to the CameraRecord class used throughout this program. This includes constructors, getter functions and private variables.
    NeighborhoodData.h and NeighborhoodData.cpp contain all the data related to the NeighborhoodData class used throughout this program. This includes constructors, getter functions and private variables.
    functions.h and functions.cpp contain all code related to the various functions used throughout this program.
    main.cpp is the main file used to run this program. 
These files are vital for proper use of this program. Failure to include one of these files when using this program may result in fatal errors.
*/
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