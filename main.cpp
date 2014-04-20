#include "util.h"
#include "project_1.h"
#include "project_2.h"

vector<counter> * getCounterVector();

int main() {
	for (int i = 0; i<10; i++) {
		vector < pair<int*, int> > * samples = initSamples();

		performSort(heap_sort, samples);

		performSort(merge_sort, samples);

		deallocSamples(samples);
	}
	char filename[] = "OMG.csv";

    printCountersToCSV(filename, getCounterVector());
}

vector<counter> * getCounterVector() {
	vector<counter> * counters = new vector<counter>();
	//project 1
	counters->push_back(bubbleComps);
	counters->push_back(bubbleSwaps);
	counters->push_back(adapBubbleComps);
	counters->push_back(adapBubbleSwaps);
	counters->push_back(selectionComps);
	counters->push_back(bubbleComps);
	counters->push_back(selectionSwaps);
	counters->push_back(sequencialComps);
	counters->push_back(orderedSequencialComps);
	counters->push_back(adapSequence1Comps);
	counters->push_back(adapSequence2Comps);
	//project 2
	counters->push_back(merge_sort_Comps);
	counters->push_back(adap_merge_sort_Comps);
	counters->push_back(adap20_merge_sort_Comps);
	counters->push_back(heap_sort_Comps);
	counters->push_back(heap_sort_Swaps);
	return counters;
} 