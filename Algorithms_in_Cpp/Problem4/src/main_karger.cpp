/*
 *		main_karger.h
 *	Algorithms: Programming Assignment #4
 * Run the karger code against the test instance for the online assignment
 *
 */
#include "karger_min_cut.h"
#include <iostream>
#include <math.h>
using namespace std;
/*
 * 0. Read the input file
 * 1. Call the karger algorithm
 */

int main(){
	int min_cut;
	int num_trials = NUM_ELEMENTS*log2(NUM_ELEMENTS) + 10; 
	min_cut = main_karger_min_cut(GRAPH_INPUT_FILE, num_trials);
	cout << "The minimum cut has " << min_cut << " cut" << ((min_cut>1)?"s.":".")<< endl;

}
