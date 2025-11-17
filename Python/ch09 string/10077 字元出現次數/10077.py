freq = {}
for i in range(26): # A ~ Z
    freq[chr(ord('A') + i)] = 0
for i in range(26): # a ~ z
    freq[chr(ord('a') + i)] = 0

s = input()

for c in s:
    if c in freq:
        freq[c] += 1

for c in freq:
    if freq[c] > 0:
        print(f"{c} {freq[c]}")