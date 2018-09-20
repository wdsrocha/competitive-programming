def log2(x):
    if x == 0: return -2**63
    b = 0
    while 1<<b <= x:
        b += 1
    return b-1

def f(n, k):
    q = 1<<(log2(k)+1)
    p = n-k
    lo = p//q
    hi = (p+q//2)//q
    return [hi, lo]

for tc in range(int(input())):
    n, k = map(int, input().split())
    ans = f(n, k)
    print('Case #{}: {} {}'.format(tc+1, ans[0], ans[1]))
