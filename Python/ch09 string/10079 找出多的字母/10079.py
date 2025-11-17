str1 = list(input().lower())
str2 = list(input().lower())
repeated = []

for char in str2:
    if char not in str1 and char not in repeated:
        repeated.append(char)

repeated.sort()
print(''.join(repeated))