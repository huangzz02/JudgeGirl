arr = list(map(int, input().split()))
max_1 = arr[0]
max_2 = arr[1]
if max_1 < max_2:
    max_1, max_2 = max_2, max_1

for i in range(2, len(arr)):
    if arr[i] > max_1:
        max_2 = max_1
        max_1 = arr[i]
    elif arr[i] > max_2:
        max_2 = arr[i]

print(max_1 * max_2)

"""
Or using built-in functions:
    arr = list(map(int, input().split()))
    max_1 = max(arr)
    arr.remove(max_1)
    max_2 = max(arr)
    print(max_1 * max_2)
"""