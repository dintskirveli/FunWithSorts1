#include "util.h"
#include "project_1.h"
#include "project_2.h"
#include <assert.h>
#include <list>

void project_1();
void project_2();
void testSort(void f(int *, int), int size);
char project_1_filename[] = "project_1.csv";
char project_2_filename[] = "project_2.csv";

int main() {
	//testSort(shellSort, 100);
	/*
    srand(clock()*time(NULL));
    for (int i = 0; i < 1000000; i++) {
		cout << randrand() << "\n";
	}
    */
    
	project_1();
	//project_2();
/*
		int size = 10;
		int * arr = (int *) malloc(size * sizeof(int));
		srand(clock());
		createRandArray(arr, size);
		printArray(arr, size);
		cout << "================\n";
        cout << "================\n";
        cout << "================\n";
		
		std::list<int> mylist;

		for (int i = 0; i < size; i++) {
			mylist.push_back(arr[i]);
		}

		for (std::list<int>::iterator it = mylist.begin(); it!=mylist.end(); ++it) {
    		std::cout << ' ' << *it;
    	}

		for (std::list<int>::iterator it=mylist.begin(); it != mylist.end(); ++it) {
	    	
	    	if (*it == arr[0]) {
	    		mylist.push_front(*it);
	    		mylist.erase(it);
	    		
	    		break;
	    	}
		}

		cout << "================\n";
        cout << "================\n";
        cout << "================\n";
		
		for (std::list<int>::iterator it = mylist.begin(); it!=mylist.end(); ++it) {
    		std::cout << ' ' << *it;
    	}
		

	    int * toSearch = createElementArray(arr, size); */
	    /*
	    //printArray(toSearch, size);
	    cout << "================\n";
	    printArray(arr, size);
	    int ret1 = adap_sequencial_search1(arr, size, toSearch[1], 0);
	    if (ret1 == -1) {
            	cout << toSearch[1] << "\n";
            	cout << "NOT FOUND 1111\n";
         }
         cout << "================\n";
        printArray(arr, size);
        ret1 = adap_sequencial_search1(arr, size, toSearch[0], 0);
	    if (ret1 == -1) {
            	cout << toSearch[0] << "\n";
            	cout << "NOT FOUND 2222\n";
         }
         

        cout << 2 % size << "\n";
        cout << 3 % size << "\n";
        cout << 499*2 % size << "\n";*/
       /* cout << "================\n";
        		printArray(arr, size);
        		cout << "================\n";
        		cout << "================\n";
        		cout << "================\n";


        for (int i = 0; i < size * 1; i++) {
            //int keyIndex = randrand(p.second);
            //f(p, toSearch[rand() % p.second]);
            int ret1 = adap_sequencial_search1(arr, size, toSearch[i % size], i % size);
            int ret2 = adap_sequencial_search2(arr, size, toSearch[i % size]);
            if (ret1 == -1) {
            	cout << "index: "<< i % size << "\n";
            	cout << toSearch[i % size] << "\n";
            	cout << "NOT FOUND 1\n";
            	cout << "================\n";
        		printArray(arr, size);
            } 
            if (ret2 == -1) {
            	cout << "index: "<< i % size << "\n";
            	cout << toSearch[i % size] << "\n";
            	cout << "NOT FOUND 2\n";
            	cout << "================\n";
        		printArray(arr, size);
            } 
        }*/
}

void project_1() {
	int runs = 1;
	int range = 1000000; //range of random numers, one million
	for (int i = 0; i<runs; i++) {
		vector < pair<int*, int> > * samples = initSamples(project1getSampleSizes(), project1getSampleTypes());
        performSearch(adap_sequencial_search1, samples);
        //performSearch(adap_sequencial_search2, samples);
 		
		deallocSamples(samples);
	}
	printCountersToCSV(project_1_filename, project1CounterVector(), project1getSampleSizes(), project1getSampleTypes(), true);
}

void project_2() {
	int runs = 50;
	int range = 10000000; //range of random numers, ten million
	for (int i = 0; i<runs; i++) {
		vector < pair<int*, int> > * samples = initSamples(project2getSampleSizes(), project2getSampleTypes());

		performSort(heap_sort, samples);
		//performSort(quickSort, samples);
		//performSort(merge_sort, samples);

		deallocSamples(samples);
	}
	printCountersToCSV(project_2_filename, project2CounterVector(), project2getSampleSizes(), project2getSampleTypes(), true);
	printTimersToCSV(project_2_filename, project2TimerVector(), project2getSampleSizes(), project2getSampleTypes(), false);
}

void testSort(void f(int *, int), int size) {
	int * a = (int *) malloc(size * sizeof(int));
	srand(clock());
	createRandArray(a, size);
	cout << "testing sort...\n";
	f(a, size);
	assert(isSorted(a, size));
	cout << "passed.\n";
}