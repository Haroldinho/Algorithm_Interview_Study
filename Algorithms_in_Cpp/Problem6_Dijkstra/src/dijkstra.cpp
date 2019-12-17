#include <vector>
#include"dijkstra.h"
#include <queue> // std::priority_queue
#include <iostream> 
#include <cstdio>
#include <functional>
#include <unordered_set>
/*
 Your task is to run Dijkstra's shortest-path algorithm on this graph, using 1 (the first vertex) as the source vertex, and to compute the shortest-path distances between 1 and every other vertex of the graph. If there is no path between a vertex vv and vertex 1, we'll define the shortest-path distance between 1 and vv to be 1000000.
*/
const unsigned int MAX_SCORE = 1000000;
using namespace std;
std::vector<unsigned int> return_shortest_path(string file_name_prefix, string file_name_suffix, string path_prefix){
	std::string file_name = file_name_prefix + file_name_suffix ;
	string path_file_name = path_prefix + file_name_suffix;
	cout << "Reading file: " << file_name << endl;
	int num_nodes;
	AdjacencyGraph G = read_input_adjacency_list(file_name, num_nodes);  
	vector<unsigned int> shortest_path_graph = compute_dijkstra_shortest_path(G, path_file_name);
	return shortest_path_graph;
}

vector<unsigned int> compute_dijkstra_shortest_path(AdjacencyGraph graph_adj_list,string path_file_name){
	// 1. Read the root of the graph 
	// 	. append all the neighbors of the graph into the heap.
	// 	Add the root to the set of visited nodes.
	// 2. While the heap is not empty and the set of visited nodes does not contain all the nodes do
	// 	a) Get the first element in the heap
	// 	b) if that element is not in the visited nodes, add it to the set of visited node
	// 		and set the value at that index to the cost to go.
	// 		bb) add all the neighbors of the current node to the list
	// 	c) if the element has been visited, check if the new cost to go is lower than the current one assigned 
	// 		if it is, assign the new value as the current cost to get to that node
	//		otherwise do nothing, and move on to the next element in the heap
	//	ADDED Paths as an add-on feature to be printed to a separate file when debugging the code.
	//	In a production environment, that would be removed.
	//
	// priority_queue<Vertex, vector<Vertex>, MyVertexComparator> current_node_heap;
	priority_queue<DijkstraNode, vector<DijkstraNode>, DijkstraNodeComparator> node_heap;
	unsigned int num_nodes = graph_adj_list.size();

	//initialize shortest_path_vector to be 10000000 for every node
	vector<unsigned int> shortest_path_score(num_nodes, MAX_SCORE);
	unordered_map<unsigned int, std::vector<unsigned int>> paths;
	unordered_set<unsigned int> visited_nodes;
	paths.reserve(num_nodes);
	visited_nodes.reserve(num_nodes);
	unordered_set<unsigned int>::iterator set_it;
	const int ROOT_NODE_IDX = 1;

	vector<Vertex> next_vertexs = graph_adj_list[ROOT_NODE_IDX]; // 1 is the index of the root node
	Vertex root_vertex = Vertex(0, 1, 0);
	shortest_path_score[0] = 0;
	visited_nodes.insert(ROOT_NODE_IDX);

	vector<unsigned int> initial_path_vector = {ROOT_NODE_IDX};
	paths.insert({ROOT_NODE_IDX,initial_path_vector});
	unsigned int cur_idx, prev_idx;
	unsigned long cost_to_go, next_cost_to_go;
	for(auto next_vertex:next_vertexs){
		cost_to_go = next_vertex.get_cost();
		node_heap.push(DijkstraNode(next_vertex, cost_to_go, root_vertex));
	}
	//while(!node_heap.empty() && visited_nodes.size()< graph_adj_list.size()){
	while(!node_heap.empty()){
		DijkstraNode current_node = node_heap.top();
		Vertex current_vertex = current_node.get_vertex();
		cost_to_go = current_node.get_cost();
		node_heap.pop();
		cur_idx = current_vertex.get_index();
		prev_idx = current_node.get_pred_index();
		//Check if the cur_idx has been visited (exists in the hash-set)
		set_it = visited_nodes.find(cur_idx);
		if(set_it == visited_nodes.end()){
//			cout << "Current Node: " << cur_idx << "\t Previous Node: " << prev_idx << "." << endl;
			// Visit this node, and add its neighbors to the  heap of nodes to visit
			visited_nodes.insert(cur_idx);
			
			shortest_path_score[cur_idx-1] = cost_to_go;
			vector<unsigned int> path_vector(paths[prev_idx]);
			path_vector.push_back(cur_idx);
			paths.insert({cur_idx, path_vector});
			for(auto next_vertex:graph_adj_list[cur_idx]){
				next_cost_to_go = cost_to_go + next_vertex.get_cost();
				node_heap.push(DijkstraNode(next_vertex,next_cost_to_go, current_vertex));
			}

		}

	}
	cout << "In Dijkstra, the load factor is: " << visited_nodes.load_factor() << " out of " 
		<< visited_nodes.max_load_factor() << "."<< endl;
	plot_dijkstraGraph(paths, path_file_name, num_nodes, shortest_path_score);
	return shortest_path_score;
}

vector<unsigned int> get_output_cost(vector<unsigned int> shortest_path_score, vector<int> test_input){
	vector<unsigned int> output_vector;
	for(auto target_node: test_input){
		// if the target_node is not in the list return a cost of 1,000,000
		// otherwise returns the cost found by dijkstra
		output_vector.push_back(shortest_path_score[target_node-1]);
	}
	return output_vector;
}
/*
 * Plotting utilities for dijkstra algorithm implementations
 */
void plot_dijkstraGraph(std::unordered_map<unsigned int, std::vector<unsigned int>> paths, string path_file_name, unsigned int num_nodes, 
		vector<unsigned int> shortest_path_cost){
	freopen(path_file_name.c_str(), "w", stderr);
	unordered_map<unsigned int, vector<unsigned int>>::iterator path_it;
	for(unsigned int index=1; index<=num_nodes; index++){
		path_it = paths.find(index);
		if(path_it==paths.end()){
			cerr << index << " => Path => \t" << index << endl;
		}else{
			cerr << index << " => Path => \t";
			for(auto tail_idx: paths[index])
				cerr << tail_idx << "(" << shortest_path_cost[tail_idx-1] << ")"  << ", ";
			cerr << endl;
		}
	}
	
}
