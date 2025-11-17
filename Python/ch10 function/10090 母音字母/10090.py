def count_vowels(s):
    if not s:
        return 0
    
    vowels = 'aeiou'
    first = s[0].lower()

    return (first in vowels) + count_vowels(s[1:])

def main():
    s = input()
    print(count_vowels(s))

if __name__ == "__main__":
    main()