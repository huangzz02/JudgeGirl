def find_combinations(arr, target, start = 0, path=[], res=[]):
    if target == 0:
        res.append(path)
        return
    if target < 0: # Not a valid combination
        return
    
    for i in range(start, len(arr)):
        find_combinations(arr, target - arr[i], i, path + [arr[i]], res)

    return res

def main():
    arr = list(map(int, input().split()))
    arr = sorted(set(arr))  # Remove duplicates and sort
    target = 21
    combinations = find_combinations(arr, target)
    
    print(len(combinations))
    for combo in combinations:
        print(*combo)

if __name__ == "__main__":
    main()