#ifndef PROJECT_1_H
#define PROJECT_1_H

#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include <vector>
#include <utility>
#include <algorithm> 

using namespace std;

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
int 	adap_sequencial_search1		(int ary [], int, int);		// function perform apaptive sequencial search 1.
int 	adap_sequencial_search1		(pair<int*, int>, int);		// function perform apaptive sequencial search 1.
int 	adap_sequencial_search2		(int ary [], int, int);		// function perform apaptive sequencial search 2.
int 	adap_sequencial_search2		(pair<int*, int>, int);		// function perform apaptive sequencial search 2.
void 	printArray 					(int ary [], int size);		// function print an array.
void	printArray					(pair<int*, int>);		// function print an array.

void initSamples();

vector< pair<int*, int> > * copySamples();
void deallocSamples(vector< pair<int*, int> > * victim);
void performSort(void f(pair<int*, int>));

vector< pair<int*, int> > * SAMPLES;

void printArray(pair<int*, int> p) {
	printArray(p.first, p.second);
}

void printArray(int ary[], int size) {
	for (int i = 0; i < size; i ++) {
		cout << ary[i] << ", ";
	}
	cout << "\n";
}

class counter
{
public :
	counter(string desc) {
		description = desc;
		index = -1;
		runs = new vector<uint64_t>();
	}

	~counter() {
		delete runs;
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

	void next() {
		runs->push_back(0);
		index++;
	}

private:
	string description;
	vector<uint64_t> * runs;
	int index;
};

#endif