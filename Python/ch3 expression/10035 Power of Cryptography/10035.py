from math import exp, log

n = int(input())
p = float(input())

print((int)(exp(log(p) / n) + 0.5))

# k ^ n = p
# n * ln(k) = ln(p)
# ln(k) = ln(p) / n
# k = e ^ (ln(p) / n)

# (int)(k + 0.5) is like (int)round(k)