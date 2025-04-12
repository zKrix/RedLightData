/* Krrish Karwal

The CameraRecord class is used to keep track of the various red light cameras scattered around Chicago.
Each CameraRecord object keeps track of:
    the intersection a camera is located at,
    the address a camera is located at,
    the ID number of a camera,
    a date that's used for tracking violations,
    the number of violations at the camera's intersection and address
    and the neighborhood the camera is located in.
*/

#ifndef CAMERARECORD_H
#define CAMERARECORD_H
#include <string>

using namespace std;

class CameraRecord
{
    public:
        // Constructor to initalize a CameraRecord object
        CameraRecord(string userIntersection, string userAddress, int userCameraID, string userDate, int userViolations, string userNeighborhood);

        // Functions to get a specific value of a CameraRecord object
        string getIntersection() const;
        string getAddress() const;
        int getCameraID() const;
        string getDate() const;
        int getViolations() const;
        string getNeighborhood() const;

    private:
        // Variables used to keep track of a CameraRecord object's attributes
        string intersection;
        string address;
        int cameraID;
        string date;
        int violations;
        string neighborhood;
};

#endif