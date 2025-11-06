import math

m = int(input())

price = 80
if m > 1500:
    price += math.ceil((m - 1500) / 500) * 5

print(price)