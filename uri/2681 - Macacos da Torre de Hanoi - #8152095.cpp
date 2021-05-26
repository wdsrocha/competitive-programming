n = int(input())
m = 86400
e = n
b = 2
x = 1
while e:
    if e%2:
        x = (x*b)%m
    b = (b*b)%m
    e //= 2
x = (x+m-1)%m
s = x%60
x//=60
m = x%60
h = x//60
print("{:02}:{:02}:{:02}".format(h, m, s))