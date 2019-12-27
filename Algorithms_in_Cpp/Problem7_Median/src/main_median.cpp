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
#include<string>
#include<sstream>
#include<fstream>
#include<math.h> // fmod
using namespace std;




unsigned int main_median(std::string file_name){
	long long median_val;
	ifstream main_file(file_name);
	string line;
	int current_num;
	long long running_sum = 0;
	const long DIVIDER_C = 10000;
	// 0. Initialize the median_heap structure, 
	// 	Set the current sum to zero
	Median_heap my_median_object = Median_heap();	
	// Read file line by line
	// 1. Read the input file 
	while(getline(main_file, line)){
		stringstream ss(line);
		ss >> current_num;
	//  1.1. For each number read, insert that number in the median heap
		my_median_object.insert(current_num);
	//  1.2. Return the running median and add it to the running sum
		median_val = my_median_object.get_median();
		running_sum += median_val;
	}//  STOP at the end of the file
	// 2. Get the last 10000 digits of the sum 
	cout << "\n\nTotal running sum is: " << running_sum << endl;

	return (unsigned int)( fmod(running_sum, DIVIDER_C));
}
