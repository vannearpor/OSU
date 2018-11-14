/*****************************************************************
 * ** Author: Vannear Por
 * ** Date: April 8, 2017
 * ** Description: This program contains the functions that will
 * ** read a matrix in the form of an array.
 * ******************************************************************/

#include "readMatrix.hpp"
using std::cout;
using std::cin;
using std::endl;

/****************************************************************
 *  * Default Constructor.                                         *
 *   ****************************************************************/

ReadMatrix::ReadMatrix()
{
}

/****************************************************************
 *  * ReadMatrix::getMatrixValue                                   *
 *   * This function receives an array and it's size and reads the  *
 *    * values of the matrix.                                        *
 *     ****************************************************************/

void ReadMatrix::getMatrixValues (int* twoDArray[], int size)
{
    std::cout << "Please enter " << size*size << " elements into the matrix." << std::endl;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cin >> twoDArray[i][j];
            std::cout << std::endl;
        }
    }
}

