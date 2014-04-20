import matplotlib.pyplot as plt
import csv
import sys


def i2str(i):
	if i < 3:
		size = 500
	elif i < 6:
		size = 2500
	elif i < 9:
		size = 12500
	else : 
		size = 62500
	type = i % 3
	strtype = ""
	if type == 0:
		strtype = "random"
	elif type == 1: 
		strtype = "reverse"
	else :
		strtype = "20 percent"
	return strtype+ ": "+str(size)

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

seriesDict = {}
title = ""
with open('OMG.csv', 'rb') as csvfile:
	reader = csv.reader(csvfile)
	for row in reader:
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
	plt.ylabel("Counter")
	plt.xlabel("run #")

	if isBarGraph(key):
		plt.bar(range(12), [sum(s)/len(s) for s in [seriesy[i] for i in range(12)]] )
		plt.xticks(range(12), [i2str(i) for i in range(12)], rotation = 45, ha='center')
	else :
		for i in range(12):
			l = i2str(i)
			print seriesy[i], average," ", l
			averages.append(average)
			plt.plot(seriesy[i], label=l)
		#plt.

	#
	plt.title(key)
	plt.legend(loc="upper left")
	plt.savefig(key.replace(" ", "_"), bbox_inches='tight')




