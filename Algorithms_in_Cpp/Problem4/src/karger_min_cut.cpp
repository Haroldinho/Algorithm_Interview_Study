/*
 *		karger_min_cut.h
 *	Algorithms: Programming Assignment #4
 * Implement Karger min cut randomized algorithm to find the minimum number of cuts in a graph
 *
 */
#include "karger_min_cut.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include<bits/stdc++.h> //INT_MAX, INT_MIN
#include <random>
using namespace std;

std::istream& comma(std::istream& in){
	if((in >> std::ws).peek() != std::char_traits<char>::to_int_type(','))
		in.setstate(std::ios_base::failbit);
	return in.ignore();
}

map<int, vector<int>> read_input_adjacency_list(std::string file_name, int max_lines){
	cout << "READING GRAPH: " << endl;
	int initial_loc= 0;
	map<int, vector<int>> adjacency_list;
	ifstream fin(file_name); // file pointer
	istringstream in; 
	if(!fin.is_open()){
		cerr << "error: file" << file_name << " failed to open. \n" ;
		throw std::invalid_argument("Wrong filename.");
	}
	for(string line; getline(fin, line);){
		++initial_loc;
		stringstream ss(line);
		int node;
		vector<int> neighbors;
		int index_on_line = 0;
		for(int i; ss >> i;){
			if(index_on_line>0){
				neighbors.push_back(i);
			}else{
				node = i;
			}
			if(ss.peek()==' ')
				ss.ignore();
			++index_on_line;
		}
		adjacency_list.insert(pair<int,vector<int>>(node, neighbors));

	}
	cout << "\nFINISHED READING ARRAY OF " << initial_loc << " ELEMENTS. " << endl;
	return adjacency_list;
}

void show_adjacency_list(map<int, vector<int>> graph_adj_list){
	map<int, vector<int>>::iterator it;
	for(it=graph_adj_list.begin(); it!=graph_adj_list.end(); ++ it){
		cout << it->first << "\t\t" ;
		vector<int> vec = it->second;
		for(auto val:vec)
			cout << val << ", ";
		cout << "\n";
	}
}

// contract two nodes
void contract_graph(std::map<int, std::vector<int>>& graph_adj_list, int node_u, int node_v){
	// 0. define super nodes
	map<int, vector<int>> new_graph_list;
	vector<int> supernode;
	for(map<int, vector<int>>::iterator it=graph_adj_list.begin(); it!=graph_adj_list.end(); ++ it){
		int main_node = it->first;
		if(main_node == node_v)
			continue; // skip that entry
		vector<int> current_node_neighbors = it->second;
		vector<int> new_node_neighbors;
		// Copy all the neighbors of the current node to the new_graph_list 
		for(auto neighbor_node: it->second){
			if(neighbor_node != node_v){
				new_node_neighbors.push_back(neighbor_node);
			}else{
				new_node_neighbors.push_back(node_u);
			}
		}
		if(main_node==node_u){
			// Copy all the neighbors to the node_v to new_graph_list
			for(auto neighbor_node: graph_adj_list[node_v]){
				if(neighbor_node != node_v){
					new_node_neighbors.push_back(neighbor_node);
				}
			}
		}
		new_graph_list.insert(pair<int, vector<int>>(main_node, new_node_neighbors));
	}
	graph_adj_list = new_graph_list;
}	
// Remove self-loops
void remove_self_loop(std::map<int, std::vector<int>>& graph_adj_list){
	map<int, vector<int>> new_graph_list;
	for(map<int, vector<int>>::iterator it=graph_adj_list.begin(); it!=graph_adj_list.end(); ++ it){
		int main_node = it->first;
		vector<int> new_vector;
		for(auto neighbor_node: it->second){
			if(neighbor_node != main_node)
				new_vector.push_back(neighbor_node);
		}
		new_graph_list.insert(pair<int, vector<int>>(main_node, new_vector));
	}
	graph_adj_list = new_graph_list;
}

