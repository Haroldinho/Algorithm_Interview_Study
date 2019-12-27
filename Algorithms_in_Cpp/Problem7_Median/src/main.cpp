/*
 *
 * 			~~~~ main_median.cpp ~~~~
 * 		Coursera: Algorithms with Tim Roughegarden
 * 	Course 2: Graph Search, Shortest Paths and Data Structures
 *	Assignment 3: Implementing Running median for a list of numbers
 *	Need to return the sum of the running median
 * 
 *	The goal of this problem is to implement the "Median Maintenance" algorithm. 
 * 	The text file contains a list of the integers from 1 to 10000 in unsorted order; 
 * 	you should treat this as a stream of numbers, arriving one by one. Letting x_ix 
 *
 * This file introduces a median heap class that handles two different heaps to support
 * insertion of any number in O(1)
 * retrieval of the median in O(1)
 *
 *
 */


#include "median.h"
#include <string>
#include <iostream>
using namespace std;

int main(){
	// 
	string FILE_NAME = "Median.txt";
	unsigned int running_sum_ending = main_median(FILE_NAME);
	cout << "\n\n <<<<<< The answer is: " << running_sum_ending;
        cout <<     ". >>>>>>"	<<endl;
	
}
