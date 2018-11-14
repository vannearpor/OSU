/********************************************************
** Author: Vannear Por
** Date: May 28, 2017
** Description: This file contains the Searchsort Class
** member function definitions which will allow the program
** to Linear Search, Binary Search, and Bubble Sort through
** different .txt files.
*********************************************************/

#include "searchsort.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;


/********************************************************
 *  Searchsort::linearSearch () (Slide #4)              *
 ********************************************************/
void Searchsort::linearSearch(int target,string file)
{
    bool found = false;
    std::ifstream in(file.c_str());
    int number;
    std::vector<int> numList;
    
    while(!in.eof())
    {
        in >> number;
        numList.push_back(number);
    }
    
    int fileSize = numList.size();
    
    for (int i = 0; i < fileSize; i++)
    {
        if (numList[i] == target)
        {
            std::cout << "Target is found in file "<< file << std::endl;
            
            found = true;
            
            break;
        }
    }
    if(found == false)
    {
        std::cout << "Target is not found in file " << file << std::endl;
    }
}


/********************************************************
 *  Searchsort::bubbleSort () (Slide #5)                *
 ********************************************************/
void Searchsort::bubbleSort(string inputfile,string outputfile)
{
    std::ifstream in;
    in.open(inputfile.c_str());
    std::vector<int> bubblevector;
    bool change = false;
    int holder;
    
    while (in >> holder)
    {
        bubblevector.push_back(holder);
    }
    
    in.close();

    int fileSize = bubblevector.size(); 

    std::cout << "Here are the contents of the " << inputfile << " file." << std::endl;
    
    for (int i = 0; i < fileSize; i++)
    {
        std::cout << bubblevector[i] << " " << std::endl;
    }
    
    int sortSize = fileSize;
    
    while (change == false)
    {
        for (int i = 0; i < sortSize; i++)
        {
            if (bubblevector[i] > bubblevector[i + 1])
            {
                holder = bubblevector[i];
                bubblevector[i] = bubblevector[i+1];
                bubblevector[i+1] = holder;
            }
        }
        sortSize = sortSize - 1;
        
        if (sortSize == 1)
        {
            change = true;
        }
    }
    
    std::ofstream out(outputfile.c_str());
    
    std::cout << "Here are the contents after the Bubble Sort: " << std::endl;
    
    for (int i = 0; i < fileSize; i++)
    {
        std::cout << bubblevector[i] << " " << std::endl;
    }
    
    out.close();
}

/********************************************************
 *  Searchsort::binarySearch () (Slide #11)             *
 ********************************************************/

void Searchsort::binarySearch (int target, std::string inputfile)
{
    std::ifstream in;
    in.open(inputfile.c_str());
    std::vector<int> binaryvector;
    int holder;
    bool found = false;
    
    while (in >> holder)
    {
        binaryvector.push_back(holder);
    }
    
    int fileSize = binaryvector.size();
    
    std::cout << "Here are the contents of the " << inputfile << " file." << std::endl;
    
    for (int i = 0; i < fileSize; i++)
    {
        std::cout << binaryvector[i] << " " << std::endl;
    }
   // std::cout << "debug test 1." << std::endl; 

    int start = 0;
    int middle = 0;
    int end = (fileSize - 1);
    int position = 0;
	//std::cout << "debug test 2." << std::endl;
    while ((found == false) && (start <= end))
    {
        middle = ((start+end)/2);
        
        if (binaryvector[middle] == target)
        {
            position = middle;
            found = true;
		//std::cout << "debug test 3" << std::endl;
        }
        else if (binaryvector[middle] < target)
        {
            start = middle + 1;
		//std::cout << "debug test 4" << std::endl;
        }
        else
        {
            end = middle - 1;
		//std::cout << "debug test 5" << std::endl;
        }
    }
    //std::cout << "debug test 6." << std::endl;
    if (found == false)
    {
        std::cout << "Target number " << target << " was not found in the file." << std::endl;
    }
    else
    {
        std::cout << "Target number " << target << " was found at position " << position << "!" << std::endl;
    }
    //std::cout <<"debug test 7." << std::endl;
    in.close();
}

