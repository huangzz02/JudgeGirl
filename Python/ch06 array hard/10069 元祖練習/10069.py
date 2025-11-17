n = int(input())
nums = [int(input()) for _ in range(n)]

nums_tuple = tuple(sorted(nums, reverse=True))

print(nums_tuple)