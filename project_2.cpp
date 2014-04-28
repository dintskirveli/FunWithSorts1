#include "project_2.h"

counter merge_sort_Comps("merge_sort comparisons");
counter adap_merge_sort_Comps("adap_merge_sort comparisons");
counter adap20_merge_sort_Comps("adap20_merge_sort comparisons");
counter heap_sort_Comps("heap_sort comparisons");
counter heap_sort_Swaps("heap_sort exchanges");
counter quicksort1_Comps("quick_sort1 comparisons");
counter quicksort1_Swaps("quick_sort1 exchanges");
counter quickToInsertSortTime_Comps("quickToInsertSortTime comparisons");
counter quickToInsertSortTime_Swaps("quickToInsertSortTime exchanges");
counter quickMedianOfThreeSort_Comps("quickMedianOfThreeSort comparisons");
counter quickMedianOfThreeSort_Swaps("quickMedianOfThreeSort exchanges");
counter quickMedianOfThreeToInsertionSort_Comps("quickMedianOfThreeToInsertionSort comparisons");
counter quickMedianOfThreeToInsertionSort_Swaps("quickMedianOfThreeToInsertionSort exchanges");
counter shellSort1_Comps("shellSort1 comparisons");
counter shellSort1_Swaps("shellSort1 exchanges");
counter shellSort2_Comps("shellSort2 comparisons");
counter shellSort2_Swaps("shellSort2 exchanges");

timer mergeSortTime("merge sort time");
timer adapMergeSortTime("adap_merge_sort time");
timer adap20SortTime("adap20_sort_time");
timer heapSortTime("heap sort time");
timer shellSort1Timer("shellSort1 time");
timer shellSort2Timer("shellSort2 time");
timer quickSort1Time("vanilla quicksort time");
timer quickToInsertSortTime("quick to insertion sort time");
timer quickMedianOfThreeSortTime("quick median of three sort time");
timer quickMedianOfThreeToInsertionSortTime("quick median of three to insertion sort time");

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

	counters->push_back(quicksort1_Comps);
	counters->push_back(quicksort1_Swaps);
	counters->push_back(quickToInsertSortTime_Swaps);
	counters->push_back(quickToInsertSortTime_Comps);
	counters->push_back(quickMedianOfThreeSort_Comps);
	counters->push_back(quickMedianOfThreeSort_Swaps);
	counters->push_back(quickMedianOfThreeToInsertionSort_Comps);
	counters->push_back(quickMedianOfThreeToInsertionSort_Swaps);

	counters->push_back(shellSort1_Comps);
	counters->push_back(shellSort1_Swaps);
	counters->push_back(shellSort2_Comps);
	counters->push_back(shellSort2_Swaps);

	return counters;
} 

