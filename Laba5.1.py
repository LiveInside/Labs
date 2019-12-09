a = str(input("Введите число, без пробела\n a =  "))
s = 0
i = 0
for i in range(len(a)):
    if a[i] == '.':
        s = 0
        break
    if a[i] == '.':
        s = 0
        break
    if int(a[i]) % 2 == 0:
        s = s + 1
if s != 0:
    print("Колличество четных чисел ", s)
else:
    print(0)