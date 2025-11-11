import math

a = int(input())
b = int(input())
found = False

for i in range(a, b + 1):
    if i == 1:
        continue

    s = 1 # 1 is a proper divisor
    sqrt_i = int(math.sqrt(i)) # calculate square root once
    for j in range(2, sqrt_i + 1): # start from 2 to sqrt_i
        if i % j == 0:
            s += j
            if j != i // j:
                s += i // j
        if s > i:
            break
    if s == i:
        found = True
        print(i)

if not found:
    print("None")

# Compared to 10334_2.py, the part with the comments has been changed.