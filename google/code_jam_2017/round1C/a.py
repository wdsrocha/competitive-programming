from itertools import permutations
from math import pi
from functools import cmp_to_key as cmpf

area = lambda r: pi*r*r
perimeter = lambda r, h: 2*pi*r*h

for tc in range(int(input())):
    n, k = map(int, input().split())
    pancakes = [[int(x) for x in input().split()] for y in range(n)] 
    best = 0
    pancakes = sorted(pancakes)[::-1]
    print(sorted(pancakes, key=cmpf(lambda a, b: a[1] > b[1])))
    print(sorted(pancakes))
    continue
    for i in range(n-k):
        value = area(pancakes[i]) + perimeter(pancakes[i])
        value += sum(sorted(pancakes[i:], key=cmpf(lambda a, b: a[1]>b[1])))
    print('Case #{}: {:.9f}'.format(tc+1, best))
