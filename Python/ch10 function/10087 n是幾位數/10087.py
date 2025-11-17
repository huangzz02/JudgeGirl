def count_digits(n):
    if n == 0:
        return 0
    
    return 1 + count_digits(n // 10)

def main():
    n = int(input())
    print(count_digits(n))

if __name__ == "__main__":
    main()