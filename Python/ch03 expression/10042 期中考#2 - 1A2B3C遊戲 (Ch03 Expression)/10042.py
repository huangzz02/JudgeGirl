n = list(input())
m = list(input())

A = sum(n[i] == m[i] for i in range(3))
B = sum(n[i] != m[i] and n[i] in m for i in range(3))
C = (3 - A - B) * 2

print(f"{A}A{B}B{C}C")