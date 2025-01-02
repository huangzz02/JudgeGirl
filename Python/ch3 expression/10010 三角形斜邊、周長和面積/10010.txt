import math

a, b = map(int, input().split())
c = math.sqrt(a ** 2 + b ** 2)

s = a + b + c
area = 0.5 * a * b
print(f"{c:.1f}, {s:.1f}, {area:.1f}")