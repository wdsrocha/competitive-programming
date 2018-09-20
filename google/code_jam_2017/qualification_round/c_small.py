def f(a):
    b = len(a)*[0]
    b[0] = 0 if a[0] else 1
    for i in range(1, len(a)):
        b[i] = 0 if a[i] else b[i-1]+1
    return b

def g(n, k):
    stalls = [0]*n
    for i in range(k):
        l = f(stalls)
        r = f(stalls[::-1])[::-1]
        index = great_lo = great_hi = -1
        for j in range(n):
            if min(l[j], r[j]) > great_lo or\
               (min(l[j], r[j]) == great_lo and max(l[j], r[j]) > great_hi):
                great_lo = min(l[j], r[j])
                great_hi = max(l[j], r[j])
                index = j
        stalls[index] = 1
    hi = max(l[index], r[index])-1
    lo = min(l[index], r[index])-1
    return [hi, lo]


for tc in range(int(input())):
    n, k = map(int, input().split())
    ans = g(n, k)
    print('Case #{0}: {1} {2}'.format(tc+1, ans[0], ans[1]))
