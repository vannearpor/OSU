/*******************************************************************
** Author: Vannear Por
** Date: April 27, 2017
** Description: This is the header file for the List class which
** contains it's member variables and functions. The variables will
** hold the array needed to create the list itself and it's
** characteristics, such as the size and capacity. The member functions
** will control the tasks done with the list, such as adding, removing,
** deleting, and displaying the items on the list. The default
** constructor will instantiate a list with 4 slots open.
*******************************************************************/

#ifndef LIST_HPP
#define LIST_HPP
#include "item.hpp"

using std::string;
using std::cout;
using std::endl;

class List
{
    private:
        Item * itemList;
        int listSize;
        int listMaximum;
        double priceAllItems;
    
    public:
        List ();
        ~List ();
    
        void addItem (std::string n, std::string u, int q, double p);
        void removeItem ();
        void deleteSpace (int ii);
        void displayList ();
        bool operator == (Item);
        double getPriceAllItems ();
    
};

#endif


