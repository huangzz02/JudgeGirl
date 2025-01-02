n, m = input().split()

A = B = 0

n_list = list(n)
m_list = list(m)

for i in range(4):
    if n[i] == m[i]:
        A += 1
        n_list[i] = m_list[i] = None

for i in range(4):
    if n_list[i] is not None and n_list[i] in m_list:
        B += 1

print(f"{A}A{B}B")