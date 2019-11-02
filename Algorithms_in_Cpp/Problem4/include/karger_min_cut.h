/*
 *		karger_min_cut.h
 *	Algorithms: Programming Assignment #4
 * Implement Karger min cut randomized algorithm to find the minimum number of cuts in a graph
 *
 */

#ifndef KARGER_MIN_CUT_H
#define KARGER_MIN_CUT_H
#include <string>
#include <map>
#include <vector>
const int NUM_ELEMENTS = 200;
const std::string GRAPH_INPUT_FILE = "kargerMinCut.txt";

void show_adjacency_list(std::map<int,std::vector<int>> graph_adj_list);

std::map<int,std::vector<int>> read_input_adjacency_list(std::string file_name, int max_lines);

// Read input file and run Karger algorithm
int main_karger_min_cut(std::string filename, int num_trials);

//Compute the fewest number of randomized cuts
int compute_number_randomized_cuts(std::map<int,std::vector<int>> graph_adj_list);

// contract two nodes
void contract_graph(std::map<int,std::vector<int>>& graph_adj_list, int node_u, int node_v);

// Remove self-loops
void remove_self_loop(std::map<int,std::vector<int>>& graph_adj_list);
#endif
