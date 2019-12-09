import math
import random
import time

T_All = 1000000


def getRandomNumber():
	return random.uniform(-10, 10)


def isValid	(Points, CenterPoint):
	if(math.sqrt(((Points[1] - CenterPoint[1])*(Points[1] - CenterPoint[1]))+((Points[2] - CenterPoint[2])*(Points[2] - CenterPoint[2]))) <=  CenterPoint[3]):
		return 1
	return 0


def SearchArea(r):
	CenterPoint = dict.fromkeys([1, 2, 3])
	CenterPoint[1] = getRandomNumber()
	CenterPoint[2] = getRandomNumber()
	CenterPoint[3] = r
	return CenterPoint


r = 5.0
CenterPoint = SearchArea(r)

Points = []
for i in range(T_All):
    tochka = dict.fromkeys([1, 2])
    tochka[1] = getRandomNumber()
    tochka[2] = getRandomNumber()
    Points.append(tochka)

i = 0
N = 0
start_time = time.time()
for i in range(T_All):

	true = isValid(Points[i], CenterPoint)
	if (true == 1):
		N = N+1

print("--- %s seconds ---" % (time.time() - start_time))
print('Колличество точек в области = ', N)
f =  open('Laba8py.txt', 'a')
f.write('{:2f}\t {:2f}\n'.format(T_All, (time.time() - start_time)))
f.close