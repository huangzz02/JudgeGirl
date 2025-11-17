n = int(input())
n += 1911

if (n % 400 == 0) or (n % 4 == 0 and n % 100 != 0):
    print(True)
else:
    print(False)