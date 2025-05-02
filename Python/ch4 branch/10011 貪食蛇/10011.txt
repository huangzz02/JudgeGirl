n = int(input())

i = 0
while n - i * i > 0:
    i += 1

if i % 2 != 0:
    if n - (i - 1) * (i - 1) <= i:
        x = i
        y = n - (i - 1) * (i - 1)
    else:
        x = (i * i - n) + 1
        y = i
else:
    if n - (i - 1) * (i - 1) <= i:
        x = n - (i - 1) * (i - 1)
        y = i
    else:
        x = i
        y = (i * i - n) + 1

print(x, y)