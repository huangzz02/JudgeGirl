def binary_search(target, array):
    left, right = 0, len(array) - 1

    while left <= right:
        mid = (left + right) // 2
        if array[mid] == target:
            return mid + 1  # Return 1-based index
        elif array[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
            
    return -1

def main():
    n = int(input())
    arr = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24]
    result = binary_search(n, arr)
    print(result)

if __name__ == "__main__":
    main()