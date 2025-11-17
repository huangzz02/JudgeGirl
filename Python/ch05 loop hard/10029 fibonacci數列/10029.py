n = int(input())

a = 0
b = 1

if n == 1:
    print(a)
elif n == 2:
    print(a, b)
else:
    print(a, b, end=' ')
    for i in range(2, n):
        c = a + b
        print(c, end="")
        a = b
        b = c
        if i != n - 1:
            print(" ", end="")