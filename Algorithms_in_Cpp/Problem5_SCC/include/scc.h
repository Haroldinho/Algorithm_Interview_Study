/*
 *		scc.h
 *	Algorithms: Programming Assignment #5
 * Implement Strong Connected Component Analysis using deapth first search
 * The trick in the implementation is the data structure to store the data
 *
 */

#ifndef SCC_H
#define SCC_H
#include <string>
#include <map>
#include <vector>
const int NUM_ELEMENTS = 5060000;
const std::string GRAPH_INPUT_FILE = "SCC.txt";
typedef std::map<int, std::vector<int>> graph;

void show_graph(graph graph_adj_list, int num_nodes);

graph read_input_graph(std::string file_name, int max_lines, int&);

std::string main_kasaraju(std::string input_file_name, int max_num_elements);

std::string kasaraju(graph G, int num_nodes);

int dfs_loop(graph G, int* graph_label, int* component_array, int num_nodes);

void dfs(graph G, int i, bool* is_node_explored, int & t, int* array_components, int* graph_label, int leader_idx);

void relabel_graph(graph& G, int* new_graph_label, int num_nodes);

graph invert_graph(graph G, int num_nodes);

std::string convert_array_to_five_best_answers_output(int* component_array, int num_components);
#endif
