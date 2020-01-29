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
const string DEF_ORDER = "R";

void error();
void ascending(int n);
void descending(int n);
void random(int n);
void chooseFunction(int n = DEF_SIZE, string s = DEF_ORDER);
void insertionSort(int * p, int s);
void printArray(int * p, int s);

int main(int argc, char** argv)
{
	string order;
	string size = "";
	int strToInt_Sz = 0;

	if (argc == 4) {

		size = argv[1];
		strToInt_Sz = stoi(size);
		order = *argv[2];
		chooseFunction(strToInt_Sz, order);
	}
	else if (argc == 3) {

		if ((int)*argv[1]) {
			size = argv[1];
			strToInt_Sz = stoi(size);
			chooseFunction(strToInt_Sz, DEF_ORDER);
		}
		else {
			order = argv[1];
			chooseFunction(DEF_SIZE, order);
		}
	}
	else {
		chooseFunction(DEF_SIZE, DEF_ORDER);
	}
}

void error() {
	cout << "ERROR: Please enter a positive number!" << endl;
}

void ascending(int n) {
	int size = 0;

	if (n > 1) {
		int *array = new int[n];
		for (int j = 0; j <= n - 1; j++) {
			array[j] = j;
			cout << "a[" << j << "] = " << array[j] << endl;
			size = j + 1;

		}
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
			cout << "a[" << j << "] = " << array[j] << endl;
			size = j + 1;
		}
		cout << "Array Size: " << size << endl;
		insertionSort(array, size);
	}
	else {
		error();
	}
}

void random(int n) {
	int size = 0;

	if (n > 1) {
		int *array = new int[n];
		srand((unsigned)time(0));
		for (int j = 0; n - 1 >= 0; j++) {
			n--;
			array[j] = (rand() % 1000) + 1;
			cout << "a[" << j << "] = " << array[j] << endl;
			size = j + 1;
		}
		cout << "Array Size: " << size << endl;
		insertionSort(array, size);
	}
	else {
		error();
	}
}

void chooseFunction(int n, string s) {

	if (s.compare("A") == 0) {
		ascending(n);
	}
	else if (s.compare("D") == 0) {
		descending(n);
	}
	else {
		random(n);
	}

}

void insertionSort(int * p, int s) {

	cout << endl << "Insertion Sort" << endl;
	cout << "---------------------- - " << endl;

	for (int j = 2; j <= s; j++) {
		int key = p[j];
		int i = j - 1;
		while (i > 0 && p[i] > key)
		{
			p[i + 1] = p[i];
			i--;
		}
		p[i + 1] = key;
	}
	printArray(p, s);
}

void printArray(int * p, int s) {
	for (int o = 0; o < s; o++) {
		cout << "a[" << o << "] = " << p[o] << endl;
	}
}
