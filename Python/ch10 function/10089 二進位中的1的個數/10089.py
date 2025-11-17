def count_ones_in_binary(n):
    if n == 0:
        return 0
    
    return (n & 1) + count_ones_in_binary(n >> 1)

def main():
    number = int(input())
    result = count_ones_in_binary(number)
    print(result)

if __name__ == "__main__":
    main()