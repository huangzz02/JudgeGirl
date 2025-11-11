a = int(input())
b = int(input())

# precompute the sum of proper divisors for all numbers up to b
s = [0] * (b + 1)
for i in range(1, b + 1):
    for j in range(i * 2, b + 1, i):  # start from 2*i to avoid adding itself
        s[j] += i

found = False
for i in range(a, b + 1):
    if s[i] == i:  # sum of proper divisors equals i
        print(i)
        found = True

if not found:
    print("None")

# Completely change the logic, and use a lookup table to avoid repeated calculations.