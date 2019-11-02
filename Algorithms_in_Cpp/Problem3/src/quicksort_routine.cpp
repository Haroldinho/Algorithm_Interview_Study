/*
 *		quicksort_routine.cpp
 *	Algorithms: Programming Assignment #3
 * Implement the Quicksort algorithm with different pivot selection rules
 *
 */

#include "../include/quicksort_routine.h"
#include <iostream>
#include <fstream>
using namespace std;
inline int  Max(int a, int b){
	return (a > b) ? (a): (b);
}
void swap_array(ulong*  array, int i, int j){
	ulong temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void show_array(ulong* test_array, int num_elts){
	cout << "\t ["; 
	for(int i=0; i<num_elts-1; i++){
		cout << test_array[i] << ", ";
	}
	cout << test_array[num_elts-1] << "]";

}

void read_input_array(std::string file_name, ulong* array, int max_lines){
	cout << "READING ARRAY: " << endl;
	ifstream fin(file_name); // file pointer
	int initial_loc = 0;
	ulong input_num;
	// Open an existing file
	while(fin >> input_num && initial_loc< max_lines){
		array[initial_loc++] = input_num;
		if(initial_loc>=max_lines)
			break;
	}
	cout << "\nFINISHED READING ARRAY OF " << initial_loc << " ELEMENTS. " << endl;
}

long quicksort_1(ulong* array, size_t n){
//	cout << "Entering quicksort_1  for an array of size " << n << endl;
	int pivot_position, left_num_comparisons, right_num_comparisons, recursive_comp;
	if(n<=1)
		return 0;
	choose_first_element_as_pivot(array, n);
	pivot_position = partition(array, 0, n);
//	cout << "(Quicksort_1) array of size " << n << "\t ";
//	show_array(array, n);
//	cout << " \t " ;
//	show_array(array, Max(pivot_position,1));
//	cout << "\t";
//	show_array(array+pivot_position+1, n - (pivot_position+1));
//	cout << " with pivot at position " << pivot_position << "." <<  endl;
	left_num_comparisons = quicksort_1(array, pivot_position);
	recursive_comp = n-1;
	right_num_comparisons = quicksort_1(array+pivot_position+1, n -(pivot_position+1));
	return left_num_comparisons + right_num_comparisons + recursive_comp;
}

long quicksort_2(ulong* array, size_t n){
	int pivot_position, left_num_comparisons, right_num_comparisons, recursive_comp;
	if(n<=1)
		return 0;
	choose_last_element_as_pivot(array, n);
	pivot_position = partition(array, 0, n);
//	cout << "(Quicksort_2) array of size " << n << "\t ";
//	show_array(array, n);
//	cout << " \t " ;
//	show_array(array, Max(pivot_position,1));
//	cout << "\t";
//	show_array(array+pivot_position+1, n - (pivot_position+1));
//	cout << " with pivot at position " << pivot_position << "." <<  endl;
	left_num_comparisons = quicksort_2(array, pivot_position);
	recursive_comp = n-1;
	right_num_comparisons = quicksort_2(array+pivot_position+1, n -(pivot_position+1));
	return left_num_comparisons + right_num_comparisons + recursive_comp;
}

long quicksort_3(ulong* array, size_t n){
	int pivot_position, left_num_comparisons, right_num_comparisons, recursive_comp;
	if(n<=1)
		return 0;
	if(n>2)
		choose_median_of_three(array, n);
	pivot_position = partition(array, 0, n);
//	cout << "(Quicksort_1) array of size " << n << "\t ";
//	show_array(array, n);
//	cout << " \t " ;
//	show_array(array, Max(pivot_position,1));
//	cout << "\t";
//	show_array(array+pivot_position+1, n - (pivot_position+1));
//	cout << " with pivot at position " << pivot_position << "." <<  endl;
	left_num_comparisons = quicksort_3(array, pivot_position);
	recursive_comp = n-1;
	right_num_comparisons = quicksort_3(array+pivot_position+1, n -(pivot_position+1));
	return left_num_comparisons + right_num_comparisons + recursive_comp;
}

int partition(ulong* array, int left_index, int right_index){
	ulong p = array[left_index];
	int  i = left_index + 1;
	for(int j=left_index + 1; j < right_index; j++){
		if(array[j] < p){
			swap_array(array, j, i);
			i = i + 1;
		}
	}
	swap_array(array, left_index, i-1);
	return i-1;
}


void choose_first_element_as_pivot(ulong* array, size_t n){
	//Nothing to do 
	return;
}

void choose_last_element_as_pivot(ulong* array, size_t n){
	swap_array(array, 0, n-1);
}
// Identify the median amongst the first, last and middle ceil(n/2) element of the array.
// Return the same array with the pivot now occupying the first location. 
void choose_median_of_three(ulong* array, size_t n){
	ulong a, b, c;
	int index_b = int((n-1)/2), index_c = n-1; 
	a = array[0];
	b = array[index_b];
	c = array[n-1];

	if(a < b){
		if(b<c){
			//b is the median
			swap_array(array, 0, index_b);
		}else{ // c < b
			if( a< c){
				// c is the pivot
				swap_array(array, 0, index_c);
			}//otherwise do nothing
		}
	}else{// b < a
		if(a < c){
			// a is the median
			//do nothing
		}else{// a > c, a is th greatest element
			if(c < b){
				swap_array(array, 0, index_b);
			}else
				swap_array(array, 0, index_c);
		}	

	}
}
