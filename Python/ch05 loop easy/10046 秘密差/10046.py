x = input()

A = 0
B = 0

for i in range(len(x)):
    digit = int(x[i])
    if (i + 1) % 2 != 0:
        A += digit
    else:
        B += digit

print(abs(A - B))