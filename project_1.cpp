#include "project_1.h"

int main() {

	/*
	
	int nums [20];

	for (int i = 0; i < 20; i++)
		nums[i] = rand() % 1000;

	cout << "Original Array \n";
	printArray(nums, 20);

	heap_sort(nums, 20);
	
	cout << "\nAfter heap_sort \n\n";
	printArray(nums, 20);

	cout << "\n";
	return 0;

	*/

	///*
	for (int i = 0; i<10; i++) {
		vector < pair<int*, int> > * samples = initSamples();

		// printSamples(samples);
	    // performSearch(adap_sequencial_search1, samples);

	    // performSearch(adap_sequencial_search2, samples);

	    // performSearch(sequencial_search, samples);

	    // performSearch(ordered_sequencial_search, samples);
		// performSort(insertion_sort, samples);
		
		performSort(heap_sort, samples);

		performSort(merge_sort, samples);
		
		// performSort(adap_merge_sort, samples);
	    // performSort(adap20_merge_sort, samples);
	   	
	    // performSort(selection_sort, samples);
	    //  performSort(bubble_sort, samples);
	    
		deallocSamples(samples);
	}	
	
    char filename[] = "OMG.csv";
    printCountersToCSV(filename);
    //*/
    
}

void performSearch(int f(pair<int*, int>, int), vector< pair<int*, int> > *samples) {
	
	vector< pair<int*, int> > *victim = copySamples(samples); 

	for (vector<pair<int*,int> >::iterator it = victim->begin() ; it != victim->end(); ++it) {
		pair<int *, int> p = *it;
		cout<<"searching size: "<< p.second<<"\n";
		int keyIndex = rand() % p.second;
		f(p, p.first[keyIndex]);
	}	
	
	deallocSamples(victim);
}

void performSort(void f(pair<int*, int>), vector< pair<int*, int> > *samples) {
	vector< pair<int*, int> > *victim = copySamples(samples); 
	for (vector<pair<int*,int> >::iterator it = victim->begin() ; it != victim->end(); ++it) {
		pair<int *, int> p = *it;
		cout<<"sorting size: "<<p.second<<"\n";
		f(*it);
	}
	deallocSamples(victim);
}

void printCountersToCSV(char * filename) {
	vector<counter> * counters = getCounterVector();
	ofstream myfile;
  	myfile.open (filename, fstream::app);
  	/*myfile << ",";
  	for (int i = 0; i < NUM_SAMPLE_SIZES; i++) {
		int size = SAMPLE_SIZES[i];	
		for (int j = 0; j < 3; j++) {
			switch(j) {
				case 0:
					myfile<<size<<"rand,";
					break;
				case 1:
					myfile<<size<<"reverse,";
					break;
				case 2:
					myfile<<size<<"twentypercent,";
					break;
				default:
					cout << "WAT\n";
					break;	
			}
		}
	}
	myfile << "\n";
	*/
	for (vector< counter >::iterator it = counters->begin() ; it != counters->end(); ++it) {
		counter cur = *it;
		
		for (int i = 0; i < cur.numTrials();i++ ) {
			myfile << cur.desc()<<",";
			for (int j = 0; j < 12; j ++) {
				myfile <<cur.at(j+12*i) <<",";
			}
			myfile<<"\n";
		}
		myfile<<"\n";
	}

  	myfile.close();
}

void createRandArray(int *a, int size) {
	for (int i = 0; i < size; i++) {
		a[i] = rand() % 1000000;
	}
}

void createReverseArray(int *a, int size) {
	for (int i = 0; i < size; i++) {
		a[size - i - 1] = i;
	}
}

void createTwentyPercentArray(int *a, int size) {
	int sorted = size/5;

	for (int i = 0; i < size; i++) {
		a[i] = rand() % 1000000; 
	}

	vector<int> used;
	for (int i = 0; i < sorted; i ++) {
		used.push_back(rand() % size);
	}

	sort(used.begin(), used.end());
	int count = 0;
	for (vector<int>::iterator it=used.begin(); it!=used.end(); ++it) {
		a[((int)*it)] = count++;
	}
}

vector< pair<int*, int> > * initSamples() {
	vector< pair<int*, int> > * samples = new vector< pair<int*, int> >();
	srand(clock());
	for (int i = 0; i < NUM_SAMPLE_SIZES; i++) {
		int size = SAMPLE_SIZES[i];	
		for (int j = 0; j < 3; j++) {
			int * cur = (int *)malloc(sizeof(int) * size);
			switch(j) {
				case 0:
					createRandArray(cur, size);
					break;
				case 1:
					createReverseArray(cur, size);
					break;
				case 2:
					createTwentyPercentArray(cur, size);
					break;
				default:
					cout << "WAT\n";
					break;	
			}
			samples->push_back(make_pair(cur, size));
		}
	}
	return samples;
}