vector<int> get_keys_from_map(map<int, vector<int>> a_map){
	vector<int> keys;
	for(map<int, vector<int>>::iterator it = a_map.begin(); it != a_map.end(); it++){
		keys.push_back(it->first);
	}
	return keys;
}
//Compute the fewest number of randomized cuts
int compute_number_randomized_cuts(std::map<int, std::vector<int>> a_graph_adj_list){

//	cout << "Entering compute number randomized cut " << endl;
	size_t num_nodes_n;
	map<int, vector<int>> my_graph_adj_list;
	vector<int> graph_nodes;
	for(map<int, vector<int>>::iterator it=a_graph_adj_list.begin(); it!=a_graph_adj_list.end(); ++ it){
		int main_node = it->first;
		vector<int> new_vector;
		for(auto neighbor_node: it->second){
			new_vector.push_back(neighbor_node);
		}
		my_graph_adj_list.insert(pair<int,vector<int>>(main_node, new_vector));
	}
//	cout << "Copied graph adjacency list " << endl;
	// Get a random edge to cut
	random_device rd;
	mt19937 e2(rd());
	uniform_real_distribution<double> distribution(0.0, 1.0);
	int index_of_node_to_cut_a, index_of_node_to_cut_b, node_to_cut_a, node_to_cut_b;
	// Iterate over the next edge to cut until you are only left with two nodes
	while(my_graph_adj_list.size() > 2){
		num_nodes_n = my_graph_adj_list.size();
		graph_nodes = get_keys_from_map(my_graph_adj_list);
		// Pick Edge
		index_of_node_to_cut_a = int(distribution(e2)*num_nodes_n);
		node_to_cut_a = graph_nodes[index_of_node_to_cut_a];
		index_of_node_to_cut_b = int(distribution(e2)*my_graph_adj_list[node_to_cut_a].size());
		node_to_cut_b = my_graph_adj_list[node_to_cut_a][index_of_node_to_cut_b];
		
		// Contract graph for this edge
//		cout << "Contracting nodes " << node_to_cut_a << " and " << node_to_cut_b << " of a graph with "<< num_nodes_n << " nodes." << endl;
		contract_graph(my_graph_adj_list,  node_to_cut_a, node_to_cut_b);
//		show_adjacency_list(my_graph_adj_list);
		// Remove self-loop
//		cout << "Removing self loops " << endl;
		remove_self_loop(my_graph_adj_list);
//		show_adjacency_list(my_graph_adj_list);
	}
	// Compute the number of edges remaining
	// Only needs to focus on the degree of the first node
	unsigned int num_edges;
	map<int, vector<int>>::iterator it = my_graph_adj_list.begin();
	// count the number of edges remaining between the two nodes
	for(num_edges=0; num_edges < (it->second).size(); num_edges++){
	}
//	cout << "Final graph: \n";
//	show_adjacency_list(my_graph_adj_list);
//	cout << endl;
	return num_edges;
}



// Read input file and run Karger algorithm
int main_karger_min_cut(std::string file_name, int num_trials){
	//0. Procure graph adjacency list
	map<int, vector<int>> my_graph = read_input_adjacency_list(file_name, 200); 
	cout << " Initial graph: \n";
	show_adjacency_list(my_graph);
	cout << endl;
	//1.Perform num_trials randomized minimum cuts
	int min_cut = INT_MAX, current_min_cut;
	for(int trial_num = 0; trial_num < num_trials; trial_num++){
		current_min_cut = compute_number_randomized_cuts(my_graph);
		cout << "Trial: " << trial_num << " returned " << current_min_cut << " cuts. " ;
		cout << "\t Global minimum: " << min_cut << endl;
		if(current_min_cut < min_cut)
			min_cut = current_min_cut;
	}
	cout << "Final graph: \n";
	show_adjacency_list(my_graph);
	cout << endl;
	cout << "\n\n";
	return min_cut;
}
