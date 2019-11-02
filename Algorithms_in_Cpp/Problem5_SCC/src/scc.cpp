/* 
*		scc.h
 *	Algorithms: Programming Assignment #5
 * Implement Strong Connected Component Analysis using deapth first search
 * The trick in the implementation is the data structure to store the data
 *
*/



#include <iostream>
#include <sstream>//ostringstream
#include <fstream>
#include "scc.h"
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

inline bool binary_max(int a,int b){
	if(b>a){
		return b;
	}else
		return a;
}

std::istream& comma(std::istream& in){
	if((in >> std::ws).peek() != std::char_traits<char>::to_int_type(','))
		in.setstate(std::ios_base::failbit);
	return in.ignore();
}

graph read_input_graph(std::string file_name, int max_num_nodes, int& num_nodes){
	cout << "READING GRAPH: " << endl;
	int initial_loc= 0;
	map<int,vector<int>> adjacency_list;//in case it does not start from zero
	ifstream fin(file_name); // file pointer
	istringstream in; 
	int max_index = 0;
	if(!fin.is_open()){
		cerr << "error: file - " << file_name << " failed to open. \n" ;
		throw std::invalid_argument("Wrong filename.");
	}
	// DO an initial pass on the file until all lines have been read
	for(string line; getline(fin, line);){
		++initial_loc;
		stringstream ss(line);
		int root_node, tip_node;
		int index_on_line = 0;
		for(int i; ss >> i;){
			if(i > max_index){
				max_index = i;
			}
			if(index_on_line>0){
				tip_node =i;
			}else{
				root_node = i;
			}
			if(ss.peek()==' ')
				ss.ignore();
			++index_on_line;
		}
		if(adjacency_list.find(root_node)==adjacency_list.end()){
		//Key does not exist
			vector<int> initial_vec{tip_node};
			adjacency_list.insert(pair<int,vector<int>>(root_node,initial_vec));
		}else
			adjacency_list[root_node].push_back(tip_node);
		
	}
	num_nodes = max_index;
	cout << "\nFINISHED READING GRAPH WITH " << num_nodes << " NODES. " << endl;
	return adjacency_list;
		//TODO create a unit test to verify the file has the correct number of entries
}


string convert_array_to_five_best_answers_output(int* component_array, int num_components){
	int output_numbers[5];
	ostringstream out_string;
	for(int idx=0; idx< 5; idx++){
		if(idx>=num_components){
			output_numbers[idx] = 0;
		}else{
			output_numbers[idx] = component_array[idx];
		}
		if(idx < 4){
			out_string << output_numbers[idx] << ",";
		}else
			out_string << output_numbers[idx];
	}
	cout << "Obtained output " << out_string.str()<< endl;
	return out_string.str();

}

string main_kasaraju(string input_file_name, int max_num_elements){
	int num_nodes;
	graph G = read_input_graph(input_file_name, max_num_elements, num_nodes);  
	string my_strongest_5_components = kasaraju(G, num_nodes);
	cout << "Found a solution with " << num_nodes << "." << endl;
	return my_strongest_5_components;
}

string kasaraju(graph G, int num_nodes){
	int graph_label[num_nodes];
	int num_components;
	int component_array[num_nodes] = {0}; 
	map<int,int> my_component_map;
	cout << "Initial graph: "<< endl;
	show_graph(G, num_nodes);
	cout << "\nInverted graph: " << endl;
	graph inverted_graph = invert_graph(G, num_nodes);
	show_graph(inverted_graph, num_nodes);
	dfs_loop(inverted_graph, graph_label, component_array, num_nodes);
	relabel_graph(G, graph_label, num_nodes);
	for(int idx=0; idx< num_nodes; idx++)
		component_array[idx] = 0;	
       	num_components = dfs_loop(G, graph_label, component_array, num_nodes);
	sort(component_array, component_array + num_components, greater<int>());
	return convert_array_to_five_best_answers_output(component_array, num_components);
}

int dfs_loop(graph G, int* graph_label, int* component_array, int num_nodes){
	int num_components = 0;
	int t = 0;
	int leader_idx=-1;
	bool is_node_explored[num_nodes];
	for(int i = num_nodes-1;i>0; i--){
		if(!is_node_explored[i]){
			num_components++;
			dfs(G, i, is_node_explored, t, component_array, graph_label, ++leader_idx);
		}
	}
	return num_components;
}

void dfs(graph G, int i, bool* is_node_explored, int & t, int* array_components, int* graph_label, int leader_idx){
	is_node_explored[i] = true;
	for(int j: G[i]){
		if(!is_node_explored[j])
			dfs(G, j, is_node_explored, t, array_components, graph_label, leader_idx);
	}
	array_components[leader_idx]++;
	graph_label[i] = t++;//TODO verify appropriate use of this t
}

/*
 * Invert directions of the arcs of the original graph
 * This is done by creating a new adjacency list where for each entry p_i of the list of a given key i, we treat that value p_i as a key j=p_i of the new adjacency list
 * and append the key i to the vector k_j=i. 
 */
graph invert_graph(graph G, int num_nodes){
//RECALL	typedef *(std::vector<int>) graph;
	graph new_graph;
	for(map<int,vector<int>>::iterator it=G.begin();it!=G.end();++it ){
		int source_node_idx = it->first;
		vector<int> list_of_destination_nodes= it->second;
		for(auto node: list_of_destination_nodes){
			if(new_graph.find(node)==new_graph.end()){
				vector<int> new_vec{source_node_idx};
				new_graph.insert(pair<int,vector<int>>(node, new_vec));
			}else
				new_graph[node].push_back(source_node_idx);
		}
	}
	return new_graph;
}

void show_graph(graph graph_adj_list, int num_nodes){
	for(map<int,vector<int>>::iterator it=graph_adj_list.begin(); it!=graph_adj_list.end(); it++){	
		cout << it->first << " -> \t\t";
		for(auto val: it->second)
			cout <<val << ",";
		cout << "\n";
	}
}
/*
 * Construct a new graph with new data.
 * Migrate new graph to old G  and delete original G.
 */
void relabel_graph(graph& G, int* new_graph_label, int num_nodes){
	graph new_graph;
	for(map<int, vector<int>>::iterator it=G.begin(); it!=G.end(); ++it){
		int source_node_idx = it->first;
		vector<int> list_of_destination_nodes = it->second;
		vector<int> new_destinations;
		for(auto original_node:list_of_destination_nodes){
			new_destinations.push_back(new_graph_label[original_node]);
		}
		new_graph.insert(pair<int,vector<int>>(new_graph_label[source_node_idx],new_destinations));
	}
	G = new_graph;
}
