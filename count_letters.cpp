/*********************************************************************
** Program name: lab2
** Author:       Rebekah Koon
** Date:         7/3/19
** Description:  Source file for void function count_letters, which is
**               used to count and store the number of occurrence of
**               each letter in a paragraph within a file.
*********************************************************************/

#include "count_letters.hpp"

#include <iostream>
#include <fstream>
#include <string>

using std::ifstream;
using std::string;
using std::getline;


/********************************************************************* 
** Description: Void function count_letters takes in a reference to a
**              input file stream variable and a pointer to an array 
**              of integers as parameters. Finds the number of 
**              occurrences of each letter, no matter if it is upper
**              or lowercase, in one paragraph and stores the 
**              frequencies within the array.
**              Source: http://www.cplusplus.com/forum/general/52319/
*********************************************************************/
void count_letters(ifstream &inFile, int *alphabetArr)
{
    string paragraph;
    char symbol;

    //Getting one paragraph of the file
    getline(inFile, paragraph);

    //Determining if symbol is a letter
    for (int i = 0; i < paragraph.length(); i++)
    {
        symbol = paragraph[i];

        if ('a' <= tolower(symbol) && 'z' >= tolower(symbol))
        {
            //Uses ASCII value of lowercase letter to increase letter's count
            alphabetArr[tolower(symbol) - 'a']++;
        }
    }
}