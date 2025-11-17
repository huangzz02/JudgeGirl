def sum_of_digits(n):
    if n == 0:
        return 0
    
    return n % 10 + sum_of_digits(n // 10)

def main():
    number = int(input())
    result = sum_of_digits(number)
    print(result)

if __name__ == "__main__":
    main()