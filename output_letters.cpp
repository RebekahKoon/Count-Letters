/*********************************************************************
** Program name: lab2
** Author:       Rebekah Koon
** Date:         7/3/19
** Description:  Source file for void function output_letters, which
**               takes a reference to an output file stream and a 
**               pointer to an array as parameters and stores the 
**               contents of the array into the output file.
*********************************************************************/

#include "output_letters.hpp"

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::getline;
using std::ofstream;
using std::string;
using std::endl;


/*********************************************************************
** Description: Void function output_letters takes a reference to an
**              output file and a pointer to an array containing the
**              frequency of letters in a paragraph as parameters.
**              Asks the user to type in the file name and, if the
**              file can be opened, stores each letter's frequency
**              into the chosen file.
**              Source: Gaddis et al., section 13.3 (pp. 865-877)
*********************************************************************/
void output_letters(ofstream &outFile, int *alphabetArr)
{
    string file;
    const int LETTERS = 26;
    char firstLetter = 'a';
    char currentLetter;

    cout << "Please type in the name of the output file: ";
    getline(cin, file);

    outFile.open(file.c_str());

    //If the file does not open
    while (!outFile)
    {
        cout << endl << "The file could not be opened." << endl
             << "Please type in another file name: ";
        getline(cin, file);

        outFile.open(file.c_str());
    }

    //Storing each letter's frequency within the selected file
    for (int i = 0; i < LETTERS; i++)
    {
        //Using ASCII to find character for current letter
        currentLetter = firstLetter + i;

        outFile << currentLetter << ": " << alphabetArr[i] << endl;
    }

    cout << "Frequency data has been sent to " << file << endl << endl;

    outFile.close();
}