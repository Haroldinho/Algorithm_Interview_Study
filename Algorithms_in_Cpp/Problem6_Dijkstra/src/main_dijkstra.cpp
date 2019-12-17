/*
 *			Coursera- Stanford Algorithms Specialization
 *		Graph Search, Shortest Paths, and Data Structures by Stanford University
 *			Algorithms 2 - Assignment 2: Dijkstra Algorithm
 *Prompt:The file contains an adjacency list representation of an undirected weighted graph with 200 vertices labeled 1 to 200. Each row consists of the node tuples that are adjacent to that particular vertex along with the length of that edge. For example, the 6th row has 6 as the first entry indicating that this row corresponds to the vertex labeled 6. The next entry of this row "141,8200" indicates that there is an edge between vertex 6 and vertex 141 that has length 8200. The rest of the pairs of this row indicate the other vertices adjacent to vertex 6 and the lengths of the corresponding edges.

 Your task is to run Dijkstra's shortest-path algorithm on this graph, using 1 (the first vertex) as the source vertex, and to compute the shortest-path distances between 1 and every other vertex of the graph. If there is no path between a vertex vv and vertex 1, we'll define the shortest-path distance between 1 and vv to be 1000000.

std::vector<unsigned int> get_output_cost(std::map<unsigned short, unsigned int> , std::vector<int> test_input = {7,37,59,82,99,115,133,165,188,197});
 You should report the shortest-path distances to the following ten vertices, in order: 7,37,59,82,99,115,133,165,188,197. You should encode the distances as a comma-separated string of integers. So if you find that all ten of these vertices except 115 are at distance 1000 away from vertex 1 and 115 is 2000 distance away, then your answer should be 1000,1000,1000,1000,1000,2000,1000,1000,1000,1000. Remember the order of reporting DOES MATTER, and the string should be in the same order in which the above ten vertices are given. The string should not contain any spaces. Please type your answer in the space provided.
 *
 * Harold Nikoue
 */


#include "graph_functions.h"
#include "dijkstra.h"
#include <iostream>
#include "../../lib/catch2/catch.hpp"
#include <string>
#include <math.h>
using namespace std;


int main(){
	int num_nodes;
	std::string prefix = "";
	std::string file_name_0 = prefix + "dijkstraData.txt" ;
	string path_file_name = prefix + "path.txt;
	cout << "Starting main code by reading file: " << file_name_0 << endl;
	vector<unsigned int> target_vertices = {7,37,59,82,99,115,133,165,188,197};
        vector<unsigned int> result_cost;	

	AdjacencyGraph G = read_input_adjacency_list(file_name_0, num_nodes);  
	unsigned int* shortest_path_list = compute_dijkstra_shortest_path(G, path_file_name);
	vector<unsigned int> target_costs = get_output_cost(shortest_path_list);
	cout << "Found solutions " << endl;
	for(auto target_node: target_vertices){
		result_cost.push_back(target_costs[target_node]);
		cout << "\t " << target_node << " with cost " << shortest_path_graph[target_node] < endl;

	}

	cout << "Found solution "  "." << endl;
}
