def insertion_sort(arr):
    for i in range(len(arr) - 1):
        key = arr[i + 1]
        j = i
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
        print(f"{i + 1} : {' '.join(map(str, arr))}")

def main():
    input_list = list(map(int, input().split()))
    insertion_sort(input_list)

if __name__ == "__main__":
    main()