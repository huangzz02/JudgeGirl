def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    # just check odd numbers from 3 to sqrt(n)
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    return True

def find_perfect_numbers(start, end):
    perfect_numbers = []
    
    p = 2
    while True:
        # calculate Mersenne number Mp = 2^p - 1
        mp = (1 << p) - 1  # 2^p - 1 using bit shift
        
        # if perfect number exceeds end, break the loop
        if (1 << (p - 1)) * mp > end:
            break
            
        # check if both p and Mp are prime
        if is_prime(p) and is_prime(mp):
            perfect_number = (1 << (p - 1)) * mp
            
            # check if perfect number is within the range
            if start <= perfect_number <= end:
                perfect_numbers.append(perfect_number)
        
        p += 1
    
    return perfect_numbers

def main():
    a = int(input())
    b = int(input())
            
    perfect_nums = find_perfect_numbers(a, b)
        
    if perfect_nums:
        for num in perfect_nums:
            print(num)
    else:
        print("None")

if __name__ == "__main__":
    main()

# Completely change the logic, use the property of Mersenne primes to find perfect numbers.