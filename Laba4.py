import math

Exit = 0
Spisok_G = []
Spisok_F = []
Spisok_Y = []
Max_G = 0
Min_G = 0
Max_F = 0
Min_F = 0
Max_Y = 0
Min_Y = 0

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
        i = 0
        while x1 <= x and x <= x2:
            g1 = -45 * a ** 2 + 26 * a * x + 7 * x ** 2
            if g1 != 0:
                G = -1 * (7 * (4 * a ** 2 + 15 * a * x - 4 * x ** 2) / g1)
                Spisok_G.append(G)

                print('Аргумент x = {:2f}\t Значение = {:2f}'.format(x, Spisok_G[i]))

                i = i + 1
                x = x + Step
            else:
                print("Входные значения не принадлежат области определения функции.")
                continue

        print(Spisok_G)
        Max_G = max(Spisok_G)
        Min_G = min(Spisok_G)
        print('Максимум списка = ' + str(Max_G))
        print('Минимум списка = ' + str(Min_G))

    elif ch == 2:
        i = 0
        while x1 <= x and x <= x2:
            F = 2 ** (40 * a ** 2 - 107 * a * x + 63 * x ** 2)
            Spisok_F.append(F)

            print('Аргумент x = {:2f}\t Значение = {:2f}'.format(x, Spisok_F[i]))

            i = i + 1
            x = x + Step

        print(Spisok_F)
        Max_F = max(Spisok_F)
        Min_F = min(Spisok_F)
        print('Максимум списка = ' + str(Max_F))
        print('Минимум списка = ' + str(Min_F))

    elif ch == 3:
        i = 0
        while x1 <= x and x <= x2:
            y1 = a ** 2 - 2 * a * x + 3 * x ** 2 + 1
            if y1 >= 0:
                Y = math.log(y1)
                Spisok_Y.append(Y)

                print('Аргумент x = {:2f}\t Значение = {:2f}'.format(x, Spisok_Y[i]))

                i = i + 1
                x = x + Step
            else:
                print("Входные значения не принадлежат области определения функции.")
                continue

        print(Spisok_Y)
        Max_Y = max(Spisok_Y)
        Min_Y = min(Spisok_Y)
        print('Максимум списка = ' + str(Max_Y))
        print('Минимум списка = ' + str(Min_Y))

    else:
        print("Номер функции выбран не верно.")

    print("Выйти из программы?(1-да, 0-нет)")
    Exit = int(input())
