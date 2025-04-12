/* Krrish Karwal
functions.h and functions.cpp contain all the functions that are not tied to CameraRecord or NeighborhoodData
*/

#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

/* Reads data from a given file and adds the data to a given CameraRecord vector
parameters:
    const string& fileName: The name of the data file to be used. Contains a list of cameras and information for each camera.
    vector<CameraRecord>& records: A vector containing a list of various CameraRecord objects.
*/
void loadFile(const string& fileName, vector<CameraRecord>& records)
{
    ifstream fileIn(fileName);

    string line;
    while (getline(fileIn, line))
    {
        // Used to read each line in the given file
        stringstream ss(line);
        
        // Variables used to assign values from the given file
        string intersection;
        string address;
        int cameraID;
        string date;
        int violations;
        string neighborhood;

        // Used for converting values for cameraID and violations from strings to integers
        string temp;

        // Reads each line and splits the line's data into different Variables
        getline(ss, intersection, ',');
        getline(ss, address, ',');
        getline(ss, temp, ',');
        cameraID = stoi(temp);
        getline(ss, date, ',');
        getline(ss, temp, ',');
        violations = stoi(temp);
        getline(ss, neighborhood);

        // Converts the date from year-month-day to month-day-year
        stringstream dateSS(date);
        string day;
        string month;
        string year;
        getline(dateSS, year, '-');
        getline(dateSS, month, '-');
        getline(dateSS, day, '-');
        string dateFormatted = month + "-" + day + "-" + year;

        // Adds the camera data into the CameraRecord vector
        records.emplace_back(intersection, address, cameraID, dateFormatted, violations, neighborhood);
    }

    fileIn.close();
}

/* Helper function for Option 4: Search for cameras
* Converts a string to lower case
*/
string convertToLowerCase(string& userString)
{
    string lowerString = userString;
    for (int i = 0; i < lowerString.length(); i++)
    {
        lowerString[i] = tolower(lowerString[i]);
    }
    return lowerString;
}

/* Option 1: Data overview
This option displays the following:
    the number of camera records,
    the number of unique cameras,
    the total violations,
    and information denoting what intersection had the most violations in one day.
parameters:
    const vector<CameraRecord>& records: A vector containing a list of various CameraRecord objects. The vector is not user-made.
    Instead, the vector is created automatically from loadFile() first.
*/
void dataOverview(const vector<CameraRecord>& records)
{
    int totalRecords = records.size();
    int totalViolations = 0;
    int maxViolations = 0;
    string maxViolationDate;
    string maxViolationIntersection;
    vector<int> uniqueCameraIDs;

    // Loops through records to get the total violations as well as the date and intersection that had the most violations
    for (int i = 0; i < records.size(); i++)
    {
        const CameraRecord& record = records[i];
        totalViolations += record.getViolations();

        // Gets the date and intersection that had the most violations
        if (record.getViolations() > maxViolations)
        {
            maxViolations = record.getViolations();
            maxViolationDate = record.getDate();
            maxViolationIntersection = record.getIntersection();
        }

        /* Checks to see if a given cameraID already exists in uniqueCameraIDs. 
        * If it does not exist, then the camera ID is added to uniqueCameraIDs.
        */
        if (find(uniqueCameraIDs.begin(), uniqueCameraIDs.end(), record.getCameraID()) == uniqueCameraIDs.end())
        {
            uniqueCameraIDs.push_back(record.getCameraID());
        }
    }

    // Outputs the results
    cout << "Read file with "  << totalRecords << " records." << endl;
    cout << "There are " << uniqueCameraIDs.size() << " cameras." << endl;
    cout << "A total of " << totalViolations << " violations." << endl;
    cout << "The most violations in one day were " << maxViolations << " on " << maxViolationDate << " at " << maxViolationIntersection << endl;
}

