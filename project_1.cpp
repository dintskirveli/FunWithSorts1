#include "project_1.h"

counter bubbleComps("bubble comparisons");
counter bubbleSwaps("bubble exchanges");
counter adapBubbleComps("adap. bubble sort comparisons");
counter adapBubbleSwaps("adap. bubble sort exchanges");
counter insertionComps("insertion sort comparisons");
counter selectionComps("selection sort comparisons");
counter selectionSwaps("selection sort exchanges");


int main() {
	vector < pair<int*, int> > * samples = initSamples();

    /*performSort(bubble_sort);
    bubbleComps.printAll();
	bubbleSwaps.printAll();*/

	/*performSort(adap_bubble_sort);
    adapBubbleComps.printAll();
	adapBubbleSwaps.printAll();*/

	performSort(insertion_sort, samples);
	insertionComps.printAll();

	deallocSamples(samples);
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
		if (i <= sorted) a[i] = i;
		else a[i] = rand() % 1000000; 
	}
}

vector< pair<int*, int> > * initSamples() {
	vector< pair<int*, int> > * samples = new vector< pair<int*, int> >();
	srand(time(NULL));
	for (int i = 0; i < 4; i++) {
		int size; 
		switch (i) {
			case 0:
				size = 500;
				//size = 5;
				break;
			case 1:
				size = 2500;
				//size = 10;
				break;
			case 2:
				size = 12500;
				//size = 15;
				break;
			case 3:
				size = 62500;
				//size = 20;
				break;
			default:
				cout << "WAT\n";
				break;
		}
		
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

void performSort(void f(pair<int*, int>), vector< pair<int*, int> > *samples) {
	vector< pair<int*, int> > *victim = copySamples(samples); 
	for (vector<pair<int*,int> >::iterator it = victim->begin() ; it != victim->end(); ++it) {
		pair<int *, int> p = *it;
		cout<<"sorting size: "<<p.second<<"\n";
		f(*it);
	}
	deallocSamples(victim);
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
	bool flag = true;
	for (int i = 1; (i <= size) && flag; i++) {
		flag = false;
		for (int j = 0; j < size - 1; j++) {
			adapBubbleComps.increment();
			if (ary[j] > ary[j+1]) {
				adapBubbleSwaps.increment();
				swap(ary[j], ary[j+1]);
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
		selectionSwaps.increment();
		swap(ary[min],ary[i]);
	}
}

int sequencial_search(pair<int*, int>p, int key) {
	sequencial_search(p.first, p.second, key);
}

int sequencial_search(int ary [], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (ary[i] == key) return i;
	}
	return -1;
}

int ordered_sequencial_search(pair<int*, int>p, int key) {
	ordered_sequencial_search(p.first, p.second, key);
}

int ordered_sequencial_search(int ary [], int size, int key) {
	for (int i = 0; i < size; i++) {
		if (ary[i] <= key) return i;
	}
	return -1;
}

int adap_sequencial_search1(pair<int*, int>p, int key) {
	adap_sequencial_search1(p.first, p.second, key);
}

int adap_sequencial_search1(int ary [], int size, int key) {
	int temp;
	for (int i = 0; i < size; i++) {
		if (ary[i] == key) {
			temp = ary[1];
			ary[1] = key;
			ary[i] = temp;
			return i;
		}
	}
	return -1;
}

int adap_sequencial_search2(pair<int*, int>p, int key) {
	adap_sequencial_search2(p.first, p.second, key);
}

int adap_sequencial_search2(int ary [], int size, int key) {
	int temp;
	for (int i = 0; i < size; i++) {
		if (ary[i] == key) {
			swap(ary[i], ary[i-1]);
			return i;
		}
	}
	return -1;
}