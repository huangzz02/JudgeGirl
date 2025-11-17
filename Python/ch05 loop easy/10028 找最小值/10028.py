min = -1

for i in range(3):
    n = int(input())
    if min == -1 or n < min:
        min = n

print(min)