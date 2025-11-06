currency = int(input())
NTD = int(input())

if currency == 1:
    result = NTD / 30.57
elif currency == 2:
    result = NTD / 0.209

print(int(result))