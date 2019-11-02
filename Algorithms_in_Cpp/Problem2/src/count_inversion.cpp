/*
 * 			~~~~ count_inversion.cpp ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 *	Divide and Counquer, Sorting and Searching and Randomized Algorithms	
 *	Assignment 2: Computing the number of inversions in a list
 * Harold Nikoue
 */

#include "../include/count_inversion.h"
#include <iostream>
#include <fstream> //std::ifstream
using namespace std;
void show_array(ull* test_array, int num_elts){
	cout << "\t ["; 
	for(int i=0; i<num_elts-1; i++){
		cout << test_array[i] << ", ";
	}
	cout << test_array[num_elts-1] << "]"<< endl;

}

/*
 * Follow the algorithm in the lecture
 */
long count_array(ull* array, int num_elts){
	if(num_elts<=1){
		return 0;
	}else{
		long x,y,z;
		int half_count = int(num_elts/2);
//		show_array(array, num_elts);
		x = count_array(array, half_count);
		y = count_array(array + half_count, num_elts - half_count);
		z = count_split_array(array, num_elts);
//		show_array(array, num_elts);
		return x+y+z;
	}
}
/*
 * The idea is simply to perform a merge on the array
 * rerturn an array in sorted order along with the count of the number of inversions
 *  
 */
long count_split_array(ull* array, int num_elts){
	long num_inversions = 0;
	int i = 0, j =0;
	int half_length = int(num_elts/2);
	ull* array_b = array;
	ull* array_c = array + half_length;
	ull* array_d = new ull[num_elts];
	for(int k=0; k< num_elts; k++){
		if(i>= half_length){
			array_d[k] = array_c[j++];
		}else if(j>=num_elts- half_length){
			array_d[k] = array_b[i];
			//num_inversions += half_length -i-1;
			//show_array(array_d, num_elts);
			i++;
		}else if(array_b[i] < array_c[j]){
			array_d[k] = array_b[i++];
		}else{
			array_d[k] = array_c[j++];
			num_inversions += half_length - i;
		}
	}
	for(int k=0;k<num_elts;k++)
		array[k] = array_d[k];
	delete array_d;
	return num_inversions;
}


void read_input_array(std::string file_name, ull* array, int max_lines){
	cout << "READING ARRAY: " << endl;
	ifstream fin(file_name); // file pointer
	int initial_loc = 0;
	ull input_num;
	// Open an existing file
	while(fin >> input_num && initial_loc< max_lines){
		array[initial_loc++] = input_num;
		if(initial_loc>=max_lines)
			break;
	}
	cout << "\nFINISHED READING ARRAY OF " << initial_loc << " ELEMENTS. " << endl;
}

void show_results(ull* test_array, int num_elts, long num_inversions){
	cout << num_inversions << " inversion" << ((num_inversions>1)?"s":"") << " for array: " << endl;	
	cout << "\t ["; 
	for(int i=0; i<num_elts-1; i++){
		cout << test_array[i] << ", ";
	}
	cout << test_array[num_elts-1] << "]"<< endl;

}

