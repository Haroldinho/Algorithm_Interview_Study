#include<iostream>
/*
 * Merge sorted array a and sorted array b
 * TODO: Instead of using a local array, do a swap on original data
 */
int*  merge(int * array_a, int* array_b, int size_array_a, int size_array_b){
	int i= 0, j = 0;
	int n= size_array_a + size_array_b;
	int array_c[n];
	for(int k=0; k<n; k++){
		if(i==size_array_a){
			array_c[k] = array_b[j++];
		}else if(j==size_array_b){
			array_c[k] = array_a[i++];
		}else if(array_a[i] < array_b[j]){
			array_c[k] = array_a[i];
			i++;	
		}else{
			array_c[k] = array_b[j];
			j++;
		}
			
	}
	return &array_cc[0];
}


void merge_sort(int array[], int array_size){


}


