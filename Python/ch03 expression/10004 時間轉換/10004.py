s = int(input())

h = s // 3600
m = (s % 3600) // 60
new_s = s % 60

print(f"{s} 秒可分解為")
print(f"{h} 小時")
print(f"{m} 分")
print(f"{new_s} 秒")