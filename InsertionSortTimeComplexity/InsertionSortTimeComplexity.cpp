/***********************************************************************************/
/* Course - Assignment - Semester: CSCI 602 - Assignment 1 - Spring 2020           */
/*                                                                                 */
/* Progammer: Flores, Joshua A.                                                    */
/* Z-ID: z1682720                                                                  */
/* Section: 1                                                                      */
/* Date Due: January 28, 2020                                                      */
/*                                                                                 */
/* Purpose: This program takes one mandatory and two optional arguments. It        */
/* creates an array of a specific size (otherwise the default) and sorts in        */
/* ascending, descending, or random order. Finally, it sorts the array in          */
/* ascending order (if not already sorted in ascending order) using the insertion  */
/* sort mechanism.                                                                 */
/***********************************************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

using std::cout;
using std::cin;
using std::endl;

const int DEF_SIZE = 10;
const string DEF_ORDER = "R", DEF_ALG = "I", DELIMITER = "=";

string getToken(string str);
void checkInsertArg(int strToInt_Sz, string sortToken, string insAlg);
void error(string message);
void ascending(int n);
void descending(int n);
void random(int n);
void chooseSortOrder(int n = DEF_SIZE, string s = DEF_ORDER);
void insertionSort(int * p, int s);
void printArray(int * p, int s);

int main(int argc, char** argv)
{
	string number = "", sort = "", numberToken = "", sortToken = "", insAlg = "", insAlgToken = "";
	int strToInt_Sz = 0;

	/*Takes the arguments from the command line and determines which type of call is required.
	Defaults to command with two arguments (the name of the executable program and the argument
	for the algorithm). The last argument is, however, useless as the purpose of each module is 
	to focus on one algorithm specifically. Therefore, even though "S" is selected, it will always 
	run insertion, to avoid confusion. This is the purpose of the two separate module, as specified 
	in the assignment.
	*/
	if (argc == 4) {
		number = argv[1];
		sort = argv[2];
		insAlg = argv[3];
		string numberToken = getToken(number), sortToken = getToken(sort), algToken = getToken(insAlg);
		int strToInt_Sz = stoi(numberToken);
		checkInsertArg(strToInt_Sz, sortToken, insAlg);
	}
	else if (argc == 3) {
		string firstArg = argv[1];
		string firstArgToken = getToken(firstArg);
		if ((stoi(firstArgToken)) == true) {
			strToInt_Sz = stoi(numberToken);
			insAlg = argv[2];
			checkInsertArg(strToInt_Sz, DEF_ORDER, insAlg);
		}
		else {
			sort = argv[1];
			sortToken = getToken(sort);
			insAlg = argv[2];
			checkInsertArg(DEF_SIZE, sortToken, insAlg);
		}
	}
	else {
		insAlg = argv[1];
		insAlgToken = getToken(insAlg);
		checkInsertArg(DEF_SIZE, DEF_ORDER, insAlgToken);
	}
}

string getToken(string str) {
	string token = str.substr(str.find(DELIMITER) + 1);
	return token;
}

void checkInsertArg(int strToInt_Sz, string sortToken, string insAlg) {
	string insAlgToken = getToken(insAlg);
	if (insAlgToken.compare("I") == 0) {
		chooseSortOrder(strToInt_Sz, sortToken);
	}
	else {
		error("This is module supports insertion sorting only! Provide argument G=I.");
	}
}

void error(string message = "Enter a positive number!") {
	cout << "ERROR: " + message << endl;
}

void ascending(int n) {
	int size = 0;

	if (n > 1) {
		int *array = new int[n];
		for (int j = 0; j <= n - 1; j++) {
			array[j] = j;
			size = j + 1;
		}
		printArray(array, n);
		cout << "Array Size: " << size << endl;
		insertionSort(array, size);
	}
	else {
		error();
	}
}

void descending(int n) {
	int size = 0;

	if (n > 1) {
		int *array = new int[n];
		for (int j = 0; n - 1 >= 0; j++) {
			n--;
			array[j] = n;
			size = j + 1;
		}
		printArray(array, n);
		cout << "Array Size: " << size << endl;
		insertionSort(array, size);
	}
	else {
		error();
	}
}

void random(int n) {
	int size = 0;

	/* This will create an array with all random numbers.*/
	if (n > 1) {
		int *array = new int[n];
		srand((unsigned)time(0));
		for (int j = 0; n - 1 >= 0; j++) {
			n--;
			array[j] = (rand() % 1000) + 1;
			size = j + 1;
		}
		printArray(array, size);
		cout << "Array Size: " << size << endl;
		insertionSort(array, size);
	}
	else {
		error();
	}
}

void chooseSortOrder(int n, string s) {

	// Conditional statements to run the program depending on the provided argument for sorting order.
	if (s.compare("A") == 0) {
		ascending(n);
	}
	else if (s.compare("D") == 0) {
		descending(n);
	}
	else if (s.compare("R") == 0){
		random(n);
	}
	else if (s.compare("A") != 0 || s.compare("D") != 0 || s.compare("R") != 0){
		error("Provide only valid optional parameters (S=A, S=D, or S=R) /n or leave the optional field blank for the defualt random sorting.");
	}
	else {
		random(n);
	}
}

void insertionSort(int * p, int s) {

	cout << endl << "Insertion Sort" << endl;
	cout << "-----------------------" << endl;

	/* key is initially set to the array's third element.
	i is set to 1. While i is greater than zero and the array's
	current element is greather than the key, sort is necessary.
	swapping p's upcoming element with the previous both.
	*/
	for (int j = 1; j < s; j++) {
		int key = p[j];
		int i = j - 1;
		while (i >= 0 && p[i] > key) {
			p[i + 1] = p[i];
			i--;
		}
		p[i + 1] = key;
	}
	printArray(p, s);
}

void printArray(int * p, int s) {
	for (int o = 0; o < s; o++) {
		cout << "A[" << o << "] = " << p[o] << endl;
	}
}

