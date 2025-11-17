N = int(input())
score = 0

if N <= 10:
    score = N * 6
elif N <= 20:
    score = 60 + (N - 10) * 2
elif N <= 40:
    score = 80 + (N - 20) * 1
else:
    score = 100

print(score)