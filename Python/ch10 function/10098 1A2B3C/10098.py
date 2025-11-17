def compare_ABC(n, m):
    str_n = str(n)
    str_m = str(m)
    
    count_A = sum(1 for a, b in zip(str_n, str_m) if a == b)
    count_B = sum(1 for a, b in zip(str_n, str_m) if a != b and a in str_m)
    count_C = (len(str_n) - count_A - count_B) * 2
    # Example: a, b in zip("1234", "1253") 
    #          -> compare (a, b) and ('1','1'), ('2','2'), ('3','5'), ('4','3')
    
    return f"{count_A}A{count_B}B{count_C}C"

def main():
    n = int(input())
    m = int(input())
    result = compare_ABC(n, m)
    print(result)

if __name__ == "__main__":
    main()

"""
    Other solution (easier to read):
        def compare_ABC(n, m):
            n_str = str(n)
            m_str = str(m)
            
            A = 0
            B = 0
            C = 0
            
            for i in range(4):
                if n_str[i] == m_str[i]:
                    A += 1
            
            for i in range(4):
                if n_str[i] != m_str[i] and n_str[i] in m_str:
                    B += 1
            
            for digit in n_str:
                if digit not in m_str:
                    C += 1
            for digit in m_str:
                if digit not in n_str:
                    C += 1
            
            print(f"{A}A{B}B{C}C")
"""