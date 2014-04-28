import matplotlib.pyplot as plt
import csv
import sys
import os.path

files = ["project_1.csv", "project_2.csv"]

indexToNameMap = {};
def processHeader(row) :
	count = 0 
	for mapping in enumerate(row):
		count += 1
		indexToNameMap[mapping[0]] = mapping[1]
	return count

def i2str(i):
	return indexToNameMap[i]

def initSeries() :
	seriesy = []
	for i in range(schemaSize):
		seriesy.append([])
	return seriesy

file = sys.argv[1]

seriesDict = {}
title = ""
processedHeader = False
schemaSize = 0;
if not os.path.isfile(file) :
	eixt("file doesnt exist");
with open(file, 'rb') as csvfile:
	reader = csv.reader(csvfile)
	for row in reader:
		if not processedHeader :
			row = row[1:-1]
			schemaSize = processHeader(row)
			processedHeader = True
			continue

		row = row[:-1]
		for item in enumerate(row):
			if item[0] == 0:
				#ignore, is title
				title = item[1]
			else :
				try:
					y = seriesDict[title]
				except KeyError:
					seriesDict[title] = initSeries()
					y = seriesDict[title]
				index = item[0]-1
				y[index].append(int(item[1]))

print ","+",".join([i2str(i) for i in range(schemaSize)])

seriesList = []
for key in seriesDict:
	seriesList.append(key)
seriesList.sort()
for key in seriesList:
	#print indexToNameMap
	
	seriesy = seriesDict[key]
	print key+","+",".join([str(sum(x)) for x in seriesy])

