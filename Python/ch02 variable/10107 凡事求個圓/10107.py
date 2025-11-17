import math

R = int(input())

circumference = 2 * math.pi * R
area = math.pi * R * R

print(f"圓周率為{math.pi:.7f}")
print(f"半徑為{R}")
print(f"圓周長為{circumference:.7f}")
print(f"圓面積為{area:.7f}")