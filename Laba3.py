import math

Exit = 0

while Exit == 0:

    print("Ввести a")
    a = float(input())

    print("Ввести нижнюю границу - x")
    x1 = float(input())
    print("Ввести вверхнюю границу - x")
    x2 = float(input())
    print("Ввести x")
    x = float(input())

    print('Ввести шаг изменения переменной x')
    Step = float(input())

    print("Выбрать номер функции 1-3")
    ch = int(input())

    if ch == 1:
        while x1 <= x and x <= x2:
            g1 = -45 * a ** 2 + 26 * a * x + 7 * x ** 2
            if g1 != 0:
                G = -1 * (7 * (4 * a ** 2 + 15 * a * x - 4 * x ** 2) / g1)
                print('G = ' + str(G))
                x = x + Step
            else:
                print("Входные значения не принадлежат области определения функции.")
                continue

    elif ch == 2:
        while x1 <= x and x <= x2:
            F = 2 ** (40 * a ** 2 - 107 * a * x + 63 * x ** 2)
            print('F = ' + str(F))
            x = x + Step

    elif ch == 3:
        while x1 <= x and x <= x2:
            y1 = a ** 2 - 2 * a * x + 3 * x ** 2 + 1
            if y1 >= 0:
                Y = math.log(y1)
                print('Y = ' + str(Y))
                x = x + Step
            else:
                print("Входные значения не принадлежат области определения функции.")
                continue
    else:
        print("Номер функции выбран не верно.")

    print("Выйти из программы?(1-да, 0-нет)")
    Exit = int(input())
