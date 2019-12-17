/*
 * 			~~~~ main_test.cpp ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Algorithms: Programming Assignment #5
 * Run the Kasaraju strong component analysis on a 
 * Harold Nikoue
 */
#include "graph_functions.h"
#include "dijkstra.h"
#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../lib/catch2/catch.hpp"
#include <string>
#include <math.h>
using namespace std;


//TEST_CASE("Graph is of correct size and return correct output small graph", "[test-size-correctness_1]")
//{
//	std::string prefix = "";
//	std::string file_name_0 = prefix + "dijkstraData.txt" ;
//	string path_prefix = "Paths/path_"
//
//	int num_nodes;
//	AdjacencyGraph G = read_input_adjacency_list(file_name_0, num_nodes);  
//	SECTION("test_length"){
//		cout << "Reading file: " << file_name_0 << endl;
//		//show_graph(G);
//		REQUIRE(num_nodes == 200);
//	}
//
//	SECTION("test_root_node_0"){
//		string suffix = "main.txt";
//		std::string file_name = prefix + suffix ;
//		string path_file_name = path_prefix + suffix;
//		cout << "Reading file: " << file_name << endl;
//		cout << "Cost to root node should  be zero " << endl;
//		vector<unsigned int> shortest_path_list = compute_dijkstra_shortest_path(G, path_file_name);
//		REQUIRE(shortest_path_list[1] == 0);
//	}
//}

TEST_CASE("Medium Tests on paths with known solution", "[battery_of_test_1]")
{	
	std::string prefix = "Tests/input_random_";
	string path_prefix = "Paths/path_";
	vector<unsigned int> target_vertices = {7,37,59,82,99,115,133,165,188,197};

	SECTION("test_1"){
		string suffix = "1_4.txt";
		vector<unsigned int> shortest_path_list = 
			return_shortest_path(prefix, suffix, path_prefix);
		vector<unsigned int> target_cost = {253,172,197,242,331,402,143,272,249,265};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_2"){
		std::string suffix =  "2_4.txt";
		vector<unsigned int> shortest_path_list = 
			return_shortest_path(prefix, suffix, path_prefix);
		vector<unsigned int> target_cost = {247,431,362,429,376,382,430,474,430,361};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_5"){
		std::string suffix =  "5_8.txt";
		vector<unsigned int> shortest_path_list = 
			return_shortest_path(prefix, suffix, path_prefix);
		vector<unsigned int> target_cost = {341,463,256,406,341,244,198,305,361,371};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_7"){
		std::string suffix =  "7_8.txt";
		vector<unsigned int> shortest_path_list = 
			return_shortest_path(prefix, suffix, path_prefix);
		vector<unsigned int> target_cost = {161,252,304,208,103,60,363,235,245,203};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_10"){
		string suffix = "10_16.txt";
		vector<unsigned int> shortest_path_list = 
			return_shortest_path(prefix, suffix, path_prefix);
		vector<unsigned int> target_cost = {588,405,675,521,909,328,418,957,830,839};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_15"){
		string suffix = "15_32.txt";
		vector<unsigned int> shortest_path_list = 
			return_shortest_path(prefix, suffix, path_prefix);
		vector<unsigned int> target_cost = {5194,9990,8494,8548,14509,14421,8601,10812,9890,6589};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}

}

TEST_CASE("Advanced Tests on paths with known solution", "[battery_of_test_2]")
{	
	std::string prefix = "Tests/input_random_";
	vector<unsigned int> target_vertices = {7,37,59,82,99,115,133,165,188,197};
	string path_prefix = "Paths/path_";
	SECTION("test_20"){
		string suffix = "20_64.txt";
		vector<unsigned int> shortest_path_list = 
			return_shortest_path(prefix, suffix, path_prefix);
		vector<unsigned int> target_cost = {699513,452243,60365,166860,289662,820910,593399,836776,621238,439299};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_21"){
		string suffix = "21_128.txt";
		vector<unsigned int> shortest_path_list = 
			return_shortest_path(prefix, suffix, path_prefix);
		vector<unsigned int> target_cost = {50457,53230,69495,56659,62464,59575,59741,39038,73375,152141};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_22"){

		string suffix = "22_128.txt";
		std::string file_name = prefix + suffix ;
		string path_file_name = path_prefix + suffix;
		cout << "Reading file: " << file_name << endl;
		int num_nodes;
		AdjacencyGraph G = read_input_adjacency_list(file_name, num_nodes);  
		vector<unsigned int> shortest_path_list = compute_dijkstra_shortest_path(G, path_file_name);
		vector<unsigned int> target_cost = {232502,181515,149506,143014,106325,338747,172980,124364,162768,156250};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_23"){
		string suffix = "23_128.txt";
		std::string file_name = prefix + suffix ;
		string path_file_name = path_prefix + suffix;
		cout << "Reading file: " << file_name << endl;
		int num_nodes;
		AdjacencyGraph G = read_input_adjacency_list(file_name, num_nodes);  
		vector<unsigned int> shortest_path_list = compute_dijkstra_shortest_path(G, path_file_name);
		vector<unsigned int> target_cost = {677840,788375,514311,303598,431966,491550,533171,444822,350078,514566};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_24"){
		string suffix = "24_128.txt";
		std::string file_name = prefix + suffix ;
		string path_file_name = path_prefix + suffix;
		cout << "Reading file: " << file_name << endl;
		int num_nodes;
		AdjacencyGraph G = read_input_adjacency_list(file_name, num_nodes);  
		vector<unsigned int> shortest_path_list = compute_dijkstra_shortest_path(G, path_file_name);
		vector<unsigned int> target_cost = {28256,26397,28788,24491,48786,27993,29617,19807,40062,31045};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
	SECTION("test_28"){
		string suffix = "28_256.txt";
		std::string file_name = prefix + suffix ;
		string path_file_name = path_prefix + suffix;
		cout << "Reading file: " << file_name << endl;
		int num_nodes;
		AdjacencyGraph G = read_input_adjacency_list(file_name, num_nodes);  
		vector<unsigned int> shortest_path_list = compute_dijkstra_shortest_path(G, path_file_name);
		vector<unsigned int> target_cost = {561210,512598,559247,660768,485338,534807,364902,307456,511454,453935};
		REQUIRE(get_output_cost(shortest_path_list) == target_cost);
	}
}
