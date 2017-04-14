TC = int(input())
for tc in range(1, TC+1):
    n = int(input())
    s = list(str(n))
    while (s != sorted(s)):
        n -= 1
        s = list(str(n))
    
    print('Case #{0}: {1}'.format(tc, n))
