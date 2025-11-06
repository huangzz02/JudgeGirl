even_count = 0
odd_count = 0

for i in range(5):
    num = int(input())
    if num % 2 == 0:
        even_count += 1
    else:
        odd_count += 1

print(f"偶數個數: {even_count}")
print(f"奇數個數: {odd_count}")