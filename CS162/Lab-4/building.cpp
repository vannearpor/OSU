/****************************************************************
** Author: Vannear Por
** Date: April 27, 2017
** Description: This is the implementation file for the Building
** class which will contain the function definitions of the member
** functions which will set the name, size, and address of the 
** building. It will also have a function that will display
** the data for the objects.
*****************************************************************/

#include "building.hpp"

using std::cout;
using std::endl;
using std::string;

/****************************************************************
* Default Constructor                                           *
*****************************************************************/

Building::Building ()
{
}

/****************************************************************
* Default Deconstructor                                         *
*****************************************************************/

Building::~Building()
{
}

/****************************************************************
* Building::setBuildingName ()                                  *
*****************************************************************/

void Building::setBuildingName (std::string name)
{
    buildingName = name;
}

/****************************************************************
* Building::setBuildingSize ()                                  *
*****************************************************************/

void Building::setBuildingSize (int size)
{
    buildingSize = size;
}

/****************************************************************
* Building::setBuildingAddress ()                               *
*****************************************************************/

void Building::setBuildingAddress (std::string address)
{
    buildingAddress = address;
}

/****************************************************************
* Building::displayBuilding ()                                  *
*****************************************************************/

void Building::displayBuilding ()
{
    std::cout << "Building Name: " << buildingName << std::endl;
    std::cout << "Building Size: " << buildingSize << " square feet." << std::endl;
    std::cout << "Building Address: " << buildingAddress << std::endl;
}
