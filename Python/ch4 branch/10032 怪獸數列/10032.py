n = input().strip()

result = ""
used = set()

for ch in n:
    if ch not in used:
        count = n.count(ch)
        result += str(count) + ch
        used.add(ch)

print(result)