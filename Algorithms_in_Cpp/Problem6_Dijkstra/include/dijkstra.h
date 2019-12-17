/*
 * Header files that supports the implementation of Dijkstra algorithm
 *
 * Defines the classes and functions necessary for the implementation
 *
 */
#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include "graph_functions.h"
std::vector<unsigned int> compute_dijkstra_shortest_path(AdjacencyGraph graph_adj_list, std::string);
std::vector<unsigned int> get_output_cost(std::vector<unsigned int> , std::vector<int> test_input = {7,37,59,82,99,115,133,165,188,197});

class DijkstraNode{
private:
	Vertex _node;
	unsigned long _cost_to_get_there;
	Vertex _prev_vertex;
public:
	DijkstraNode(Vertex node, unsigned long cost, Vertex pred): _node(node), _cost_to_get_there(cost), _prev_vertex(pred){};
	unsigned long get_cost() const{
		return _cost_to_get_there;
	};

	Vertex get_vertex(){return _node;};

	unsigned int get_index() const {return _node.get_index();};

	unsigned int get_pred_index() const { 
		return _prev_vertex.get_index();
	};

};
class DijkstraNodeComparator
{
public:
	bool operator() (const DijkstraNode& lhs, const DijkstraNode& rhs) const
	{
		return lhs.get_cost() > rhs.get_cost();
	}
};

std::vector<unsigned int> return_shortest_path(std::string , std::string , std::string);
void plot_dijkstraGraph(std::unordered_map<unsigned int, std::vector<unsigned int>> paths, std::string path_filename, unsigned int, std::vector<unsigned int>);
#endif
