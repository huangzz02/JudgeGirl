a = int(input())
b = int(input())
found = False

for i in range(a, b + 1):
    if i == 1:
        continue

    s = 0
    for j in range(1, int(i**0.5) + 1): # If you use range(1, i), it will cause TLE
        if i % j == 0:
            s += j
            if j != 1 and j != i // j:  # Add another pair of factors
                s += i // j
        if s > i: # No need to continue if sum already exceeds i
            break
    if s == i:
        found = True
        print(i)

if not found:
    print("None")

# Compared to 10334_1.py, the part with the comments has been changed.