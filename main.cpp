/*********************************************************************
** Program name: lab2
** Author:       Rebekah Koon
** Date:         7/3/19
** Description:  This program counts the number frequencies of letters
**               within each paragraph of a file. The program runs by
**               asking the user to enter a file to read. If the file
**               is found, calls function count_letters to count the
**               occurrences of each letter in a paragraph, then calls
**               function output_letters to store the frequencies in
**               a user-selected file. This repeats for each paragraph
**               in the file that is being read.
*********************************************************************/

#include "count_letters.hpp"
#include "output_letters.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <typeindex>

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
    string fileName;
    ifstream inFile;
    ofstream outFile;

    const int LETTERS = 26;
    int count = 0;
    int *alphabet = new int[LETTERS];

    cout << "The frequencies of letters in each paragraph of a chosen" << endl
         << "file will be found and stored in separate files." << endl << endl;

    cout << "What file would you like to read?" << endl
         << "Type in the name of the file: ";
    getline(cin, fileName);

    inFile.open(fileName.c_str());

    //If the selected file cannot be opened
    while (!inFile)
    {
        cout << endl << "File could not be found." << endl
             << "Please enter another name: ";
        getline(cin, fileName);

        inFile.open(fileName.c_str());
    }

    cout << fileName << " will be opened." << endl << endl;

    //Going through each paragraph in the file
    while (!inFile.eof())
    {
        //Used to keep track of the paragraph number
        count ++;

        //Initializing the frequency of each letter to 0 for each paragraph
        for (int i = 0; i < LETTERS; i++)
        {
            alphabet[i] = 0;
        }

        //Counting the letter frequency of a single paragraph in the file
        count_letters(inFile, alphabet);

        cout << "What file should store the frequency data for paragraph #"
             << count << "?" << endl;
        
        //Putting letter frequency into user-selected file
        output_letters(outFile, alphabet);
    }

    //If only one paragraph was in the file that was read
    if (count == 1)
    {
        cout << count << " file has been added that contains the " << endl
             << "paragraph's frequency count for each letter." << endl;
    }

    //If more than one paragraph was in the file that was read
    else
    {
        cout << count << " files have been added. Each file contains " << endl
             << "one paragraph's frequency count for each letter." << endl;
    }

    inFile.close();
    outFile.close();

    delete [] alphabet;

    return 0;
}
