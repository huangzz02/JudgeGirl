count = 0

def hnr(n, A, B, C):
    global count
    if n == 1:
        print(f"盤子從{A}移動到{C}")
        count += 1
        return
    
    hnr(n - 1, A, C, B) # Step 1: Move n-1 disks from A to B (using C as a reference).
    
    print(f"盤子從{A}移動到{C}") # Step 2: Move the nth disk from A to C
    count += 1
    
    hnr(n - 1, B, A, C) # Step 3: Move n-1 disks from B to C (using A as a reference)

def main():
    n = int(input())
    hnr(n, 'A', 'B', 'C')
    print(count)

if __name__ == "__main__":
    main()