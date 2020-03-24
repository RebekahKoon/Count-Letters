## Program name: lab2
## Author:       Rebekah Koon
## Date:         7/3/19
## Description:  Makefile that compiles a program that counts 
##               the frequency of letters in each paragraph of
##               a file and stores each paragraph's letter
##               frequency data in a separate file.

CXXFLAGS = -std=c++11

lab2: main.o count_letters.o output_letters.o
	g++ $(CXXFLAGS) main.o count_letters.o output_letters.o -o lab2

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

count_letters.o: count_letters.cpp
	g++ $(CXXFLAGS) -c count_letters.cpp

output_letters.o: output_letters.cpp
	g++ $(CXXFLAGS) -c output_letters.cpp

clean:
	rm *.o lab2