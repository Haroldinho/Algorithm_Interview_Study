/*
 * 			~~~~ main_test.cpp ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Divide and Counquer, Sorting and Searching and Randomized Algorithms	
 *	Assignment 4: Finding the minimum cut in a connected graph
 * Harold Nikoue
 */
#include "karger_min_cut.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../lib/catch2/catch.hpp"
#include <string>
#include <math.h>
using namespace std;


TEST_CASE("Test from test suite", "[test-suite]")
{
	std::string prefix = "Test/";
	SECTION("random_test"){
		int min_num_cuts, num_trials;
		std::string file_name_0 = prefix + "input_random_1_6.txt" ;
		num_trials = 6*log2(6) + 1; 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name_0, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials." << endl;
		REQUIRE(min_num_cuts == 2);

		std::string file_name_1 = prefix + "input_random_2_6.txt" ;
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name_1, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials." << endl;
		REQUIRE(min_num_cuts == 1);

		std::string file_name_2 = prefix + "input_random_3_6.txt" ;
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name_2, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials." << endl;
		REQUIRE(min_num_cuts == 3);

		std::string file_name_3 = prefix + "input_random_4_6.txt" ;
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name_3, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials." << endl;
		REQUIRE(min_num_cuts == 4);

		std::string file_name_4 = prefix + "input_random_5_10.txt" ;
		num_trials = 10*log2(10) + 1; 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name_4, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials." << endl;
		REQUIRE(min_num_cuts == 4);

		std::string file_name_5 = prefix + "input_random_6_10.txt" ;
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name_5, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials." << endl;
		REQUIRE(min_num_cuts == 3);
		
		int size_file = 25;
		std::string file_name = prefix + "input_random_10_25.txt" ;
		num_trials = size_file*log2(size_file) + 1; 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials for file " << file_name << "."  << endl;
		REQUIRE(min_num_cuts == 6);

		file_name = prefix + "input_random_15_50.txt" ;
		size_file = 50;
		num_trials = size_file*log2(size_file) + 1; 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials for file " << file_name << "."  << endl;
		REQUIRE(min_num_cuts == 14);

		file_name = prefix + "input_random_18_75.txt" ;
		size_file = 75;
		num_trials = size_file*log2(size_file) + 1; 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials for file " << file_name << "."  << endl;
		REQUIRE(min_num_cuts == 15);

		file_name = prefix + "input_random_22_100.txt" ;
		size_file = 100;
		num_trials = size_file*log2(size_file) + 1; 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials for file " << file_name << "."  << endl;
		REQUIRE(min_num_cuts == 23);

		file_name = prefix + "input_random_27_125.txt" ;
		size_file = 125;
		num_trials = size_file*log2(size_file) + 1; 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials for file " << file_name << "."  << endl;
		REQUIRE(min_num_cuts == 36);

		file_name = prefix + "input_random_29_150.txt" ;
		size_file = 150;
		num_trials = size_file*log2(size_file); 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials for file " << file_name << "."  << endl;
		REQUIRE(min_num_cuts == 37);

		file_name = prefix + "input_random_34_175.txt" ;
		size_file = 175;
		num_trials = size_file*log2(size_file); 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials for file " << file_name << "."  << endl;
		REQUIRE(min_num_cuts == 45);

		file_name = prefix + "input_random_37_200.txt" ;
		size_file = 200;
		num_trials = size_file*log2(size_file); 
		cout << "Running min_cut for " << num_trials << " trials." << endl;
		min_num_cuts = main_karger_min_cut(file_name, num_trials);
		cout << "The minimum cut has " << min_num_cuts << " cut" << ((min_num_cuts>1)?"s":"")<< " after " << num_trials << " trials for file " << file_name << "."  << endl;
		REQUIRE(min_num_cuts == 54);


	}
}
