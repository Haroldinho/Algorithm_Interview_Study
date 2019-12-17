#include <iostream>
#include <fstream>
#include <sstream>
#include "graph_functions.h"

using namespace std;
/*
 * The input file is an adjacency list
 * Each line consists of a node and all its neighbors.
 * 	The first entry is the node.
 * 	All subsequent entries are a pair consisting of a node and the length of the arc
 * 	that we want to minimize. 
 *
 */
typedef std::map<int, std::vector<Vertex>> AdjacencyGraph;
AdjacencyGraph read_input_adjacency_list(std::string file_name, int& num_nodes){
//	cout << "READING GRAPH FILE: " << endl;
	int initial_loc= 0;
	map<int,vector<Vertex>> adjacency_list;
	ifstream fin(file_name); // file pointer
	istringstream in; 
	if(!fin.is_open()){
		cerr << "error: file - " << file_name << " failed to open. \n" ;
		throw std::invalid_argument("Wrong filename.");
	}
	// DO an initial pass on the file until all lines have been read
	for(string line; getline(fin, line);){
		++initial_loc;
		stringstream ss(line);
		unsigned int root_node, tip_node;
		unsigned long tip_length;
		vector<Vertex> vec_of_pairs;
		ss >> root_node;
		if(ss.peek()==' ')
			ss.ignore();
		for(unsigned long i; ss >> i;){
			tip_node =i;
			if(ss.peek()==',')
				ss.ignore();
			ss >> tip_length;
			vec_of_pairs.push_back(Vertex(root_node, tip_node, tip_length));
			if(ss.peek()==' '|| ss.peek()==',')
				ss.ignore();
		}
		adjacency_list.insert(make_pair(root_node, vec_of_pairs));
		
	}
	num_nodes = initial_loc;
//	cout << "\nFINISHED READING GRAPH WITH " << initial_loc << " NODES. " << endl;
	return adjacency_list;
		//TODO create a unit test to verify the file has the correct number of entries
}
void show_graph(AdjacencyGraph graph_adj_list){
	for(map<int,vector<Vertex>>::iterator it=graph_adj_list.begin(); it!=graph_adj_list.end(); it++){	
		cout << it->first << " -> \t\t";
		for(auto val: it->second)
			cout << val.get_index() << " (" << val.get_cost() 
				<< ")" << ", ";
		cout << "\n";
	}
}
