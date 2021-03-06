#ifndef PROJECT_2_H
#define PROJECT_2_H

#include "util.h"


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
void 	quickSort 					( int *a, int first, int last );

int partition(int *a, int first, int last, int value);
void quickSort(pair<int*, int> p);

void insertion_sort(int ary [], int first, int last);
int partition2(int* a, int p, int r, int value);
void quickToInsertSort(pair<int*, int> p);
void quickToInsertSort( int *a, int first, int last );

int partition3(int* a, int p, int r, int value);
void quickMedianOfThreeSort( int *a, int first, int last );
void quickMedianOfThreeSort( pair<int*, int> p );

void insertion_sort2(int ary [], int first, int last);
int partition4(int* a, int p, int r, int value);
void quickMedianOfThreeToInsertionSort( int *a, int first, int last );
void quickMedianOfThreeToInsertionSort( pair<int*, int> p );
pair <int*, int> genIncs1(int N);
pair <int*, int> genIncs2(int N);
void shellSort1(int * a, int size);
void shellSort1(pair<int*, int> p);

void shellSort2(int * a, int size);
void shellSort2(pair<int*, int> p);

vector<int> project2getSampleSizes();
vector<SAMPLETYPE> project2getSampleTypes();
vector<counter> * project2CounterVector();
vector<timer> * project2TimerVector();
#endif