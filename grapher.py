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
	for i in range(12):
		l = i2str(i)
		plt.plot(seriesy[i], label=l)
	plt.title(key)
	plt.legend(loc="upper left")
	plt.savefig(key)




