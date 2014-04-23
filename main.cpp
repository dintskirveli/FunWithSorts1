#include "util.h"
#include "project_1.h"
#include "project_2.h"
#include <assert.h>

void project_1();
void project_2();
void testSort(void f(int *, int), int size);
char project_1_filename[] = "project_1.csv";
char project_2_filename[] = "project_2.csv";

float randrand() {
	return ((float)rand()/RAND_MAX) * ((float)rand()/RAND_MAX);
}
int main() {
	//testSort(shellSort, 100);
	srand(clock()*time(NULL));
	for (int i = 0; i < 1000000; i++) {
		cout << randrand() << "\n";
	}
	//project_1();
	//project_2();
}

void project_1() {
	int runs = 10;
	int range = 1000000; //range of random numers, one million
	for (int i = 0; i<runs; i++) {
		vector < pair<int*, int> > * samples = initSamples(project1getSampleSizes(), project1getSampleTypes());



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