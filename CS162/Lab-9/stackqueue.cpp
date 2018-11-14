/**************************************************************
** Author: Vannear Por
** Date: June 4, 2017
** Description: This is the Stackqueue class implementation file
** which contains the class member function definitions of the
** functions that will allow the user to create a palindrome
** using stack, and a buffer using queue.
***************************************************************/

#include "stackqueue.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::queue;
using std::stack;

/**************************************************************
 * Default Constructor ()                                     *
 **************************************************************/

Stackqueue::Stackqueue ()
{
}

/**************************************************************
 * Deconstructor ()                                           *
 ***************************************************************/

Stackqueue::~Stackqueue()
{
}

/**************************************************************
 * Stackqueue::getNumber ()                                   *
 ***************************************************************/

int Stackqueue::getNumber()
{
    int number = rand () % 1000 + 1;
    
    return number;
}

/**************************************************************
 * Stackqueue::inRoll ()                                      *
 ***************************************************************/

int Stackqueue::inRoll()
{
    int number = rand () % 100 + 1;
    
    return number;
}

/**************************************************************
 * Stackqueue::outRoll ()                                     *
 ***************************************************************/

int Stackqueue::outRoll ()
{
    int number = rand () % 100 + 1;
    
    return number;
}

/**************************************************************
 * Stackqueue::displayQueue ()                                *
 ***************************************************************/

void Stackqueue::displayQueue(std::queue<int> que)
{
    std::cout << "Queue: " << std::endl;
    
    while (!que.empty())
    {
        std::cout << que.front() << " ";
        que.pop();
    }
}

/**************************************************************
 * Stackqueue::useQueue ()                                    *
 ***************************************************************/

void Stackqueue::useQueue (int in, int out, int r)
{
    int inChance = in;
    int outChance = out;
    int rounds = r;
    int inRollOutcome;
    int outRollOutcome;
    int randNum;
    
    std::queue<int> testQueue;
    
    for (int i = 0; i < rounds; i++)
    {
        std::cout << "\nRound " << i+1 << std::endl;
        randNum = getNumber();
        
        inRollOutcome = inRoll();
        outRollOutcome = outRoll();
        
        if (inRollOutcome < inChance)
        {
            std::cout << randNum << " is added to the Queue!" << std::endl;
            testQueue.push(randNum);
        }
        else
        {
            std::cout << randNum << " failed to be added into the Queue." << std::endl;
        }
        
        if ((outRollOutcome < outChance) && (!testQueue.empty()))
        {
            std::cout << "First number will now be removed from the Queue!" << std::endl;
            testQueue.pop();
        }
        else
        {
            std::cout << "No numbers were removed from the Queue this round." << std::endl;
        }
        
        displayQueue(testQueue);
    }
}

/**************************************************************
 * Stackqueue::palindrome ()                                  *
 ***************************************************************/

std::string Stackqueue::palindrome (std::string input)
{
    std::stack<char> strPalin;
    std::string word = input;
    
    for (int i = 0; i < input.size(); i++)
    {
        strPalin.push(input[i]);
    }
    
    while (!strPalin.empty())
    {
        word += strPalin.top();
        strPalin.pop();
    }
    
    return word;
}
