max_size = 1000000
cycle_len = [0] * (max_size + 1)
cycle_len[1] = 1
# cycle_len[i] record the loop length of number i

m = int(input())

for case in range(m):
    i, j = map(int, input().split())
    max_cycle = 0

    for k in range(i, j + 1):
        n = k
        temp_seq = []
        count = 0 # Different from previous version (count = 1), because we use memoization here

        while n != 1 and (n >= (max_size + 1) or cycle_len[n] == 0):
                         # If you encounter a number that is already in the list along the way,
                         # you can directly add the known loop length and stop the calculation.
            temp_seq.append(n)
            if n % 2 == 0:
                n //= 2
            else:
                n = 3 * n + 1
            count += 1

        # If n is within the range and its cycle length is known, add it to count
        if n < len(cycle_len):
            count += cycle_len[n]

        # Store the loop length of each number in the sequence into memo
        for idx, val in enumerate(temp_seq): # "enumerate" can get both index and value
            if val < len(cycle_len):
                cycle_len[val] = count - idx

        max_cycle = max(max_cycle, count)

    print(max_cycle)