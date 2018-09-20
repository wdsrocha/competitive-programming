for tc in range(int(input())):
    x, y = map(int, input().split())
    k = min(x, y)
    s3 = (k*k*(k+1)*(k+1)) // 4
    s2 = (k*(k+1)*(2*k+1)) // 6
    s1 = k*(k+1) // 2
    ans = s3 - (x+y)*s2 + x*y*s1
    ans %= 1000000007
    print('Case #{}: {}'.format(tc+1, ans))
