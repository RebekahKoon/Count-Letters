/**********************************************************************
** Program name: lab2
** Author:       Rebekah Koon
** Date:         7/3/19
** Description:  Header file for void function count_letters. Takes an
**               input file stream variable by reference and a pointer
**               to an array of integers as parameters. Counts the
**               number of occurrences of each letter in one paragraph
**               and stores the frequencies in the array.
**********************************************************************/

#ifndef COUNT_LETTERS_HPP
#define COUNT_LETTERS_HPP

#include <iostream>

using std::ifstream;

void count_letters(ifstream &, int *);

#endif