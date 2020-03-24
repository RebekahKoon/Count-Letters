/*********************************************************************
** Program name: lab2
** Author:       Rebekah Koon
** Date:         7/3/19
** Description:  Void function output_letters take reference to an 
**               output file stream and a pointer to an array of 
**               integers containing the frequency of letters in a 
**               paragraph as parameters. Asks the user for an output
**               file's name and then outputs the contents of the 
**               array into the output file.
*********************************************************************/

#ifndef OUTPUT_LETTERS_HPP
#define OUTPUT_LETTERS_HPP

#include <fstream>

using std::ofstream;

void output_letters(ofstream &, int *);

#endif