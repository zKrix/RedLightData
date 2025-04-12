/* Krrish Karwal

The NeighborhoodData class is used to keep track of the neighborhoods in Chicago.
Each NeighborhoodData object keeps track of:
    a neighborhood's name, 
    number of cameras, 
    and total violations counted in that neighborhood.
*/

#include "NeighborhoodData.h"

// Constructor to initalize a NeighborhoodData object
NeighborhoodData::NeighborhoodData(string name)
{
    neighborhood = name;
    cameraCount = 0;
    totalViolations = 0;
}

// Functions to get a specific value of a NeighborhoodData object 
string NeighborhoodData::getNeighborhood() const { return neighborhood; }
int NeighborhoodData::getCameraCount() const { return cameraCount; }
int NeighborhoodData::getTotalViolations() const { return totalViolations; }

// Functions to add a camera or violations to a NeighborhoodData object
void NeighborhoodData::addCamera() { cameraCount++; }
void NeighborhoodData::addViolations(int violations) { totalViolations += violations; }