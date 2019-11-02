/*
 * 			~~~~ main_test.cpp ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Algorithms: Programming Assignment #5
 * Run the Kasaraju strong component analysis on a 
 * Harold Nikoue
 */
#include "scc.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../lib/catch2/catch.hpp"
#include <string>
#include <math.h>
using namespace std;


TEST_CASE("Graph is of correct size and return correct output small graph", "[test-size-correctness_1]")
{
	std::string prefix = "Test/";
	std::string file_name_0 = prefix + "input_mostlyCycles_1_8.txt" ;
	int max_num_elements = 8;

	SECTION("test_length"){
		int num_nodes;
		cout << "Reading file: " << file_name_0 << endl;
		graph G = read_input_graph(file_name_0, max_num_elements, num_nodes);  
		show_graph(G, num_nodes);
		REQUIRE(num_nodes <= 8);
	}
	SECTION("mostly_cycles_correctness_test"){
		string expected_answer = "4,2,2,0,0";
		string actual_answer;
		cout << "Running Kasaraju's strong connected component analysis on " << max_num_elements << " nodes." << endl;
		actual_answer = main_kasaraju(file_name_0, max_num_elements);
		cout << "Expected answer= " << expected_answer << endl;
		REQUIRE(actual_answer.compare(expected_answer) == 0);
	}
}
TEST_CASE("Graph is of correct size and return correct output small graph_2", "[test-size-correctness_2]")
{
	std::string prefix = "Test/";
	std::string file_name_0 = prefix + "input_mostlyCycles_2_8.txt" ;
	int max_num_elements = 8;

	SECTION("test_length"){
		int num_nodes;
		cout << "Reading file: " << file_name_0 << endl;
		graph G = read_input_graph(file_name_0, max_num_elements, num_nodes);  
		show_graph(G, num_nodes);
		REQUIRE(num_nodes <= 8);
	}
	SECTION("mostly_cycles_correctness_test"){
		string expected_answer = "8,0,0,0,0";
		string actual_answer;
		cout << "Running Kasaraju's strong connected component analysis on " << max_num_elements << " nodes." << endl;
		actual_answer = main_kasaraju(file_name_0, max_num_elements);
		cout << "Expected answer= " << expected_answer << endl;
		REQUIRE(actual_answer.compare(expected_answer) == 0);
	}
}
TEST_CASE("Graph is of correct size and return correct output small graph_10", "[test-size-correctness_10]")
{
	std::string prefix = "Test/";
	std::string file_name_0 = prefix + "input_mostlyCycles_10_32.txt" ;
	int max_num_elements = 8;

	SECTION("test_length"){
		int num_nodes;
		cout << "Reading file: " << file_name_0 << endl;
		graph G = read_input_graph(file_name_0, max_num_elements, num_nodes);  
		show_graph(G, num_nodes);
		REQUIRE(num_nodes <= 8);
	}
	SECTION("mostly_cycles_correctness_test"){
		string expected_answer = "11,10,5,4,0";
		string actual_answer;
		cout << "Running Kasaraju's strong connected component analysis on " << max_num_elements << " nodes." << endl;
		actual_answer = main_kasaraju(file_name_0, max_num_elements);
		cout << "Expected answer= " << expected_answer << endl;
		REQUIRE(actual_answer.compare(expected_answer) == 0);
	}
}
