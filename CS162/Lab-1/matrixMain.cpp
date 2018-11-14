/********************
 * Author: Vannear Por
** Date: April 8, 2017
** Description: This program is the main file that will prompt the
** user to choose the size of the matrix and then have the user
** enter values into the matrix corresponding to the size. This
** program will also return the determinant of those values. It will
** then display the matrix and determinant to the user.
********************************************************************/

#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

using std::cout;
using std::cin;
using std::endl;

int main ()
{
    int size;
    int matrixDeterminant;
    ReadMatrix array;
    Determinant arraydeterminant;

    std::cout << "Please enter the size of the matrix (2 or 3)." << std::endl;
    std::cin >> size;
    
    if (size !=2 && size !=3)
    {
        std::cout << "Size has to be either 2 or 3. Please try again." << std::endl;
    }
    else
    {
        std::cout << "Please enter " << size*size << " values to be placed into the matrix." << std::endl;
    }
    
    int** newMatrix = new int*[size];
    
    for (int i = 0; i < size; i++)
    {
        newMatrix[i] = new int[size];
    }
    
    array.getMatrixValues(newMatrix, size);
    
    matrixDeterminant = arraydeterminant.getDeterminant(newMatrix, size);
    
    std::cout << "Matrix received displayed: " << std::endl;
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << newMatrix[i][j] << std::endl;
        }
    }
    
    std::cout << endl;
    
    std::cout << "This determinant for this matrix is: " << matrixDeterminant << std::endl;
    
    for (int i = 0; i < size; i++)
    {
        delete [] newMatrix[i];
    }
    
    delete [] newMatrix;
    
    return 0;
}

