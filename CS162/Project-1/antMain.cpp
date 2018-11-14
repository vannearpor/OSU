/*************************************************************
** Author: Vannear Por
** Date: April 15, 2017
** Description: This program contains the main file that will
** prompt the user to enter the number of rows and columns
** for their 2D array and the number of steps they want
** their ant to take. The program will then utilize the
** matrix and Ant class file to create a Langton's ant that 
** will take the amount of steps specified by the user. The
** Ant, depending on the steps it takes, will change the color
** of the cell of the matrix to black (#) or white (' ').
*************************************************************/

#include <iostream>
#include "ant.hpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int matrixRows, matrixColumns;
    int antSteps;
    int antRow, antColumn;
    
    //Prompt user for Board
    std::cout << "You will determine the size of the rows and columns for the matrix." << std::endl;
    
    std::cout << "Please enter the number of rows you would like for the board size and press [Enter] (Keep integer under 80 please): " << std::endl;
    std::cin >> matrixRows;
    std::cout << std::endl;
    
    std::cout << "Please enter the number of columns you would like for the board size and press [Enter] (Keep integer under 80 please): " << std::endl;
    std::cin >> matrixColumns;
    std::cout << std::endl;
    
    std::cout << "Your board will display " << matrixRows << " rows, and " << matrixColumns << " columns." << std::endl;
    std::cout << std::endl;
    
    //Menu for user to choose the number of steps for the Ant.
    int choice;
        
    std::cout << "You will choose out of 4 options the number of steps that you want the ant to take." << std::endl;
    std::cout << " 1 - Five(5) steps." << std::endl;
    std::cout << " 2 - Ten(10) steps." << std::endl;
    std::cout << " 3 - Fifteen(15) steps." << std::endl;
    std::cout << " 4 - Twenty(20) steps." << std::endl;
    std::cout << " 5 - Choose your own number." << std::endl;
    std::cout << "Enter the number of your choice between 1 - 5 and press [Enter]:" << std::endl;
        
    std::cin >> choice;
        
    switch (choice)
    {
        case 1:
            std::cout << "The Ant will take five(5) steps." << std::endl;
            antSteps = 5;
            break;
        case 2:
            std::cout << "The Ant will take ten(10) steps." << std::endl;
            antSteps = 10;
            break;
        case 3:
            std::cout << "The Ant will take fifteen(15) steps." << std::endl;
            antSteps = 15;
            break;
        case 4:
            std::cout << "The Ant will take twenty(20) steps." << std::endl;
            antSteps = 20;
            break;
        case 5:
            std::cout << "Please enter your own number of steps and press [Enter]: " << std::endl;
            std::cin >> antSteps;
            break;
    }
    
    std::cout << std::endl;
    
    bool legitRow = true;
    bool legitColumn = true;
    
    //Prompt the user for the starting location of the ant
    //Getting the ant's starting row
    while (legitRow == true)
    {
        std::cout << "Now before beginning, please select the starting location of the ant." << std::endl;
        std::cout << "Please enter the row of the ant's starting location (take into account the row size): " << std::endl;
        std::cin >> antRow;
        std::cout << std::endl;
    
        //Make sure they stay within row size limit
        if (antRow <= matrixRows)
        {
            antRow = antRow - 1;          //arrays start at 0
        
            legitRow = false;
        }
        else
        {
            std::cout << "Error! The row is out of the matrix range. Please try again." << std::endl;
        }
    }
    
    
    //Getting ant's starting column
    while (legitColumn == true)
    {
        std::cout << "Please enter the column of the ant's starting location (take into account the column size): " << std::endl;
        std::cin >> antColumn;
        std::cout << std::endl;
        
        //Make sure they stay within the column size limit
        if (antColumn <= matrixColumns)
        {
            antColumn = antColumn - 1;      //arrays start at 0
            
            legitColumn = false;
        }
        else
        {
            std::cout << "Error! The column is out of the matrix range. Please try again." << std::endl;
        }
    }
    
    //Dynamically allocate and create matrix board
    char** antMatrix = new char*[matrixRows];
    for (int i = 0; i < matrixRows; i++)
    {
        antMatrix[i] = new char[matrixColumns];
    }
    
    //Place blank characters into the matrix
    for (int i = 0; i < matrixRows; i++)
    {
        for (int j = 0; j < matrixColumns; j++)
        {
            antMatrix[i][j] = ' ';
        }
    }
    
    //Create Ant class object
    Ant walkingAnt(antRow, antColumn);
    
    //Create the Ant on the matrix using the start location
    antMatrix[antRow][antColumn] = '@';
    
    //Matrix is ready to display; display matrix
    for (int i = 0; i < matrixRows; i++)
    {
        for (int j = 0; j < matrixColumns; j++)
        {
            std::cout << antMatrix[i][j];
        }
        std::cout << std::endl;
    }
    
    //The ant will now move according to the rules:
    //1. In a white (' ') square, turn right 90 degrees and change the square to black ('#'), move forward one step.
    //2. In a black ('#') square, turn left 90 degrees and change the square to white (' '), move forward one step.
    //Loop as many times as the number of steps specified by the user.
    
    for (int i = antSteps; i > 0; i--)
    {
        //Check to see if color is currently white or black
        if (walkingAnt.getColor() == ' ')
        {
            antMatrix[walkingAnt.getCurrentRow()][walkingAnt.getCurrentColumn()] = '#';
            
            if (walkingAnt.getDirection() == up)
            {
                walkingAnt.setDirection(right);
                antColumn = walkingAnt.getNewColumn();
                antColumn = antColumn + 1;
                if (antColumn >= matrixColumns)
                {
                    walkingAnt.setDirection(left);
                }
                walkingAnt.setNewColumn(antColumn);
                antMatrix[walkingAnt.getNewRow()][walkingAnt.getNewColumn()] = '@';
            }
            
            else if (walkingAnt.getDirection() == right)
            {
                walkingAnt.setDirection(down);
                antRow = walkingAnt.getNewRow();
                antRow = antRow + 1;
                if (antRow >= matrixRows)
                {
                    walkingAnt.setDirection(up);
                }
                walkingAnt.setNewRow(antRow);
                antMatrix[walkingAnt.getNewRow()][walkingAnt.getNewColumn()] = '@';
            }
            
            else if (walkingAnt.getDirection() == down)
            {
                walkingAnt.setDirection(left);
                antColumn = walkingAnt.getNewColumn();
                antColumn = antColumn - 1;
                if (antColumn < 0)
                {
                    walkingAnt.setDirection(right);
                }
                walkingAnt.setNewColumn(antColumn);
                antMatrix[walkingAnt.getNewRow()][walkingAnt.getNewColumn()] = '@';
            }
            
            else if (walkingAnt.getDirection() == left)
            {
                walkingAnt.setDirection(up);
                antRow = walkingAnt.getNewRow();
                antRow = antRow - 1;
                if (antRow < 0)
                {
                    walkingAnt.setDirection(down);
                }
                walkingAnt.setNewRow(antRow);
                antMatrix[walkingAnt.getNewRow()][walkingAnt.getNewColumn()] = '@';
            }
        }
        else if (walkingAnt.getColor() == '#')
        {
            antMatrix[walkingAnt.getCurrentRow()][walkingAnt.getCurrentColumn()] = ' ';
            
            if (walkingAnt.getDirection() == up)
            {
                walkingAnt.setDirection(left);
                antColumn = walkingAnt.getNewColumn();
                antColumn = antColumn - 1;
                if (antColumn >= matrixColumns)
                {
                    walkingAnt.setDirection(right);
                }
                walkingAnt.setNewColumn(antColumn);
                antMatrix[walkingAnt.getNewRow()][walkingAnt.getNewColumn()] = '@';
            }
            
            else if (walkingAnt.getDirection() == right)
            {
                walkingAnt.setDirection(up);
                antRow = walkingAnt.getNewRow();
                antRow = antRow - 1;
                if (antRow >= matrixRows)
                {
                    walkingAnt.setDirection(down);
                }
                walkingAnt.setNewRow(antRow);
                antMatrix[walkingAnt.getNewRow()][walkingAnt.getNewColumn()] = '@';
            }
            
            else if (walkingAnt.getDirection() == down)
            {
                walkingAnt.setDirection(right);
                antColumn = walkingAnt.getNewColumn();
                antColumn = antColumn + 1;
                if (antColumn < 0)
                {
                    walkingAnt.setDirection(left);
                }
                walkingAnt.setNewColumn(antColumn);
                antMatrix[walkingAnt.getNewRow()][walkingAnt.getNewColumn()] = '@';
            }
            
            else if (walkingAnt.getDirection() == left)
            {
                walkingAnt.setDirection(down);
                antRow = walkingAnt.getNewRow();
                antRow = antRow + 1;
                if (antRow < 0)
                {
                    walkingAnt.setDirection(up);
                }
                walkingAnt.setNewRow(antRow);
                antMatrix[walkingAnt.getNewRow()][walkingAnt.getNewColumn()] = '@';
            }
        }
    
        for (int i = 0; i < matrixRows; i++)
        {
            for (int j = 0; j < matrixColumns; j++)
            {
                std::cout << antMatrix[i][j];
            }
            std::cout << std::endl;
        }
        
        walkingAnt.setCurrentRow(antRow);
        walkingAnt.setCurrentColumn(antColumn);
        
    }
    
    //Delete matrix after finished.
    for (int i = 0; i < matrixRows; i++)
    {
        delete [] antMatrix[i];
    }
    delete [] antMatrix;
    
    return 0;
}

