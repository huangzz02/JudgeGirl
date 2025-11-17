s = input().split()
reversed_words = [word[::-1] for word in s]
print(*reversed_words)