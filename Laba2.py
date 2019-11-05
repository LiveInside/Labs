import math
print("Ввести a")
a = float(input())

print("Ввести x")
x = float(input())

print("Выбрать номер функции 1-3")
ch = int(input())

if ch == 1:
    g1 = -45 * a ** 2 + 26 * a * x + 7 * x ** 2
    if g1 != 0:
        G = -1 * (7 * (4 * a ** 2 + 15 * a * x - 4 * x ** 2) / g1)
        print(G)
    else:
        print("Входные значения не принадлежат области определения функции.")

elif ch == 2:
    F = 2 ** (40 * a ** 2 - 107 * a * x + 63 * x ** 2)
    print(F)

elif ch == 3:
    y1 = a ** 2 - 2 * a * x + 3 * x ** 2 + 1
    if y1 >= 0:
        Y = math.log(y1)
        print(Y)
    else:
        print("Входные значения не принадлежат области определения функции.")

else:
    print("Номер функции выбран не верно.")









