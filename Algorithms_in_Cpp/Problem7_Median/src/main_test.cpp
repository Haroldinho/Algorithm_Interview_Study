/*
 * 			~~~~ main_test.cpp ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Algorithms: Programming Assignment #5
 * Run the Kasaraju strong component analysis on a 
 * Harold Nikoue
 */
#include "median.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../lib/catch2/catch.hpp"
#include <string>
#include <math.h>
using namespace std;



TEST_CASE("Median Tests  Small DataSets", "[Test 1 of 3]")
{	
	std::string prefix = "Tests/input_random_";
	SECTION("test_1"){
		string suffix = "1_10.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 53);
	}
	SECTION("test_2"){
		string suffix = "2_10.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 32);
	}
	SECTION("test_3"){
		string suffix = "3_10.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 43);
	}
	SECTION("test_4"){
		string suffix = "4_10.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 56);
	}
	SECTION("test_5"){
		string suffix = "5_20.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 168);
	}

}

TEST_CASE("Median Tests  Medium DataSets", "[Test 2 of 3]")
{	
	std::string prefix = "Tests/input_random_";
	SECTION("test_1"){
		string suffix = "10_40.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 695);
	}
	SECTION("test_2"){
		string suffix = "12_40.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 834);
	}
	SECTION("test_3"){
		string suffix = "15_80.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 3033);
	}
	SECTION("test_4"){
		string suffix = "18_160.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 3151);
	}
	SECTION("test_5"){
		string suffix = "20_160.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 1898);
	}

}
TEST_CASE("Median Tests Large  DataSets", "[Test 3 of 3]")
{	
	std::string prefix = "Tests/input_random_";
	SECTION("test_1"){
		string suffix = "21_320.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 8114);
	}
	SECTION("test_2"){
		string suffix = "23_320.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 8306);
	}
	SECTION("test_3"){
		string suffix = "25_640.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 698);
	}
	SECTION("test_4"){
		string suffix = "28_640.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 9063);
	}
	SECTION("test_5"){
		string suffix = "30_1280.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 3110);
	}
	SECTION("test_6"){
		string suffix = "38_5120.txt";
		unsigned int running_sum_end = main_median(prefix+suffix);
		REQUIRE(running_sum_end == 7282);
	}

}
