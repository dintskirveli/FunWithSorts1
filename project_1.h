#ifndef PROJECT_1_H
#define PROJECT_1_H

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include <vector>
#include <utility>
#include <algorithm> 

using namespace std;

class counter
{
public :
	counter(string desc) {
		description = desc;
		index = -1;
		runs = new vector<uint64_t>();
	}

	void increment() {
		runs->at(index)++;
	}

	void printCurrent() {
		cout << description << ": " << runs->at(index) << "\n";
	}

	void printAll() {
		cout << description << ":\n";
		for (vector<uint64_t>::iterator it = runs->begin() ; it != runs->end(); ++it) {
			cout << (uint64_t)*it << "\n"; 
		}
	}

	uint64_t at(int index) {
		return runs->at(index);
	}

	string desc() {
		return description;
	}

	int numTrials() {
		return runs->size()/12;
	}

	void next() {
		runs->push_back(0);
		index++;
	}

private:
	string description;
	vector<uint64_t> * runs;
	int index;
};

counter bubbleComps("bubble comparisons");
counter bubbleSwaps("bubble exchanges");
counter adapBubbleComps("adap. bubble sort comparisons");
counter adapBubbleSwaps("adap. bubble sort exchanges");
counter insertionComps("insertion sort comparisons");
counter selectionComps("selection sort comparisons");
counter selectionSwaps("selection sort exchanges");
counter sequencialComps("sequencial search comparisons");
counter orderedSequencialComps("ordered sequencial search comparisons");
counter adapSequence1Comps("adap_sequencial_search1 comparisons");
counter adapSequence2Comps("adap_sequencial_search2 comparisons");

vector<counter> * getCounterVector() {
	vector<counter> * counters = new vector<counter>();
	counters->push_back(bubbleComps);
	counters->push_back(bubbleSwaps);
	counters->push_back(adapBubbleComps);
	counters->push_back(adapBubbleSwaps);
	counters->push_back(insertionComps);
	counters->push_back(selectionComps);
	counters->push_back(selectionSwaps);
	counters->push_back(sequencialComps);
	counters->push_back(orderedSequencialComps);
	counters->push_back(adapSequence1Comps);
	counters->push_back(adapSequence2Comps);
	return counters;
}

void 	bubble_sort					(int ary [], int size);		// function performs Bubble Sort.
void 	bubble_sort					(pair<int*, int>);		// function performs Bubble Sort.
void	adap_bubble_sort			(int ary [], int size);		// function performs Adaptive Bubble Sort.
void	adap_bubble_sort			(pair<int*, int>);		// function performs Adaptive Bubble Sort.
void  	insertion_sort				(int ary [], int size);		// function performs Insertion Sort.
void  	insertion_sort				(pair<int*, int>);		// function performs Insertion Sort.
void 	selection_sort				(int ary [], int size);		// function performs Selection Sort.
void  	selection_sort				(pair<int*, int>);		// function performs Insertion Sort.
int		sequencial_search			(int ary [], int, int);		// function perform Sequencial Search.
int		sequencial_search			(pair<int*, int>, int);		// function perform Sequencial Search.
int		ordered_sequencial_search	(int ary [], int, int);		// function perform ordered Sequencial Search.
int		ordered_sequencial_search	(pair<int*, int>, int);		// function perform ordered Sequencial Search.
int 	adap_sequencial_search1		(int *ary, int size, int);		// function perform apaptive sequencial search 1.
int 	adap_sequencial_search1		(pair<int*, int> p, int);		// function perform apaptive sequencial search 1.
int 	adap_sequencial_search2		(int ary [], int, int);		// function perform apaptive sequencial search 2.
int 	adap_sequencial_search2		(pair<int*, int>, int);		// function perform apaptive sequencial search 2.
void 	printArray 					(int ary [], int size);		// function print an array.
void	printArray					(pair<int*, int>);		// function print an array.

const int SAMPLE_SIZES[] = { 500, 2500, 12500, 62500 };
const int NUM_SAMPLE_SIZES = (sizeof SAMPLE_SIZES / sizeof SAMPLE_SIZES[0]);

void printCountersToCSV(char * filename);

vector < pair<int*, int> > * initSamples();

vector< pair<int*, int> > * copySamples(vector< pair<int*, int> > * p);
void deallocSamples(vector< pair<int*, int> > * victim);
void performSort(void f(pair<int*, int>), vector< pair<int*, int> > * samples);
void performSearch(int f(pair<int*, int>, int), vector< pair<int*, int> > * samples);

void printArray(pair<int*, int> p) {
	printArray(p.first, p.second);
}

void printArray(int ary[], int size) {
	for (int i = 0; i < size; i ++) {
		cout << ary[i] << ", ";
	}
	cout << "\n";
}

void printSamples (vector< pair<int*, int> > * s) {
	for (vector< pair<int*, int> >::iterator it = s->begin() ; it != s->end(); ++it) {
		pair <int*, int> p = *it;
		printArray(p);
	}
}

void createTwentyPercentArray(int *a, int size);

#endif