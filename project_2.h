#ifndef PROJECT_2_H
#define PROJECT_2_H

#include "util.h"

extern counter merge_sort_Comps;
extern counter adap_merge_sort_Comps;
extern counter adap20_merge_sort_Comps;
extern counter heap_sort_Comps;
extern counter heap_sort_Swaps;

void	build_maxHeap				(int ary[], int size);
void	max_heapify					(int ary[], int i, int size);
void	heap_sort					(int ary[], int size);
void 	heap_sort					(pair<int*, int>);

void	merge_sort					(int ary[], int size, int low, int high);	// function performs merge_sort
void 	merge_sort					(pair<int*, int>);
void 	merge 						(int ary[], int size, int low, int middle, int high);
void	adap_merge_sort				(int ary[], int size, int low, int high);	// function performs merge_sort and insertion sort with last 100 elements
void 	adap_merge_sort				(pair<int*, int>);
void 	adap_merge 					(int ary[], int size, int low, int middle, int high);
void  	merge_to_insertion			(int ary [], int size);
void	adap20_merge_sort			(int ary[], int size, int low, int high); 	// function performs merge_sort and insertion sort with last 20 elements
void 	adap20_merge_sort			(pair<int*, int>);			// function performs merge_sort
void 	adap20_merge 				(int ary[], int size, int low, int middle, int high);
void  	merge20_to_insertion		(int ary [], int size);		// function performs Insertion Sort.

#endif