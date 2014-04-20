#include "util.h"
#include "project_1.h"
#include "project_2.h"

vector<counter> * getCounterVector();
void project_1();
void project_2();
char project_1_filename[] = "project_1.csv";
char project_2_filename[] = "project_2.csv";

int main() {
	project_1();
	project_2();
}

void project_1() {
	int runs = 10;
	for (int i = 0; i<runs; i++) {
		vector < pair<int*, int> > * samples = initSamples(project1getSampleSizes(), project1getSampleTypes());



		deallocSamples(samples);
	}
	printCountersToCSV(project_1_filename, project1CounterVector(), project1getSampleSizes(), project1getSampleTypes(), true);
}

void project_2() {
	int runs = 5;
	for (int i = 0; i<runs; i++) {
		vector < pair<int*, int> > * samples = initSamples(project2getSampleSizes(), project2getSampleTypes());

		performSort(heap_sort, samples);

		//performSort(merge_sort, samples);

		deallocSamples(samples);
	}
	printCountersToCSV(project_2_filename, project2CounterVector(), project2getSampleSizes(), project2getSampleTypes(), true);
	printTimersToCSV(project_2_filename, project2TimerVector(), project2getSampleSizes(), project2getSampleTypes(), false);
}