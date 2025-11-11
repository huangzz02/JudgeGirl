guess = input()
Target = "1234"
A = 0
B = 0

if len(guess) != 4 or not guess.isdigit():
    print("Invalid input")
    exit()

for i in range(4):
    if guess[i] == Target[i]:
        A += 1
    elif guess[i] in Target:
        B += 1

print(f"{A}A{B}B")