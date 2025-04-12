/* Krrish Karwal

The NeighborhoodData class is used to keep track of the neighborhoods in Chicago.
Each NeighborhoodData object keeps track of:
    a neighborhood's name, 
    number of cameras, 
    and total violations counted in that neighborhood.
*/

#ifndef NEIGHBORHOODDATA_H
#define NEIGHBORHOODDATA_H
#include <string>

using namespace std;

class NeighborhoodData
{
    public:
        // Constructor to initalize a NeighborhoodData object
        NeighborhoodData(string name);

        // Functions to get a specific value of a NeighborhoodData object 
        string getNeighborhood() const;
        int getCameraCount() const;
        int getTotalViolations() const;

        // Functions to add a camera or violations to a NeighborhoodData object
        void addCamera();
        void addViolations(int violations);

    private:
        // Variables used to keep track of a NeighborhoodData object's attributes
        string neighborhood;
        int cameraCount;
        int totalViolations;
};

#endif