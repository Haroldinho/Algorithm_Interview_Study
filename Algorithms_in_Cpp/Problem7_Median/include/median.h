/*
 *
 * 			~~~~ median.h ~~~~~ 
 * 		Coursera: Algorithms with Tim Roughegarden
 * 	Course 2: Graph Search, Shortest Paths and Data Structures
 *	Assignment 3: Implementing Running median for a list of numbers
 *	Need to return the sum of the running median
 * 
 *	The goal of this problem is to implement the "Median Maintenance" algorithm. 
 * 	The text file contains a list of the integers from 1 to 10000 in unsorted order; 
 * 	you should treat this as a stream of numbers, arriving one by one. Letting x_ix 
 *
 * This file introduces a median heap class that handles two different heaps to support
 * insertion of any number in O(1)
 * retrieval of the median in O(1)
 *
 *
 */

#ifndef MEDIAN_HEAP_H
#define MEDIAN_HEAP_H
#include<vector>
#include<queue>
#include<cstdlib>
#include<iostream>
#include<string>
#include<assert.h>
#define ABS(A) ((A)>0 ? (A): -(A))
class Median_heap
{
	private:
		size_t _heap_size;
		size_t _left_size;
		size_t _right_size;
		std::priority_queue<long> _left_heap; // max heap
		std::priority_queue<long, std::vector<long>, std::greater<long>> _right_heap; // min heap
		void _rebalance_heaps(){
			_left_size = _left_heap.size();
			_right_size = _right_heap.size();
			_heap_size = _left_size + _right_size;
			// check that the size does not differ by more than once
			// If it does, transfer the front of the heap with the lower cardinality to the other heap.
			if(ABS(_left_size-_right_size)>1){
				long elt_to_transfer;
				if(_left_size < _right_size){
					// transfer an elment from the right_heap to the left_heap
					elt_to_transfer = _right_heap.top();
					_right_heap.pop();
					_left_heap.push(elt_to_transfer);
				}else{
					elt_to_transfer = _left_heap.top();
					_left_heap.pop();
					_right_heap.push(elt_to_transfer);
				}
			}
			_left_size = _left_heap.size();
			_right_size = _right_heap.size();
			assert(ABS(_left_size-_right_size)<=1);
			assert(_heap_size==_left_size+_right_size);
		};

	public:
		Median_heap():_heap_size(0), _left_size(0), _right_size(0){};
		// Add another number to the median heap
		// Take the max number from the left heap, 
		// 	If new_number is bigger than that number, put new_number in left heap
		// 	Otherwise put new number is right heap. (especially if right heap has less element than the left
		//
		void insert(long new_number){
			if(_left_size==0){
				_left_heap.push(new_number);
			}else{
				long left_number;
				left_number = _left_heap.top();
				if(new_number <= left_number){
					// place in max_heap
					_left_heap.push(new_number);
				}else{
					_right_heap.push(new_number);
				}
			}
			_rebalance_heaps();
			
		};

		long long get_median(){
			long long return_number;
			if(_heap_size==1){
				if(_left_size==1){
					return_number = _left_heap.top();
				}else
					return_number = _right_heap.top();
				return return_number;
			}
			long left_number;
		       //	right_number;
			left_number = _left_heap.top();
			// right_number = _right_heap.top();
			// if we have a even number of elements return the average of both front heap elements
			if((_heap_size%2)==0){
				return_number = left_number;
			}else{
			// otherwise return the front element from the side with more elements
				if(_left_size < _right_size){
					return_number = _right_heap.top();
				}else{
					return_number = _left_heap.top();
				}
			}
//			std::cout << "Max of left heap: " << left_number;
//			std::cout << "\t Median: " << return_number;
//			std::cout << "\t Min of right heap: " << right_number << std::endl;

			return return_number;
		}



};

unsigned int main_median(std::string );

#endif
