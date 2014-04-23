import matplotlib.pyplot as plt
import random
#from numpy.random import normal, uniform

#gaussian_numbers = normal(size=1000)
#uniform_numbers = uniform(low=-3, high=3, size=1000)
def testfunc1():
	return random.random()*random.random();

def testfunc2():
	return 1-random.random()*random.random();

N = 1000000
bins = 100
testarr1 = [testfunc1() for f in range(N)]
testarr2 = [testfunc2() for f in range(N)]


plt.hist(testarr1, bins=bins, histtype='stepfilled', color='b', label='rand()*rand()', weights=[1.0/N for n in range(N)])
plt.hist(testarr2, bins=bins, histtype='stepfilled', color='r', alpha=0.5, label='1-rand()*rand()', weights=[1.0/N for n in range(N)])
plt.title("Random Histogram")
plt.xlabel("Value")
plt.ylabel("Probability")
plt.legend()
plt.savefig("randtest.png")