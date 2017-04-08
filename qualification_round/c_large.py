from math import log2

def f(n, k):
    q = 1<<(int(log2(k))+1)
    p = n-k
    lo = p//q
    hi = (p+q//2)//q
    return [hi, lo]

TC = int(input())
for tc in range(TC):
    n, k = map(int, input().split())
    ans = f(n, k)
    print('Case #{}: {} {}'.format(tc+1, ans[0], ans[1]))
