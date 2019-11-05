import math
print("Ввести a")
a = float(input())

print("Ввести x")
x = float(input())

g1 = -45*a**2+26*a*x+7*x**2
G = -1 * (7*(4*a**2+15*a*x-4*x**2)/g1)
print(G)

F = 2**(40*a**2-107*a*x+63*x**2)
print(F)

y1 = a**2-2*a*x+3*x**2+1
Y = math.log(y1)
print(Y)








