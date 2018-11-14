/****************************************************************
**Author: Vannear Por
** Date: April 27, 2017
** Description: This is the header file for the building
** class which will contain the member variables of the name,
** size, and address of the buildings. It will also contain the
** member functions to set and display the building information.
*****************************************************************/

#ifndef BUILDING_HPP
#define BUILDING_HPP

#include <iostream>
std::string

class Building
{
    private:
        std::string buildingName;
        int buildingSize;
        std::string buildingAddress;
    
    public:
        Building() {};
        ~Building() {};
        void setBuildingName (std::string name);
        void setBuildingSize (int size);
        void setBuildingAddress (std::string address);
        void displayBuilding ();
};

#endif
