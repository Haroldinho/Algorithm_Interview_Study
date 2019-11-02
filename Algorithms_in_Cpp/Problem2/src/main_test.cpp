/*
 * 			~~~~ main_test.cpp ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Divide and Counquer, Sorting and Searching and Randomized Algorithms	
 *	Assignment 2: Computing the number of inversions in a list
 *	Test counting inversion implementation
 * Harold Nikoue
 */
#include "../include/count_inversion.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../lib/catch2/catch.hpp"
#include <string>


long count_num_inversions(std::string file_name, int num_lines_read){
	ull input_array[num_lines_read];
       	read_input_array(file_name, input_array, num_lines_read);
//	std::cout << "Initial Array: \t";
//	show_array(input_array, num_lines_read);
	long result =  count_array(&input_array[0], num_lines_read);
//	std::cout << "Final Array: \t";
//	show_results(input_array, num_lines_read, result);
	return result;
}

TEST_CASE("Test from test suite", "[test-suite]")
{
	std::string prefix = "TestSuite/";
	SECTION("beaunus"){
		long num_inversions;
		std::string file_name_0 = prefix + "input_beaunus_1_4.txt" ;
		num_inversions = count_num_inversions(file_name_0, 4); 
		REQUIRE(num_inversions == 4);

		std::string file_name_1 = prefix + "input_beaunus_2_4.txt" ;
		REQUIRE(count_num_inversions(file_name_1,4) == 3);

		std::string file_name_2 = prefix + "input_beaunus_3_4.txt" ;
		REQUIRE(count_num_inversions(file_name_2, 4) == 2);

		std::string file_name_3 = prefix + "input_beaunus_4_4.txt" ;
		REQUIRE(count_num_inversions(file_name_3, 4) == 6);

		std::string file_name_4 = prefix + "input_beaunus_5_8.txt" ;
		REQUIRE(count_num_inversions(file_name_4, 8) == 15);

		std::string file_name_5 = prefix + "input_beaunus_6_8.txt" ;
		REQUIRE(count_num_inversions(file_name_5, 8) == 18);

		std::string file_name_6 = prefix + "input_beaunus_7_8.txt" ;
		REQUIRE(count_num_inversions(file_name_6, 8) == 17);

		std::string file_name_7 = prefix + "input_beaunus_8_8.txt" ;
		REQUIRE(count_num_inversions(file_name_7, 8) == 16);

		std::string file_name_8 = prefix + "input_beaunus_9_16.txt" ;
		REQUIRE(count_num_inversions(file_name_8, 16) == 65);

		std::string file_name_9 = prefix + "input_beaunus_10_16.txt" ;
		REQUIRE(count_num_inversions(file_name_9, 16) == 64);

		std::string file_name_13 = prefix + "input_beaunus_23_128.txt" ;
		REQUIRE(count_num_inversions(file_name_13, 128) == 3839);

		std::string file_name_10 = prefix + "input_beaunus_25_256.txt" ;
		REQUIRE(count_num_inversions(file_name_10, 256) == 16444);

		std::string file_name_11 = prefix + "input_beaunus_30_512.txt" ;
		REQUIRE(count_num_inversions(file_name_11, 512) == 63957);

		std::string file_name_12 = prefix + "input_beaunus_48_8192.txt" ;
		REQUIRE(count_num_inversions(file_name_12, 8192) == 16590181);

	}
}
