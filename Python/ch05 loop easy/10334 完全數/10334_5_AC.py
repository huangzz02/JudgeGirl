KNOWN = [6, 28, 496, 8128, 33550336, 8589869056, 137438691328, 2305843008139952128,
         2658455991569831744654692615953842176, 191561942608236107294793378084303638130997321548169216]
# KNOWN must at least = [6, 28, 496, 8128, 33550336] to pass the test cases
# It also shows if you use loop to find perfect numbers, it will TLE

a = int(input())
b = int(input())

found = False
for p in KNOWN:
    if p > b: break
    if p >= a:
        print(p)
        found = True

if not found:
    print("None")

# Completely change the logic, use the pre-known perfect numbers (brute-force).