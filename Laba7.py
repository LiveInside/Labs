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
    strA = input('a = ')
    a = float(strA)

    print("Ввести нижнюю границу - x")
    strX1 = input('X1 = ')
    print("Ввести вверхнюю границу - x")
    strX2 = input('X2 = ')
    print("Ввести x")
    strX = input('X = ')

    print('Ввести шаг изменения переменной x')
    strStep = input("Step = ")
    Step = float(strStep)

    x1 = float(strX1)
    x2 = float(strX2)
    x = float(strX)
    i = 0
    while x1 <= x and x <= x2:
        g1 = -45 * a ** 2 + 26 * a * x + 7 * x ** 2
        if g1 != 0:
            G = -1 * (7 * (4 * a ** 2 + 15 * a * x - 4 * x ** 2) / g1)
            Spisok_G.append(G)

            strG = "\t".join([str(i) for i in Spisok_G])
            print('Аргумент x = {:2f}\t Значение = {:2f}'.format(x, Spisok_G[i]))

            i = i + 1
            x = x + Step
        else:
            print("Входные значения не принадлежат области определения функции.")
            continue

    print(strG)
    shablon = input("Задать шаблон для поиска совпадений")
    sovpod = strG.count(shablon)
    print('Кол-во совпадений = ' '%d' %sovpod)
    Max_G = max(Spisok_G)
    Min_G = min(Spisok_G)
    print('Максимум списка = ' + str(Max_G))
    print('Минимум списка = ' + str(Min_G))

    x1 = float(strX1)
    x2 = float(strX2)
    x = float(strX)
    i = 0
    while x1 <= x and x <= x2:
        F = 2 ** (40 * a ** 2 - 107 * a * x + 63 * x ** 2)
        Spisok_F.append(F)
        strF = "\t".join([str(i) for i in Spisok_F])
        print('Аргумент x = {:2f}\t Значение = {:2f}'.format(x, Spisok_F[i]))

        i = i + 1
        x = x + Step

    print(strF)
    shablon = input("Задать шаблон для поиска совпадений")
    sovpod = strF.count(shablon)
    print('Кол-во совпадений = ' '%d' %sovpod)
    Max_F = max(Spisok_F)
    Min_F = min(Spisok_F)
    print('Максимум списка = ' + str(Max_F))
    print('Минимум списка = ' + str(Min_F))

    x1 = float(strX1)
    x2 = float(strX2)
    x = float(strX)
    i = 0
    while x1 <= x and x <= x2:
        y1 = a ** 2 - 2 * a * x + 3 * x ** 2 + 1
        if y1 >= 0:
            Y = math.log(y1)
            Spisok_Y.append(Y)
            strY = "\t".join([str(i) for i in Spisok_Y])
            print('Аргумент x = {:2f}\t Значение = {:2f}'.format(x, Spisok_Y[i]))

            i = i + 1
            x = x + Step
        else:
            print("Входные значения не принадлежат области определения функции.")
            continue

    print(strY)
    shablon = input("Задать шаблон для поиска совпадений")
    sovpod = strY.count(shablon)
    print('Кол-во совпадений = ' '%d' %sovpod)
    Max_Y = max(Spisok_Y)
    Min_Y = min(Spisok_Y)
    print('Максимум списка = ' + str(Max_Y))
    print('Минимум списка = ' + str(Min_Y))

    dictALL = {1: Spisok_G, 2: Spisok_F, 3: Spisok_Y}
    print(dictALL)
    print(dictALL[1])
    dictALL_F = '\n'.join('{}{}'.format(key, val) for key, val in dictALL.items())

    f = open('Laba7.txt', 'r+')
    try:
        f.write(dictALL_F)
    finally:
        f.close()

    dictALL.clear()

    with open('Laba7.txt', 'r+') as f:
       otvet = f.read()
    print(otvet)

    print("Выйти из программы?(1-да, 0-нет)")
    Exit = int(input())