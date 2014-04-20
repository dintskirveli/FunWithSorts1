#ifndef UTIL_H
#define UTIL_H

using namespace std;

#include <stdlib.h>
#include <cstdlib>
#include <time.h>
#include <utility>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>

#include "counter.h"

using namespace std;

const int SAMPLE_SIZES[] = { 500, 2500, 12500, 62500 };
const int NUM_SAMPLE_SIZES = (sizeof SAMPLE_SIZES / sizeof SAMPLE_SIZES[0]);

void printCountersToCSV(char * filename, vector<counter> * counters);
vector < pair<int*, int> > * initSamples();
vector< pair<int*, int> > * copySamples(vector< pair<int*, int> > * p);
void deallocSamples(vector< pair<int*, int> > * victim);
void performSort(void f(pair<int*, int>), vector< pair<int*, int> > * samples);
void performSearch(int f(pair<int*, int>, int), vector< pair<int*, int> > * samples);

void printArray(pair<int*, int> p);
void printArray(int ary[], int size);
void printSamples (vector< pair<int*, int> > * s);

void createTwentyPercentArray(int *a, int size);
void createRandArray(int *a, int size);
void createReverseArray(int *a, int size);


#endif