vector< pair<int*, int> > * copySamples(vector< pair<int*, int> > * src) {
	vector< pair<int*, int> > *dest = new vector< pair<int*, int> >();
	for (vector<pair<int*,int> >::iterator it = src->begin() ; it != src->end(); ++it) {
		pair<int *, int> p = *it;
		int * ary = p.first;
		int size = p.second;
		int * newAry = (int *)malloc(sizeof(int) * size);
		memcpy(newAry, ary, sizeof(int) * size);
		dest->push_back(make_pair(newAry, size));
	}
	return dest;
}

void deallocSamples(vector< pair<int*, int> > *victim) {
	for (vector<pair<int*,int> >::iterator it = victim->begin() ; it != victim->end(); ++it) {
		pair<int *, int> p = *it;
		int * ary = p.first;
		free(ary);
	}
	delete victim;
}

void bubble_sort(pair<int *, int> p) {
	bubble_sort(p.first, p.second);
}

// bubble sort important steps are comparisons and exchanges.
void bubble_sort(int ary [], int size)
{
	bubbleComps.next();
	bubbleSwaps.next();
	int i, j, temp;
	for (i = 1; i <= size; i++) {
		for (j = 0; j < size - 1; j++) {
			bubbleComps.increment();
			if (ary[j] > ary[j+1]) {
				bubbleSwaps.increment();
				temp = ary[j];
				ary[j] = ary[j+1];
				ary[j+1] = temp;
			}
		}
	}
}

void adap_bubble_sort(pair<int *, int> p) {
	adap_bubble_sort(p.first, p.second);
}

void adap_bubble_sort(int ary [], int size) {
	adapBubbleComps.next();
	adapBubbleSwaps.next();
	
	int i, j, temp;
	bool flag = true;
	for (i = 1; (i <= size) && flag; i++) {
		flag = false;
		for (j = 0; j < size - 1; j++) {
			adapBubbleComps.increment();
			if (ary[j] > ary[j+1]) {
				adapBubbleSwaps.increment();
				temp = ary[j];
				ary[j] = ary[j+1];
				ary[j+1] = temp;
				flag = true;						
			}
		}
	}
}

void insertion_sort(pair<int *, int> p) {
	insertion_sort(p.first, p.second);
}

void insertion_sort(int ary [], int size) {
	insertionComps.next();
	
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = ary[i];
		j = i - 1;
		while (j >= 0 && ary[j] > key) {
			insertionComps.increment();
			ary[j + 1] = ary[j];
			j = j - 1;
		}
		ary[j + 1] = key;
	}
}

void selection_sort(pair<int *, int> p) {
	selection_sort(p.first, p.second);
}

void selection_sort(int ary [], int size) {
	selectionComps.next();
	selectionSwaps.next();
	int i, j, min;
	for (i = 0; i < size - 1; i++) {				// loop goes from 0 - (n-1)
		min = i; 									// index of the minimum 
		for (j = i + 1; j < size; j++) {
			selectionComps.increment();
			if (ary[j] < ary[min]) {
				min = j;
			}
		}
		if (min != i) {
			selectionSwaps.increment();
			swap(ary[min],ary[i]);
		}
	}
}

int sequencial_search(pair<int*, int>p, int key) {
	sequencial_search(p.first, p.second, key);
}

int sequencial_search(int ary [], int size, int key) {
	sequencialComps.next();
	for (int i = 0; i < size; i++) {
		sequencialComps.increment();
		if (ary[i] == key) return i;
	}
	return -1;
}

int ordered_sequencial_search(pair<int*, int>p, int key) {
	ordered_sequencial_search(p.first, p.second, key);
}

int ordered_sequencial_search(int ary [], int size, int key) {
	orderedSequencialComps.next();
	for (int i = 0; i < size; i++) {
		orderedSequencialComps.increment();
		if (ary[i] == key) return i;
		else if (ary[i] > key) return -1;
	}
	return -1;
}

int adap_sequencial_search1(pair<int*, int>p, int key) {
	adap_sequencial_search1(p.first, p.second, key);
}

int adap_sequencial_search1(int ary [], int size, int key) {
	adapSequence1Comps.next();
	for (int i = 0; i < size; i++) {
		adapSequence1Comps.increment();
		if (ary[i] == key) {
			swap (ary[i], ary[0]);
			return i;
		}
	}
	return -1;
}

int adap_sequencial_search2(pair<int*, int>p, int key) {
	adap_sequencial_search2(p.first, p.second, key);
}

int adap_sequencial_search2(int ary [], int size, int key) {
	adapSequence2Comps.next();
	for (int i = 0; i < size; i++) {
		adapSequence2Comps.increment();
		if (ary[i] == key) {
			swap(ary[i-1], ary[i]);
			return i;
		}
	}
	return -1;
}

// Programming Project 2

void merge_sort(pair<int*, int> p) {
	merge_sort_Comps.next();
	merge_sort(p.first, p.second, 0, p.second - 1);
}

void merge_sort(int ary [], int size, int low, int high) {
	if (low < high) {
		int middle = (low + high)/2;			// divide: get the middle element
		merge_sort(ary, size, low, middle);		// merge_sort the left part of the array
		merge_sort(ary, size, middle + 1, high);// merge_sort the right part of the array
		merge(ary, size, low, middle, high);	// combine the sub arrays
	}
}

