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

#include "CameraRecord.h"

// Constructor to initalize a CameraRecord object
CameraRecord::CameraRecord(string userIntersection, string userAddress, int userCameraID, string userDate, int userViolations, string userNeighborhood)
{
    intersection = userIntersection;
    address = userAddress;
    cameraID = userCameraID;
    date = userDate;
    violations = userViolations;
    neighborhood = userNeighborhood;
}

// Functions to get a specific value of a CameraRecord object
string CameraRecord::getIntersection() const { return intersection; }
string CameraRecord::getAddress() const { return address; }
int CameraRecord::getCameraID() const { return cameraID; }
string CameraRecord::getDate() const { return date; }
int CameraRecord::getViolations() const { return violations; }
string CameraRecord::getNeighborhood() const { return neighborhood; }