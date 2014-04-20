#include "project_2.h"

counter merge_sort_Comps("merge_sort comparisons");
counter adap_merge_sort_Comps("adap_merge_sort comparisons");
counter adap20_merge_sort_Comps("adap20_merge_sort comparisons");
counter heap_sort_Comps("heap_sort comparisons");
counter heap_sort_Swaps("heap_sort exchanges");

timer mergeSortTime("merge sort time");
timer adapMergeSortTime("adap merge sort time");
timer adap20SortTime("adap20 sort time");
timer heapSortTime("heap sort time");

vector<int> project2getSampleSizes() {
	vector<int> project_2_sizes;
	project_2_sizes.push_back(2500);
	project_2_sizes.push_back(12500);
	project_2_sizes.push_back(62500);
	project_2_sizes.push_back(312500);
	return project_2_sizes;
}

vector<SAMPLETYPE> project2getSampleTypes() {
	vector<SAMPLETYPE> project_2_sample_types;
	project_2_sample_types.push_back(RANDOM);
	project_2_sample_types.push_back(TWENTY_PERCENT);
	project_2_sample_types.push_back(FIFTY_PERCENT);
	return project_2_sample_types;
}

vector<counter> * project2CounterVector() {
	vector<counter> * counters = new vector<counter>();

	counters->push_back(merge_sort_Comps);
	counters->push_back(adap_merge_sort_Comps);
	counters->push_back(adap20_merge_sort_Comps);
	counters->push_back(heap_sort_Comps);
	counters->push_back(heap_sort_Swaps);
	return counters;
} 

vector<timer> * project2TimerVector() {
	vector<timer> * timers = new vector<timer>();

	timers->push_back(mergeSortTime);
	timers->push_back(adapMergeSortTime);
	timers->push_back(adap20SortTime);
	timers->push_back(heapSortTime);
	return timers;
} 

void merge_sort(pair<int*, int> p) {
	merge_sort_Comps.next();
	mergeSortTime.next();
	mergeSortTime.start();
	merge_sort(p.first, p.second, 0, p.second - 1);
	mergeSortTime.stop();
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
	adapMergeSortTime.next();
	adapMergeSortTime.start();
	adap_merge_sort(p.first, p.second, 0, p.second - 1);
	adapMergeSortTime.start();
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
	adap20SortTime.next();
	adap20SortTime.start();
	adap20_merge_sort(p.first, p.second, 0, p.second - 1);
	adap20SortTime.stop();
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
	heapSortTime.next();
	heapSortTime.start();
	heap_sort(p.first, p.second);
	heapSortTime.stop();
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