void merge (int ary [], int size, int low, int middle, int high) {
	
	int temp[size];
	for (int i = low; i <= high; i++) {
		temp[i] = ary[i];
	}

	int i = low;
	int j = middle + 1;
	int k = low;

	while ( i <= middle && j <= high) {
		if (temp[i] <= temp[j]) {
			ary[k] = temp[i];
			i++;
		} else {
			ary[k] = temp[j];
			j++;
		}
		k++;
		merge_sort_Comps.increment();
	}

	while (i <= middle) {
		ary[k] = temp[i];
		k++;
		i++;
	}
}

void adap_merge_sort(pair<int*, int> p) {
	adap_merge_sort_Comps.next();
	adap_merge_sort(p.first, p.second, 0, p.second - 1);
}

void adap_merge_sort(int ary [], int size, int low, int high) {
	if (high <= low + 100 - 1) {
		merge_to_insertion(ary, high - low + 1);
		return;
	} else if (low < high) {
		int middle = (low + high)/2;			// divide: get the middle element
		adap_merge_sort(ary, size, low, middle);		// merge_sort the left part of the array
		adap_merge_sort(ary, size, middle + 1, high);// merge_sort the right part of the array
		adap_merge(ary, size, low, middle, high);	// combine the sub arrays
	}
}

void adap_merge (int ary [], int size, int low, int middle, int high) {
	
	int temp[size];
	for (int i = low; i <= high; i++) {
		temp[i] = ary[i];
	}

	int i = low;
	int j = middle + 1;
	int k = low;

	while ( i <= middle && j <= high) {
		if (temp[i] <= temp[j]) {
			ary[k] = temp[i];
			i++;
		} else {
			ary[k] = temp[j];
			j++;
		}
		k++;
		adap_merge_sort_Comps.increment();
	}

	while (i <= middle) {
		ary[k] = temp[i];
		k++;
		i++;
	}
}

void merge_to_insertion(int ary [], int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = ary[i];
		j = i - 1;
		while (j >= 0 && ary[j] > key) {
			adap_merge_sort_Comps.increment();
			ary[j + 1] = ary[j];
			j = j - 1;
		}
		ary[j + 1] = key;
	}
}

void adap20_merge_sort(pair<int*, int> p) {
	adap20_merge_sort_Comps.next();
	adap20_merge_sort(p.first, p.second, 0, p.second - 1);
}

void adap20_merge_sort(int ary [], int size, int low, int high) {
	if (high <= low + 20 - 1) {
		merge_to_insertion(ary, high - low + 1);
		return;
	} else if (low < high) {
		int middle = (low + high)/2;					// divide: get the middle element
		adap20_merge_sort(ary, size, low, middle);		// merge_sort the left part of the array
		adap20_merge_sort(ary, size, middle + 1, high);	// merge_sort the right part of the array
		adap20_merge(ary, size, low, middle, high);		// combine the sub arrays
	}
}

void adap20_merge (int ary [], int size, int low, int middle, int high) {
	
	int temp[size];
	for (int i = low; i <= high; i++) {
		temp[i] = ary[i];
	}

	int i = low;
	int j = middle + 1;
	int k = low;

	while ( i <= middle && j <= high) {
		if (temp[i] <= temp[j]) {
			ary[k] = temp[i];
			i++;
		} else {
			ary[k] = temp[j];
			j++;
		}
		k++;
		adap20_merge_sort_Comps.increment();
	}

	while (i <= middle) {
		ary[k] = temp[i];
		k++;
		i++;
	}
}

void merge20_to_insertion(int ary [], int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = ary[i];
		j = i - 1;
		while (j >= 0 && ary[j] > key) {
			adap20_merge_sort_Comps.increment();
			ary[j + 1] = ary[j];
			j = j - 1;
		}
		ary[j + 1] = key;
	}
}

// Heapsort

void heap_sort(pair<int*, int> p) {
	heap_sort_Comps.next();
	heap_sort_Swaps.next();
	heap_sort(p.first, p.second);
}

void heap_sort(int ary [], int size) {
	build_maxHeap(ary, size);
	for (int i = size - 1; i >= 1; i--) {
		heap_sort_Swaps.increment();
		swap(ary[0], ary[i]);
		size -= 1;
		max_heapify(ary, 0, size);
	}
}

void build_maxHeap(int ary [], int size) {
	for(int i = size/2; i >= 0; i--)
        max_heapify(ary, i, size);
}

void max_heapify(int ary [], int i, int size) {
	int leftChild_index = 2 * i + 1;
	int rightChild_index = 2 * i + 2;

	int largest_index;

	heap_sort_Comps.increment();
	if (leftChild_index < size && ary[leftChild_index] > ary[i])
		largest_index = leftChild_index;
	else
		largest_index = i;

	heap_sort_Comps.increment();
	if (rightChild_index < size && ary[rightChild_index] > ary[largest_index])
		largest_index = rightChild_index;
	
	if (largest_index != i) {
		heap_sort_Swaps.increment();
		swap(ary[i], ary[largest_index]);
		max_heapify(ary, largest_index, size);
	}

}