/* Option 2: Results by Neighborhood
This option displays:
    each neighborhood,
    the number of cameras in each neighborhood,
    and the number of violations given per neighborhood.
parameters:
    const vector<CameraRecord>& records: A vector containing a list of various CameraRecord objects. The vector is not user-made.
    Instead, the vector is created automatically from loadFile() first.
*/
void resultsByNeighborhood(const vector<CameraRecord>& records)
{
    vector<NeighborhoodData> neighborhoodData;
    vector<vector<int>> uniqueCameraIDs;

    // Loops through each object in the given vector to add data relating to each neighborhood
    for (int i = 0; i < records.size(); i++)
    {
        string neighborhood = records[i].getNeighborhood();
        int cameraID = records[i].getCameraID();
        int violations = records[i].getViolations();

        // Checks to see if a given neighborhood already exists in the vector
        int indexFound = -1;
        for (int j = 0; j < neighborhoodData.size(); j++)
        {
            if (neighborhoodData[j].getNeighborhood() == neighborhood)
            {
                indexFound = j;
                break;
            }
        }

        /* If indexFound does not equal -1, the neighborhood already exists.
        * The existing neighborhood's data is then simply updated.
        * Otherwise, a new neighborhood is created and added to 'neighborhoodData'.
        */
        if (indexFound != -1)
        {
            neighborhoodData[indexFound].addViolations(violations);

            if (find(uniqueCameraIDs[indexFound].begin(), uniqueCameraIDs[indexFound].end(), cameraID) == uniqueCameraIDs[indexFound].end())
            {
                uniqueCameraIDs[indexFound].push_back(cameraID);
                neighborhoodData[indexFound].addCamera();
            }
        }
        else
        {
            NeighborhoodData newNeighborhood(neighborhood);
            newNeighborhood.addCamera();
            newNeighborhood.addViolations(violations);
            neighborhoodData.push_back(newNeighborhood);
            uniqueCameraIDs.push_back({cameraID});
        }
    }

    // Sorts the neighborhoods based on total violations
    for (int i = 0; i < neighborhoodData.size() - 1; i++)
    {
        for (int j = i + 1; j < neighborhoodData.size(); j++)
        {
            if (neighborhoodData[i].getTotalViolations() < neighborhoodData[j].getTotalViolations())
            {
                swap(neighborhoodData[i], neighborhoodData[j]);
                swap(uniqueCameraIDs[i], uniqueCameraIDs[j]);
            }
        }
    }

    // Outputs the results
    for (int i = 0; i < neighborhoodData.size(); i++)
    {
        cout << left << setw(25) << neighborhoodData[i].getNeighborhood() << right << setw(4) << neighborhoodData[i].getCameraCount() << setw(7) << neighborhoodData[i].getTotalViolations() << endl;
    }
}

/* Option 3: Chart by Month
This option displays a chart showing the amount of violations per month of the year. 
Each * in the chart equates to 1000 violations.

parameters:
    const vector<CameraRecord>& records: A vector containing a list of various CameraRecord objects. The vector is not user-made.
    Instead, the vector is created automatically from loadFile() first.
*/
void chartByMonth(const vector<CameraRecord>& records)
{
    // These arrays are used to store violation counts for each month of the year
    string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", 
    "September", "October", "November", "December"};
    int violationsByMonth[12] = {0};

    for (int i = 0; i < records.size(); i++)
    {
        string date = records[i].getDate();
        int index = stoi(date.substr(0, date.find('-'))) - 1;
        violationsByMonth[index] += records[i].getViolations();
    }

    // Prints out the chart for violations by month. One '*' = 1000 violations.
    for (int i = 0; i < 12; i++)
    {
        cout << left << setw(15) << months[i];
        cout << string(violationsByMonth[i] / 1000, '*') << endl;
    }
}

/* Option 4: Search for cameras
This option allows the user to search for a red light camera of their choosing. 
After entering a search term, the program then searches and displays all cameras that contain the search term in either the intersection or neighborhood section of the camera's data.

parameters:
    const vector<CameraRecord>& records: A vector containing a list of various CameraRecord objects. The vector is not user-made.
    Instead, the vector is created automatically from loadFile() first.
*/
void searchForCameras(const vector<CameraRecord>& records)
{
    // Prompts the user on what to search for
    cout << "What should we search for? ";
    string search;
    getline(cin, search);

    search = convertToLowerCase(search);
    vector<int> uniqueCameraIDs;
    bool cameraFound = false;

    // Loops through records to search for any intersection or neighborhood that contains the search term
    for (int i = 0; i < records.size(); i++)
    {
        const CameraRecord& record = records[i];

        string recordIntersection = record.getIntersection();
        string recordNeighborhood = record.getNeighborhood();
        
        string lowerIntersection = convertToLowerCase(recordIntersection);
        string lowerNeighborhood = convertToLowerCase(recordNeighborhood);

        // Checks to see if the search term exists in either lowerIntersection or lowerNeighborhood
        if (lowerIntersection.find(search) != string::npos || lowerNeighborhood.find(search) != string::npos)
        {
            // Checks if the record's camera ID already exists in uniqueCameraIDs
            if (find(uniqueCameraIDs.begin(), uniqueCameraIDs.end(), record.getCameraID()) == uniqueCameraIDs.end())
            {
                uniqueCameraIDs.push_back(record.getCameraID());

                cout << "Camera: " << record.getCameraID() << endl;
                cout << "Address: " << record.getAddress() << endl;
                cout << "intersection: " << record.getIntersection() << endl;
                cout << "Neighborhood: " << record.getNeighborhood() << endl;
                cout << endl;

                cameraFound = true;
            }
        }
    }

    // Only executes if no cameras were found based on the given search term
    if (!cameraFound)
    {
        cout << "No cameras found." << endl;
    }
}