vector<timer> * project2TimerVector() {
	vector<timer> * timers = new vector<timer>();

	timers->push_back(mergeSortTime);
	timers->push_back(adapMergeSortTime);
	timers->push_back(adap20SortTime);
	timers->push_back(heapSortTime);
	timers->push_back(quickSort1Time);
	timers->push_back(quickToInsertSortTime);
	timers->push_back(quickMedianOfThreeSortTime);
	timers->push_back(quickMedianOfThreeToInsertionSortTime);
	timers->push_back(shellSort1Timer);
	timers->push_back(shellSort2Timer);	
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
	adapMergeSortTime.stop();
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

void quickSort(pair<int*, int> p) {
	quickSort1Time.next();
	quickSort1Time.start();
	quicksort1_Comps.next();
	quicksort1_Swaps.next();
	quickSort(p.first, 0, p.second-1);
	quickSort1Time.stop();
}

int partition(int* a, int p, int r, int value)
{
    int pivot = value;
    if (value == -1) pivot = a[r];

    while ( p < r )
    {
    	quicksort1_Comps.increment();
        while ( a[p] < pivot ) p++;
        quicksort1_Comps.increment();
        while ( a[r] > pivot ) r--;
        quicksort1_Comps.increment();
        if ( a[p] == a[r] ) p++;

        if ( p < r ) {
        	quicksort1_Swaps.increment();
            swap(a[p], a[r]);
        } else {
        	break;
        }
    }
    return r;
}

void quickSort( int *a, int first, int last ) {
    if(first < last) {
        int pivotElement = partition(a, first, last, -1);
        quickSort(a, first, pivotElement-1);
        quickSort(a, pivotElement+1, last);
    }
}

void quickToInsertSort(pair<int*, int> p) {
	quickToInsertSortTime.next();
	quickToInsertSortTime.start();

	quickToInsertSortTime_Comps.next();
	quickToInsertSortTime_Swaps.next();

	quickToInsertSort( p.first, 0, p.second-1);
	insertion_sort(p.first, 0, p.second-1);
	
	quickToInsertSortTime.stop();
}

void insertion_sort(int ary [], int first, int last) {
	int i, j, key;
	for (i = first + 1; i <= last; i++) {
		key = ary[i];
		j = i - 1;
		while (j >= first && ary[j] > key) {
			quickToInsertSortTime_Comps.increment();
			ary[j + 1] = ary[j];
			j = j - 1;
		}
		ary[j + 1] = key;
	}
}

int partition2(int* a, int p, int r, int value)
{
    int pivot = value;
    if (value == -1) pivot = a[r];

    while ( p < r )
    {
    	quickToInsertSortTime_Comps.increment();
        while ( a[p] < pivot ) p++;
        quickToInsertSortTime_Comps.increment();
        while ( a[r] > pivot ) r--;
        quickToInsertSortTime_Comps.increment();
        if ( a[p] == a[r] ) p++;

        if ( p < r ) {
        	quickToInsertSortTime_Swaps.increment();
            swap(a[p], a[r]);
        } else {
        	break;
        }
    }
    return r;
}

void quickToInsertSort( int *a, int first, int last ) {
 	if (last - first < 50) {
 		return;
 	} else if(first < last) {
        int pivotElement = partition2(a, first, last, -1);
        quickToInsertSort(a, first, pivotElement-1);
        quickToInsertSort(a, pivotElement+1, last);
    }
}

int partition3(int* a, int p, int r, int value)
{
    int pivot = value;
    if (value == -1) pivot = a[r];

    while ( p < r )
    {
    	quickMedianOfThreeSort_Comps.increment();
        while ( a[p] < pivot ) p++;
        quickMedianOfThreeSort_Comps.increment();
        while ( a[r] > pivot ) r--;
        quickMedianOfThreeSort_Comps.increment();
        if ( a[p] == a[r] ) p++;

        if ( p < r ) {
        	quickMedianOfThreeSort_Swaps.increment();
            swap(a[p], a[r]);
        } else {
        	break;
        }
    }
    return r;
}

//TODO: make random, not just first/last/middle
int medianOfThree(int * a, int first, int last) {
    return max(min(a[first],a[last]), min(max(a[first],a[last]), a[(first + last)/2]));
}

void quickMedianOfThreeSort( pair<int*, int> p ) {
	quickMedianOfThreeSort_Comps.next();
	quickMedianOfThreeSort_Swaps.next();
	
	quickMedianOfThreeSortTime.next();
	quickMedianOfThreeSortTime.start();
	
	quickMedianOfThreeSort(p.first, 0, p.second-1);
	
	quickMedianOfThreeSortTime.stop();
}

void quickMedianOfThreeSort( int *a, int first, int last ) {
    if(first < last) {
    	int value = medianOfThree(a, first, last);
        int pivotElement = partition3(a, first, last, value);
        quickMedianOfThreeSort(a, first, pivotElement-1);
        quickMedianOfThreeSort(a, pivotElement+1, last);
    }
}

void insertion_sort2(int ary [], int first, int last) {
	int i, j, key;
	for (i = first + 1; i <= last; i++) {
		key = ary[i];
		j = i - 1;
		while (j >= first && ary[j] > key) {
			quickMedianOfThreeToInsertionSort_Comps.increment();
			ary[j + 1] = ary[j];
			j = j - 1;
		}
		ary[j + 1] = key;
	}
}

int partition4(int* a, int p, int r, int value)
{
    int pivot = value;
    if (value == -1) pivot = a[r];

    while ( p < r )
    {
    	quickMedianOfThreeToInsertionSort_Comps.increment();
        while ( a[p] < pivot ) p++;
        quickMedianOfThreeToInsertionSort_Comps.increment();
        while ( a[r] > pivot ) r--;
        quickMedianOfThreeToInsertionSort_Comps.increment();
        if ( a[p] == a[r] ) p++;

        if ( p < r ) {
        	quickMedianOfThreeToInsertionSort_Swaps.increment();
            swap(a[p], a[r]);
        } else {
        	break;
        }
    }
    return r;
}

void quickMedianOfThreeToInsertionSort( pair<int*, int> p ) {
	quickMedianOfThreeToInsertionSort_Comps.next();
	quickMedianOfThreeToInsertionSort_Swaps.next();

	quickMedianOfThreeToInsertionSortTime.next();
	quickMedianOfThreeToInsertionSortTime.start();
	
	quickMedianOfThreeToInsertionSort(p.first, 0, p.second-1);
	insertion_sort2(p.first, 0, p.second-1);
	
	quickMedianOfThreeToInsertionSortTime.stop();
}

void quickMedianOfThreeToInsertionSort( int *a, int first, int last ) {
    if (last - first < 50) {
    	return;
 	} else if(first < last) {
    	int value = medianOfThree(a, first, last);
        int pivotElement = partition4(a, first, last, value);
        quickMedianOfThreeToInsertionSort(a, first, pivotElement-1);
        quickMedianOfThreeToInsertionSort(a, pivotElement+1, last);
    }
}

void shellSort1(pair<int*, int> p) {

	shellSort1Timer.next();
	shellSort1Timer.start();

	shellSort1_Comps.next();
	shellSort1_Swaps.next();

	shellSort1(p.first, p.second);
	shellSort1Timer.stop();
}

pair <int*, int> genIncs1(int N) {
	int size = log(N);
	int * cur = (int*)malloc((size-1)*sizeof(int));
	for (int i = 1; i < size; i++) {
		cur[i-1] = 2*i -1;
	}
	return make_pair(cur, size-1);
}

void shellSort1(int * a, int n) {
	pair<int *, int> inc = genIncs1(n);
    int h, i, j;
    for (int z = inc.second-1; z >= 0; z--) {
    	h = inc.first[z];
    	for (i = h; i < n; i++) {
            for (j = i-h; j >= 0 && (a[j] > a[i]); j -= h) {
            	shellSort1_Comps.increment();
                a[j+h] = a[j];
                shellSort1_Swaps.increment();
            }
            a[j+h] = a[i];
            shellSort1_Swaps.increment();
        }
    }
}

void shellSort2(pair<int*, int> p) {

	shellSort2Timer.next();
	shellSort2Timer.start();

	shellSort2_Comps.next();
	shellSort2_Swaps.next();

	shellSort2(p.first, p.second);
	shellSort2Timer.stop();
}

pair <int*, int> genIncs2(int N) {
	int tmpSize = 16; //enough for 312,500
	int * incs= (int *)malloc(tmpSize*sizeof(int));
	int index = 1;
	incs[0] = 1;
	while (index < tmpSize) {
		incs[index] = (3*incs[index-1]+1);
		index++;
	}
	int numIncs = 0;
	while(incs[numIncs+2] < N) {
		numIncs++;
	}
	numIncs++;
	int * realIncs = (int *)malloc(numIncs*sizeof(int));
	for (int i = 0; i < numIncs; i++) {
		realIncs[i] = incs[i];
	}
	free(incs);
	return make_pair(realIncs, numIncs);

}

void shellSort2(int * a, int n) {
	pair<int *, int> inc = genIncs2(n);
    int h, i, j;
    for (int z = inc.second-1; z >= 0; z--) {
    	h = inc.first[z];
    	for (i = h; i < n; i++) {
            for (j = i-h; j >= 0 && (a[j] > a[i]); j -= h) {
            	shellSort2_Comps.increment();
            	a[j+h] = a[j];
                shellSort2_Swaps.increment();
            }
            a[j+h] = a[i];
            shellSort2_Swaps.increment();
        }
    }
}

