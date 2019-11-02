/*
 *		main_scc.h
 *	Algorithms: Programming Assignment #5
 * Run the Kasaraju strong component analysis on a 
 *
 * OUTPUT: size of the 5 largest strongly connected components
 * If the algorithm finds less than 5 strongly connected components then write 0 for the remaining terms. 
 * No space in the answer
 */
#include "scc.h"
#include <iostream>
#include <math.h>
int main(){
	int num_nodes;
	graph G = read_input_graph(GRAPH_INPUT_FILE, NUM_ELEMENTS, num_nodes);  
	string strong_five_components = kasaraju(G, num_nodes);
	cout << "Found solution " << strong_five_components << "." << endl;
}
