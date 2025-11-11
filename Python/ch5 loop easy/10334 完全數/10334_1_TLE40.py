a = int(input())
b = int(input())
found = False

for i in range(a, b + 1):
    if i == 1:
        continue

    s = 0
    for j in range(1, i):
        if i % j == 0:
            s += j
    if s == i:
        found = True
        print(i)

if not found:
    print("None")