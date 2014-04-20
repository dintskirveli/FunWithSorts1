import matplotlib.pyplot as plt
import csv
import sys

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
	for i in range(12):
		seriesy.append([])
	return seriesy

#true if should be a bar graph
def isBarGraph(counterName) :
	if (counterName.lower().find("search") != -1):
		return False
	else :
		return True

width = int(sys.argv[1])
height = int(sys.argv[2])

files = ["project_1.csv", "project_2.csv"]

for file in files:
	seriesDict = {}
	title = ""
	processedHeader = False
	schemaSize = 0;
	with open(file, 'rb') as csvfile:
		reader = csv.reader(csvfile)
		for row in reader:
			if not processedHeader :
				row = row[1:-1]
				schemaSize = processHeader(row)
				print schemaSize
				print indexToNameMap
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

	for key in seriesDict:
		print key
		seriesy = seriesDict[key]
		fig = plt.figure()
		dpi = fig.dpi 
		fig.set_size_inches(width / dpi, height / dpi) 
		plt.ylabel("Counter value")
		plt.xlabel("Counter name")

		if isBarGraph(key):
			plt.bar(range(schemaSize), [sum(s)/len(s) for s in [seriesy[i] for i in range(schemaSize)]] )
			plt.xticks(range(schemaSize), [i2str(i) for i in range(schemaSize)], rotation = 45, ha='right')
		else :
			for i in range(schemaSize):
				l = i2str(i)
				print seriesy[i], average," ", l
				averages.append(average)
				plt.plot(seriesy[i], label=l)
			#plt.

		#
		plt.title(key)
		plt.legend(loc="upper left")
		plt.savefig(key.replace(" ", "_"), bbox_inches='tight')




