/* Krrish Karwal
functions.h and functions.cpp contain all the functions that are not tied to CameraRecord or NeighborhoodData
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "CameraRecord.h"
#include "NeighborhoodData.h"
#include <string>
#include <vector>

using namespace std;

// Function declarations
void loadFile(const string& fileName, vector<CameraRecord>& records);
string convertToLowerCase(string& userString);
void dataOverview(const vector<CameraRecord>& records);
void resultsByNeighborhood(const vector<CameraRecord>& records);
void chartByMonth(const vector<CameraRecord>& records);
void searchForCameras(const vector<CameraRecord>& records);

#endif