// Lab01.cpp
// Duyen Pham
// COSC 2030 Fall 2018 
// Lab01
// September 22, 2018

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::getline;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

#define NUM_SIZE 2

string promptUser(void);
void extractInfo(ifstream& inFile, int *num_count, double first_pair[], double last_pair[]);

int main()
{
	double firstnums[NUM_SIZE];
	double lastnums[NUM_SIZE];
	int total_num = 0;
	ifstream inFile;
	string fileName;

	// Get the file name and store it.
	fileName = promptUser();

	// Attempt to open the file.
	inFile.open(fileName);

	// Check for Error.
	if (inFile.fail())
	{
		cerr << "Error Opening File!" << endl;
		exit(1);
	}

	// Get info needed from file.
	extractInfo(inFile, &total_num, firstnums, lastnums);
	inFile.close();

	cout << endl;
	cout << "The total count of numbers in the file is " << total_num << endl;
	cout << "The first two numbers are " << firstnums[0] << " and " << firstnums[1] << endl;
	cout << "The last two numbers are " << lastnums[0] << " and " << lastnums[1] << endl;

	return 0;
}

string promptUser(void)
{
	string file;

	cout << "\n\nEnter name of input file: ";
	getline(cin, file);

	return file;
}

void extractInfo(ifstream& inFile, int *num_count, double first_pair[], double last_pair[])
{
	string item;

	// Get numbers from file.
	while (inFile >> item)
	{
		// Update last pair of numbers.
		last_pair[0] = last_pair[1];
		last_pair[1] = stod(item);

		// Update first pair of numbers.
		if (*num_count == 0)
			first_pair[0] = stod(item);
		else if (*num_count == 1)
			first_pair[1] = stod(item);

		// Count number of elements in file.
		*num_count = *num_count + 1;

	}
}

