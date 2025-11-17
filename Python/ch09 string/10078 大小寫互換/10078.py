str = list(input())

for i in range(2, len(str), 3):
    if str[i].isupper():
        str[i] = str[i].lower()
    elif str[i].islower():
        str[i] = str[i].upper()

print("".join(str))