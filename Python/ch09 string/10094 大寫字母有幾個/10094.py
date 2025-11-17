s = input()
count = 0

for char in s:
    if char.isupper():
        count += 1

print(count)