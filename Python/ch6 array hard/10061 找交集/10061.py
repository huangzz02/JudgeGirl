a = list(map(int, input().split()))
b = list(map(int, input().split()))

set_a = set(a)
set_b = set(b)
intersection = set_a & set_b

result = sorted(list(intersection))
print(*result)