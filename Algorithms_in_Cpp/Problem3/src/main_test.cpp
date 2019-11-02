/*
 * 			~~~~ main_test.cpp ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Divide and Counquer, Sorting and Searching and Randomized Algorithms	
 *	Assignment 2: Computing the number of inversions in a list
 *	Test counting inversion implementation
 * Harold Nikoue
 */
#include "../include/quicksort_routine.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../lib/catch2/catch.hpp"
#include <string>
using namespace std;


long get_num_comparisons_quicksort_1(string filename, int num_lines){
	cout << "Entered num comparisons quicksort1 " << endl;
	long num_comparisons ;
	ulong array_a[num_lines];
	read_input_array(filename, array_a, num_lines);
	cout << "Entering quickssort_1 " << endl;
	num_comparisons = quicksort_1(array_a, num_lines);
	cout << "Exited quicksort_1 " << endl;
	show_array(array_a, num_lines);
	cout << endl;
	cout << "Sorted array using Quicksort and first element as a pivot for a total of " << num_comparisons << " comparisons." << endl;
	return num_comparisons;
}

long get_num_comparisons_quicksort_2(string filename, int num_lines){
	long num_comparisons ;
	ulong array_a[num_lines];
	read_input_array(filename, array_a, num_lines);
	cout << "Entering quicksort_2 " << endl;
	num_comparisons = quicksort_2(array_a, num_lines);
	show_array(array_a, num_lines);
	cout << endl;
	cout << "Sorted array using Quicksort and last element as a pivot for a total of " << num_comparisons << " comparisons." << endl;
	return num_comparisons;
}

long get_num_comparisons_quicksort_3(string filename, int num_lines){
	long num_comparisons ;
	ulong array_a[num_lines];
	read_input_array(filename, array_a, num_lines);
	num_comparisons = quicksort_3(array_a, num_lines);
	show_array(array_a, num_lines);
	cout << endl;
	cout << "Sorted array using Quicksort and median of three elements of the array for a total of " << num_comparisons << " comparisons." << endl;
	return num_comparisons;
}


TEST_CASE("Test from test suite", "[test-suite]")
{
	std::string prefix = "Test/";
	SECTION("dgrcode"){
		long num_comparisons;
		std::string file_name_0 = prefix + "input_dgrcode_01_5.txt" ;
		cout << "calling get_num_comparisons_quicksort_1 " << endl;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_0, 5); 
		REQUIRE(num_comparisons == 6);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_0, 5); 
		REQUIRE(num_comparisons == 10);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_0, 5); 
		REQUIRE(num_comparisons == 6);

		std::string file_name_1 = prefix + "input_dgrcode_02_5.txt" ;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_1, 5); 
		REQUIRE(num_comparisons == 7);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_1, 5); 
		REQUIRE(num_comparisons == 8);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_1, 5); 
		REQUIRE(num_comparisons == 6);

		std::string file_name_2 = prefix + "input_dgrcode_03_5.txt" ;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_2, 5); 
		REQUIRE(num_comparisons == 7);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_2, 5); 
		REQUIRE(num_comparisons == 7);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_2, 5); 
		REQUIRE(num_comparisons == 6);

		std::string file_name_3 = prefix + "input_dgrcode_04_5.txt" ;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_3, 5); 
		REQUIRE(num_comparisons == 7);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_3, 5); 
		REQUIRE(num_comparisons == 6);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_3, 5); 
		REQUIRE(num_comparisons == 6);

		std::string file_name_4 = prefix + "input_dgrcode_05_5.txt" ;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_4, 5); 
		REQUIRE(num_comparisons == 7);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_4, 5); 
		REQUIRE(num_comparisons == 8);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_4, 5); 
		REQUIRE(num_comparisons == 6);

		std::string file_name_5 = prefix + "input_dgrcode_06_10.txt" ;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_5, 10); 
		REQUIRE(num_comparisons == 26);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_5, 10); 
		REQUIRE(num_comparisons == 21);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_5, 10); 
		REQUIRE(num_comparisons == 21);

		std::string file_name_6 = prefix + "input_dgrcode_07_10.txt" ;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_6, 10); 
		REQUIRE(num_comparisons == 28);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_6, 10); 
		REQUIRE(num_comparisons == 22);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_6, 10); 
		REQUIRE(num_comparisons == 22);

		std::string file_name_7 = prefix + "input_dgrcode_08_10.txt" ;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_7, 10); 
		REQUIRE(num_comparisons == 23);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_7, 10); 
		REQUIRE(num_comparisons == 21);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_7, 10); 
		REQUIRE(num_comparisons == 19);

		std::string file_name_8 = prefix + "input_dgrcode_09_10.txt" ;
		num_comparisons = get_num_comparisons_quicksort_1(file_name_8, 10); 
		REQUIRE(num_comparisons == 25);
		num_comparisons = get_num_comparisons_quicksort_2(file_name_8, 10); 
		REQUIRE(num_comparisons == 27);
		num_comparisons = get_num_comparisons_quicksort_3(file_name_8, 10); 
		REQUIRE(num_comparisons == 23);

	}
}
